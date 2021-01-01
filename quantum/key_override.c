/* 
 * Copyright 2021 Jonas Gessner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "report.h"

#include <debug.h>

// For benchmarking the time it takes to call process_key_override on every key press (needs keyboard debugging enabled as well)
// #define BENCH_KEY_OVERRIDE

// For debug output (needs keyboard debugging enabled as well)
// #define DEBUG_KEY_OVERRIDE

#ifdef BENCH_KEY_OVERRIDE
#    include "timer.h"
#endif

#ifdef DEBUG_KEY_OVERRIDE
#    define key_override_printf dprintf
#else
#    define key_override_printf(str, ...) \
        {}
#endif

// Helpers

extern uint8_t extract_mod_bits(uint16_t code);

static uint8_t clear_mods_from(uint16_t keycode) {
    uint16_t all_mods = QK_LCTL | QK_LSFT | QK_LALT | QK_LGUI | QK_RCTL | QK_RSFT | QK_RALT | QK_RGUI;

    return (uint8_t)(keycode & ~(all_mods));
}

// Internal variables
static const key_override_t *active_override                 = NULL;
static bool                  active_override_trigger_is_down = false;

// Hidden key holds the keycode of a key that is held down, but used in a currently active key override, in which case the key is not registered in the keyboard report. This is essential to allow activating a second key override that is triggered by the same key as a prior key override while the trigger key is still being held down.
static uint16_t hidden_key = 0;

static uint8_t key_down_count = 0;
static uint8_t mod_down_count = 0;

// TODO: in future maybe save in EEPROM
static bool enabled = true;

// Public variables
__attribute__((weak)) const key_override_t **key_overrides = NULL;

// Forward decls
static const key_override_t *clear_active_override(void);

void key_override_on(void) {
    enabled = true;
    key_override_printf("Key override ON\n");
}

void key_override_off(void) {
    enabled = false;
    if (clear_active_override() != NULL) {
        send_keyboard_report();
    }
    key_override_printf("Key override OFF\n");
}

void key_override_toggle(void) {
    if (key_override_is_enabled()) {
        key_override_off();
    } else {
        key_override_on();
    }
}

bool key_override_is_enabled(void) { return enabled; }

// Returns whether the modifiers that are pressed are such that the override should activate
static bool key_override_matches_active_modifiers(const key_override_t *override, const uint8_t mods) {
    // Check that negative keys pass
    if ((override->negative_modifier_mask & mods) != 0) {
        return false;
    }

    // Immediately return true if the override requires no mods down
    if (override->trigger_modifiers == 0) {
        return true;
    }

    if (override->one_mod) {
        // At least one of the trigger modifiers must be down
        return (override->trigger_modifiers & mods) != 0;
    } else {
        // All trigger modifiers must be down, but each mod can be active on either side (if both sides are specified).

        // Which mods, regardless of side, are required?
        uint8_t one_sided_required_mods = (override->trigger_modifiers & 0b1111) | (override->trigger_modifiers >> 4);

        // Which of the required modifiers are active?
        uint8_t active_required_mods = override->trigger_modifiers & mods;

        // Move the active requird mods to one side
        uint8_t one_sided_active_required_mods = (active_required_mods & 0b1111) | (active_required_mods >> 4);

        // Check that there is a full match between the required one-sided mods and active required one sided mods
        return one_sided_active_required_mods == one_sided_required_mods;
    }

    return false;
}

const key_override_t *clear_active_override(void) {
    if (active_override == NULL) {
        return NULL;
    }

    key_override_printf("Deactivating override\n");

    // Clear the suppressed mods
    clear_suppressed_mods();

    // Unregister the replacement. First remove the weak override mods
    clear_weak_override_mods();
    // del_suppressed_mods(active_override->suppressed_mods);

    const key_override_t *const old = active_override;

    bool unregister_replacement = active_override->replacement != KC_NO;
    // Try firing the custom handler
    if (active_override->custom_action != NULL) {
        unregister_replacement &= active_override->custom_action(false, active_override->context);
    }

    // Then unregister the mod-free replacement key if desired
    if (unregister_replacement) {
        const uint8_t replacement = clear_mods_from(active_override->replacement);
        if (IS_KEY(replacement)) {
            del_key(replacement);
        } else {
            key_override_printf("NOT KEY 1\n");
            send_keyboard_report();
            unregister_code(replacement);
        }
    }

    // Optionally re-register the trigger if it is still down
    if ((active_override->options & ko_option_reregister_trigger_on_deactivation) != 0 && active_override_trigger_is_down && active_override->trigger != KC_NO) {
        const uint16_t trigger = active_override->trigger;

        key_override_printf("Re-registering trigger: %u\n", trigger);

        if (IS_KEY(trigger)) {
            add_key(trigger);
        } else {
            key_override_printf("NOT KEY 2\n");
            send_keyboard_report();
            register_code(trigger);
        }

        hidden_key = 0;
    } else {
        send_keyboard_report();
    }

    active_override                 = NULL;
    active_override_trigger_is_down = false;

    return old;
}

/** Checks if the key event is an allowed activation event for the provided override. Does not check things like whether the correct mods or correct trigger key is down. */
static bool check_activation_event(const key_override_t *override, const bool key_down, const bool is_mod) {
    ko_activation_event_t allowed_events = override->allowed_activation_events;

    if (is_mod) {
        if (key_down) {
            return (allowed_events & ko_activation_mod_down) != 0;
        } else {
            return (allowed_events & ko_activation_mod_up) != 0;
        }
    }
    else {
        if (key_down) {
            return (allowed_events & ko_activation_key_down) != 0;
        } else {
            return (allowed_events & ko_activation_key_up) != 0;
        }
    }
}

/** Checks if the options of the override allow activating the override given the current keyboard state. */
static bool check_options(const key_override_t *const override) {
    const bool no_trigger = override->trigger == KC_NO;

    bool ok = true;

    if ((override->options & ko_option_exclusive_key_on_activate) != 0) {
        ok &= (key_down_count - mod_down_count) > (1 - (uint8_t)no_trigger);
    }

    return ok;
}

/** Iterates through the list of key overrides and tries activating each, until it finds one that activates or reaches the end of overrides. Returns true if the key action for `keycode` should be sent */
static bool try_activating_override(const uint16_t keycode, const uint8_t layer, const bool key_down, const bool is_mod, const uint8_t active_mods, const key_override_t *const blocked) {
    if (key_overrides == NULL) {
        return true;
    }

    for (uint8_t i = 0;; i++) {
        const key_override_t *const override = key_overrides[i];

        // End of array
        if (override == NULL) {
            break;
        }

        // Fast, but not full mods check. Most key presses will not have any mods down, and most overrides will require mods. Hence here we filter overrides that require mods to be down while no mods are down
        if (active_mods == 0 && override->trigger_modifiers != 0) {
            key_override_printf("Not activating override: Modifiers don't match\n");
            continue;
        }

        // Check layer
        if ((override->layers & (1 << layer)) == 0) {
            key_override_printf("Not activating override: Not set to activate on pressed layer\n");
            continue;
        }

        // Check allowed activation events
        if (!check_activation_event(override, key_down, is_mod)) {
            key_override_printf("Not activating override: Activation event not allowed\n");
            continue;
        }

        // Check options
        if (!check_options(override)) {
            key_override_printf("Not activating override: Options not allowing activation\n");
            continue;
        }

        const bool is_trigger = override->trigger == keycode;

        // Check if trigger lifted. This is a small optimization in order to skip the remaining checks
        if (is_trigger && !key_down) {
            key_override_printf("Not activating override: Trigger lifted\n");
            continue;
        }

        // If the trigger is KC_NO it means 'no key', so only the required modifiers need to be down.
        const bool no_trigger = override->trigger == KC_NO;

        // Check if blocked
        if (override == blocked) {
            key_override_printf("Not activating override: Blocked\n");
            continue;
        }

        // Check if enabled
        if (override->enabled != NULL && !((*(override->enabled) & 1))) {
            key_override_printf("Not activating override: Not enabled\n");
            continue;
        }

        // Check mods precisely
        if (!key_override_matches_active_modifiers(override, active_mods)) {
            key_override_printf("Not activating override: Modifiers don't match\n");
            continue;
        }

        // Check if trigger key is down.
        const bool trigger_down = is_trigger && key_down;

        // At this point, all requirements for activation are checked, except whether the trigger key is pressed. Now we check if the required trigger is down
        // If no trigger key is required, yes. If the trigger was just pressed, yes. If the trigger is the hidden key it is also down, so yes.
        bool should_activate = no_trigger || trigger_down || hidden_key == override->trigger;

        // Look through pressed key codes to see if trigger is down
        if (!should_activate && override->trigger <= UINT8_MAX) {
            if (is_key_pressed(keyboard_report, (uint8_t) override->trigger)) {
                should_activate = true;
                key_override_printf("Trigger already down\n");
            }
        } else if (!should_activate) {
            key_override_printf("ERROR! Complex keycode cannot appear in keyboard report. Override can only be activated when trigger is pressed down after modifiers!\n");
        }

        if (!should_activate) {
            key_override_printf("Not activating override. Trigger not down\n");
            continue;
        }

        key_override_printf("Activating override\n");

#ifdef DEBUG_KEY_OVERRIDE
        // Sanity check
        if (extract_mod_bits(override->trigger) != 0) {
            key_override_printf("ERROR! Not activating override: Trigger key includes mod bits. It cannot include any mod bits. Use trigger_modifiers for this.\n");
            continue;
        }
#endif

        clear_active_override();

        active_override                 = override;
        active_override_trigger_is_down = true;

        add_suppressed_mods(override->suppressed_mods);

        hidden_key = override->trigger;

        if (!trigger_down && !no_trigger) {
            // When activating a key override the trigger is is always unregistered. In the case where the key that newly pressed is not the trigger key, we havwe to explicitly remove the trigger key from the keyboard report. If the trigger was just pressed down we simply suppress the event which also has the effect of the trigger key not being registered in the keyboard report.
            del_key(override->trigger);
        }

        // If the replacement key is KC_NO, there is nothing to register.
        const bool register_replacement = override->replacement != KC_NO;

        // Try firing the custom handler
        if (override->custom_action != NULL) {
            register_replacement &= override->custom_action(true, override->context);
        }

        if (register_replacement) {
            const uint8_t  override_mods = extract_mod_bits(override->replacement);
            const uint16_t mod_free      = clear_mods_from(override->replacement);

            set_weak_override_mods(override_mods);

            if (IS_KEY(mod_free)) {
                add_key(mod_free);
            } else {
                key_override_printf("NOT KEY 3\n");
                // Have to send keyboard report before reigstering non key, as those are not sent in the keyboard report.
                send_keyboard_report();
                register_code(mod_free);
            }
        } else {
            // If not registering the replacement key send keyboard report to update the unregistered keys.
            send_keyboard_report();
        }

        // If the trigger is down, suppress the event so that it does not get added to the keyboard report.
        return !trigger_down;
    }

    return true;
}

bool process_key_override(const uint16_t keycode, const keyrecord_t *const record) {
#ifdef BENCH_KEY_OVERRIDE
    uint16_t start = timer_read();
#endif

    const bool key_down = record->event.pressed;

    if (key_down) {
        key_down_count++;

        switch (keycode) {
            case KEY_OVERRIDE_TOGGLE:
                key_override_toggle();
                return false;

            case KEY_OVERRIDE_ON:
                key_override_on();
                return false;

            case KEY_OVERRIDE_OFF:
                key_override_off();
                return false;

            default:
                break;
        }
    } else if (key_down_count > 0) {
        key_down_count--;
    }

    if (!enabled) {
        return true;
    }

    const key_override_t *blocked = NULL;

    // This only takes the physical mods on purpose. Key overrides are currently only supposed to trigger on physical key press events (process_record_quantum).
    uint8_t effective_mods = get_mods();
    const bool is_mod = IS_MOD(keycode);

    if (is_mod) {
        if (key_down) {
            mod_down_count++;
            effective_mods |= MOD_BIT(keycode);
        } else {
            effective_mods &= ~MOD_BIT(keycode);
            if (mod_down_count > 0) {
                mod_down_count--;
            }
        }

        // Check if necessary modifier of current override goes up or a negative mod goes down
        if (active_override != NULL && !key_override_matches_active_modifiers(active_override, effective_mods)) {
            key_override_printf("Deactivating override because necessary modifier lifted or negative mod pressed\n");
            blocked = clear_active_override();
        }
    } else {
        if (keycode == hidden_key && !key_down) {
            hidden_key = 0;
        }

        // Check if trigger of current override goes up or if override does not allow additional keys to be down and another key goes down
        if (active_override != NULL) {
            const bool is_trigger = keycode == active_override->trigger;
            const bool trigger_up = is_trigger && !key_down;

            bool should_deactivate = false;
            
            // Check if trigger key lifted
            if (is_trigger && !key_down) {
                active_override_trigger_is_down = false;
                should_deactivate = true;
                key_override_printf("Deactivating override because trigger key up\n");
            }

            if (!is_trigger && key_down && (active_override->options & ko_option_exclusive_key_during_active) != 0) {
                key_override_printf("Deactivating override because another key was pressed and no other keys are allowed down\n");
                should_deactivate = true;
            }

            if (should_deactivate) {
                blocked = clear_active_override();
            }
        }
    }

    // Get the exact layer that was hit. It will be cached at this point
    const uint8_t layer = read_source_layers_cache(record->event.key);

    // Use blocked to ensure the same override is not activated again immediately after it is deactivated
    const bool send_key_action = try_activating_override(keycode, layer, key_down, effective_mods, blocked);

    if (!send_key_action) {
        send_keyboard_report();
    }

#ifdef BENCH_KEY_OVERRIDE
    uint16_t elapsed = timer_elapsed(start);

    dprintf("Processing key overrides took: %u ms\n", elapsed);
#endif

    return send_key_action;
}

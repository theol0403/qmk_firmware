#include "smartcaps.h"

static bool smart_caps_on = false;

void smart_caps_enable() { smart_caps_on = true; }
void smart_caps_disable() { smart_caps_on = false; }
bool smart_caps_status() { return smart_caps_on; }

// decide whether the incoming keycode should disable smart caps
void smart_caps_check_disable(uint16_t keycode, keyrecord_t *record) {
  if (smart_caps_on && record->event.pressed) {
    // if any modifier is being pressed with this keycode, disable smart caps
    if (get_mods() != 0) {
      smart_caps_on = false;
      return;
    }
    // if button is a tap-hold, extract the keycode
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        keycode = keycode & 0xFF;
        // if the tap-hold is being held, don't disable smart caps
        if (record->tap.count == 0) return;
    }

    // Catch non-breaking keycodes (ie keycodes that won't disable smart caps)
    switch (keycode) {
      case KC_A ... KC_Z:
      case KC_BSPC:
      case KC_ENT:
      case KC_DEL:
      case KC_UNDS:
      case KC_MINS:
        break;
      default:
        // If we didn't break earlier, disable smart caps
        smart_caps_on = false;
    }
  }
}

// decide whether incoming keycodes should be shifted, and return false to prevent further processing
bool smart_caps_process(uint16_t keycode, keyrecord_t *record) {
  smart_caps_check_disable(keycode, record);
  if (smart_caps_on) {
    // if button is a tap-hold, extract the keycode
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        keycode = keycode & 0xFF;
        // if the tap-hold is being held don't shift, and process as usual
        // otherwise if tap-hold is being tapped, treat as the underlying alpha
        if (record->tap.count == 0) return true;
    }

    // keys we want to shift
    switch (keycode) {
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          register_code16(S(keycode));
        } else {
          unregister_code16(S(keycode));
        }
        // don't process the keycode any further
        return false;
    }
  }
  return true;
}

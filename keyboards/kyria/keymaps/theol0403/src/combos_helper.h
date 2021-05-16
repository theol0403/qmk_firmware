// credit to germ from gboards
// this helper takes a combo definition file (defined by COMBOS_FILE) and converts it to a qmk-compatible combo syntax

#define K_ENUM(name, key, ...) combo_##name,
#define K_DATA(name, key, ...) static const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#define K_COMB(name, key, ...) [combo_##name] = COMBO(cmb_##name, key),

#define A_DATA(name, string, ...) static const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#define A_COMB(name, string, ...) [combo_##name] = COMBO_ACTION(cmb_##name),
#define A_ACTI(name, string, ...)     \
  case combo_##name:                  \
    if (pressed) SEND_STRING(string); \
    break;

#define A_TOGG(name, layer, ...)      \
  case combo_##name:                  \
    if (pressed) layer_invert(layer); \
    break;

#define A_TAPP(name, code, ...)    \
  case combo_##name:               \
    if (pressed) tap_code16(code); \
    break;

#define A_TAPP8(name, code, ...) \
  case combo_##name:             \
    if (pressed) tap_code(code); \
    break;

#define BLANK(...)
// Generate data needed for combos/actions
// Create Enum
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8
#define COMB K_ENUM
#define SUBS K_ENUM
#define TOGG K_ENUM
#define TAPP K_ENUM
#define TAPP8 K_ENUM
#undef BEGIN_SECTION
#undef END_SECTION
enum combos {
#include COMBOS_FILE
  COMBO_LENGTH
};
// Export length to combo module
uint16_t COMBO_LEN = COMBO_LENGTH;

// Bake combos into mem
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8
#define COMB K_DATA
#define SUBS A_DATA
#define TOGG A_DATA
#define TAPP A_DATA
#define TAPP8 A_DATA
#undef BEGIN_SECTION
#undef END_SECTION
#define BEGIN_SECTION BLANK
#define END_SECTION BLANK
#include COMBOS_FILE
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8

// Fill combo array
#define COMB K_COMB
#define SUBS A_COMB
#define TOGG A_COMB
#define TAPP A_COMB
#define TAPP8 A_COMB
#undef BEGIN_SECTION
#undef END_SECTION
const combo_t key_combos[] = {
#include COMBOS_FILE
};
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8

// Fill QMK hook
#define COMB BLANK
#define SUBS A_ACTI
#define TOGG A_TOGG
#define TAPP A_TAPP
#define TAPP8 A_TAPP8
void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef CONSOLE_KEYLOG
  if (pressed) {
    const combo_t *combo = &key_combos[combo_index];
    uint8_t        idx   = 0;
    uint16_t       combo_keycode;
    while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
      uprintf("0x%04X,NA,NA,%u\n", combo_keycode, get_highest_layer(layer_state));
      idx++;
    }
  }
#endif

  // resolve any pending mod-taps
  action_tapping_process((keyrecord_t){});

  // apply smart caps to combos
  if (smart_caps_status()) {
    switch (combo_index) {
      // case BEGIN_BIGRAMS ... END_BIGRAMS:
      case BEGIN_TRIGRAMS ... END_TRIGRAMS:
      case BEGIN_WORDS ... END_WORDS:
        if (pressed) {
          register_mods(MOD_LSFT);
        } else {
          unregister_mods(MOD_LSFT);
        }
    }
  } else if (get_mods() & MOD_MASK_SHIFT) {
    // only shift first character of word combo
    switch (combo_index) {
      // case BEGIN_TRIGRAMS ... END_TRIGRAMS:
      case BEGIN_WORDS ... END_WORDS:
        clear_mods();
        set_oneshot_mods(MOD_LSFT);
    }
  }

  switch (combo_index) {
#include COMBOS_FILE
// Allow user overrides per keymap
#ifdef COMBOS_USER
#  include COMBOS_USER
#endif
  }
}
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8

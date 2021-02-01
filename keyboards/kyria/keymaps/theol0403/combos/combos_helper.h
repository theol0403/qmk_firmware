// credit germ from gboards
// Keymap helpers

#include "action.h"
#define K_ENUM(name, key, ...) combo_##name,
#define K_DATA(name, key, ...) const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
#define K_COMB(name, key, ...) [combo_##name] = COMBO(cmb_##name, key),

#define A_DATA(name, string, ...) const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
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
#include "combos.h"
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
#include "combos.h"
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
combo_t key_combos[] = {
#include "combos.h"
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
  if (smart_caps_on) {
    switch (combo_index) {
      case BEGIN_CORRECTIVE_BIGRAMS ... END_WORDS:
        if (pressed) {
          register_mods(MOD_LSFT);
        } else {
          unregister_mods(MOD_LSFT);
        }
    }
  }
  action_tapping_process((keyrecord_t){});
  if (get_mods() & MOD_MASK_SHIFT) {
    switch (combo_index) {
      case BEGIN_TRIGRAMS ... END_TRIGRAMS:
      case BEGIN_WORDS ... END_WORDS:
        clear_mods();
        set_oneshot_mods(MOD_LSFT);
    }
  }
  switch (combo_index) {
#include "combos.h"
    // Allow user overrides per keymap
#if __has_include("combos_user.h")
#  include "combos_user.h"
#endif
  }
}
#undef COMB
#undef SUBS
#undef TOGG
#undef TAPP
#undef TAPP8

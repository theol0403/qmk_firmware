#include "../keymap.h"

#define COMBOS_FILE "combos/combos.inc"
#include "combos_helper.h"

int16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    // case BEGIN_CORRECTIVE_BIGRAMS ... END_CORRECTIVE_BIGRAMS:
    //   return 9;
    //   break;
    // case BEGIN_TRIGRAMS ... END_TRIGRAMS:
    //   return 30;
    //   break;
    case BEGIN_WORDS ... END_WORDS:
      return 25;
      break;
    case BEGIN_SHORTCUT ... END_SHORTCUT:
      return 25;
      break;
    case BEGIN_HOLDS ... END_HOLDS:
      return 70;
      break;
  }
  return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
    case BEGIN_HOLDS ... END_HOLDS:
      return false;
  }
  return true;
}

#define NEW_RECORD(press)                  \
  .event = {                               \
      .key     = {.col = 254, .row = 254}, \
      .time    = timer_read() | 1,         \
      .pressed = press,                    \
  }

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
  // count the number of keys that were held down before
  uint8_t count = __builtin_popcount(combo->state);
  // if the key being released is the first that breaks the combo
  if (pgm_read_word(&combo->keys[count]) == COMBO_END) {
    // loop through all keys that are still held down
    for (uint8_t i = 0; i < count; ++i) {
      // don't touch the key that was released
      if (i == key_index) continue;
      // get the keycode of the keys still being pressed
      uint16_t other = pgm_read_word(&combo->keys[i]);
      switch (other) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
          // remove alt and gui
          if ((other & QK_MOD_TAP) == QK_MOD_TAP) other = other & 0xF3FF;
          action_tapping_process((keyrecord_t){NEW_RECORD(true), .keycode = other & 0xFF00});
      }
    }
  } else {
    // release all the tap-holds one by one
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        if ((keycode & QK_MOD_TAP) == QK_MOD_TAP) keycode = keycode & 0xF3FF;
        action_tapping_process((keyrecord_t){NEW_RECORD(false), .keycode = keycode & 0xFF00});
    }
  }
  return false;
}

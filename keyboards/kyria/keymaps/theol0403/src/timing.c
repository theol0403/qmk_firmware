#include "../keymap.h"

#define THUMB_TERM 190
#define PINKY_TERM 260
#define CTRL_TERM 170
#define SHIFT_TERM 120
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case T_R1:
      return THUMB_TERM - 60;
    case T_R2:
      return THUMB_TERM + 20;
    case T_R3:
    case T_L1:
    case T_L2:
    case T_L3:
      return THUMB_TERM;
    case U_Y:
    case U_T:
    case U_O:
    case U_I:
      return PINKY_TERM;
    case U_H:
    case U_N:
      return SHIFT_TERM;
    case U_A:
    case U_S:
      return CTRL_TERM;
  }
  return TAPPING_TERM;
}

// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case U_H:
//     case U_N:
//       return true;
//   }
//   return false;
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  int tapping = get_event_keycode(record->event, false);
  switch (keycode) {
    case T_R1:
    case T_R2:
      switch (tapping) {
        case T_L1:
        case T_L3:
          return true;
      }
      break;
    case U_N:
      switch (tapping) {
        case U_DOT:
        case U_QUES:
        case U_COMM:
          return true;
      }
      break;
    case U_H:
      switch (tapping) {
        case U_QUOT:
        case U_SL:
          return true;
      }
      break;
    case T_L2:
      switch (tapping) {
        case T_R1:
          return true;
      }
      break;
    case U_T:
      switch (tapping) {
        case T_L3:
          return true;
      }
      break;
  }
  return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  int tapping = get_event_keycode(record->event, false);
  switch (keycode) {
    case T_R1:
    case T_R3:
    case T_L1:
    case T_L3:
      return true;
    case U_H:
      switch (tapping) {
        case U_I:
          return true;
      }
  }
  return false;
}

bool get_bilateral_combinations(keypos_t *hold, keypos_t *tap) {
  bool same     = (hold->row < MATRIX_ROWS / 2) == (tap->row < MATRIX_ROWS / 2);
  bool adjacent = same && (abs(hold->row - tap->row) < 4) && (abs(tap->col - hold->col) < 4);
  return adjacent;
}

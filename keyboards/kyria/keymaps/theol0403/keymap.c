#include "action.h"
#include "action_code.h"
#include "keycode.h"
#include QMK_KEYBOARD_H

#define _ KC_NO
#define __ _______

enum layers { BASE, NUM, SYM, NAV, FUNC, MDIA, GAME };

enum custom_keycodes { START = SAFE_RANGE, SENT, QUES, SMRTCAPS };

#define U_RDO C(KC_Y)  // KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND C(KC_Z)  // KC_UNDO

#define HM_Y LGUI_T(KC_Y)
#define HM_T LALT_T(KC_T)
#define HM_H LSFT_T(KC_H)
#define HM_A LCTL_T(KC_A)

#define HM_S RCTL_T(KC_S)
#define HM_N RSFT_T(KC_N)
#define HM_O RALT_T(KC_O)
#define HM_I GUI_T(KC_I)

#define THMB_L1 LT(MDIA, KC_ESC)
#define THMB_L2 LT(NAV, KC_E)
#define THMB_L3 MT(MOD_LSFT, KC_TAB)

#define THMB_R3 LT(FUNC, KC_ENT)
#define THMB_R2 LT(NUM, KC_SPC)
#define THMB_R1 LT(SYM, KC_BSPC)

#define HM_Z LT(NUM, KC_Z)
#define HM_K LT(SYM, KC_K)
#define HM_Q KC_Q
#define HM_SL LT(NAV, KC_SLASH)

#define L(l) DF(l)
#define UNL DF(BASE)
#define LSF KC_LSFT
#define RSF KC_RSFT

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
  _,    _,    KC_P, KC_L, KC_U, KC_QUES,                                     KC_B,    KC_D,  KC_R, KC_QUOT, KC_BSLS, _,
  HM_Z, HM_Y, HM_T, HM_H, HM_A, KC_DOT,                                      KC_C,    HM_S,  HM_N, HM_O,    HM_I,    HM_SL,
  LSF,  HM_K, KC_M, KC_F, KC_J, KC_COMM, MO(NUM), MO(SYM), _,       MO(NAV), KC_V,    KC_G,  KC_W, KC_X,    HM_Q,    RSF,
                    _,    _,    THMB_L1, THMB_L2, THMB_L3, THMB_R3, THMB_R2, THMB_R1, KC_DEL,TG(GAME)
),
[NUM] = LAYOUT(
  L(NUM), _,       KC_6, KC_5, KC_4, KC_CIRC,                                _,       _,       _,       _,       RESET,   L(NUM), 
  UNL,    KC_ASTR, KC_3, KC_2, KC_1, KC_DOT,                                 _,       KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, UNL,     
  LSF,    _,       KC_9, KC_8, KC_7, KC_EQL,  _,    _,       _,      KC_SPC, _,       _,       _,       _,       _,       RSF,
                         _,    _,    KC_MINS, KC_0, KC_PLUS, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
[SYM] = LAYOUT(
  L(SYM), KC_TILD, KC_LT,   KC_LCBR, KC_RCBR, KC_GT,                                    _,       _,       _,       EEP_RST, RESET,   L(SYM), 
  UNL,    KC_HASH, KC_PERC, KC_LPRN, KC_RPRN, KC_AT,                                    _,       KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, UNL,     
  LSF,    KC_GRV,  KC_PIPE, KC_LBRC, KC_RBRC, KC_EQL,  _,      _,       _,      _,      KC_BSPC, _,       _,       _,       _,       RSF,
                            _,       _,       KC_UNDS, KC_DLR, KC_AMPR, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
[NAV] = LAYOUT(
  L(NAV), RESET,   _,       _,       _,       _,                           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS, L(NAV), 
  UNL,    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, U_UND,   UNL,     
  LSF,    U_RDO,   U_CUT,   U_CPY,   U_PST,   U_UND, _, _, _,      _,      U_UND,   U_PST,   U_CPY,   U_CUT,   U_RDO,   RSF,
                            _,       _,       _,     _, _, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
[FUNC] = LAYOUT(
  L(FUNC), KC_F10, KC_F6, KC_F5, KC_F4, _,                                       _,       _,       _,       _,       RESET,   L(FUNC), 
  UNL,     KC_F11, KC_F3, KC_F2, KC_F1, KC_PSCR,                                 _,       KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, UNL,     
  LSF,     KC_F12, KC_F9, KC_F8, KC_F7, _,       _,      _,      KC_ENT, _,      _,       _,       _,       _,       _,       RSF,
                          _,     _,     KC_ESC,  KC_APP, KC_TAB, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
[MDIA] = LAYOUT(
  L(MDIA), RESET,   EEP_RST, _,       _,       _,                                      RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, L(MDIA), 
  UNL,     KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, UNL,     
  LSF,     U_RDO,   U_CUT,   U_CPY,   U_PST,   U_UND, _, _,          _,       _,       _,       _,       _,       _,       _,       RSF,
                             _,       _,       _,     _, _, KC_MSTP, KC_MPLY, KC_MUTE, _,       _
),
[GAME] = LAYOUT(
  __, __,   KC_Q, KC_W, KC_R, KC_R,                        __,   __,   __,   __,   __, __,
  __, KC_Q, KC_A, KC_S, KC_D, KC_F,                        KC_A, KC_S, KC_W, KC_D, __, __,
  __, __,   KC_Z, KC_X, KC_Q, KC_Q,   __,   __,     __, __, __,  __,   __,   __,   __, __,
                  __,   __,   KC_ESC, KC_E, KC_TAB, __, __, __,  __,   __
),
// [TEMP] = LAYOUT(
//   __, __, __, __, __, __,                 __, __, __, __, __, __,
//   __, __, __, __, __, __,                 __, __, __, __, __, __,
//   __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __,
//               __, __, __, __, __, __, __, __, __, __
// ),
// [TEMP] = LAYOUT(
//   _, _, _, _, _, _,             _, _, _, _, _, _,
//   _, _, _, _, _, _,             _, _, _, _, _, _,
//   _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
//               _, _, _, _, _, _, _, _, _, _
// ),
};
// clang-format on

bool smart_caps_on = false;

// check if smart caps should be disabled
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

bool smart_caps_apply(uint16_t keycode, keyrecord_t *record) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  smart_caps_check_disable(keycode, record);
  if (!smart_caps_apply(keycode, record)) {
    return false;
  };
  switch (keycode) {
    case KC_QUES:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), BASE, record, KC_EXLM) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BASE, record, KC_EXLM);
    case KC_DOT:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), BASE, record, KC_COLON) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BASE, record, KC_COLON);
    case KC_COMM:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), BASE, record, KC_SCOLON) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BASE, record, KC_SCOLON);
    case HM_SL:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), BASE, record, KC_BSLS) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BASE, record, KC_BSLS);
    case HM_T:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LALT), BASE, record, KC_BSLS) && custom_keycode_on_modifiers(MOD_BIT(KC_RALT), BASE, record, A(KC_TAB));
    case SENT:
      if (record->event.pressed) {
        tap_code(KC_DOT);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());
      }
      return false;
    case QUES:
      if (record->event.pressed) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_QUES);
        } else {
          tap_code16(KC_EXLM);
        }
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());
      }
      return false;
    case SMRTCAPS:
      if (record->event.pressed) {
        smart_caps_on = true;
      }
      return false;
  }
  return true;
}

#define THUMB_TERM 200
#define PINKY_TERM 300
#define CTRL_TERM 200
#define SHIFT_TERM 150
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case THMB_R1:
      return THUMB_TERM - 60;
    case THMB_R2:
      return THUMB_TERM + 10;
    case THMB_R3:
    case THMB_L1:
    case THMB_L2:
    case THMB_L3:
      return THUMB_TERM;
    case HM_Y:
    case HM_T:
    case HM_O:
    case HM_I:
      return PINKY_TERM;
    case HM_H:
    case HM_N:
      return SHIFT_TERM;
    case HM_A:
    case HM_S:
      return CTRL_TERM;
  }
  return TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  int tapping = get_event_keycode(record->event, false);
  switch (keycode) {
    case THMB_R1:
    case THMB_R2:
      switch (tapping) {
        case THMB_L1:
        case THMB_L3:
          return true;
      }
      break;
    case HM_N:
      switch (tapping) {
        case KC_DOT:
        case KC_QUES:
        case KC_COMMA:
          return true;
      }
      break;
    case HM_H:
      switch (tapping) {
        case KC_QUOT:
        case HM_SL:
        case HM_I:
          return true;
      }
      break;
    case THMB_L2:
      switch (tapping) {
        case THMB_R1:
          return true;
      }
      break;
    case HM_T:
      switch (tapping) {
        case THMB_L3:
          return true;
      }
      break;
  }
  return false;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case THMB_R1:
    case THMB_R3:
    case THMB_L1:
    case THMB_L3:
    case THMB_L2:
      return true;
  }
  return false;
}

#ifdef COMBO_ENABLE
#  include "combos/combos_helper.h"

int16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    case BEGIN_CORRECTIVE_BIGRAMS ... END_CORRECTIVE_BIGRAMS:
      return 9;
      break;
    case BEGIN_TRIGRAMS ... END_TRIGRAMS:
      return 30;
      break;
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

#  define NEW_RECORD(press)                  \
    .event = {                               \
        .key     = {.col = 254, .row = 254}, \
        .time    = timer_read() | 1,         \
        .pressed = press,                    \
    }

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
  // the number of keys remaining
  switch (__builtin_popcount(combo->state)) {
    case 2: {
      // remove the key that was released from the state
      uint8_t new_state = (~(1 << key_index) & combo->state);
      // the index of the other key
      uint8_t other_index = __builtin_ctz(new_state);
      // the other keycode
      uint16_t other = pgm_read_word(&combo->keys[other_index]);
      switch (other) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX: {
          uint8_t mod = (other >> 8) & 0x3;
          action_tapping_process((keyrecord_t){
              NEW_RECORD(true),
              .keycode = MT(mod, KC_NO),
          });
          break;
        }
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX: {
          uint8_t layer = (other >> 8) & 0x3;
          action_tapping_process((keyrecord_t){
              NEW_RECORD(true),
              .keycode = LT(layer, KC_NO),
          });
          break;
        }
      }
      break;
    }
    case 1: {
      // the index of the last key
      uint8_t last_index = __builtin_ctz(combo->state);
      // the other keycode
      uint16_t last = pgm_read_word(&combo->keys[last_index]);
      switch (last) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX: {
          uint8_t mod = (last >> 8) & 0x3;
          action_tapping_process((keyrecord_t){
              NEW_RECORD(false),
              .keycode = MT(mod, KC_NO),
          });
          break;
        }
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX: {
          uint8_t layer = (last >> 8) & 0x3;
          action_tapping_process((keyrecord_t){
              NEW_RECORD(false),
              .keycode = LT(layer, KC_NO),
          });
          break;
        }
      }
      break;
    }
  }
  return false;
}

#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (!index) {
    // Volume control
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else {
    // Page up/Page down
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_status(void) {
  switch (get_highest_layer(layer_state)) {
    case BASE:
      oled_write_P(PSTR("Bs\n"), false);
      break;
    case MDIA:
      oled_write_P(PSTR("Md\n"), false);
      break;
    case NAV:
      oled_write_P(PSTR("Na\n"), false);
      break;
    case SYM:
      oled_write_P(PSTR("Sy\n"), false);
      break;
    case NUM:
      oled_write_P(PSTR("Nm\n"), false);
      break;
    case FUNC:
      oled_write_P(PSTR("Fn\n"), false);
      break;
    case GAME:
      oled_write_P(PSTR("G\n"), false);
      break;
  }
}

#  if IS_LEFT == false
// clang-format off
// static void render_qmk_logo(void) {
//   static const char PROGMEM qmk_logo[] = {
//     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

//   oled_write_P(qmk_logo, false);
// }
#else
static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}
// clang-format on
#  endif

void oled_task_user(void) {
#  if IS_LEFT == false
  // render_qmk_logo();
#  else
  render_kyria_logo();
#  endif
  if (is_keyboard_master()) {
    render_status();
  }
}

void suspend_power_down_user() { oled_off(); }
#endif

bool is_keyboard_left(void) { return IS_LEFT; }

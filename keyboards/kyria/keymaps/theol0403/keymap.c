#include "keymap.h"
#include "src/smartcaps.h"

#ifdef CONSOLE_ENABLE
#  include "print.h"
#endif

// structural helpers
#define _ _______
#define RST RESET
#define EST EEPROM_RESET

// mode layers
#define U_TH TG(THE)
#define U_GM TG(GME)
#define U_NUM TG(NUM)
#define U_NAV TG(NAV)

// misc
#define GUI KC_LGUI

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  P   |  L   |  U   | ? !  |                              |  B   |  D   |  R   | ' "  |      |  GM  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Z   |  Y   |  T   |  H   |  A   | . :  |                              |  C   |  S   |  N   |  O   |  I   | / \  |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * | GUI  |  K   |  M   |  F   |  J   | , ;  | NAV  |      |  |      | NUM  |  V   |  G   |  W   |  X   |  Q   |  TH  |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      | AUX  |  UL  | ESC  |  E   | TAB  |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[BSE] = LAYOUT(
  _,   _,   U_P, U_L,  U_U, U_QUES,                             U_B,  U_D,  U_R, U_QUOT, _,   U_GM, 
  U_Z, U_Y, U_T, U_H,  U_A, U_DOT,                              U_C,  U_S,  U_N, U_O,    U_I, U_SL, 
  GUI, U_K, U_M, U_F,  U_J, U_COMM, U_NAV, _,      _,    U_NUM, U_V,  U_G,  U_W, U_X,    U_Q, U_TH, 
                 T_LK, UL,  T_L1,   T_L2,  T_L3,   T_R3, T_R2,  T_R1, T_R0, _                       
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  6   |  5   |  4   |  ^   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  *   |  3   |  2   |  1   | . :  |                              | BSPC | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |  /   |  9   |  8   |  7   |  =   |      |      |  |      |      |      |  (   |  )   |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |  -   |  0   |  +   |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[NUM] = LAYOUT(
  _, _,        KC_6, KC_5, KC_4, KC_CIRC,                         _,       _,       _,       _,       _,       _, 
  _, NUM_ASTR, KC_3, KC_2, KC_1, KC_DOT,                          KC_BSPC, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _, 
  _, KC_SLSH,  KC_9, KC_8, KC_7, KC_EQL,  _,     _,         _, _, _,       KC_LPRN, KC_RPRN, _,       _,       _, 
                     _,    _,    KC_MINS, NUM_0, KC_PLUS,   _, _, _,       _,       _                             
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |  |   |  <   |  {   |  }   |  >   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  *   |  %   |  (   |  )   |  @   |                              |      | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |  ~/  | ` ~  |  &   |  [   |  ]   |  =   |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |  _   |  $   |  #   |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[SYM] = LAYOUT(
  _,    KC_PIPE, KC_LT,   KC_LCBR, KC_RCBR, KC_GT,                            _, _,       _,       _,       _,       _, 
  _,    KC_ASTR, KC_PERC, KC_LPRN, KC_RPRN, KC_AT,                            _, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _, 
  HOME, KC_GRV,  KC_AMPR, KC_LBRC, KC_RBRC, KC_EQL,  _,      _,         _, _, _, _,       _,       _,       _,       _, 
                          _,       _,       KC_UNDS, KC_DLR, KC_HASH,   _, _, _, _,       _                             
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              | HOME | PGDN | PGUP | END  |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | LGUI | LALT | LSFT | LCTL |      |                              | LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | RDO  | CUT  | CPY  | PST  | UND  |TG(NAV|      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[NAV] = LAYOUT(
  _, RST,     EST,     _,       _,       _,                                 KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _, _, 
  _, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _, _, 
  _, RDO,     CUT,     CPY,     PST,     UND, TG(NAV), _,   _,      _,      _,       _,       _,       _,       _, _, 
                       _,       _,       _,   _,       _,   KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _                       
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      | F10  |  F6  |  F5  |  F4  |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | F11  |  F3  |  F2  |  F1  | PSCR |                              |      | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | F12  |  F9  |  F8  |  F7  |      |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      | APP  |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[FUN] = LAYOUT(
  _, KC_F10, KC_F6, KC_F5, KC_F4, _,                          _, _,       _,       _,       _,       _, 
  _, KC_F11, KC_F3, KC_F2, KC_F1, KC_PSCR,                    _, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _, 
  _, KC_F12, KC_F9, KC_F8, KC_F7, _,       _,      _,   _, _, _, _,       _,       _,       _,       _, 
                    _,     _,     _,       KC_APP, _,   _, _, _, _,       _                             
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |RGB_TO|RGB_MO|RGB_VA|RGB_HU|RGB_SA|      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | LGUI | LALT | LSFT | LCTL |      |                              | MPRV | VOLD | VOLU | MNXT | MPLY |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  | MSTP | MPLY | MUTE |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[MDA] = LAYOUT(
  _, RST,     EST,     _,       _,       _,                           RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, _, 
  _, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                           KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _, 
  _, _,       _,       _,       _,       _, _, _,   _,       _,       _,       _,       _,       _,       _,       _, 
                       _,       _,       _, _, _,   KC_MSTP, KC_MPLY, KC_MUTE, _,       _                             
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | LGUI | LALT | LSFT | LCTL |      |                              | MS_L | MS_D | MS_U | MS_R |      |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      | WH_L | WH_D | WH_U | WH_R |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  | BTN3 | BTN1 | BTN2 |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[MOUS] = LAYOUT(
  _, RST,     EST,     _,       _,       _,                           _,       _,       _,       _,       _, _, 
  _, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _, _, 
  _, _,       _,       _,       _,       _, _, _,   _,       _,       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _, _, 
                       _,       _,       _, _, _,   KC_BTN3, KC_BTN1, KC_BTN2, _,       _                       
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  P   |  L   |  U   | ? !  |                              |  B   |  D   |  R   | ' "  |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Z   |  Y   |  T   |  H   |  A   | . :  |                              |  C   |  S   |  N   |  O   |  I   |  /   |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |  K   |  M   |  F   |  J   | , ;  |      |      |  |      |      |  V   |  G   |  W   |  X   |  Q   |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      | ESC  |  E   | TAB  |  | ENT  |SPACE | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[THE] = LAYOUT( // no home row mods
  _,    _,    KC_P, KC_L, KC_U, KC_QUES,                                   KC_B,    KC_D,   KC_R, KC_QUOT, _,    _,       
  KC_Z, KC_Y, KC_T, KC_H, KC_A, KC_DOT,                                    KC_C,    KC_S,   KC_N, KC_O,    KC_I, KC_SLSH, 
  _,    KC_K, KC_M, KC_F, KC_J, KC_COMM, _,    _,        _,      _,        KC_V,    KC_G,   KC_W, KC_X,    KC_Q, _,       
                    _,    _,    KC_ESC,  KC_E, KC_TAB,   KC_ENT, KC_SPACE, KC_BSPC, KC_DEL, _                             
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  Q   |  W   |  R   |  R   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  Q   |  A   |  S   |  D   |  F   |                              |  A   |  S   |  W   |  D   |      |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |      |  Z   |  X   |  Q   |  Q   |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[GME] = LAYOUT(
  _, _,    KC_Q, KC_W, KC_R, KC_R,               _,    _,    _,    _,    _, _, 
  _, KC_Q, KC_A, KC_S, KC_D, KC_F,               KC_A, KC_S, KC_W, KC_D, _, _, 
  _, _,    KC_Z, KC_X, KC_Q, KC_Q, _, _,   _, _, _,    _,    _,    _,    _, _, 
                 _,    _,    _,    _, _,   _, _, _,    _,    _                 
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef CONSOLE_ENABLE
  if (record->event.pressed) {
    uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
  }
#endif
  switch (keycode) {
      // finish a sentence using period and space and shift the next character
    case SENT:
      if (record->event.pressed) {
        tap_code(KC_DOT);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());
      }
      break;
      // finish a sentence using question and space and shift the next character
    case QUES:
      if (record->event.pressed) {
        // if shift is held apply exlm instead
        if (!(get_mods() & MOD_MASK_SHIFT)) {
          tap_code16(KC_QUES);
        } else {
          tap_code16(KC_EXLM);
        }
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());
      }
      break;
      // enable smartcaps
    case SMRTCAPS:
      if (record->event.pressed) {
        smart_caps_toggle();
      }
      break;
    case UL:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_SPC)));
      }
      break;
    case HOME:
      if (record->event.pressed) {
        SEND_STRING("~/");
      }
      break;
    case NUM_ASTR:
      if (record->tap.count) {
        if (record->event.pressed) {
          register_code16(KC_ASTR);
        } else {
          unregister_code16(KC_ASTR);
        }
      } else {
        return true;
      }
      break;
    default:
      // let smart caps handle keys
      if (!smart_caps_process(keycode, record)) {
        return false;
      };
      return true;
  }
  return false;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
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

#ifndef IS_LEFT
#  define IS_LEFT false
#endif
bool is_keyboard_left(void) { return IS_LEFT; }

/*
qmk-keyboard-format:json:begin
{
    "name": "Kyria",
    "numkeys": 50,
    "rows": [
        [ -3,  0,  1,  2,  3,  4,  5, -1, -1, -2, -1, -1,  6,  7,  8,  9, 10, 11 ],
        [ -3, 12, 13, 14, 15, 16, 17, -1, -1, -2, -1, -1, 18, 19, 20, 21, 22, 23 ],
        [ -3, 24, 25, 26, 27, 28, 29, 30, 31, -2, 32, 33, 34, 35, 36, 37, 38, 39 ],
        [ -3, -1, -1, -1, 40, 41, 42, 43, 44, -2, 45, 46, 47, 48, 49, -1, -1, -1 ]
    ],
    "spacing": [
        0
    ]
}
qmk-keyboard-format:json:end
*/

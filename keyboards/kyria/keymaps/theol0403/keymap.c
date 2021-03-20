#include "keymap.h"
#include "src/smartcaps.h"

// structural helpers
#define _ KC_NO
#define __ _______
#define RST RESET
#define EST EEPROM_RESET

// layer locking
#define L(l) DF(l)
#define UNL DF(BSE)

// mode layers
#define U_TH TG(THE)
#define U_GM TG(GME)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  P   |  L   |  U   | ? !  |                              |  B   |  D   |  R   | ' "  |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Z   |  Y   |  T   |  H   |  A   | . :  |                              |  C   |  S   |  N   |  O   |  I   | / \  |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |  K   |  M   |  F   |  J   | , ;  |      |      |  |      |      |  V   |  G   |  W   |  X   |  Q   |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      | ESC  |  E   | TAB  |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[BSE] = LAYOUT(
  _,    _,  U_P, U_L, U_U, U_QUES,                         U_B,  U_D,  U_R, U_QUOT,  _,  _,
  U_Z, U_Y, U_T, U_H, U_A, U_DOT,                          U_C,  U_S,  U_N, U_O,    U_I, U_SL,
  _,   U_K, U_M, U_F, U_J, U_COMM, _,    _,    U_TH, U_GM, U_V,  U_G,  U_W, U_X,    U_Q, _,
                 _,   _,   T_L1,   T_L2, T_L3, T_R3, T_R2, T_R1, T_R0, _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  6   |  5   |  4   |  ^   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  *   |  3   |  2   |  1   | . :  |                              |      | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | / \  |  9   |  8   |  7   |  =   |      |      |  |      |      |      |  (   |  )   |  ^   |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |  -   |  0   |  +   |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[NUM] = LAYOUT(
  _, _,       KC_6, KC_5, KC_4, KC_CIRC,                                _,       _,       _,       _,       _,       L(NUM),
  _, KC_ASTR, KC_3, KC_2, KC_1, KC_DOT,                                 _,       KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, UNL,
  _, KC_SLSH, KC_9, KC_8, KC_7, KC_EQL,  _,    _,       _,      _,      _,       KC_LPRN, KC_RPRN, KC_CIRC, _,       _,
                    _,    _,    KC_MINS, KC_0, KC_PLUS, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |  |   |  <   |  {   |  }   |  >   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  *   |  %   |  (   |  )   |  @   |                              |      | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | ` ~  |  &   |  [   |  ]   |  =   |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |  _   |  $   |  #   |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[SYM] = LAYOUT(
  _, KC_PIPE, KC_LT,   KC_LCBR, KC_RCBR, KC_GT,                                    _,       _,       _,       _,       _,       L(SYM),
  _, KC_ASTR, KC_PERC, KC_LPRN, KC_RPRN, KC_AT,                                    _,       KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, UNL,
  _, KC_GRV,  KC_AMPR, KC_LBRC, KC_RBRC, KC_EQL,  _,      _,       _,      _,      _,       _,       _,       _,       _,       _,
                       _,       _,       KC_UNDS, KC_DLR, KC_HASH, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              | HOME | PGDN | PGUP | END  | CAPS |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | LGUI | LALT | LSFT | LCTL |      |                              | LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | RDO  | CUT  | CPY  | PST  | UND  |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[NAV] = LAYOUT(
  L(NAV), RST,     EST,     _,       _,       _,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS, _,
  UNL,    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _,       _,
  _,      RDO,     CUT,     CPY,     PST,     UND, _, _, _,      _,      _,       _,       _,       _,       _,       _,
                            _,       _,       _,   _, _, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      | F10  |  F6  |  F5  |  F4  |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | F11  |  F3  |  F2  |  F1  | PSCR |                              |      | RCTL | RSFT | LALT | RGUI |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | F12  |  F9  |  F8  |  F7  |      |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      | ESC  | APP  | TAB  |  | ENT  | SPC  | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[FUN] = LAYOUT(
  _, KC_F10, KC_F6, KC_F5, KC_F4, _,                                       _,       _,       _,       _,       _,       L(FUN),
  _, KC_F11, KC_F3, KC_F2, KC_F1, KC_PSCR,                                 _,       KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, UNL,
  _, KC_F12, KC_F9, KC_F8, KC_F7, _,       _,      _,      _,      _,      _,       _,       _,       _,       _,       _,
                    _,     _,     KC_ESC,  KC_APP, KC_TAB, KC_ENT, KC_SPC, KC_BSPC, KC_DEL,  _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |RGB_TO|RGB_MO|RGB_VA|RGB_HU|RGB_SA|      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | LGUI | LALT | LSFT | LCTL |      |                              | MPRV | VOLD | VOLU | MNXT | MPLY |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      | RDO  | CUT  | CPY  | PST  | UND  |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      |      |      |      |  | MSTP | MPLY | MUTE |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[MDA] = LAYOUT(
  L(MDA), RST,     EST,     _,       _,       _,                                    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, _,
  UNL,    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _,                                    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _,
  _,      RDO,     CUT,     CPY,     PST,     UND, _, _,          _,       _,       _,       _,       _,       _,       _,       _,
                             _,       _,      _,   _, _, KC_MSTP, KC_MPLY, KC_MUTE, _,       _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  P   |  L   |  U   | ? !  |                              |  B   |  D   |  R   | ' "  |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  Z   |  Y   |  T   |  H   |  A   | . :  |                              |  C   |  S   |  N   |  O   |  I   | / \  |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |  K   |  M   |  F   |  J   | , ;  |      |      |  |      |      |  V   |  G   |  W   |  X   |  Q   |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      | ESC  |  E   | TAB  |  | ENT  |SPACE | BSPC | DEL  |      |
 *                      `----------------------------------'  `----------------------------------' */
[THE] = LAYOUT( // no home row mods
  _,    _,    KC_P, KC_L, KC_U,  KC_QUES,                                 KC_B,    KC_D,   KC_R, KC_QUOT, _,    _,
  KC_Z, KC_Y, KC_T, KC_H, KC_A,  KC_DOT,                                  KC_C,    KC_S,   KC_N, KC_O,    KC_I, KC_SLSH,
  _,    KC_K, KC_M, KC_F, KC_J,  KC_COMM, _,    _,      __,     _,        KC_V,    KC_G,   KC_W, KC_X,    KC_Q, _,
                    _,    _,     KC_ESC,  KC_E, KC_TAB, KC_ENT, KC_SPACE, KC_BSPC, KC_DEL, _
),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |  Q   |  W   |  R   |  R   |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |  Q   |  A   |  S   |  D   |  F   |                              |  A   |  S   |  W   |  D   |      |      |
 * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 * |      |      |  Z   |  X   |  Q   |  Q   |      |      |  |      |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
 *                      |      |      | ESC  |  E   | TAB  |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------' */
[GME] = LAYOUT(
  __, __,   KC_Q, KC_W, KC_R, KC_R,                           __,   __,   __,   __,   __, __,
  __, KC_Q, KC_A, KC_S, KC_D, KC_F,                           KC_A, KC_S, KC_W, KC_D, __, __,
  __, __,   KC_Z, KC_X, KC_Q, KC_Q,   __,   __,     __, __,   __,   __,   __,   __,   __, __,
                  __,   __,   KC_ESC, KC_E, KC_TAB, __, __,   __,   __,   __
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // let smart caps handle keys
  if (!smart_caps_process(keycode, record)) {
    return false;
  };
  switch (keycode) {
      // custom shifted keycode pairs
    case KC_QUES:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), -1, record, KC_EXLM) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BSE, record, KC_EXLM);
    case KC_DOT:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), -1, record, KC_COLON) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BSE, record, KC_COLON);
    case KC_COMM:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), -1, record, KC_SCOLON) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BSE, record, KC_SCOLON);
    case U_SL:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSFT), -1, record, KC_BSLS) && custom_keycode_on_modifiers(MOD_BIT(KC_RSFT), BSE, record, KC_BSLS);
      // finish a sentence using period and space and shift the next character
    case SENT:
      if (record->event.pressed) {
        tap_code(KC_DOT);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());
      }
      return false;
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
      return false;
      // enable smartcaps
    case SMRTCAPS:
      if (record->event.pressed) {
        smart_caps_enable();
      }
      return false;
  }
  return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    // Page up/Page down
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  } else {
    // Volume control
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
#endif

#ifndef IS_LEFT
#  define IS_LEFT false
#endif
bool is_keyboard_left(void) { return IS_LEFT; }

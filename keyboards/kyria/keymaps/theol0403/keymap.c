#include QMK_KEYBOARD_H

#define _ KC_NO

enum layers { BASE, NUM, SYM, NAV, MOUS, FUNC, MDIA };

#define HM_R LGUI_T(KC_R)
#define HM_T LALT_T(KC_T)
#define HM_H LCTL_T(KC_H)
#define HM_A LSFT_T(KC_A)

#define HM_S LSFT_T(KC_S)
#define HM_N LCTL_T(KC_N)
#define HM_O LALT_T(KC_O)
#define HM_I LGUI_T(KC_I)

#define THMB_L1 LT(MDIA, KC_ESC)
#define THMB_L2 LT(NAV, KC_E)
#define THMB_L3 LT(MOUS, KC_TAB)

#define THMB_R3 LT(SYM, KC_ENT)
#define THMB_R2 LT(NUM, KC_SPC)
#define THMB_R1 LT(FUNC, KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
  _, KC_K, KC_M, KC_L, KC_U, KC_QUES,                                     KC_V,    KC_D, KC_B, KC_QUOT, KC_Q, _,
  _, HM_R, HM_T, HM_H, HM_A, KC_DOT,                                      KC_C,    HM_S, HM_N, HM_O,    HM_I, _,
  _, KC_Z, KC_P, KC_F, KC_J, KC_COMM, _,       _,       _,       _,       KC_AT,   KC_G, KC_W, KC_X,    KC_Y, _,
                 _,    _,    THMB_L1, THMB_L2, THMB_L3, THMB_R3, THMB_R2, THMB_R1, _,    _
),
[NUM] = LAYOUT(
  _, KC_LBRC, KC_9, KC_8, KC_7, KC_RBRC,                      _, _,       _,       _,       RESET,   _,
  _, KC_SCLN, KC_3, KC_2, KC_1, KC_EQL,                       _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_GRV,  KC_6, KC_5, KC_4, KC_BSLS, _,    _,       _, _, _, _,       _,       KC_ALGR, _,       _,
                    _,    _,    KC_DOT,  KC_0, KC_MINS, _, _, _, _,       _
),
[SYM] = LAYOUT(
  _, KC_LCBR, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,                         _, _,       _,       _,       RESET,   _,
  _, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                         _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _,       _,       _, _, _, _,       _,       KC_ALGR, _,       _,
                       _,       _,       KC_LPRN, KC_RPRN, KC_UNDS, _, _, _, _,       _
),
[NAV] = LAYOUT(
  _,  RESET,   _,       _,       _,       _,                       KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _,
  _,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _,
  _,  _,       KC_ALGR, _,       _,       _, _, _, _,      _,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _,
                        _,       _,       _, _, _, KC_ENT, KC_DEL, KC_BSPC, _,       _
),
[MOUS] = LAYOUT(
  _, RESET,   _,       _,       _,       _,                          _,       _,       _,       _,       _, _,
  _, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                          KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _, _,
  _, _,       KC_ALGR, _,       _,       _, _, _,  _,      _,        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _, _,
                       _,       _,       _, _, _,  KC_BTN3, KC_BTN1, KC_BTN2, _,       _
),
[FUNC] = LAYOUT(
  _, KC_F12, KC_F9, KC_F8, KC_F7, KC_PSCR,                       _, _,       _,       _,       RESET,   _,
  _, KC_F11, KC_F3, KC_F2, KC_F1, KC_SLCK,                       _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_F10, KC_F6, KC_F5, KC_F4, KC_PAUS, _,      _,      _, _, _, _,       _,       KC_ALGR, _,       _,
                    _,     _,     KC_APP,  KC_SPC, KC_TAB, _, _, _, _,       _
),
[MDIA] = LAYOUT(
  _, RESET,   _,       _,       _,       _,                          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _,
  _, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                          KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _,       _,
  _, _,       KC_ALGR, _,       _,       _, _, _,  _,       _,       _,       _,       _,       _,       _,       _,
                       _,       _,       _, _, _,  KC_MSTP, KC_MPLY, KC_MUTE, _,       _
)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_QUES:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), BASE, record, KC_EXLM);
    case KC_DOT:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), BASE, record, KC_COLON);
    case KC_COMM:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), BASE, record, KC_SCOLON);
    case KC_AT:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), BASE, record, KC_GRAVE);
    case THMB_R1:
      return custom_keycode_on_modifiers(MOD_BIT(KC_LSHIFT), BASE, record, KC_DEL);
  }
  return true;
}

int16_t autoshift_custom_shifts(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_QUES:
      return KC_EXLM;
    case KC_DOT:
      return KC_COLON;
    case KC_COMM:
      return KC_SCOLON;
  }
  return -2;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_status(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case BASE:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case MDIA:
      oled_write_P(PSTR("Media\n"), false);
      break;
    case NAV:
      oled_write_P(PSTR("Navigation\n"), false);
      break;
    case MOUS:
      oled_write_P(PSTR("Mouse\n"), false);
      break;
    case SYM:
      oled_write_P(PSTR("Symbol\n"), false);
      break;
    case NUM:
      oled_write_P(PSTR("Number\n"), false);
      break;
    case FUNC:
      oled_write_P(PSTR("Function\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n"), false);
  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
  }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    // Volume control
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {
    // Page up/Page down
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  }
}
#endif

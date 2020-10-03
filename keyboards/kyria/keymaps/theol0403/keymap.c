#include QMK_KEYBOARD_H

#define _ KC_NO

enum layers { BASE, NUM, SYM, NAV, MOUS, FUNC, MDIA };

#define HM_A LGUI_T(KC_A)
#define HM_T LALT_T(KC_T)
#define HM_H LCTL_T(KC_H)
#define HM_E LSFT_T(KC_E)

#define HM_S LSFT_T(KC_S)
#define HM_N LCTL_T(KC_N)
#define HM_O LALT_T(KC_O)
#define HM_I LGUI_T(KC_I)

#define THMB_L1 LT(MDIA, KC_ESC)
#define THMB_L2 LT(NAV , KC_SPC)
#define THMB_L3 LT(MOUS, KC_TAB)

#define THMB_R3 LT(SYM , KC_ENT)
#define THMB_R2 LT(NUM , KC_BSPC)
#define THMB_R1 LT(FUNC, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
  _, KC_K, KC_W, KC_L, KC_U, KC_QUES,                                     KC_V,    KC_D, KC_R, KC_QUOT, KC_Q, _,
  _, HM_A, HM_T, HM_H, HM_E, KC_DOT,                                      KC_C,    HM_S, HM_N, HM_O,    HM_I, _,
  _, KC_Z, KC_P, KC_F, KC_J, KC_COMM, _,       _,       _,       _,       KC_B,    KC_G, KC_W, KC_X,    KC_Y, _,
                 _,    _,    THMB_L1, THMB_L2, THMB_L3, THMB_R3, THMB_R2, THMB_R1, _,    _
),
[NUM] = LAYOUT(
  _, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                      _, _,       _,       _,       RESET,   _,
  _, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                       _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS, _,    _,       _, _, _, _,       _,       KC_ALGR, _,       _,
                    _,    _,    KC_DOT,  KC_0, KC_MINS, _, _, _, _,       _
),
[SYM] = LAYOUT(
  _, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                         _, _,       _,       _,       RESET,   _,
  _, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                         _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _,       _,       _, _, _, _,       _,       KC_ALGR, _,       _,
                       _,       _,       KC_LPRN, KC_RPRN, KC_UNDS, _, _, _, _,       _
),
[NAV] = LAYOUT(
  _,  RESET,   _,       _,       _,       _,                       KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _,
  _,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _,
  _,  _,       KC_ALGR, _,       _,       _, _, _,  _,     _,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _,
                        _,       _,       _, _, _, KC_ENT, KC_BSPC, KC_DEL, _,       _
),
[MOUS] = LAYOUT(
  _, RESET,   _,       _,       _,       _,                          _,       _,       _,       _,       _, _,
  _, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                          KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _, _,
  _, _,       KC_ALGR, _,       _,       _, _, _,  _,      _,        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _, _,
                       _,       _,       _, _, _,  KC_BTN1, KC_BTN3, KC_BTN2, _,       _
),
[FUNC] = LAYOUT(
  _, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                       _, _,       _,       _,       RESET,   _,
  _, KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK,                       _, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _,
  _, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, _,      _,      _, _, _, _,       _,       KC_ALGR, _,       _,
                    _,     _,     KC_APP,  KC_SPC, KC_TAB, _, _, _, _,       _
),
[MDIA] = LAYOUT(
  _, RESET,   _,       _,       _,       _,                          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _,
  _, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,                          KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _,       _,
  _, _,       KC_ALGR, _,       _,       _, _, _,  _,       _,       _,       _,       _,       _,       _,       _,
                       _,       _,       _, _, _,  KC_MSTP, KC_MPLY, KC_MUTE, _,       _
)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

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

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
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

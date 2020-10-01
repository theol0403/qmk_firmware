/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define XXX KC_NO

#define mLAYOUT(\
     K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX, XXX,      XXX, XXX, K25, K26, K27, K28, K29, XXX,\
               XXX, XXX, K32, K33, K34,      K35, K36, K37, XXX, XXX\
)

#define X_NP KC_NO // key is not present
#define X_NA KC_NO // present but not available for use
#define X_NU KC_NO // available but not used

enum layers { BASE, MEDR, NAVR, MOUR, NSSL, NSL, FUNL };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    XXX, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                                                                     KC_Y,             KC_U,         KC_I,         KC_O,           KC_P,            XXX,
    XXX, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                                                                                     KC_H,             LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_QUOT), XXX,
    XXX, KC_Z,         ALGR_T(KC_X), KC_C,         KC_V,         KC_B,             XXX,              XXX,              XXX,              XXX,              KC_N,             KC_M,         KC_COMM,      ALGR_T(KC_DOT), KC_SLSH,         XXX,
                                     XXX,          XXX,          LT(MEDR, KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), XXX,          XXX
  )
  // [NAVR] = LAYOUT(
  //   RESET,   X_NA,    X_NA,    X_NA,    X_NA,    KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
  //   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, X_NA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
  //   X_NA,    KC_ALGR, X_NA,    X_NA,    X_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
  //   X_NP,    X_NP,    X_NA,    X_NA,    X_NA,    KC_ENT,  KC_BSPC, KC_DEL,  X_NP,    X_NP
  // ),
  // [MOUR] = LAYOUT(
  //   RESET,   X_NA,    X_NA,    X_NA,    X_NA,    X_NU,    X_NU,    X_NU,    X_NU,    X_NU,
  //   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, X_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, X_NU,
  //   X_NA,    KC_ALGR, X_NA,    X_NA,    X_NA,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, X_NU,
  //   X_NP,    X_NP,    X_NA,    X_NA,    X_NA,    KC_BTN1, KC_BTN3, KC_BTN2, X_NP,    X_NP
  // ),
  // [MEDR] = LAYOUT(
  //   RESET,   X_NA,    X_NA,    X_NA,    X_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  //   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, X_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, X_NU,
  //   X_NA,    KC_ALGR, X_NA,    X_NA,    X_NA,    X_NU,    X_NU,    X_NU,    X_NU,    X_NU,
  //   X_NP,    X_NP,    X_NA,    X_NA,    X_NA,    KC_MSTP, KC_MPLY, KC_MUTE, X_NP,    X_NP
  // ),
  // [FUNL] = LAYOUT(
  //   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, X_NA,    X_NA,    X_NA,    X_NA,    RESET,
  //   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, X_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, X_NA,    X_NA,    X_NA,    KC_ALGR, X_NA,
  //   X_NP,    X_NP,    KC_APP,  KC_SPC,  KC_TAB,  X_NA,    X_NA,    X_NA,    X_NP,    X_NP
  // ),
  // [NSL] = LAYOUT(
  //   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, X_NA,    X_NA,    X_NA,    X_NA,    RESET,
  //   KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  X_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, X_NA,    X_NA,    X_NA,    KC_ALGR, X_NA,
  //   X_NP,    X_NP,    KC_DOT,  KC_0,    KC_MINS, X_NA,    X_NA,    X_NA,    X_NP,    X_NP
  // ),
  // [NSSL] = LAYOUT(
  //   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, X_NA,    X_NA,    X_NA,    X_NA,    RESET,
  //   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, X_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, X_NA,    X_NA,    X_NA,    KC_ALGR, X_NA,
  //   X_NP,    X_NP,    KC_LPRN, KC_RPRN, KC_UNDS, X_NA,    X_NA,    X_NA,    X_NP,    X_NP
  // )
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
        case MEDR:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case NAVR:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case MOUR:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case NSSL:
            oled_write_P(PSTR("Shift Number\n"), false);
            break;
        case NSL:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case FUNL:
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
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
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
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}
#endif

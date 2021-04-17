#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#  include "print.h"
#endif

enum layers { BSE, NUM, SYM, NAV, FUN, MDA, MOUS, THE, GME };
enum custom_keycodes { START = SAFE_RANGE, SENT, QUES, SMRTCAPS, UL, HOME };

// function shortcuts
#define RDO C(KC_Y)  // KC_AGIN
#define PST S(KC_INS)
#define CPY C(KC_INS)
#define CUT S(KC_DEL)
#define UND C(KC_Z)  // KC_UNDO

// left top row
#define U_P KC_P
#define U_L KC_L
#define U_U KC_U
#define U_QUES KC_QUES

// left home row
#define U_Z LT(NUM, KC_Z)
#define U_Y LGUI_T(KC_Y)
#define U_T LALT_T(KC_T)
#define U_H LSFT_T(KC_H)
#define U_A LCTL_T(KC_A)
#define U_DOT KC_DOT

// left bottom row
#define U_K LT(SYM, KC_K)
#define U_M KC_M
#define U_F KC_F
#define U_J KC_J
#define U_COMM KC_COMM

// right top row
#define U_B KC_B
#define U_D KC_D
#define U_R KC_R
#define U_QUOT KC_QUOT

// right home row
#define U_C KC_C
#define U_S RCTL_T(KC_S)
#define U_N RSFT_T(KC_N)
#define U_O LALT_T(KC_O)
#define U_I GUI_T(KC_I)
#define U_SL LT(NAV, KC_SLASH)

// right bottom row
#define U_V KC_V
#define U_G KC_G
#define U_W KC_W
#define U_X KC_X
#define U_Q LT(MDA, KC_Q)

// left thumbs
#define T_LK KC_MUTE
#define T_L1 LT(MDA, KC_ESC)
#define T_L2 LT(NAV, KC_E)
#define T_L3 LT(MOUS, KC_TAB)

// right thumbs
#define T_R3 LT(FUN, KC_ENT)
#define T_R2 LT(NUM, KC_SPC)
#define T_R1 LT(SYM, KC_BSPC)
#define T_R0 LT(SYM, KC_DEL)

// num layer
#define ASTR KC_F20
#define NUM_0 LT(NAV, KC_0)
#define NUM_ASTR LT(SYM, ASTR)
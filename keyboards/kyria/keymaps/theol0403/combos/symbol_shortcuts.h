#include "action_code.h"
#include "keycode.h"
#define BEGIN_SHORTCUT combo_sym_hi
TAPP(sym_hi, S(KC_I), HM_H, HM_I)
// SUBS(sym_kc, "KC_", HM_K, KC_C)

TAPP(sym_col, KC_COLN, HM_N, KC_DOT)
TAPP(sym_exl, KC_EXLM, HM_N, KC_QUES)
TAPP8(sym_scol, KC_SCOLON, HM_N, KC_COMMA)

TAPP(sym_quot, S(KC_QUOT), HM_H, KC_QUOT)
TAPP8(sym_slash, KC_BSLASH, HM_H, HM_SL)

TAPP8(dash, KC_MINS, THMB_L1, THMB_R2)
TAPP(under, KC_UNDS, THMB_L1, THMB_R1)

COMB(dott, SENT, KC_DOT, HM_H)
COMB(ques, QUES, KC_QUES, HM_H)

COMB(osshift, OSM(MOD_RSFT), KC_D, KC_R)
COMB(osrshift, OSM(MOD_LSFT), KC_L, KC_U)
COMB(smrtcaps, SMRTCAPS, KC_R, KC_D, KC_QUOT)

SUBS(semi, ";\n", KC_W, KC_G)
SUBS(arrow, "->", KC_F, KC_J)
// COMB(capsl, KC_CAPS, KC_L, KC_U)
#define END_SHORTCUT combo_arrow

#define BEGIN_HOLDS combo_space
COMB(space, KC_SPC, OSL(NAV), THMB_R2)
COMB(back, KC_BSPC, KC_V, THMB_R1)
// COMB(ent, KC_ENT, OSL(MOUS), THMB_R3)
COMB(e, KC_E, OSL(NUM), THMB_L2)
COMB(tab, KC_TAB, OSL(SYM), THMB_L3)
#define END_HOLDS combo_tab

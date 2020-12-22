
#include "keycode.h"
#include "quantum_keycodes.h"
BEGIN_SECTION(SYMBOLS)
TAPP(sym_hi, S(KC_I), HM_H, HM_I)
// SUBS(sym_kc, "KC_", HM_K, KC_C)

TAPP(sym_col, KC_COLN, HM_N, KC_DOT)
TAPP(sym_exl, KC_EXLM, HM_N, KC_QUES)
TAPP(sym_scol, KC_SCOLON, HM_N, KC_COMMA)

TAPP(sym_quot, S(KC_QUOT), HM_H, KC_QUOT)
TAPP(sym_slash, KC_BSLASH, HM_H, HM_SL)

TAPP(dash, KC_MINS, THMB_L1, THMB_R2)

// COMB(one, KC_1, HM_S, KC_D)
// COMB(two, KC_2, HM_N, KC_R)
// COMB(three, KC_3, HM_O, KC_QUOT)
END_SECTION(SYMBOLS)

BEGIN_SECTION(HOLDS)
COMB(space, KC_SPC, OSL(NAV), THMB_R2)
COMB(back, KC_BSPC, KC_V, THMB_R1)
COMB(ent, KC_ENT, OSL(MOUS), THMB_R3)
COMB(e, KC_E, OSL(NUM), THMB_L2)
COMB(tab, KC_TAB, OSL(SYM), THMB_L3)
END_SECTION(HOLDS)

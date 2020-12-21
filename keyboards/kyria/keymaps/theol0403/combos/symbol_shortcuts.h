
#include "keycode.h"
#include "quantum_keycodes.h"
BEGIN_SECTION(SYMBOLS)
COMB(sym_hi, S(KC_I), HM_H, HM_I)
SUBS(sym_kc, "KC_", HM_K, KC_C)

COMB(sym_col, KC_COLN, HM_N, KC_DOT)
COMB(sym_exl, KC_EXLM, HM_N, KC_QUES)
COMB(sym_scol, KC_SCOLON, HM_N, KC_COMMA)

COMB(sym_quot, S(KC_QUOT), HM_H, KC_QUOT)
COMB(sym_slash, KC_BSLASH, HM_H, HM_SL)

COMB(space, KC_SPC, OSL(NAV), THMB_R2)
COMB(back, KC_BSPC, KC_V, THMB_R1)
COMB(ent, KC_ENT, OSL(MOUS), THMB_R3)
COMB(e, KC_E, OSL(NUM), THMB_L2)
COMB(tab, KC_TAB, OSL(SYM), THMB_L3)
END_SECTION(SYMBOLS)

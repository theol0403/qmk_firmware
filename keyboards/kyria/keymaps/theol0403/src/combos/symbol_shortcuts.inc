#define BEGIN_SHORTCUT combo_sym_hi
TAPP(sym_hi, S(KC_I), U_H, U_I)
// SUBS(sym_kc, "KC_", U_K, KC_C)

TAPP(sym_col, KC_COLN, U_N, KC_DOT)
TAPP(sym_exl, KC_EXLM, U_N, KC_QUES)
TAPP8(sym_scol, KC_SCOLON, U_N, KC_COMMA)

TAPP(sym_quot, S(KC_QUOT), U_H, KC_QUOT)
TAPP8(sym_slash, KC_BSLASH, U_H, U_SL)

TAPP8(dash, KC_MINS, T_L1, T_R2)
TAPP(under, KC_UNDS, T_L1, T_R1)

COMB(dott, SENT, KC_DOT, T_R2)
COMB(ques, QUES, KC_QUES, T_R2)

COMB(smrtcaps, SMRTCAPS, KC_R, KC_D)

SUBS(semi, ";\n", KC_W, KC_G)
SUBS(arrow, "->", KC_F, KC_J)
// COMB(capsl, KC_CAPS, KC_L, KC_U)
#define END_SHORTCUT combo_arrow

#define BEGIN_HOLDS combo_space
COMB(space, KC_SPC, OSL(NAV), T_R2)
COMB(back, KC_BSPC, KC_V, T_R1)
// COMB(ent, KC_ENT, OSL(MOUS), T_R3)
COMB(e, KC_E, OSL(NUM), T_L2)
COMB(tab, KC_TAB, OSL(SYM), T_L3)
#define END_HOLDS combo_tab

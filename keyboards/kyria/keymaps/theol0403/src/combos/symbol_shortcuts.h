
// accelerators are shortcuts to speed up specific tap-hold sequences
// for example, shift and i can be pressed together to output I without waiting for tapping term or worrying about order
#define BEGIN_ACCELERATORS combo_i
TAPP(i, S(KC_I), U_H, U_I)  // speed up I

TAPP(col, KC_COLN, U_N, KC_DOT)        // speed up :
TAPP(exl, KC_EXLM, U_N, KC_QUES)       // speed up !
TAPP8(scol, KC_SCOLON, U_N, KC_COMMA)  // speed up ,
TAPP(quot, S(KC_QUOT), U_H, KC_QUOT)   // speed up "
TAPP8(slash, KC_BSLASH, U_H, U_SL)     // speed up "\"

TAPP8(dash, KC_MINS, T_L1, T_R2)  // speed up -
TAPP(under, KC_UNDS, T_L1, T_R1)  // speed up _
#define END_ACCELERATORS combo_under

#define BEGIN_ACTIONS combo_dott
COMB(dott, SENT, KC_DOT, T_R2)   // sentence end .
COMB(ques, QUES, KC_QUES, T_R2)  // sentence end ?

COMB(caps, SMRTCAPS, KC_R, KC_D)  // trigger smart caps

SUBS(semi, ";\n", KC_W, KC_G)  // end line of c code
SUBS(arrow, "->", KC_F, KC_J)  // arrow
#define END_ACTIONS combo_arrow

// combos that require that they are held
#define BEGIN_HOLDS combo_back
// allow backspace to autorepeat if pressed with thumb key above it
COMB(back, KC_BSPC, KC_V, T_R1)
#define END_HOLDS combo_back

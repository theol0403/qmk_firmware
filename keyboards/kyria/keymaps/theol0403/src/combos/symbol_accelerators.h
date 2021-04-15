
// accelerators are shortcuts to speed up specific tap-hold sequences
// for example, shift and i can be pressed together to output I without waiting for tapping term or worrying about order
// tapp macros remove keyrepeat
#define BEGIN_ACCELERATORS combo_i
TAPP(i, S(U_I), U_H, U_I)  // speed up I

TAPP(col, KC_COLN, U_N, U_DOT)       // speed up :
TAPP(exl, KC_EXLM, U_N, U_QUES)      // speed up !
TAPP8(scol, KC_SCOLON, U_N, U_COMM)  // speed up ,
TAPP(quot, S(KC_QUOT), U_H, U_QUOT)  // speed up "
TAPP8(slash, KC_BSLASH, U_H, U_SL)   // speed up "\"

TAPP8(dash, KC_MINS, T_L1, T_R2)  // speed up -
TAPP(under, KC_UNDS, T_L1, T_R1)  // speed up _
#define END_ACCELERATORS combo_under

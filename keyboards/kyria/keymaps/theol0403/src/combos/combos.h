#include "typing_correction.h"
#include "word_shortcuts.h"
#include "symbol_accelerators.h"

// combos that require that they are held
#define BEGIN_HOLDS combo_back
// allow backspace to autorepeat if pressed with thumb key above it
COMB(back, KC_BSPC, U_V, T_R1)
#define END_HOLDS combo_back

SUBS(semi, ";\n", U_W, U_G)  // end line of c code
SUBS(arrow, "->", U_F, U_J)  // arrow

COMB(caps, SMRTCAPS, U_R, U_D)  // trigger smart caps

// COMB(tab, A(U_TAB), U_T, T_L3)  // alt tab

COMB(numrprn, KC_RPRN, KC_1, KC_2)
COMB(numlprn, KC_LPRN, KC_3, KC_2)
COMB(numrbrc, KC_RBRC, KC_7, KC_8)
COMB(numlbrc, KC_LBRC, KC_9, KC_8)

COMB(numright, KC_RIGHT, KC_1, NUM_0)
COMB(numleft, KC_LEFT, KC_2, NUM_0)

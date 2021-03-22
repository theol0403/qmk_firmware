#include "../keymap.h"

#define OVERRIDES_DEF                                     \
  OVERRIDE_BASIC(colon, MOD_MASK_SHIFT, U_DOT, KC_COLON)  \
  OVERRIDE_BASIC(slash, MOD_MASK_SHIFT, U_SL, KC_BSLS)    \
  OVERRIDE_BASIC(semi, MOD_MASK_SHIFT, U_COMM, KC_SCOLON) \
  OVERRIDE_BASIC(exlm, MOD_MASK_SHIFT, U_QUES, KC_EXLM)

#include "overrides_helper.h"

// credit to precondition

#define COPP TD(C_TD)
enum {
  C_TD = 0,
};

// Tap dance states
typedef enum { SINGLE_TAP, SINGLE_HOLD, DOUBLE_SINGLE_TAP } td_state_t;

td_state_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
    return DOUBLE_SINGLE_TAP;
  } else {
    return 3;  // any number higher than the maximum state value you return above
  }
};

void CA_CC_CV_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (cur_dance(state)) {
    case SINGLE_TAP:
      tap_code16(C(KC_C));
      break;
    case SINGLE_HOLD:
      tap_code16(C(KC_A));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(C(KC_V));
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [C_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
};

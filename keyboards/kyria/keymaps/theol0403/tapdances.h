// credit to precondition

#define DOTT TD(DOT_TD)
#define COPP TD(CA_CC_CV)
enum {
  CA_CC_CV = 0,
  DOT_TD   = 1,
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

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    // Double tapping TD_DOT produces
    // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
    // This helps to quickly end a sentence and begin another one
    // without having to hit shift.
    case 2:
      /* Check that Shift is inactive */
      if (!(get_mods() & MOD_MASK_SHIFT)) {
        tap_code(KC_SPC);
        /* Internal code of OSM(MOD_LSFT) */
        set_oneshot_mods(MOD_BIT(KC_LSHIFT) | get_oneshot_mods());

      } else {
        // send ">" (KC_DOT + shift → ">")
        tap_code(KC_DOT);
      }
      break;

    // Since `sentence_end` is called on each tap
    // and not at the end of the tapping term,
    // the third tap needs to cancel the effects
    // of the double tap in order to get the expected
    // three dots ellipsis.
    case 3:
      // remove the added space of the double tap case
      tap_code(KC_BSPC);
      // replace the space with a second dot
      tap_code(KC_DOT);
      // tap the third dot
      tap_code(KC_DOT);
      break;

    // send KC_DOT on every normal tap of TD_DOT
    default:
      tap_code(KC_DOT);
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [DOT_TD]   = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
};

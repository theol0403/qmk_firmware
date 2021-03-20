#include QMK_KEYBOARD_H

// turn on smart caps
void smart_caps_enable(void);

// decide whether the incoming keycode should disable smart caps
void smart_caps_check_disable(uint16_t keycode, keyrecord_t *record);

// decide whether incoming keycodes should be shifted, apply the shift, and return false to prevent further processing
bool smart_caps_process(uint16_t keycode, keyrecord_t *record);

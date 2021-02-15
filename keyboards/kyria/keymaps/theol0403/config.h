#pragma once

// system settings
#ifdef OLED_DRIVER_ENABLE
#  define OLED_DISPLAY_128X64
#  define OLED_UPDATE_INTERVAL 20
#endif

#ifdef ENCODER_ENABLE
#  define ENCODER_RESOLUTION 2
#  define ENCODER_DIRECTION_FLIP
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define QMK_KEYS_PER_SCAN 4  // Recommended for heavy chording.

// rgb settings
#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_SLEEP
// rgb hue settings
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 8
#  define RGBLIGHT_LIMIT_VAL 150
#  define RBGLIGHT_LED_MAP \
    { 9, 8, 6, 7, 5, 3, 2, 4, 1, 0, 10, 12, 13, 11, 14, 16, 17, 15, 18, 19 }
// #  define RGBLIGHT_LED_MAP
//     { 0, 1, 2, 9, 8, 7, 4, 3, 5, 6, 19, 18, 17, 10, 11, 12, 15, 16, 14, 13 }
// animation modes
// #  define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #  define RGBLIGHT_EFFECT_RAINBOW_MOOD
#  define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #  define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #  define RGBLIGHT_ANIMATIONS
#endif

// tapping settings
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define BILATERAL_COMBINATIONS

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define COMBO_TERM 30
#define COMBO_STRICT_TIMER
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_HOLD_MODS
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_HOLD_TERM 150
#define COMBO_PROCESS_KEY_RELEASE
#define COMBO_BUFFER_LENGTH 8

// Mouse key speed and acceleration.
#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_INITIAL_SPEED 10
#define MOUSEKEY_BASE_SPEED 100

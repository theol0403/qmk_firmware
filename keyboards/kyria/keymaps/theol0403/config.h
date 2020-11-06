#pragma once

// system settings
#ifdef OLED_DRIVER_ENABLE
#  define OLED_DISPLAY_128X64
#endif
#define OLED_UPDATE_INTERVAL 20
#define ENCODER_RESOLUTION 2

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// rgb settings
#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_SLEEP
// rgb hue settings
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 8
#  define RBGLIGHT_LED_MAP \
    { 9, 8, 6, 7, 5, 3, 2, 4, 1, 0, 10, 12, 13, 11, 14, 16, 17, 15, 18, 19 }
// animation modes
#  define RGBLIGHT_EFFECT_STATIC_GRADIENT
#  define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#  define RGBLIGHT_EFFECT_RAINBOW_MOOD
#endif

// tapping settings
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
#define BILATERAL_COMBINATIONS 400

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift and Retro Shift (Auto Shift for Tap Hold).
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define NO_AUTO_SHIFT_SPECIAL
// #define RETRO_SHIFT 500
// #define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
// #define MOUSEKEY_DELAY 0
// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_WHEEL_DELAY 0
// #define MOUSEKEY_MAX_SPEED 4
// #define MOUSEKEY_TIME_TO_MAX 24

#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_INITIAL_SPEED 10
#define MOUSEKEY_BASE_SPEED 100

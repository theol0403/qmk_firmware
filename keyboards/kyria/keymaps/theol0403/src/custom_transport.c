/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <stddef.h>

#include "matrix.h"
#include QMK_KEYBOARD_H

#define ROWS_PER_HAND (MATRIX_ROWS / 2)
#define SYNC_TIMER_OFFSET 2

#ifdef RGBLIGHT_ENABLE
#  include "rgblight.h"
#endif

#ifdef BACKLIGHT_ENABLE
#  include "backlight.h"
#endif

#ifdef ENCODER_ENABLE
#  include "encoder.h"
static pin_t encoders_pad[] = ENCODERS_PAD_A;
#  define NUMBER_OF_ENCODERS (sizeof(encoders_pad) / sizeof(pin_t))
#endif

#ifdef OLED_DRIVER_ENABLE
#  include "oled_driver.h"
#endif

#include "serial.h"

typedef struct _Serial_s2m_buffer_t {
  matrix_row_t smatrix[ROWS_PER_HAND];
#ifdef ENCODER_ENABLE
  uint8_t encoder_state[NUMBER_OF_ENCODERS];
#endif
} __attribute__((packed)) Serial_s2m_buffer_t;

typedef struct _Serial_m2s_buffer_t {
#ifdef SPLIT_MODS_ENABLE
  uint8_t real_mods;
  uint8_t weak_mods;
#  ifndef NO_ACTION_ONESHOT
  uint8_t oneshot_mods;
#  endif
#endif
#ifndef DISABLE_SYNC_TIMER
  uint32_t sync_timer;
#endif
#ifdef SPLIT_TRANSPORT_MIRROR
  matrix_row_t mmatrix[ROWS_PER_HAND];
#endif
#ifdef BACKLIGHT_ENABLE
  uint8_t backlight_level;
#endif
#ifdef WPM_ENABLE
  uint8_t current_wpm;
#endif
  bool          oled_on;
  layer_state_t t_layer_state;
} __attribute__((packed)) Serial_m2s_buffer_t;

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
// When MCUs on both sides drive their respective RGB LED chains,
// it is necessary to synchronize, so it is necessary to communicate RGB
// information. In that case, define RGBLIGHT_SPLIT with info on the number
// of LEDs on each half.
//
// Otherwise, if the master side MCU drives both sides RGB LED chains,
// there is no need to communicate.

typedef struct _Serial_rgblight_t {
  rgblight_syncinfo_t rgblight_sync;
} Serial_rgblight_t;

volatile Serial_rgblight_t serial_rgblight = {};
uint8_t volatile status_rgblight           = 0;
#endif

volatile Serial_s2m_buffer_t serial_s2m_buffer = {};
volatile Serial_m2s_buffer_t serial_m2s_buffer = {};
uint8_t volatile status0                       = 0;

enum serial_transaction_id {
  GET_SLAVE_MATRIX = 0,
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
  PUT_RGBLIGHT,
#endif
};

SSTD_t transactions[] = {
    [GET_SLAVE_MATRIX] =
        {
            (uint8_t *)&status0,
            sizeof(serial_m2s_buffer),
            (uint8_t *)&serial_m2s_buffer,
            sizeof(serial_s2m_buffer),
            (uint8_t *)&serial_s2m_buffer,
        },
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
    [PUT_RGBLIGHT] =
        {
            (uint8_t *)&status_rgblight, sizeof(serial_rgblight), (uint8_t *)&serial_rgblight, 0, NULL  // no slave to master transfer
        },
#endif
};

void transport_master_init(void) { soft_serial_initiator_init(transactions, TID_LIMIT(transactions)); }

void transport_slave_init(void) { soft_serial_target_init(transactions, TID_LIMIT(transactions)); }

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)

// rgblight synchronization information communication.

void transport_rgblight_master(void) {
  if (rgblight_get_change_flags()) {
    rgblight_get_syncinfo((rgblight_syncinfo_t *)&serial_rgblight.rgblight_sync);
    if (soft_serial_transaction(PUT_RGBLIGHT) == TRANSACTION_END) {
      rgblight_clear_change_flags();
    }
  }
}

void transport_rgblight_slave(void) {
  if (status_rgblight == TRANSACTION_ACCEPTED) {
    rgblight_update_sync((rgblight_syncinfo_t *)&serial_rgblight.rgblight_sync, false);
    status_rgblight = TRANSACTION_END;
  }
}

#else
#  define transport_rgblight_master()
#  define transport_rgblight_slave()
#endif

bool transport_master(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]) {
#ifndef SERIAL_USE_MULTI_TRANSACTION
  if (soft_serial_transaction() != TRANSACTION_END) {
    return false;
  }
#else
  transport_rgblight_master();
  if (soft_serial_transaction(GET_SLAVE_MATRIX) != TRANSACTION_END) {
    return false;
  }
#endif

  // TODO:  if MATRIX_COLS > 8 change to unpack()
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    slave_matrix[i] = serial_s2m_buffer.smatrix[i];
#ifdef SPLIT_TRANSPORT_MIRROR
    serial_m2s_buffer.mmatrix[i] = master_matrix[i];
#endif
  }

#ifdef BACKLIGHT_ENABLE
  // Write backlight level for slave to read
  serial_m2s_buffer.backlight_level = is_backlight_enabled() ? get_backlight_level() : 0;
#endif

#ifdef ENCODER_ENABLE
  encoder_update_raw((uint8_t *)serial_s2m_buffer.encoder_state);
#endif

#ifdef WPM_ENABLE
  // Write wpm to slave
  serial_m2s_buffer.current_wpm = get_current_wpm();
#endif

#ifdef SPLIT_MODS_ENABLE
  serial_m2s_buffer.real_mods = get_mods();
  serial_m2s_buffer.weak_mods = get_weak_mods();
#  ifndef NO_ACTION_ONESHOT
  serial_m2s_buffer.oneshot_mods = get_oneshot_mods();
#  endif
#endif

  serial_m2s_buffer.t_layer_state = layer_state;
#ifdef OLED_DRIVER_ENABLE
  serial_m2s_buffer.oled_on = is_oled_on();
#endif

#ifdef RGB_MATRIX_ENABLE
  serial_m2s_buffer.is_rgb_matrix_suspended = rgb_matrix_get_suspend_state();
#endif
#ifndef DISABLE_SYNC_TIMER
  serial_m2s_buffer.sync_timer = sync_timer_read32() + SYNC_TIMER_OFFSET;
#endif
  return true;
}

void transport_slave(matrix_row_t master_matrix[], matrix_row_t slave_matrix[]) {
  transport_rgblight_slave();
#ifndef DISABLE_SYNC_TIMER
  sync_timer_update(serial_m2s_buffer.sync_timer);
#endif

  // TODO: if MATRIX_COLS > 8 change to pack()
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    serial_s2m_buffer.smatrix[i] = slave_matrix[i];
#ifdef SPLIT_TRANSPORT_MIRROR
    master_matrix[i] = serial_m2s_buffer.mmatrix[i];
#endif
  }

#ifdef BACKLIGHT_ENABLE
  backlight_set(serial_m2s_buffer.backlight_level);
#endif

#ifdef ENCODER_ENABLE
  encoder_state_raw((uint8_t *)serial_s2m_buffer.encoder_state);
#endif

#ifdef WPM_ENABLE
  set_current_wpm(serial_m2s_buffer.current_wpm);
#endif

#ifdef SPLIT_MODS_ENABLE
  set_mods(serial_m2s_buffer.real_mods);
  set_weak_mods(serial_m2s_buffer.weak_mods);
#  ifndef NO_ACTION_ONESHOT
  set_oneshot_mods(serial_m2s_buffer.oneshot_mods);
#  endif
#endif

  if (layer_state != serial_m2s_buffer.t_layer_state) {
    layer_state = serial_m2s_buffer.t_layer_state;
  }
#ifdef OLED_DRIVER_ENABLE
  if (serial_m2s_buffer.oled_on) {
    oled_on();
  } else {
    oled_off();
  }
#endif

#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_set_suspend_state(serial_m2s_buffer.is_rgb_matrix_suspended);
#endif
}

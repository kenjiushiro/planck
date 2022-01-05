/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum custom_keycodes  {
    GMAIL_EMAIL = SAFE_RANGE,
    LIVE_EMAIL,
    DEVARTIS_EMAIL,
    ALT_TAB,
    LSALT_TAB
};

enum layers {
    _QWERTY,
    _NUMERIC,
    _NAVIGATION,
    _SYMBOLS,
    _FN_KEYS,
    _CONFIG
};

// enum planck_keycodes {
//   PLOVER = SAFE_RANGE,
// };

#define NUM_LAYER LT(_NUMERIC, KC_TAB)
#define NAV_LAYER MO(_NAVIGATION)
#define SYM_LAYER MO(_SYMBOLS)
#define FN_LAYER MO(_FN_KEYS)
#define CONF_LAYER MO(_CONFIG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(
    NUM_LAYER,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, NAV_LAYER, SYM_LAYER,   KC_SPC,  FN_LAYER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_NUMERIC] = LAYOUT_planck_mit(
    _______,  KC_TAB,LSFT(KC_EQL),KC_MINUS,KC_EQL, XXXXXXX,XXXXXXX,KC_7,KC_8,KC_9, XXXXXXX, KC_BSPC,
    KC_LCTL, XXXXXXX,LSFT(KC_8),KC_SLSH, XXXXXXX, XXXXXXX,XXXXXXX,KC_4,KC_5, KC_6, XXXXXXX,  KC_DEL,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,KC_1,KC_2,KC_3, XXXXXXX,  KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT, KC_SPC, KC_0, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAVIGATION] = LAYOUT_planck_mit(
    KC_PSCR,  KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  KC_END, XXXXXXX, KC_BSPC,
    KC_PSCR, KC_BSPC, KC_LCTL, KC_LSFT,  KC_ENT, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_DEL,
    KC_LGUI, XXXXXXX, XXXXXXX,   KC_DEL,XXXXXXX,XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_ENT,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
),

[_SYMBOLS] = LAYOUT_planck_mit(
    LSFT(KC_GRV),LSFT(KC_1),LSFT(KC_5),LSFT(KC_3),LSFT(KC_8),XXXXXXX, XXXXXXX, XXXXXXX,LSFT(KC_LBRC),LSFT(KC_RBRC),XXXXXXX,KC_BSPC,
    KC_LCTL,LSFT(KC_4),KC_GRV,LSFT(KC_QUOT),KC_QUOT,XXXXXXX, XXXXXXX, LSFT(KC_9),LSFT(KC_0),XXXXXXX, KC_MINUS,XXXXXXX,
    KC_LSFT,KC_BSLS,LSFT(KC_6),LSFT(KC_7),LSFT(KC_BSLS),XXXXXXX, XXXXXXX,KC_LBRC,KC_RBRC,XXXXXXX,LSFT(KC_MINUS),XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, CONF_LAYER,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
),

[_FN_KEYS] = LAYOUT_planck_mit(
    XXXXXXX,LSFT(KC_2),LSFT(KC_COMM),LSFT(KC_DOT),XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
    KC_LCTL, LSFT(KC_2),LSFT(KC_EQL),KC_MINUS, KC_EQL, XXXXXXX, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CONF_LAYER, XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
),

[_CONFIG] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, GMAIL_EMAIL,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, LIVE_EMAIL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, DEVARTIS_EMAIL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GMAIL_EMAIL:
      if (record->event.pressed) {
          SEND_STRING("kenjimartinushiro@gmail.com");
      }
      break;
    case LIVE_EMAIL:
      if (record->event.pressed) {
          SEND_STRING("kenjiushiro@live.com");
      }
      break;
    case DEVARTIS_EMAIL:
      if (record->event.pressed) {
          SEND_STRING("kushiro@devartis.com");
      }
      break;
  }
  return true;
}

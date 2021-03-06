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

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;

enum custom_keycodes  {
    GMAIL_EMAIL = SAFE_RANGE,
    LIVE_EMAIL,
    TIENDANUBE_EMAIL,
    ALT_TAB,
    LSALT_TAB,
    DESKTOP_LEFT,
    DESKTOP_RIGHT,
    DESKTOP_UP,
    SWITCH_TO_MAC,
    SWITCH_TO_WINDOWS,
    SWITCH_TO_LINUX,
    WORD_MODIFIER,
    UNDO,
    CUT,
    COPY,
    PASTE,
};

enum OS {
    _MAC,
    _WINDOWS,
    _LINUX,
};

int currentOS = _MAC;
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

    [_QWERTY] = LAYOUT_planck_grid(
            NUM_LAYER,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
            KC_LCTL, KC_LGUI, KC_LALT, NAV_LAYER, SYM_LAYER, KC_SPC,  KC_LGUI,  FN_LAYER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
            ),

    [_NUMERIC] = LAYOUT_planck_grid(
            _______,  KC_TAB,LSFT(KC_EQL),KC_MINUS,KC_EQL, XXXXXXX,XXXXXXX,KC_7,KC_8,KC_9, XXXXXXX, KC_BSPC,
            KC_LCTL, XXXXXXX,LSFT(KC_8),KC_SLSH, XXXXXXX, XXXXXXX,XXXXXXX,KC_4,KC_5, KC_6, XXXXXXX,  KC_DEL,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,KC_1,KC_2,KC_3, XXXXXXX,  KC_ENT,
            KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT, KC_SPC, KC_COMM, KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),

    [_NAVIGATION] = LAYOUT_planck_grid(
            LSALT_TAB,  ALT_TAB, DESKTOP_LEFT, DESKTOP_UP, DESKTOP_RIGHT, KC_INS, XXXXXXX, XXXXXXX, KC_HOME,  KC_END, XXXXXXX, KC_BSPC,
            KC_PSCR, KC_BSPC, WORD_MODIFIER, KC_DEL,  KC_ENT, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_DEL,
            KC_LSFT, UNDO, CUT, COPY,PASTE,XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_ENT,
            XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
            ),

    [_SYMBOLS] = LAYOUT_planck_grid(
            LSFT(KC_GRV),LSFT(KC_1),LSFT(KC_5),LSFT(KC_3),LSFT(KC_8),XXXXXXX, XXXXXXX, XXXXXXX,LSFT(KC_LBRC),LSFT(KC_RBRC),KC_EQL,KC_BSPC,
            KC_LCTL,LSFT(KC_4),KC_GRV,LSFT(KC_QUOT),KC_QUOT,XXXXXXX, XXXXXXX, LSFT(KC_9),LSFT(KC_0),XXXXXXX, KC_MINUS,LSFT(KC_DOT),
            KC_LSFT,KC_BSLS,LSFT(KC_6),LSFT(KC_7),LSFT(KC_BSLS),XXXXXXX, XXXXXXX,KC_LBRC,KC_RBRC,XXXXXXX,LSFT(KC_MINUS),XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, CONF_LAYER,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
            ),

    [_FN_KEYS] = LAYOUT_planck_grid(
            XXXXXXX,LSFT(KC_2),LSFT(KC_COMM),LSFT(KC_DOT),XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
            KC_LCTL, LSFT(KC_2),LSFT(KC_EQL),KC_MINUS, KC_EQL, XXXXXXX, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CONF_LAYER, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
            ),

    [_CONFIG] = LAYOUT_planck_grid(

            XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, SWITCH_TO_WINDOWS,KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, LIVE_EMAIL, GMAIL_EMAIL,
            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, SWITCH_TO_MAC,XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, TIENDANUBE_EMAIL,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SWITCH_TO_LINUX,XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
            )
};

void register_desktop_switch_modifier(void) {
    switch (currentOS) {
        case _WINDOWS:
            register_code(KC_LCTL);
            register_code(KC_LGUI);
            break;
        case _MAC:
            register_code(KC_LCTL);
            break;
        case _LINUX:
            break;
    }
}

void unregister_desktop_switch_modifier(void) {
    switch (currentOS) {
        case _WINDOWS:
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
            break;
        case _MAC:
            unregister_code(KC_LCTL);
            break;
        case _LINUX:
            break;
    }
}

void desktop_switch(int direction) {
    register_desktop_switch_modifier();
    tap_code(direction);
    unregister_desktop_switch_modifier();
}

void register_alt_tab_modifier(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LALT);
            break;
    }
}

void unregister_alt_tab_modifier(void) {
    switch (currentOS) {
        case _MAC:
            unregister_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            unregister_code(KC_LALT);
            break;
    }
}

void hold_word_modifier(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LALT);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LCTL);
            break;
    }
}

void unhold_word_modifier(void) {
    switch (currentOS) {
        case _MAC:
            unregister_code(KC_LALT);
            break;
        case _WINDOWS:
        case _LINUX:
            unregister_code(KC_LCTL);
            break;
    }
}

void undo(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LGUI);
            tap_code(KC_Z);
            unregister_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LCTL);
            tap_code(KC_Z);
            unregister_code(KC_LCTL);
            break;
    }
}

void cut(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LGUI);
            tap_code(KC_X);
            unregister_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LCTL);
            tap_code(KC_X);
            unregister_code(KC_LCTL);
            break;
    }
}

void copy(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LGUI);
            tap_code(KC_C);
            unregister_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LCTL);
            tap_code(KC_C);
            unregister_code(KC_LCTL);
            break;
    }
}

void paste(void) {
    switch (currentOS) {
        case _MAC:
            register_code(KC_LGUI);
            tap_code(KC_V);
            unregister_code(KC_LGUI);
            break;
        case _WINDOWS:
        case _LINUX:
            register_code(KC_LCTL);
            tap_code(KC_V);
            unregister_code(KC_LCTL);
            break;
    }
}

void changeBacklightColor(void) {
    switch (currentOS) {
        case _MAC:
            rgblight_setrgb_range(255, 255, 255, 0, 16);
            break;
        case _WINDOWS:
            rgblight_setrgb_range(18, 216, 255, 0, 16);
            break;
        case _LINUX:
            rgblight_setrgb_range(234, 169,5, 0, 16);
            break;
    }
}
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
        case TIENDANUBE_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("kenji.ushiro@tiendanube.com");
            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_alt_tab_modifier();
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case LSALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_alt_tab_modifier();
                }
                alt_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
                unregister_code(KC_LSFT);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case DESKTOP_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);
                return false;
            }
            break;
        case DESKTOP_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case DESKTOP_UP:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_UP);
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case SWITCH_TO_MAC:
            if (record->event.pressed) {
                currentOS = _MAC;
                changeBacklightColor();
            }
            return false;
            break;
        case SWITCH_TO_WINDOWS:
            if (record->event.pressed) {
                currentOS = _WINDOWS;
                changeBacklightColor();
            }
            return false;
            break;
        case SWITCH_TO_LINUX:
            if (record->event.pressed) {
                currentOS = _LINUX;
                changeBacklightColor();
            }
            return false;
            break;
        case WORD_MODIFIER:
            if (record->event.pressed) {
                hold_word_modifier();
            } else {
                unhold_word_modifier();
            }
            return false;
            break;
        case UNDO:
            if (record->event.pressed) {
                undo();
            }
            return false;
            break;
        case CUT:
            if (record->event.pressed) {
                cut();
            }
            return false;
            break;
        case COPY:
            if (record->event.pressed) {
                copy();
            }
            return false;
            break;
        case PASTE:
            if (record->event.pressed) {
                paste();
            }
            return false;
            break;
    }
    return true;
}
void matrix_scan_user(void) { // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_alt_tab_modifier();
            is_alt_tab_active = false;
        }
    }
}

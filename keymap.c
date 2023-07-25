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

bool     is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer     = 0;

enum custom_keycodes
{
    GMAIL_EMAIL = SAFE_RANGE,
    LIVE_EMAIL,
    WORK_EMAIL,
    WORK_EMAIL2,
    DNI,
    PHONE_NUMBER,
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
    SCREENSHOT,
    ENIE,
    MISSION_CONTROL,
};

enum OS
{
    _MAC,
    _WINDOWS,
    _LINUX,
};

int currentOS = _MAC;
enum layers
{
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
#define PLUS_SIGN LSFT(KC_EQL)
#define ASTERISK LSFT(KC_8)
#define BANG LSFT(KC_1)
#define PERCENT LSFT(KC_5)
#define HASHTAG LSFT(KC_3)
#define FIRULITO LSFT(KC_GRV)
#define CARET LSFT(KC_6)
#define AMPERSAND LSFT(KC_7)
#define ARROBA LSFT(KC_2)
#define DOLLAR LSFT(KC_4)
#define PIPE LSFT(KC_BSLS)
#define COMILLA_SIMP KC_QUOT
#define COMILLA_DOBL LSFT(KC_QUOT)
#define AB_PARENT LSFT(KC_9)
#define CE_PARENT LSFT(KC_0)
#define AB_CORCHE KC_LBRC
#define CE_CORCHE KC_RBRC
#define AB_LLAVE LSFT(KC_LBRC)
#define CE_LLAVE LSFT(KC_RBRC)
#define UNDERSCORE LSFT(KC_MINUS)
#define GREATER LSFT(KC_DOT)
#define LESS_THAN LSFT(KC_COMM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_grid(
        NUM_LAYER, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_DEL,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, NAV_LAYER, SYM_LAYER, KC_SPC, FN_LAYER, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    [_NUMERIC] = LAYOUT_planck_grid(
        _______, KC_TAB, XXXXXXX, XXXXXXX, ASTERISK, XXXXXXX, KC_EQL, KC_7, KC_8, KC_9, XXXXXXX, KC_BSPC,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PLUS_SIGN, KC_4, KC_5, KC_6, KC_MINUS, KC_DEL,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ASTERISK, KC_1, KC_2, KC_3, KC_SLSH, KC_ENT,
        KC_LGUI, XXXXXXX, XXXXXXX, KC_DOT, KC_SPC, KC_COMM, KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_NAVIGATION] = LAYOUT_planck_grid(
        LSALT_TAB, ALT_TAB, DESKTOP_LEFT, DESKTOP_UP, DESKTOP_RIGHT, KC_INS, XXXXXXX, XXXXXXX, KC_HOME, KC_END, XXXXXXX, KC_BSPC,
        KC_PSCR, KC_BSPC, WORD_MODIFIER, KC_DEL, KC_ENT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, KC_DEL,
        KC_LSFT, UNDO, CUT, COPY, PASTE, SCREENSHOT, ENIE, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_SYMBOLS] = LAYOUT_planck_grid(
        FIRULITO, BANG, PERCENT, HASHTAG, ASTERISK, XXXXXXX, XXXXXXX, DOLLAR, AB_LLAVE, CE_LLAVE, KC_EQL, KC_BSPC,
        ARROBA, DOLLAR, KC_GRV, COMILLA_DOBL, KC_QUOT, XXXXXXX, LESS_THAN, AB_PARENT, CE_PARENT, XXXXXXX, KC_MINUS, GREATER,
        KC_LSFT, KC_BSLS, CARET, AMPERSAND, PIPE, XXXXXXX, XXXXXXX, AB_CORCHE, CE_CORCHE, XXXXXXX, UNDERSCORE, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, CONF_LAYER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_FN_KEYS] = LAYOUT_planck_grid(
        XXXXXXX, ARROBA, LESS_THAN, GREATER, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,
        KC_LCTL, ARROBA, PLUS_SIGN, KC_MINUS, KC_EQL, XXXXXXX, XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, CONF_LAYER, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_CONFIG] = LAYOUT_planck_grid(

        KC_TAB, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, SWITCH_TO_WINDOWS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, LIVE_EMAIL, GMAIL_EMAIL,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, SWITCH_TO_MAC, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, WORK_EMAIL2, WORK_EMAIL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SWITCH_TO_LINUX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, DNI, PHONE_NUMBER,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)};

void mission_control(void)
{
    switch (currentOS)
    {
    case _WINDOWS:
        register_code(KC_LALT);
        tap_code(KC_SPC);
        unregister_code(KC_LALT);
        break;
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_SPC);
        unregister_code(KC_LGUI);
        break;
    case _LINUX:
        tap_code(KC_LGUI);
        break;
    }
}

void register_desktop_switch_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LCTL);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        break;
    }
}

void unregister_desktop_switch_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        unregister_code(KC_LCTL);
        break;
    case _WINDOWS:
    case _LINUX:
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        break;
    }
}

void previous_desktop(void)
{
    register_desktop_switch_modifier();
    if (currentOS == _LINUX)
    {
        tap_code(KC_UP);
    }
    else
    {
        tap_code(KC_LEFT);
    }
    unregister_desktop_switch_modifier();
}

void next_desktop(void)
{
    register_desktop_switch_modifier();
    if (currentOS == _LINUX)
    {
        tap_code(KC_DOWN);
    }
    else
    {
        tap_code(KC_RIGHT);
    }
    unregister_desktop_switch_modifier();
}

void show_desktops(void)
{
    if (currentOS == _LINUX)
    {
        register_code(KC_LGUI);
        tap_code(KC_D);
        unregister_code(KC_LGUI);
    }
    else if (currentOS == _WINDOWS)
    {
        register_code(KC_LGUI);
        tap_code(KC_TAB);
        unregister_code(KC_LGUI);
    }
    else if (currentOS == _MAC)
    {
        register_code(KC_LCTL);
        tap_code(KC_UP);
        unregister_code(KC_LCTL);
    }
}

void register_alt_tab_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LALT);
        break;
    }
}

void unregister_alt_tab_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        unregister_code(KC_LALT);
        break;
    }
}

void hold_word_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LALT);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        break;
    }
}

void release_word_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        unregister_code(KC_LALT);
        break;
    case _WINDOWS:
    case _LINUX:
        unregister_code(KC_LCTL);
        break;
    }
}

void undo(void)
{
    switch (currentOS)
    {
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

void cut(void)
{
    switch (currentOS)
    {
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

void copy(void)
{
    switch (currentOS)
    {
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

void paste(void)
{
    switch (currentOS)
    {
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

void screenshot(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_X);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        break;
    case _WINDOWS:
    case _LINUX:
        tap_code(KC_PSCR);
        break;
    }
}

void enie(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LALT);
        tap_code(KC_N);
        unregister_code(KC_LALT);
        tap_code(KC_N);
        break;
    case _WINDOWS:
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_2);
        tap_code(KC_KP_4);
        tap_code(KC_KP_1);
        unregister_code(KC_LALT);
        break;
    case _LINUX:
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {

    case GMAIL_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("kenjimartinushiro@gmail.com");
        }
        return false;
        break;
    case LIVE_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("kenjiushiro@live.com");
        }
        return false;
        break;
    case WORK_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("kenji@work1.com");
        }
        return false;
        break;
    case WORK_EMAIL2:
        if (record->event.pressed)
        {
            SEND_STRING("kenji@work2.com");
        }
        return false;
        break;
    case DNI:
        if (record->event.pressed)
        {
            SEND_STRING("38521991");
        }
        return false;
        break;
    case PHONE_NUMBER:
        if (record->event.pressed)
        {
            SEND_STRING("1164484715");
        }
        return false;
        break;
    case ENIE:
        if (record->event.pressed)
        {
            enie();
        }
        return false;
        break;
    case MISSION_CONTROL:
        if (record->event.pressed)
        {
            mission_control();
        }
        return false;
        break;
    case ALT_TAB:
        if (record->event.pressed)
        {
            if (!is_alt_tab_active)
            {
                is_alt_tab_active = true;
                register_alt_tab_modifier();
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    case LSALT_TAB:
        if (record->event.pressed)
        {
            if (!is_alt_tab_active)
            {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_LSFT);
            register_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    case SCREENSHOT:
        if (record->event.pressed)
        {
            screenshot();
            return false;
        }
        break;

    case DESKTOP_LEFT:
        if (record->event.pressed)
        {
            previous_desktop();
        }
        return false;
        break;
    case DESKTOP_RIGHT:
        if (record->event.pressed)
        {
            next_desktop();
        }
        return false;
        break;
    case DESKTOP_UP:
        if (record->event.pressed)
        {
            show_desktops();
        }
        return false;
        break;
    case SWITCH_TO_MAC:
        if (record->event.pressed)
        {
            currentOS = _MAC;
        }
        return false;
        break;
    case SWITCH_TO_WINDOWS:
        if (record->event.pressed)
        {
            currentOS = _WINDOWS;
        }
        return false;
        break;
    case SWITCH_TO_LINUX:
        if (record->event.pressed)
        {
            currentOS = _LINUX;
        }
        return false;
        break;
    case WORD_MODIFIER:
        if (record->event.pressed)
        {
            hold_word_modifier();
        }
        else
        {
            release_word_modifier();
        }
        return false;
        break;
    case UNDO:
        if (record->event.pressed)
        {
            undo();
        }
        return false;
        break;
    case CUT:
        if (record->event.pressed)
        {
            cut();
        }
        return false;
        break;
    case COPY:
        if (record->event.pressed)
        {
            copy();
        }
        return false;
        break;
    case PASTE:
        if (record->event.pressed)
        {
            paste();
        }
        return false;
        break;
    }
    return true;
}
void matrix_scan_user(void)
{ // The very important timer.
    if (is_alt_tab_active)
    {
        if (timer_elapsed(alt_tab_timer) > 500)
        {
            unregister_alt_tab_modifier();
            is_alt_tab_active = false;
        }
    }
}

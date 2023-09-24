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
#include "../../../qmk_utils/utils.c"
#include "muse.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_grid(
        NUM_LAYER, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_DEL,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, NAV_LAYER, SYM_LAYER, LT(_NAVIGATION, KC_SPC), LT(_NAVIGATION, KC_SPC), FN_LAYER, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    [_NUMERIC] = LAYOUT_planck_grid(
        _______, KC_TAB, XXXXXXX, XXXXXXX, ASTERISK, XXXXXXX, KC_EQL, KC_7, KC_8, KC_9, XXXXXXX, KC_BSPC,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PLUS_SIGN, KC_4, KC_5, KC_6, KC_MINUS, KC_DEL,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ASTERISK, KC_1, KC_2, KC_3, KC_SLSH, KC_ENT,
        KC_LGUI, XXXXXXX, XXXXXXX, KC_DOT, KC_SPC, KC_SPC, KC_COMM, KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_NAVIGATION] = LAYOUT_planck_grid(
        LSALT_TAB, ALT_TAB, DESKTOP_LEFT, DESKTOP_UP, DESKTOP_RIGHT, KC_INS, XXXXXXX, XXXXXXX, KC_HOME, KC_END, XXXXXXX, KC_BSPC,
        MISSION_CONTROL, KC_BSPC, WORD_MODIFIER, KC_DEL, KC_ENT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, KC_DEL,
        KC_LSFT, UNDO, CUT, COPY, PASTE, SCREENSHOT, ENIE, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_ENT,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_SYMBOLS] = LAYOUT_planck_grid(
        FIRULITO, BANG, PERCENT, HASHTAG, ASTERISK, XXXXXXX, XXXXXXX, DOLLAR, AB_LLAVE, CE_LLAVE, KC_EQL, KC_BSPC,
        ARROBA, DOLLAR, KC_GRV, COMILLA_DOBL, KC_QUOT, XXXXXXX, LESS_THAN, AB_PARENT, CE_PARENT, XXXXXXX, KC_MINUS, GREATER,
        KC_LSFT, KC_BSLS, CARET, AMPERSAND, PIPE, XXXXXXX, XXXXXXX, AB_CORCHE, CE_CORCHE, XXXXXXX, UNDERSCORE, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, CONF_LAYER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_FN_KEYS] = LAYOUT_planck_grid(
        XXXXXXX, ARROBA, LESS_THAN, GREATER, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,
        KC_LCTL, ARROBA, PLUS_SIGN, KC_MINUS, KC_EQL, XXXXXXX, XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, CONF_LAYER, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    [_CONFIG] = LAYOUT_planck_grid(

        KC_TAB, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, SWITCH_TO_WINDOWS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, PERSONAL_EMAIL_2, PERSONAL_EMAIL_1,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, SWITCH_TO_MAC, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, WORK_EMAIL2, WORK_EMAIL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SWITCH_TO_LINUX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, DNI, PHONE_NUMBER,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)};

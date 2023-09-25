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

#define SPC_NAV LT(_NAVIGATION, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          NUM_LYR,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          LCTL_T(KC_ESC),KC_A,KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          KC_LCTL,  KC_LGUI,  KC_LALT,  NAV_LYR,  SYM_LYR,  SPC_NAV,  SPC_NAV,  FN_LYR,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
    ),

    [_NUMERIC] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          _______,  KC_TAB,   XXXXXXX,  XXXXXXX,  ASTERISK, XXXXXXX,  KC_EQL,   KC_7,     KC_8,     KC_9,     XXXXXXX,  KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  PLUS_SIGN,KC_4,     KC_5,     KC_6,     KC_MINUS, KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ASTERISK, KC_1,     KC_2,     KC_3,     KC_SLSH,  KC_ENT,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          KC_LGUI,  XXXXXXX,  XXXXXXX,  KC_DOT,   KC_SPC,   KC_SPC,   KC_COMM,  KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_NAVIGATION] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          LSALT_TAB,ALT_TAB,  PREV_DSK, SHOW_DSK, NEXT_DSK, KC_INS,   XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   XXXXXXX,  KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          MSN_CTRL, KC_BSPC,  WORD_MOD, KC_DEL,   KC_ENT,   XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, XXXXXXX,  KC_DEL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  UNDO,     CUT,      COPY,     PASTE,    SCREENSHOT,ENIE,    KC_PGDN,  KC_PGUP,  XXXXXXX,  XXXXXXX,  KC_ENT,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_SYMBOLS] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          TILDE,    BANG,     PERCENT,  HASHTAG,  ASTERISK, XXXXXXX,  XXXXXXX,  DOLLAR,   CRL_BRC_O,CRL_BRC_C,KC_EQL,   KC_BSPC,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          ARROBA,   DOLLAR,   KC_GRV,   DBL_QT,   KC_QUOT,  XXXXXXX,  LESS_THAN,PAR_OPN,  PAR_CLS,  XXXXXXX,  KC_MINUS, GREATER,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  KC_BSLS,  CARET,    AMPERSAND,PIPE,     XXXXXXX,  XXXXXXX,  SQR_BRC_O,SQR_BRC_C,XXXXXXX,  UND_SCR,  XXXXXXX,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  CONF_LYR, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_FN_KEYS] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          XXXXXXX,  ARROBA,   LESS_THAN,GREATER,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          KC_LCTL,  ARROBA,   PLUS_SIGN,KC_MINUS, KC_EQL,   XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,  CONF_LYR, XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_CONFIG] = LAYOUT_planck_grid(
        //---TAB---|----Q----|----W----|----E----|----R----|----T----|----Y----|----U----|----I----|----O----|----P----|---BKP---|
          KC_TAB,   XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,  WIN_LYR,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  EMAIL2,   EMAIL1,
        //---ESC---|----A----|----S----|----D----|----F----|----G----|----H----|----J----|----K----|----L----|----;----|---DEL---|
          XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  MAC_LYR,  XXXXXXX,  KC_BTN1,  KC_BTN2,  KC_BTN3,  WRK_EMAIL2,WRK_EMAIL,
        //---SFT---|----Z----|----X----|----C----|----V----|----B----|----N----|----M----|----,----|----.----|----/----|---ENT---|
          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LNX_LYR,  XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  DNI,      PHONE_NUMBER,
        //---CTR---|---GUI---|---ALT---|---NAV---|---SYM---|---SPC---|---SPC---|---FNC---|---LFT---|---DWN---|---UP----|---RGT---|
          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
    )
};

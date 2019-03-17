/* Copyright 2018 ''
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
// #include "devkybd.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// a name for each layer
#define _QWERTY    0
#define _FUNCTIONS 1
#define _RSPACE    2
#define _LSPACE    3
#define _DYNMACR   4
#define _MOUSE     5
#define _NUMBERS   6

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LEFTSPC LT(_LSPACE, KC_SPC)
#define RIGTSPC LT(_RSPACE, KC_SPC)
#define SUPER_F LT(_FUNCTIONS, KC_F)
#define SUPER_J LT(_NUMBERS, KC_J)
#define SEMICOL LT(_DYNMACR, KC_SCLN)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_ESC SFT_T(KC_ESC)
#define DYNREC1 DYN_REC_START1
#define DYNREC2 DYN_REC_START2
#define DYNPLY1 DYN_MACRO_PLAY1
#define DYNPLY2 DYN_MACRO_PLAY2
#define DYNSTOP DYN_REC_STOP



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 */
[_QWERTY] = LAYOUT(
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
   CTL_ESC, KC_A,    KC_S,    KC_D,    SUPER_F, KC_G,              KC_H,    SUPER_J, KC_K,    KC_L,    SEMICOL, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                              KC_LGUI, KC_LALT, LEFTSPC,           RIGTSPC, KC_ENT,  KC_RGUI                             \
),
/* Functions
 */
[_FUNCTIONS] = LAYOUT(
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,           KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
   _______, KC_F11 , KC_F12 , _______, _______, _______,           _______, _______, _______, _______, KC_PSCR, _______, \
   _______, AG_SWAP, MU_TOG , _______, _______, _______,           KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, \
   _______, AG_NORM, MU_MOD , _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______,           KC_ESC,  KC_TAB,  _______                             \
),
/* Left space
 */
[_LSPACE] = LAYOUT(

   KC_DEL , KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,           _______, _______, _______, _______, _______, _______, \
   KC_MINS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,           KC_TILD, KC_SLSH, KC_BSLS, KC_LCBR, KC_RCBR, _______, \
   _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,           KC_GRV , KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______, \
   _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   ,           KC_MINS, KC_PLUS, KC_EQL , KC_PIPE, XXXXXXX, _______, \
                              _______, _______, _______,           KC_BSPC, KC_DEL , _______                             \
),
/* Right space
 */
[_RSPACE] = LAYOUT(
   _______, _______, _______, _______, _______, _______,           KC_5   , KC_4   , KC_3   , KC_2   , KC_1   , KC_ESC , \
   _______, _______, KC_HASH, KC_DLR , KC_PERC, KC_AMPR,           KC_T   , KC_R   , KC_E   , KC_W   , KC_Q   , KC_TAB , \
   _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_CIRC,           KC_G   , KC_F   , KC_D   , KC_S   , KC_A   , _______, \
   _______, _______, KC_UNDS, KC_EXLM, KC_AT  , KC_ASTR,           KC_B   , KC_V   , KC_C   , KC_X   , KC_Z   , _______, \
                              _______, KC_DEL , KC_BSPC,           _______, _______, _______                             \
),
/* Macros
 */
[_DYNMACR] = LAYOUT(
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, DYNREC1, DYNREC2, DYNPLY1, DYNPLY2, DYNSTOP,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______,           _______, _______, _______                             \
),
/* Mouse layer
 */
[_MOUSE] = LAYOUT(
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______,           _______, _______, _______                             \
),
/* Easy numbers layer
 */
[_NUMBERS] = LAYOUT(
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, \
   _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,           _______, _______, _______, _______, _______, _______, \
   _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,           _______, _______, _______, _______, _______, _______, \
                              _______, _______, _______,           _______, _______, _______                             \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

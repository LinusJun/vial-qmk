/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "lib/keyball/keyball.h"

enum user_custom_keycodes {
  MY_MS_BTN1 = KEYBALL_SAFE_RANGE,
  MY_MS_BTN2,
  MY_MS_BTN3
};

void keyball_on_adjust_layout_user(keyball_adjust_t v); 

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q        , KC_W        , KC_E        , KC_R        , KC_T        ,                            KC_Y     , KC_U        , KC_I        , KC_O        , KC_P           ,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G        ,                            KC_H     , RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_Z        , KC_X        , KC_C        , KC_V        , KC_B        ,                            KC_N     , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH        ,
    KC_LCTL     , KC_LALT     , KC_CAPS     , LT(2,KC_ESC), LT(5,KC_TAB),LT(1,KC_SPC),KC_ENT,LT(3,KC_BSPC),  LSFT_T(KC_LNG2), KC_RALT,KC_RGUI           , KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_HOME  , KC_BTN4  , KC_BTN3  , KC_BTN5  , KC_END   ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_PGDN  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                            KC_DEL   , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_BSPC  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [3] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),

  [5] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_PPLS  , KC_7.    , KC_8     , KC_9     , KC_PMNS   ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            KC_PAST  , KC_4     , KC_5     , KC_6     , KC_PSLS  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                            KC_DEL   , KC_1     , KC_2     , KC_3     , KC_PDOT  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , KC_P0    , _______  , _______  , _______  , KC_PEQL
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // 如果启用第5层,则启用滚动模式
  keyball_set_scroll_mode(get_highest_layer(state) == 5);

  // 链接层和LED
  uint8_t layer = biton32(state);
  switch (layer)
  {
    case 1:
      rgblight_sethsv_noeeprom(HSV_CORAL);
      break;

    case 2:
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;

    default:
      rgblight_sethsv_noeeprom(HSV_OFF);
      break;
  }

  return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case MY_MS_BTN1 ... MY_MS_BTN3:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_MS_BTN1:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        keyball_set_scroll_mode(true);
      } else {
        unregister_code(KC_LCTL);
        keyball_set_scroll_mode(false);
      }
      return false;

    case MY_MS_BTN2:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_MS_BTN1);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_MS_BTN1);
      }
      return false;

    case MY_MS_BTN3:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_MS_BTN1);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_MS_BTN1);
      }
      return false;
  }

  return true;
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv(HSV_OFF);
}


/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_POINTER,
    LAYER_SYMBOL,
    LAYER_FUN,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off

enum custom_keycodes {
    CK_EXLM = SAFE_RANGE,  // !
    CK_AT,                  // @
    CK_HASH,                // #
    CK_DLR,                 // $
    CK_PERC,                // %
    CK_CIRC,                // ^
    CK_AMPR,                // &
    CK_ASTR,                // *
    CK_LPRN,                // (
    CK_RPRN,                // )
    CK_UNDS,                // _
    CK_PLUS,                // +
    CK_LCBR,                // {
    CK_RCBR,                // }
    CK_PIPE,                // |
    CK_TILD,                // ~
    CK_LABK,                //
    CK_RABK,                // >
    CK_COLN,                // :
    CK_DQUO,                // "
    CK_QUES,                // ?
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,   KC_D,   KC_F,   KC_G,           KC_H,    KC_J,     KC_K,   KC_L, KC_QUOT, KC_RSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       MO(3),    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,             KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH, MO(3),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LALT, KC_LGUI,  KC_SPC,   KC_NO,      KC_NO,  KC_ENT, KC_ESC,  KC_DEL
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_NEXT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_TOGG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,   KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_PREV,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_NO, KC_NO, KC_NO, KC_TRNS,          KC_TRNS, _______, KC_NO, KC_NO
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_SLSH,  KC_7,  KC_8,  KC_9,  KC_ASTR,  KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,         KC_MINS,  KC_4,  KC_5,  KC_6,  KC_PLUS, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,       KC_DOT, KC_1,  KC_2,  KC_3,  KC_COMM,  KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LALT, KC_TRNS ,KC_0, KC_TRNS,       KC_TRNS, KC_NO, KC_NO, KC_NO
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_NO, KC_NO, DPI_MOD, S_D_MOD,            S_D_MOD, DPI_MOD, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,        KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,      QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_NO, MS_BTN2, MS_BTN1, MS_BTN3,      MS_BTN3, MS_BTN1, MS_BTN2, KC_NO
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS,KC_GRV,CK_LABK, CK_RABK, KC_MINS, CK_PIPE,       CK_CIRC, CK_LCBR, CK_RCBR, CK_DLR, KC_BSLS, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, CK_EXLM, CK_ASTR, KC_SLSH, KC_EQL, CK_AMPR,     CK_HASH, CK_LPRN, CK_RPRN, KC_SCLN, CK_DQUO, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, CK_TILD, CK_PLUS, KC_LBRC, KC_RBRC, CK_PERC,    CK_AT, CK_COLN, KC_COMMA, KC_DOT, KC_QUOT, KC_TRNS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_FUN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_F9, KC_F10, KC_F11, KC_12, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case CK_EXLM: tap_code16(KC_EXLM); return false;  // S(KC_1)
        case CK_AT:   tap_code16(KC_AT);   return false;  // S(KC_2)
        case CK_HASH: tap_code16(KC_HASH); return false;  // S(KC_3)
        case CK_DLR:  tap_code16(KC_DLR);  return false;  // S(KC_4)
        case CK_PERC: tap_code16(KC_PERC); return false;  // S(KC_5)
        case CK_CIRC: tap_code16(KC_CIRC); return false;  // S(KC_6)
        case CK_AMPR: tap_code16(KC_AMPR); return false;  // S(KC_7)
        case CK_ASTR: tap_code16(KC_ASTR); return false;  // S(KC_8)
        case CK_LPRN: tap_code16(KC_LPRN); return false;  // S(KC_9)
        case CK_RPRN: tap_code16(KC_RPRN); return false;  // S(KC_0)
        case CK_UNDS: tap_code16(KC_UNDS); return false;  // S(KC_MINS)
        case CK_PLUS: tap_code16(KC_PLUS); return false;  // S(KC_EQL)
        case CK_LCBR: tap_code16(KC_LCBR); return false;  // S(KC_LBRC)
        case CK_RCBR: tap_code16(KC_RCBR); return false;  // S(KC_RBRC)
        case CK_PIPE: tap_code16(KC_PIPE); return false;  // S(KC_BSLS)
        case CK_TILD: tap_code16(KC_TILD); return false;  // S(KC_GRV)
        case CK_LABK: tap_code16(KC_LABK); return false;  // S(KC_COMM)
        case CK_RABK: tap_code16(KC_RABK); return false;  // S(KC_DOT)
        case CK_COLN: tap_code16(KC_COLN); return false;  // S(KC_SCLN)
        case CK_DQUO: tap_code16(KC_DQUO); return false;  // S(KC_QUOT)
        case CK_QUES: tap_code16(KC_QUES); return false;  // S(KC_SLSH)
    }
    return true;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM vbshift[] = { KC_V, KC_B, COMBO_END };
const uint16_t PROGMEM nmshift[] = { KC_N, KC_M, COMBO_END };
const uint16_t PROGMEM cvmod[] = { KC_C, KC_V, COMBO_END };
const uint16_t PROGMEM mcommmod[] = { KC_M, KC_COMMA, COMBO_END };
const uint16_t PROGMEM xcalt[] = { KC_X, KC_C, COMBO_END };
const uint16_t PROGMEM commdotalt[] = { KC_COMMA, KC_DOT, COMBO_END };
const uint16_t PROGMEM zxctrl[] = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM dotslshctrl[] = { KC_DOT, KC_SLSH, COMBO_END };
const uint16_t PROGMEM sdmodsym[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM klmodsym[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM dfmodnum[] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM jkmodfun[] = { KC_J, KC_K, COMBO_END };

combo_t key_combos[] = {
    COMBO(vbshift, KC_LSFT),
    COMBO(nmshift, KC_RSFT),
    COMBO(cvmod, KC_LGUI),
    COMBO(mcommmod, KC_RGUI),
    COMBO(xcalt, KC_LALT),
    COMBO(commdotalt, KC_LALT),
    COMBO(zxctrl, KC_LCTL),
    COMBO(dotslshctrl, KC_RCTL),
    COMBO(sdmodsym, MO(LAYER_SYMBOL)),
    COMBO(klmodsym, MO(LAYER_SYMBOL)),
    COMBO(dfmodnum, MO(LAYER_NUM)),
    COMBO(jkmodfun, MO(LAYER_FUN)),
};

#endif

// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NAV]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_NUM]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    [LAYER_SYMBOL] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [LAYER_FUN] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
       //

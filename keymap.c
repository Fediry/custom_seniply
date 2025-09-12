#include QMK_KEYBOARD_H
#include <stdio.h>

#define _COLMAKDH 0
#define _EXTEND 1
#define _FUNCTION 2
#define _SYMBOLS 3
#define _NUMBERS 4
#define _GAMING 5
#define _GAMING_ARROWS 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*  _COLMAKDH
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │, <│. >│/ ?│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤ESC│
      *           └───┤ _ ├───┐   ┌───┤TAB├───┘
      *               └───┤SPC│   │ENT├───┘
      *                   └───┘   └───┘
      */
    [_COLMAKDH] = LAYOUT_split_3x5_3(
        KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,                                   KC_J,  KC_L,  KC_U,  KC_Y,  KC_QUOT,
        KC_A,  KC_R,  KC_S,  KC_T,  KC_G,                                   KC_M,  KC_N,  KC_E,  KC_I,  KC_O,
        KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,                                   KC_K,  KC_H,  KC_COMM,  KC_DOT,  KC_SLSH,
        LT(_NUMBERS),  LT(_EXTEND, KC_UNDS),  LT(_SYMBOLS, KC_SPC),         LT(_SYMBOLS, KC_ENTER), LT(_EXTEND, KC_TAB),  LT(_FUNCTION, KC_ESC)
    ),
    /*  _EXTEND
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │Esc│Bk │Fnd│Fw │Ins│       │PgU│HOM│ UP│END│CW │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │GUI│ALT│SFT│CTL│ RA│       │PgD│LFT│DWN│RGT│DEL│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Cz │Cx │Cc │Cv │GUI│       │   │bSp│   │   │PRT│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_EXTEND] = LAYOUT_split_3x5_3(
        KC_ESC,  KC_WBAK,  KC_FIND,  KC_WFWD,  KC_INS,                                 KC_PGUP,  KC_HOME,  KC_UP,  KC_END,   CW_TOGG,
        OS_LGUI,  OS_LALT,  OS_LSFT,  OS_LCTL,  OS_RALT,                               KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_DEL,
        C(KC_Z),  C(KC_X),  C(KC_C),  C(KC_V),  KC_LGUI,                               _______,  KC_BSPC,  _______,  _______,   KC_PSCR,
        _______,  _______,  _______,                                                   _______,  _______,  _______
    ),
    /*  _FUNCTION
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │GUI│ALT│SFT│CTL│   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_FUNCTION] = LAYOUT_split_3x5_3(
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      OS_LGUI,  OS_LALT,  OS_LSFT,  OS_LCTL,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,                                                   _______,  _______,  _______
    ),
    /*  _NUMBERS
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │ = │ 7 │ 8 │ 9 │ + │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │GUI│ALT│SFT│CTL│ RA│       │ * │ 4 │ 5 │ 6 │ - │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │bSp│   │       │ 0 │ 1 │ 2 │ 3 │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │-X-├───┐           ┌───┤   │
      *           └───┤   ├───┐   ┌───┤ . ├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [_NUMBERS] = LAYOUT_split_3x5_3(
      _______,  _______,  _______,  _______,  _______,                               KC_EQUAL,  KC_7,  KC_8,  KC_9,   KC_PLUS,
      OS_LGUI,  OS_LALT,  OS_LSFT,  OS_LCTL,  OS_RALT,                               KC_ASTR,   KC_4,  KC_5,  KC_6,   KC_MINS,
      _______,  _______,  _______,  KC_BSPC,  _______,                               KC_0    ,  KC_1,  KC_2,  KC_3,   KC_SLSH,
      _______,  _______,  _______,                                                   _______,  KC_DOT,  _______
    ),
    /*  _SYMBOLS
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │GUI│ALT│SFT│CTL│   │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_SYMBOLS] = LAYOUT_split_3x5_3(
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      OS_LGUI,  OS_LALT,  OS_LSFT,  OS_LCTL,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,                                                   _______,  _______,  _______
    ),
    /*  _GAMING
     *
     */
    [_GAMING] = LAYOUT_split_3x5_3(
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,                                                   _______,  _______,  _______
    ),
    [_GAMING_ARROWS] = LAYOUT_split_3x5_3(
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,   _______,
      _______,  _______,  _______,                                                   _______,  _______,  _______
    )
};

// This changes functionality of Shifting these keys
const key_override_t colon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COLN, KC_SCLN, ~_COLMAKDH);
const key_override_t comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_LPRN, ~_COLMAKDH);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_RPRN, ~_COLMAKDH);
const key_override_t slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH, ~_COLMAKDH);
const key_override_t numbers_slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PSLS, KC_KP_ASTERISK, ~_NUMBERS);
const key_override_t numbers_plus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PPLS, KC_EQUAL, ~_NUMBERS);
const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE, ~_COLMAKDH | ~_FUNCTION | ~_EXTEND | ~_NUMBERS);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&colon_key_override,
	&comma_key_override,
	&dot_key_override,
	&slash_key_override,
	&numbers_slash_key_override,
	&numbers_plus_key_override,
	&delete_key_override,
};

// This is combo definitions
/*
const uint16_t PROGMEM extend_layer_combo[] = {KC_COLN, KC_S, COMBO_END};
const uint16_t PROGMEM numbers_layer_combo[] = {KC_COLN, KC_W, COMBO_END};
const uint16_t PROGMEM gaming_layer_combo[] = {KC_COLN, KC_F, COMBO_END};
const uint16_t PROGMEM colmakdh_layer_combo[] = {KC_DOT, KC_S, COMBO_END};
const uint16_t PROGMEM qwerty_layer_combo[] = {KC_DOT, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(extend_layer_combo, TG(_FUNCTION)),
    COMBO(numbers_layer_combo, TG(_NUMBERS)),
    COMBO(gaming_layer_combo, TG(_GAMING)),
    COMBO(colmakdh_layer_combo, TO(_COLMAKDH)),
    COMBO(qwerty_layer_combo, TG(_EXTEND)),
};
*/

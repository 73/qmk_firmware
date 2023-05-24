#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _LOCK 2


enum custom_keycodes {
    KC_ULK1 = SAFE_RANGE,
    KC_ULK2,
};


#define LR_SPC LT(_FN1, KC_SPC)
#define KC_VIM RCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap _BL: (Base Layer) Default Layer
     * +-------------------------------------------------------------------------+
     * | ESC | 1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |
     * +-------------------------------------------------------------------------+
     * | TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |
     * +-------------------------------------------------------------------------+
     * | FN     |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  RETURN |
     * +-------------------------------------------------------------------------+
     * | LSHIFT   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | SHIFT | FN |
     * +-------------------------------------------------------------------------+
     * |LALT|LMETA|RCTRL|   SPACE | FN | SPACE           | RALT| MENU| RWIN|RCTRL|
     * +-------------------------------------------------------------------------+
     */

    [_BASE] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, _______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_VIM, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_FN1),
      // KC_LCTL, KC_LALT, KC_LGUI, LR_SPC, KC_BSPC, LR_SPC, _______, KC_RALT, KC_APP, _______, KC_RGUI, KC_RCTL),
      KC_LALT, KC_LGUI, KC_LCTL, LR_SPC, KC_BSPC, LR_SPC, _______, KC_RALT, KC_APP, _______, KC_RGUI, KC_RCTL),

    /* Keymap _FL: Function Layer
     * ,-----------------------------------------------------------.
     * | ~  | F1| F2| F3| F4| F5| F6| F7| F8| F9| F0|F11|F12|  DEL |
     * |-----------------------------------------------------------|
     * |     |   | UP|  | MSL|MSD|MSU|MSR|   |   |PRT|PGD|PGU|PAUS |
     * |-----------------------------------------------------------|
     * |       | LE| DN| RE|   |   | LE| DN| UP| RE|   |   |       |
     * |-----------------------------------------------------------|
     * |        |HOM|END|   |   |PRE|NXT|MUT|VOD|VOU|  /|Shift | FN|
     * |-----------------------------------------------------------|
     * |    |    |    |    |  PLAY | PLAY     |     |    |    |    |
     * `-----------------------------------------------------------'
     */

    [_FN1] = LAYOUT(
    KC_GRAVE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_DEL,
    _______,   _______, KC_UP,   _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, _______, _______, KC_PAUS,
    TO(_LOCK), KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
    _______,   _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______,   _______, _______, KC_MPLY, KC_DEL,           KC_MPLY, _______, _______, _______, _______, _______, _______),


    [_LOCK] = LAYOUT(
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   KC_ULK1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ULK2)
};


// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
const uint16_t PROGMEM unlock_combo[] = {KC_ULK1, KC_ULK2, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(unlock_combo, TO(_BASE))
};


// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_VIM:
            return 150;
        default:
            return 200;
    }
}


// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_VIM:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

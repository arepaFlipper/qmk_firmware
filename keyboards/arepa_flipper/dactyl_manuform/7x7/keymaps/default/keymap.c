#include QMK_KEYBOARD_H

enum custom_layer {
    _QWERTY,
    _DIRECTIONS,
    _LOWER,
    _NUM,
};


#define DIRECTIONS MO(_DIRECTIONS)
#define LOWER MO(_LOWER)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    // Left Half - Row 0 to Row 6
    KC_ESC , KC_PSCR , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,
    KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,
    LSFT(KC_TAB), KC_TAB , KC_Q , KC_W , KC_E , KC_R , KC_T ,
    KC_TAB, OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_BRID,LSFT(KC_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B,
    KC_LGUI, C(KC_LALT), C(KC_LGUI), KC_HOME, KC_END, LT(DIRECTIONS, KC_SPC), KC_LSFT,
    KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_NO, KC_NO, KC_NO,

    // Right Half - Row 7 to Row 13
    KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
    KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
    KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
    KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
    KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, MS_WHLU  , C(KC_TAB),
    NUM, LT(DIRECTIONS, KC_SPC), KC_HOME, KC_END, RCTL(KC_B), MS_WHLD, C(KC_B),
    KC_DEL, KC_RALT, KC_ENT, RCTL(KC_RSFT), KC_NO, KC_NO, KC_NO
),

};



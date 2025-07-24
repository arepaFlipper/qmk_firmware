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
        // Left Half - Top to Bottom (6 keys per row except where noted)
        KC_ESC, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,     // Row 5 (top) - 7 keys
        LSFT(KC_TAB), KC_TAB , KC_Q , KC_W , KC_E , KC_R , KC_T ,     // Row 4 - 7 keys
        KC_TAB, OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,         // Row 3 - 7 keys
        KC_BRID,LSFT(KC_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B,         // Row 2 - 7 keys
        KC_LGUI, C(KC_LALT), C(KC_LGUI), KC_HOME, KC_END, LT(DIRECTIONS, KC_SPC), KC_LSFT,  // Row 1 - 7 keys
        KC_NO, KC_ENT, KC_LALT, KC_LCTL, KC_ENT, KC_LALT, KC_BSPC,      // Row 0 (bottom) - 7 keys

        // Right Half - Top to Bottom (7 keys per row)
        KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,   // Row 11 (top)
        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,  // Row 10
        KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,  // Row 9
        KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, MS_WHLU  , C(KC_TAB), // Row 8
        NUM, LT(DIRECTIONS, KC_SPC), KC_HOME, KC_END, RCTL(KC_B), MS_WHLD, C(KC_B),  // Row 7
        KC_DEL, KC_RALT, KC_ENT, RCTL(KC_RSFT), KC_NO, KC_NO, KC_NO     // Row 6 (bottom)
    ),

    [_DIRECTIONS] = LAYOUT(
        // Left Half - Top to Bottom (6 keys per row except where noted)
        KC_ESC, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,     // Row 5 (top) - 7 keys
        LSFT(KC_TAB), KC_TAB , KC_Q , KC_W , KC_E , KC_R , KC_T ,     // Row 4 - 7 keys
        KC_TAB, OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,         // Row 3 - 7 keys
        KC_BRID,LSFT(KC_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B,         // Row 2 - 7 keys
        KC_LGUI, C(KC_LALT), C(KC_LGUI), KC_HOME, KC_END, LT(DIRECTIONS, KC_SPC), KC_LSFT,  // Row 1 - 7 keys
        KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_NO, KC_NO, KC_NO,      // Row 0 (bottom) - 7 keys

        // Right Half - Top to Bottom (7 keys per row)
        S(KC_6)  , S(KC_7)   , S(KC_8)   , S(KC_9)  , S(KC_0)   , KC_MINS  , KC_EQL,
        KC_Y  , KC_HOME   , MS_WHLU   , KC_END  , KC_P   , KC_LBRC  , KC_RBRC,  // Row 10
        KC_LEFT  , KC_DOWN   , KC_UP   , KC_RIGHT  , KC_SCLN, KC_QUOT  , KC_BSLS,  // Row 9
        KC_N  , KC_PGUP   , MS_WHLD, KC_PGDN, KC_SLSH, MS_WHLU  , C(KC_TAB), // Row 8
        NUM, LT(DIRECTIONS, KC_SPC), KC_HOME, KC_END, RCTL(KC_B), MS_WHLD, KC_PRINT_SCREEN,  // Row 7
        KC_DEL, KC_RALT, KC_ENT, RCTL(KC_RSFT), KC_NO, KC_NO, KC_NO     // Row 6 (bottom)
    ),

    [_NUM] = LAYOUT(
        // Left Half - Top to Bottom (6 keys per row except where noted)
        KC_ESC, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,     // Row 5 (top) - 7 keys
        LSFT(KC_TAB), KC_TAB , KC_Q , KC_W , KC_E , KC_R , KC_T ,     // Row 4 - 7 keys
        KC_TAB, OSM(MOD_LSFT), KC_A, KC_S, KC_D, KC_F, KC_G,         // Row 3 - 7 keys
        KC_BRID,LSFT(KC_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B,         // Row 2 - 7 keys
        KC_LGUI, C(KC_LALT), C(KC_LGUI), KC_HOME, KC_END, LT(DIRECTIONS, KC_SPC), KC_LSFT,  // Row 1 - 7 keys
        KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_NO, KC_NO, KC_NO,      // Row 0 (bottom) - 7 keys

        // Right Half - Top to Bottom (7 keys per row)
        KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,   // Row 11 (top)
        KC_Y  , KC_4   , KC_5   , KC_6  , KC_P   , KC_LBRC  , KC_RBRC,  // Row 10
        KC_LEFT  , KC_1   , KC_2   , KC_3  , KC_SCLN, KC_QUOT  , KC_BSLS,  // Row 9
        KC_N  , KC_0   , KC_COMM, KC_DOT, KC_SLSH, MS_WHLU  , C(KC_TAB), // Row 8
        NUM, LT(DIRECTIONS, KC_SPC), KC_HOME, KC_END, RCTL(KC_B), MS_WHLD, C(KC_B),  // Row 7
        KC_DEL, KC_RALT, KC_ENT, RCTL(KC_RSFT), KC_NO, KC_NO, KC_NO     // Row 6 (bottom)
    )

};

enum custom_keys {
    MY_PASTE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MY_PASTE:
                SEND_STRING("Your text or paste here");
                return false;
        }
    }
    return true;
}


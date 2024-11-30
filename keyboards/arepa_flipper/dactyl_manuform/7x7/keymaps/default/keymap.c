#include QMK_KEYBOARD_H

enum custom_layer {
    _QWERTY,
    _LOWER,
    _DIRECTIONS,
    _NUM,
};

enum custom_keycodes {
    SPC_LEFT = SAFE_RANGE,
    TAB_LEFT
};


#define DIRECTIONS MO(_DIRECTIONS)
#define LOWER MO(_LOWER)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,
        KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,
        LSFT(KC_TAB), KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,
        TAB_LEFT, OSM(MOD_LSFT) , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,
        KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,
        KC_LGUI, MOD_MEH , LCTL(KC_LSFT)   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , MT(NUM,KC_SPC)  , KC_LSFT  ,
                                                    KC_LCTL, KC_ENT, KC_LALT, KC_BSPC,

            KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
            KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
            KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
            KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
            KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
            KC_RSFT, DIRECTIONS  , LSFT(KC_LBRC)   , LSFT(KC_RBRC), KC_RALT, KC_SLSH, RCTL(KC_B),
            KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    ),

    // [_DIRECTIONS] = LAYOUT(
    //     KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
    //     KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,  KC_6  , RCS(KC_HOME)   , KC_8   , RCS(KC_END)  , KC_0   , KC_MINS  , KC_EQL,
    //     KC_VOLD, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,  RSFT(KC_HOME)  , KC_HOME   , KC_PGUP   , KC_END  , KC_P   , KC_LBRC  , KC_RBRC,
    //     KC_BRIU, KC_LSFT , LCTL(KC_A)   , KC_S  , KC_D  , KC_F  , KC_G  ,  KC_LEFT  , KC_DOWN   , KC_UP   , KC_RIGHT  , KC_SCLN, KC_QUOT  , KC_BSLS,
    //     KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,  KC_N  , KC_END   , KC_PGDN, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
    //     KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,  LOWER, DIRECTIONS  , RSFT(KC_LBRC)   , RSFT(KC_RBRC), KC_RALT, KC_SLSH, LSFT(KC_B),
    //         KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    // ),
    //
    // [_LOWER] = LAYOUT(
    //     KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
    //     KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,  KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
    //     KC_VOLD, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,  KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
    //     KC_BRIU, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,  KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
    //     KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,  KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
    //     KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,  LOWER, SPC_LEFT  , LSFT(KC_LBRC)   , LSFT(KC_LBRC), KC_RALT, KC_SLSH, LSFT(KC_B),
    //         KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    // ),
    //
    // [_NUM] = LAYOUT(
    //     KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
    //     KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,  KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
    //     KC_VOLD, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,  KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
    //     KC_BRIU, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,  KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
    //     KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,  KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
    //     KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,  LOWER, NUM  , LSFT(KC_LBRC)   , LSFT(KC_LBRC), KC_RALT, KC_SLSH, LSFT(KC_B),
    //         KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    // )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_LEFT:
            if (record->tap.count && record->event.pressed) {
                // If tapped, send KC_SPC
                tap_code(KC_SPC);
                return false; // Skip further processing
            } else if (!record->tap.count && !record->event.pressed) {
                // If held and then released, send KC_LEFT
                tap_code(KC_LEFT);
                return false; // Skip further processing
            }
            break;

        case TAB_LEFT:
            if (record->tap.count && record->event.pressed) {
                // If tapped, send KC_SPC
                tap_code(KC_TAB);
                return false; // Skip further processing
            } else if (!record->tap.count && !record->event.pressed) {
                // If held and then released, send KC_LEFT
                tap_code(KC_LEFT);
                return false; // Skip further processing
            }
            break;
    }
    return true; // Process other keycodes normally
}


#include QMK_KEYBOARD_H

enum custom_layer {
    _QWERTY,
    _DIRECTIONS,
    _LOWER,
    _NUM,
};

enum custom_keycodes {
    SPC_RIGHT = SAFE_RANGE,
    TAB_LEFT
};

#define DIRECTIONS MO(_DIRECTIONS)
#define LOWER MO(_LOWER)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC , KC_PSCR , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,
                                                                    KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
        KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,
                                                                    KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
        LSFT(KC_TAB), KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,
                                                                    KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
        TAB_LEFT, OSM(MOD_LSFT) , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,
                                                                    KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
        KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,
                                                                    KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, MS_WHLU  , C(KC_TAB),
        KC_LGUI, C(KC_LALT) , C(KC_LGUI)  , KC_HOME  , KC_END  , LT(DIRECTIONS, KC_SPC)  , KC_LSFT  ,
                                                            NUM, LT(DIRECTIONS, KC_SPC)  , KC_HOME   , KC_END, RCTL(KC_B), MS_WHLD, C(KC_B),
                        KC_LCTL, KC_ENT, KC_LALT, KC_BSPC,
                                                            KC_DEL, KC_RALT, KC_ENT, RCTL(KC_RSFT)
    ),

    [_DIRECTIONS] = LAYOUT(
        KC_TRNS , KC_TRNS , KC_6  , KC_7 , KC_8 , KC_9 , KC_0 ,
                                                                    KC_TRNS  ,  KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS   , KC_TRNS ,
        KC_TRNS, KC_TRNS  , KC_TRNS   , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
                                                                    KC_6  , RSFT(KC_HOME)   , S(KC_8)   , LSFT(KC_9)  , LSFT(KC_0)   , KC_MINS  , KC_EQL,
        LSFT(KC_TAB), KC_TRNS  , KC_TRNS   , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
                                                                        KC_TRNS  , KC_HOME   , KC_TRNS   , KC_END  , KC_P   , LSFT(KC_RBRC)  , LSFT(KC_RBRC),
        TAB_LEFT, OSM(MOD_LSFT) , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,
                                                                        KC_LEFT  , KC_DOWN   , KC_UP   , KC_RIGHT  , LSFT(KC_SCLN), LSFT(KC_QUOT)  , LSFT(KC_BSLS),
        KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,
                                                                    KC_N  , KC_M   , LSFT(KC_COMM), RSFT(KC_DOT), KC_SLSH, KC_PGUP  , KC_RCTL,
        KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,
                                                                    LOWER, KC_SPC  , LSFT(KC_LBRC)   , C(S(KC_END)), KC_RALT, KC_PGDN, LSFT(KC_B),
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_LOWER] = LAYOUT(
        KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,  KC_F7 , KC_F8  , KC_F9 , KC_F10 , KC_F11   , KC_F12 ,
        KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,  KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
        KC_VOLD, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,  KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC  , KC_RBRC,
        KC_BRIU, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,  KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT  , KC_BSLS,
        KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,  KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
        KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,  LOWER, NUM  , LSFT(KC_LBRC)   , LSFT(KC_LBRC), KC_RALT, KC_SLSH, LSFT(KC_B),
            KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    ),

    [_NUM] = LAYOUT(
        KC_ESC , KC_RPRN , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_A  ,  KC_S , KC_V  , KC_T, LALT(KC_Z), KC_F11   , KC_F12 ,
        KC_VOLU, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,  KC_6  , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINS  , KC_EQL,
        KC_VOLD, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,  LGUI(KC_Y)  , KC_4   , KC_5   , KC_6  , KC_P   , KC_LBRC  , KC_RBRC,
        KC_BRIU, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,  LGUI(KC_Z)  , KC_1   , KC_2   , KC_3  , LGUI(KC_Y), KC_QUOT  , KC_BSLS,
        KC_BRID,LSFT(KC_BSLS), KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,  KC_N  , KC_0   , KC_COMM, KC_DOT, KC_SLSH, KC_LCTL  , KC_RCTL,
        KC_LGUI, KC_LCTL , KC_LALT   , LSFT(KC_COMM)  , LSFT(KC_DOT)  , DIRECTIONS  , KC_LSFT  ,  LOWER, NUM  , LSFT(KC_LBRC)   , LSFT(KC_LBRC), KC_RALT, KC_SLSH, LSFT(KC_B),
            KC_LCTL, KC_ENT, KC_LALT, KC_BSPC, KC_DEL, KC_RALT, KC_ENT, KC_RCTL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_RIGHT:
            if (record->tap.count && record->event.pressed) {
                // If tapped, send KC_SPC
                tap_code(KC_SPC);
            } else if (!record->event.pressed) {
                // If held and then released, send KC_LEFT
                tap_code(KC_LEFT);
            }
            return false; // Skip further processing
            break;

        case TAB_LEFT:
            if (record->tap.count && record->event.pressed) {
                // If tapped, send KC_SPC
                tap_code(KC_TAB);
                return false; // Skip further processing
            } else if (!record->tap.count && !record->event.pressed) {
                // If held and then released, send KC_LEFT
                tap_code(KC_HOME);
                return false; // Skip further processing
            }
            break;
    }
    return true; // Process other keycodes normally
}


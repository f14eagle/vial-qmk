#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
//#define KC_BKSL KC_BSLASH
//#define SYM_L   MO(_SYMB)

//#define KC_ALAS LALT_T(KC_PAST)
//#define KC_CTPL LCTL_T(KC_PSLS)

//#define KC_NAGR LT(_NAV, KC_GRV)
//#define KC_NAMI LT(_NAV, KC_MINS)

//#define KC_ADEN LT(_ADJUST, KC_END)
//#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(2,KC_ESC), RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_REVERSE, RGB_MODE_RAINBOW, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F5, KC_F12, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LCTL_T(KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_UP, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_DOT, KC_N, KC_M, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_NO, KC_NO, RSFT_T(KC_COMM), LM(1, MOD_LSFT), KC_SLSH, KC_SCLN, KC_NO, KC_NO, KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, RGB_TOG, RGB_MODE_FORWARD, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T)
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _QWERTY:
            //set_led_off;
            break;
        case _SYMB:
            //set_led_green;
            break;
        case _NAV:
            //set_led_blue;
            break;
        case _ADJUST:
            //set_led_red;
            break;
        default:
            break;
    }
};



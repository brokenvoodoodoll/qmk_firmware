#include QMK_KEYBOARD_H

#include "transactions.h"
#include <string.h>

#define BASE 0
#define NAV 1
#define SYM 2
#define MEDIA 3

#define CTL_ESC LCTL_T(KC_ESC)
#define LCG_LEFT LCG(KC_LEFT)
#define RCG_RGHT LCG(KC_RGHT)
#define SFT_ENT LSFT_T(KC_ENT)
#define SFT_SPC LSFT_T(KC_SPC)
#define BSPC_LT LT(NAV, KC_BSPC)
#define DEL_LT LT(MEDIA, KC_DEL)
#define TAB_L1 LT(SYM, KC_TAB)
#define TAB_L2 LT(MEDIA, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
LAYOUT(
    KC_GRV,  KC_1, KC_2,   KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_TAB,  KC_Q, KC_W,   KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
    CTL_ESC, KC_A, KC_S,   KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X,   KC_C,    KC_V,    KC_B,   LCG_LEFT,  RCG_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
                   KC_F18, KC_LALT, KC_LGUI, TAB_L1, SFT_SPC,   SFT_ENT,  BSPC_LT, KC_RGUI, KC_RALT, KC_HYPR
),
LAYOUT(
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                   MS_BTN5, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F12,
    KC_TRNS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,                   MS_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO,
    KC_TRNS, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_NO,   KC_NO,   KC_INS,  KC_BSPC, KC_DEL,  KC_NO,   KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, TAB_L2,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,   KC_NO,   S(KC_2), S(KC_3),    S(KC_6), S(KC_4),                      S(KC_LBRC), S(KC_RBRC), KC_EQL,     S(KC_EQL),  KC_TRNS,    KC_TRNS,
    KC_TRNS, S(KC_5), KC_QUOT, S(KC_QUOT), S(KC_1), S(KC_SLSH),                   S(KC_9),    S(KC_0),    KC_MINS,    S(KC_MINS), KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_NO,   KC_BSLS, S(KC_BSLS), S(KC_7), S(KC_8),    KC_NO,   KC_NO,   KC_LBRC,    KC_RBRC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                      KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, DEL_LT,     KC_TRNS,    KC_TRNS,    KC_TRNS
),
LAYOUT(
    RM_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_BRID, KC_NO,   KC_BRIU, KC_NO, KC_NO,
    KC_NO,   RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                   KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
    KC_NO,   RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
    AG_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MCTL, KC_NO,   KC_LPAD, KC_NO, KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_BRIU, KC_BRID) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_BRIU, KC_BRID) },
    { ENCODER_CCW_CW(KC_NO,   KC_NO),   ENCODER_CCW_CW(KC_NO,   KC_NO) },
};
#endif

// --- OLED ---

#define QUEUE_SIZE 21
char keystroke_queue[QUEUE_SIZE + 1] = "Ready...";

#ifdef SPLIT_KEYBOARD
void slave_receive_queue(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    memcpy(keystroke_queue, in_data, in_buflen);
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(KEYSTROKE_SYNC_ID, slave_receive_queue);
}
#endif

char keycode_to_char(uint16_t keycode) {
    uint16_t base_keycode = keycode & 0xFF;

    if (base_keycode >= KC_A && base_keycode <= KC_Z) {
        return 'a' + (base_keycode - KC_A);
    }
    if (base_keycode >= KC_1 && base_keycode <= KC_9) {
        return '1' + (base_keycode - KC_1);
    }
    if (base_keycode == KC_0) return '0';

    switch (base_keycode) {
        case KC_SPC:  return ' ';
        case KC_BSPC: return '\b';
        case KC_ENT:  return '<';
        case KC_DOT:  return '.';
        case KC_COMM: return ',';
        case KC_MINS: return '-';
        case KC_EQL:  return '=';
        case KC_SLSH: return '/';
    }
    return 0;
}

void add_to_queue(char c) {
    int len = strlen(keystroke_queue);

    if (c == '\b') {
        if (len > 0) {
            keystroke_queue[len - 1] = '\0';
        }
    } else {
        if (len >= QUEUE_SIZE) {
            memmove(keystroke_queue, keystroke_queue + 1, QUEUE_SIZE - 1);
            keystroke_queue[QUEUE_SIZE - 1] = c;
        } else {
            keystroke_queue[len] = c;
            keystroke_queue[len + 1] = '\0';
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        char c = keycode_to_char(keycode);
        if (c != 0) {
            add_to_queue(c);

            #ifdef SPLIT_KEYBOARD
                if (is_keyboard_master()) {
                    transaction_rpc_send(KEYSTROKE_SYNC_ID, sizeof(keystroke_queue), keystroke_queue);
                }
            #endif
        }
    }
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Sofle Choc V1\n\n"), false);

        uint8_t layer = get_highest_layer(layer_state);
        oled_write_P(PSTR("Active Layer:\n > "), false);

        switch (layer) {
            case BASE:  oled_write_P(PSTR("BASE\n"), false); break;
            case NAV:  oled_write_P(PSTR("NAVIGATION\n"), false); break;
            case SYM:  oled_write_P(PSTR("SYMBOLS\n"), false); break;
            case MEDIA:  oled_write_P(PSTR("MEDIA\n"), false); break;
            default: oled_write_P(PSTR("UNKNOWN\n"), false); break;
        }
    } else {
        oled_write_P(PSTR("Input History:\n\n"), false);
        oled_write(keystroke_queue, false);
    }
    return false;
}

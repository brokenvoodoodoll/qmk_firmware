#include "caps_word.h"
#include "info_config.h"
#include "keycodes.h"
#include "oled_driver.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#define BASE 0
#define NAV 1
#define SYM 2
#define MEDIA 3

#define CTL_ESC LCTL_T(KC_ESC)
#define TAB_NAV LT(NAV, KC_TAB)
#define BSPC_NAV LT(NAV, KC_BSPC)
#define SPC_SYM LT(SYM, KC_SPC)
#define ENT_SYM LT(SYM, KC_ENT)

#define TAB_MED LT(MEDIA, KC_TAB)
#define DEL_MED LT(MEDIA, KC_DEL)
#define SPC_MED LT(MEDIA, KC_SPC)
#define ENT_MED LT(MEDIA, KC_ENT)

#define MCTL_LEFT LCAG(KC_LEFT)
#define MCTL_RGHT LCAG(KC_RGHT)

#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LGUI_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K RGUI_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RCTL_T(KC_SCLN)

#define HM_F5 LCTL_T(KC_F5)
#define HM_F6 LALT_T(KC_F6)
#define HM_F7 LGUI_T(KC_F7)
#define HM_F8 LSFT_T(KC_F8)
#define HM_LEFT RSFT_T(KC_LEFT)
#define HM_DOWN RGUI_T(KC_DOWN)
#define HM_RGHT LALT_T(KC_RGHT)

#define HM_S3 LCTL_T(S(KC_3))
#define HM_S4 LALT_T(S(KC_4))
#define HM_S9 LGUI_T(S(KC_9))
#define HM_S0 LSFT_T(S(KC_0))
#define HM_P4 RSFT_T(KC_P4)
#define HM_P5 RGUI_T(KC_P5)
#define HM_P6 LALT_T(KC_P6)
#define HM_S8 RCTL_T(S(KC_8))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
LAYOUT(
    KC_GRV,   KC_1, KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_F18,   KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
    CTL_ESC,  HM_A, HM_S,    HM_D,    HM_F,    KC_G,                          KC_H,     HM_J,    HM_K,    HM_L,   HM_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    MCTL_LEFT, MCTL_RGHT, KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
                    KC_LCTL, KC_LALT, KC_LGUI, TAB_NAV, SPC_SYM,   ENT_SYM,   BSPC_NAV, KC_RGUI, KC_RALT, KC_RCTL
),
LAYOUT(
    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_F1, KC_F2,   KC_F3,   KC_F4,   CG_TOGG,                   MS_BTN5, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
    KC_TRNS, HM_F5, HM_F6,   HM_F7,   HM_F8,   CW_TOGG,                   MS_BTN4, HM_LEFT, HM_DOWN, HM_RGHT, KC_TRNS, KC_NO,
    KC_TRNS, KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_TRNS, KC_TRNS, KC_NO,   KC_PGDN, KC_INS,  KC_PGUP, KC_NO,   KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, TAB_MED, KC_TRNS, KC_TRNS, DEL_MED, KC_TRNS, KC_TRNS, KC_TRNS
),
LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,                                KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
    KC_TRNS, S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), S(KC_BSLS),                           KC_EQL,  KC_P7,   KC_P8,   KC_P9,  S(KC_7), KC_NO,
    KC_TRNS, HM_S3,   HM_S4,   HM_S9,      HM_S0,      KC_GRV,                               KC_MINS, HM_P4,   HM_P5,   HM_P6,  HM_S8,   KC_NO,
    KC_TRNS, S(KC_5), S(KC_6), KC_LBRC,    KC_RBRC,    S(KC_GRV), KC_TRNS,          KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_BSLS, KC_NO,
                      KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   SPC_MED, ENT_MED, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
LAYOUT(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, RM_SPDD, RM_SPDU, RM_HUED, RM_HUEU, KC_NO,                     KC_MCTL, KC_VOLD, KC_VOLU, KC_MUTE, DT_UP,   KC_NO,
    KC_NO, RM_PREV, RM_NEXT, RM_SATD, RM_SATU, RM_TOGG,                   KC_LPAD, KC_MPRV, KC_MNXT, KC_MPLY, DT_DOWN, KC_NO,
    KC_NO, KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_BRIU, KC_NO,   KC_NO,   KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_NO,   KC_NO),   ENCODER_CCW_CW(KC_NO,   KC_NO) },
};
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_write_uint8(uint8_t data) {
    char str[] = "   ";
    uint8_t i = 3;
    do {
        i--;
        str[i] = '0' + (data % 10);
        data /= 10;
    } while (data > 0);
    oled_write(str, false);
}

void oled_write_uint16(uint16_t data) {
    char str[] = "   ";
    uint16_t i = 3;
    do {
        i--;
        str[i] = '0' + (data % 10);
        data /= 10;
    } while (data > 0);
    oled_write(str, false);
}

void render_rgb_matrix_info(void) {
    if (!rgb_matrix_is_enabled()) {
        oled_write_P(PSTR("RGB:\nOFF\n"), false);
        oled_write_P(PSTR("                   \n"), false);
        oled_write_P(PSTR("                   \n"), false);
        return;
    }

    oled_write_P(PSTR("RGB:\nON\n"), false);
    oled_write_P(PSTR("M:"), false);
    oled_write_uint8(rgb_matrix_get_mode());
    oled_write_P(PSTR("H:"), false);
    oled_write_uint8(rgb_matrix_config.hsv.h);
    oled_write_P(PSTR("S:"), false);
    oled_write_uint8(rgb_matrix_config.hsv.s);
    oled_write_P(PSTR("V:"), false);
    oled_write_uint8(rgb_matrix_config.hsv.v);
    oled_write_P(PSTR("S:"), false);
    oled_write_uint8(rgb_matrix_config.speed);
    oled_write_P(PSTR("\n"), false);
}

void render_layer_status(void) {
    uint8_t active_layer = get_highest_layer(layer_state);
    oled_write_P(PSTR("BASE\n"), active_layer == BASE);
    oled_write_P(PSTR("NAV\n"), active_layer == NAV);
    oled_write_P(PSTR("SYM\n"), active_layer == SYM);
    oled_write_P(PSTR("MEDIA\n"), active_layer == MEDIA);
}

void render_swap_status(void) {
    if (keymap_config.swap_lalt_lgui) {
        oled_write_P(PSTR("AGWIN"), true);
    } else {
        oled_write_P(PSTR("AGMAC"), false);
    }

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("CGWIN"), true);
    } else {
        oled_write_P(PSTR("CGMAC"), false);
    }

    if (is_caps_word_on()) {
        oled_write_P(PSTR("CW ON"), true);
    } else {
        oled_write_P(PSTR("CWOFF"), false);
    }
}

void render_dynamic_tapping_term(void) {
    oled_write_P(PSTR("DT"), false);
    oled_write_uint16(g_tapping_term);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_status();
        oled_write_P(PSTR("\n"), false);
        render_swap_status();
        render_dynamic_tapping_term();
    } else {
        render_rgb_matrix_info();
    }

    return false;
}

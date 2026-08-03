#include "caps_word.h"
#include "info_config.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "oled_driver.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#define BASE 0
#define NAV 1
#define FUNC 2
#define MEDIA 3
#define SYM 4
#define NUM 5

#define CTL_ESC LCTL_T(KC_ESC)
#define SPC_SFT LSFT_T(KC_SPC)
#define ENT_SFT RSFT_T(KC_ENT)
#define F18_LT LT(FUNC, KC_F18)
#define BSPC_LT LT(NAV, KC_BSPC)

#define F18_LT2 LT(MEDIA, KC_F18)
#define DEL_LT2 LT(MEDIA, KC_DEL)

#define MCTL_LEFT LCAG(KC_LEFT)
#define MCTL_RGHT LCAG(KC_RGHT)

#define MAC_SCR LSG(KC_4)
#define WIN_SCR LSG(KC_S)

/* --- HOME ROW MODS --- */
// #define HM_A LCTL_T(KC_A)
// #define HM_S LALT_T(KC_S)
// #define HM_D LGUI_T(KC_D)
// #define HM_F LSFT_T(KC_F)
// #define HM_J RSFT_T(KC_J)
// #define HM_K RGUI_T(KC_K)
// #define HM_L LALT_T(KC_L)
// #define HM_SCLN RCTL_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
LAYOUT(
    KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
    CTL_ESC, KC_A, KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,   MCTL_LEFT, MCTL_RGHT, KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
                   KC_LCTL, KC_LALT, KC_LGUI, F18_LT, SPC_SFT,   ENT_SFT,   BSPC_LT,  KC_RGUI, KC_RALT, KC_RCTL
),
LAYOUT(
    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,
    KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MS_BTN5, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_RBRC,
    KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MS_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_GRV,
    KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_PGUP, KC_INS,  KC_PGDN, KC_BSLS, KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, F18_LT2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
LAYOUT(
    KC_NO,   KC_NO, KC_F10,  KC_F11,  KC_F12,  KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,
    KC_TRNS, KC_NO, KC_F7,   KC_F8,   KC_F9,   CW_TOGG,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RBRC,
    KC_TRNS, KC_NO, KC_F4,   KC_F5,   KC_F6,   CG_TOGG,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_GRV,
    KC_TRNS, KC_NO, KC_F1,   KC_F2,   KC_F3,   MAC_SCR, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS, KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DEL_LT2, KC_TRNS, KC_TRNS, KC_TRNS
),
LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RM_NEXT, RM_SPDU, RM_HUEU, RM_SATU, RM_VALU, KC_NO,                     KC_MCTL, KC_VOLD, KC_MUTE, KC_VOLU, DT_UP,   KC_NO,
    RM_PREV, RM_SPDD, RM_HUED, RM_SATD, RM_VALD, RM_TOGG,                   KC_LPAD, KC_MPRV, KC_MPLY, KC_MNXT, DT_DOWN, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_NO,   KC_BRIU, KC_NO,   KC_NO,
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
    oled_write_P(PSTR("FUNC\n"), active_layer == FUNC);
    oled_write_P(PSTR("MEDIA\n"), active_layer == MEDIA);
    // oled_write_P(PSTR("SYM\n"), active_layer == SYM);
    // oled_write_P(PSTR("NUM\n"), active_layer == NUM);
}

void render_swap_status(void) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
            keycode,
            is_combo ? 254 : record->event.key.row,
            is_combo ? 254 : record->event.key.col,
            get_highest_layer(layer_state),
            record->event.pressed,
            get_mods(),
            get_oneshot_mods(),
            record->tap.count
            );
#endif
    return true;
}

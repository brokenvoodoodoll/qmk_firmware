#include "caps_word.h"
#include "info_config.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "oled_driver.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#define BASE 0
#define NAV 1
#define NUM 2
#define SYM 3
#define FUN 4
#define MED 5

#define SPC_NAV LT(NUM, KC_SPC)
#define ENT_SFT LSFT_T(KC_ENT)
#define TAB_NUM LT(NAV, KC_TAB)
#define BSPC_FUN LT(FUN, KC_BSPC)
#define DEL_MED LT(MED, KC_DEL)
#define ESC_SYM LT(SYM, KC_ESC)

/* --- HOME ROW MODS --- */
#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LGUI_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K RGUI_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM combo_cg_togg[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {KC_T, KC_Y, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM lscln_combo[]   = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_cg_togg, CG_TOGG),
    COMBO(combo_caps_word, CW_TOGG),

    // COMBO(as_combo, S(KC_GRV)),
    // COMBO(we_combo, S(KC_COMM)),
    COMBO(sd_combo, KC_BSLS),
    COMBO(xc_combo, S(KC_BSLS)),
    COMBO(er_combo, S(KC_COMM)),
    COMBO(df_combo, KC_GRV),
    COMBO(cv_combo, S(KC_GRV)),
    COMBO(rt_combo, KC_LBRC),
    COMBO(fg_combo, S(KC_9)),
    COMBO(vb_combo, S(KC_LBRC)),

    // COMBO(lscln_combo, KC_BSLS),
    // COMBO(io_combo, KC_BSLS),
    COMBO(kl_combo, KC_EQL),
    COMBO(commdot_combo, S(KC_EQL)),
    COMBO(ui_combo, S(KC_DOT)),
    COMBO(jk_combo, KC_MINS),
    COMBO(mcomm_combo, S(KC_MINS)),
    COMBO(yu_combo, KC_RBRC),
    COMBO(hj_combo, S(KC_0)),
    COMBO(nm_combo, S(KC_RBRC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// BASE
LAYOUT(
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
    KC_MINS, KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,                      KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
    KC_F18,  HM_A,  HM_S,  HM_D,  HM_F,    KC_G,                      KC_H,     HM_J,    HM_K,    HM_L,   HM_SCLN, KC_QUOT,
    KC_EQL,  KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,    KC_NO,   KC_NO,   KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
                    KC_NO, KC_NO, ESC_SYM, TAB_NUM, SPC_NAV, ENT_SFT, BSPC_FUN, DEL_MED, KC_NO,   KC_NO
),
// NAV
LAYOUT(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MS_BTN5, KC_HOME, KC_UP,   KC_END,  KC_NO, KC_NO,
    KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                     MS_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_PGDN, KC_NO,   KC_PGUP, KC_NO, KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
// NUM
LAYOUT(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     S(KC_EQL), KC_7,  KC_8,  KC_9,  S(KC_8), KC_NO,
    KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                     KC_MINS,   KC_4,  KC_5,  KC_6,  KC_SLSH, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,    KC_1,  KC_2,  KC_3,  KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT,    KC_0,  KC_NO, KC_NO
),
// SYM
LAYOUT(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,                     KC_NO,      KC_NO,      KC_NO,     KC_NO,   KC_NO,   KC_NO,
    KC_NO, S(KC_1), S(KC_2), S(KC_3), S(KC_4),    S(KC_5),                   KC_GRV,     S(KC_GRV),  S(KC_8),   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,    S(KC_6),                   KC_BSLS,    KC_MINS,    KC_EQL,    KC_NO,   KC_TRNS, KC_TRNS,
    KC_NO, KC_NO,   KC_NO,   KC_BSLS, S(KC_BSLS), S(KC_7), KC_NO,   KC_NO,   S(KC_BSLS), S(KC_MINS), S(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_NO,   KC_NO,   KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_NO,     KC_NO
),
// FUN
LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,                    KC_NO,   KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO
),
// MED
LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    RM_NEXT, RM_SPDU, RM_HUEU, RM_SATU, RM_VALU, KC_NO,                     DT_UP,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
    RM_PREV, RM_SPDD, RM_HUED, RM_SATD, RM_VALD, RM_TOGG,                   DT_DOWN, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID, KC_NO,   KC_BRIU, KC_NO, KC_NO,
                      KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
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
    oled_write_P(PSTR("NUM\n"), active_layer == NUM);
    oled_write_P(PSTR("SYM\n"), active_layer == SYM);
    oled_write_P(PSTR("FUN\n"), active_layer == FUN);
    oled_write_P(PSTR("MED\n"), active_layer == MED);
}

void render_swap_status(void) {
    if (is_caps_word_on()) {
        oled_write_P(PSTR("CW ON"), true);
    } else {
        oled_write_P(PSTR("CWOFF"), false);
    }

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("CGWIN"), true);
    } else {
        oled_write_P(PSTR("CGMAC"), false);
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


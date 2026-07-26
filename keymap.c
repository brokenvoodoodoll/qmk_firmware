#include QMK_KEYBOARD_H

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
        oled_write_P(PSTR("WIN\n"), false);
    } else {
        oled_write_P(PSTR("MAC\n"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_status();
        oled_write_P(PSTR("\n"), false);
        render_swap_status();
    } else {
        render_rgb_matrix_info();
    }

    return false;
}

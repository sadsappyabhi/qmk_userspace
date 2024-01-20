#include QMK_KEYBOARD_H



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, MO(2), KC_LSFT, KC_SPC, MO(1), KC_NO),
	[1] = LAYOUT_split_3x5_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_EQL, KC_GRV, KC_COLN, KC_SCLN, KC_PLUS, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_CIRC, KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_BSPC, KC_DEL, KC_BSLS, KC_PIPE, KC_AMPR, KC_QUOT, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, KC_NO, MO(4), MO(3), KC_NO, KC_TRNS, KC_NO),
	[2] = LAYOUT_split_3x5_3(KC_ESC, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_R), LGUI(KC_F), KC_PGUP, KC_HOME, KC_UP, KC_END, KC_QUOT, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_RALT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_NO, LALT(KC_BSPC), KC_BSPC, KC_TAB, KC_APP, KC_INS, KC_NO, KC_TRNS, KC_NO, KC_ENT, MO(5), KC_NO),
	[3] = LAYOUT_split_3x5_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQL, KC_7, KC_8, KC_9, KC_EQL, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO, KC_ASTR, KC_4, KC_5, KC_6, KC_MINS, KC_NO, KC_NO, KC_TAB, KC_BSPC, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_UNDS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT_split_3x5_3(RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_SPI, KC_F12, KC_F7, KC_F8, KC_F9, RGB_MOD, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), RGB_TOG, KC_F11, KC_F4, KC_F5, KC_F6, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_SPD, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[5] = LAYOUT_split_3x5_3(QK_BOOT, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            // write_ln avoids having to use \n
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif

// Render a message before going into bootloader mode.
void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
}


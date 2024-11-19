
/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_JS = 0,
    _SYM,
    _GPAD,
};


// Aliases for readability
#define SYM_SP   LT(_SYM, KC_SPC) // sym when held, space when tapped
#define UND_SFT   MT(MOD_RSFT, KC_UNDS) // sym when held, space when tapped 

#define OS_LSFT  OSM(MOD_LSFT)
#define OS_RSFT  OSM(MOD_RSFT)
#define OS_LCTL  OSM(MOD_LCTL)
#define OS_RCTL  OSM(MOD_RCTL)
#define OS_LALT  OSM(MOD_LALT)
#define OS_RALT  OSM(MOD_RALT)
#define OS_LGUI  OSM(MOD_LGUI)
#define CTL_BKS  LCTL(KC_BSPC)

#define KVM_1  LCTL(RCTL(KC_1))
#define KVM_2  LCTL(RCTL(KC_2))

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak-JS
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Del/Esc|   Q  |   W  |   D  |   C  |   B  |                              |   Y  |   F  |   U  |   P  |   X  |CtlBksp |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   T  |   H  |   G  |                              |   M  |   N  |   E  |   O  |   I  |  Home  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  | CtlC | CtlV |   R  |   V  | Space|  Ctl |  | Enter|   _  |   K  |   L  |  ,/! |  ./? |   J  |  End   |
 * `----------------------+------+------+------+   /  +      |  |      +   /  +------+------+------+----------------------'
 *                        | GPad | LGUI | LAlt | Sym  |  Ctl |  | Enter|RShift| Enter| RCtl | KVM2 |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_JS] = LAYOUT(
     KC_DEL  , KC_Q ,  KC_W  ,  KC_D  ,  KC_C  ,  KC_B  ,                                         KC_Y   ,  KC_F  ,  KC_U  , KC_P  ,  KC_X  , CTL_BKS,
     KC_TAB  , KC_A ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_G  ,                                         KC_M   ,  KC_N  ,  KC_E  , KC_O  ,  KC_I  , KC_HOME,
     KC_LSFT , KC_Z , C(KC_C), C(KC_V),  KC_R  ,  KC_V  , SYM_SP , KC_LCTL,     KC_ENT ,UND_SFT, KC_K    ,  KC_L  , KC_COMM, KC_DOT,  KC_J  , KC_END ,
                             TG(_GPAD), KC_LGUI, KC_LALT, SYM_SP , KC_LCTL,     KC_ENT ,UND_SFT, KC_ENT  , KC_RCTL, KVM_2
    ),

/*_
 * Sym Layer: Numbers and Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Esc  |  6/$ | 4/ * | 2/+  |  0/_ |  8/\ |                              |  9/@ |  1/& |  3/# |  5/^ |  7/% |  Bkspc |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  `/~   | "/'  |  {/} |  (/) |-/CtlX|  [/] |                              | PgUp |Ctrl← |   ↑  |Ctrl→ |//Ctl/|   F2   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | </>  |  :/; |  =   |  |   |      |      |  |      |      | PgDn |   ←  |   ↓  |   →  |      |   F5   |
 * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      | KVM1 |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     KC_ESC  , KC_6   , KC_4   , KC_2   , KC_0   , KC_8   ,                                        KC_9   , KC_1     , KC_3   , KC_5      , KC_7    , KC_BSPC,
     KC_GRAVE, KC_DQUO, KC_LCBR, KC_LPRN, KC_MINS, KC_LBRC,                                        KC_PGUP,C(KC_LEFT), KC_UP  ,C(KC_RIGHT), KC_SLSH , KC_F2  ,
     KC_TRNS , KC_TRNS, KC_LABK, KC_COLN, KC_EQL , KC_PIPE, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT  , KC_DOWN, KC_RIGHT  , KC_TRNS , KC_F5  ,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  , KVM_1
    ),

/*
 * Game Pad Layer: Gaming Keys, Function Keys, and RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |                              |  F1  |  F2  |  F3  |  F4  |  F5  |   F6   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Tab  | LShft|   A  |   W  |   D  |   R  |                              |  F7  |   ←  |   ↑  |  →   |  F8  |   F9   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    Z   | LCtl |   Q  |   S  |   E  |   F  | Space| Enter|  |   V  | GPad |  F10 |   T  |   ↓  |   C  | F11  |  F12   |
 * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
 *                        |   Y  |   X  | LAlt | Space| Enter|  |   V  | GPad |   H  |  RGB |   B  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GPAD] = LAYOUT(
      QK_GESC, KC_1   , KC_2  , KC_3  , KC_4  , KC_5   ,                                    KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5 , KC_F6 ,
      KC_TAB , KC_LSFT, KC_A  , KC_W  , KC_D  , KC_R   ,                                    KC_F7  , KC_LEFT, KC_UP  , KC_RIGHT, KC_F8 , KC_F9 ,
      KC_Z   , KC_LCTL, KC_Q  , KC_S  , KC_E  , KC_F   , KC_SPC, KC_ENT,   KC_V ,TG(_GPAD), KC_F10 , KC_T   , KC_DOWN, KC_C    , KC_F11, KC_F12,
                                KC_Y  , KC_X  , KC_LALT, KC_SPC, KC_ENT,   KC_V ,TG(_GPAD), KC_H   , RGB_TOG, KC_B
    ),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {

        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_JS:
                oled_write_P(PSTR("\nQ|W|D|C|B   Y|F|U|P|X"), false);
                oled_write_P(PSTR("A|S|T|H|G   M|N|E|O|I"), false);
                oled_write_P(PSTR("Z|c|v|R|V   K|L|,|.|J\n"), false);
                oled_write_P(PSTR("Layer: Colemak-JS    \n"), false);
                break;

            case _SYM:
                oled_write_P(PSTR("\n$|*|+|_|\\   @|&|#|^|%"), false);
                oled_write_P(PSTR("\"|{|(|-|[   u|l|u|r|/"), false);
                oled_write_P(PSTR(" |<|:|=||   d|l|d|r| \n"), false);
                oled_write_P(PSTR("Layer: Symbols       \n"), false);
                break;

            case _GPAD:
                oled_write_P(PSTR("\ne|12345    F1234 5| 6"), false);
                oled_write_P(PSTR("t|sAWDR    F7lur 8| 9"), false);
                oled_write_P(PSTR("Z|cQSEF   F10TdC11|12"), false);
                oled_write_P(PSTR("   YXase VgHrB       \n"), false);
                oled_write_P(PSTR("Layer: Game Pad      \n"), false);
                break;

            default:
                oled_write_P(PSTR("Layer: Undefined\n"), false);
                break;
        }

        // Write host Keyboard LED Status to OLEDs
        // led_t led_usb_state = host_keyboard_led_state();
        // oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        // oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        // oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on

        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 0) { /* Not Layer 0 */
        // Brightness control
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else {  /* Layer 0 */
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}
#endif

// home layer
const key_override_t del_esc_key_override = ko_make_basic(MOD_MASK_ALT, KC_DEL, KC_ESC);
const key_override_t ctrlbackspace_backspace_key_override = ko_make_basic(MOD_MASK_CS, KC_BSPC, KC_BSPC);
const key_override_t shftbackspace_backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_BSPC);
const key_override_t comma_exlam_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
const key_override_t period_question_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);

// number row
const key_override_t six_dollar_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_DLR);
const key_override_t four_star_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_ASTR);
const key_override_t two_plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_PLUS);
const key_override_t zero_unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_UNDS);
const key_override_t eight_bslsh_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_BSLS);
const key_override_t nine_at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_AT);
const key_override_t one_and_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_AMPR);
const key_override_t three_hash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_HASH);
const key_override_t five_carrot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_CIRC);
const key_override_t seven_perc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_PERC);

// shortcuts
const key_override_t dquote_sqoute_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUOT);
const key_override_t lcbracket_rcbracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t lparenthesis_rparenthesis_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t minus_ctrlx_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, C(KC_X));
const key_override_t lbracket_rbracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
// const key_override_t semicolon_pgup_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_PGUP);
const key_override_t slash_ctrlslash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, C(KC_SLSH));
// const key_override_t at_f2_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_F2);

// const key_override_t bslash_f5_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_F5);
const key_override_t dollar_ctry_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, C(KC_Y));
const key_override_t langle_rangle_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_RABK);
const key_override_t colon_semic_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
// const key_override_t underscore_ctrlf_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, C(KC_F));
// const key_override_t pipe_ctrlw_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, C(KC_W));
// const key_override_t ranglebracket_pgdn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RABK, KC_PGDN);
// const key_override_t perc_f12_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_F12);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &del_esc_key_override,
    &ctrlbackspace_backspace_key_override,
    &shftbackspace_backspace_key_override,
    &comma_exlam_key_override,
    &period_question_key_override,

    &six_dollar_key_override,
    &four_star_key_override,
    &two_plus_key_override,
    &zero_unds_key_override,
    &eight_bslsh_key_override,
    &nine_at_key_override,
    &one_and_key_override,
    &three_hash_key_override,
    &five_carrot_key_override,
    &seven_perc_key_override,

    &dquote_sqoute_key_override,
    &lcbracket_rcbracket_key_override,
    &lparenthesis_rparenthesis_key_override,
    &minus_ctrlx_key_override,
    &lbracket_rbracket_key_override,
    // &semicolon_pgup_key_override,
    &slash_ctrlslash_key_override,
    // &at_f2_key_override,

    // &bslash_f5_key_override,
    &dollar_ctry_key_override,
    &langle_rangle_key_override,
    &colon_semic_key_override
    // &underscore_ctrlf_key_override,
    // &pipe_ctrlw_key_override,
    // &ranglebracket_pgdn_key_override,
    // &perc_f12_key_override,
};


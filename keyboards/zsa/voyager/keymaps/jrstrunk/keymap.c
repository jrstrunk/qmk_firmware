#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_DELETE,      KC_6,           KC_4,           KC_2,           KC_0,           KC_8,                                           KC_9,           KC_1,           KC_3,           KC_5,           KC_7,           KC_BSPC,        
    KC_TAB,         KC_V,           KC_W,           KC_D,           KC_C,           KC_B,                                           KC_Y,           KC_F,           KC_U,           KC_P,           KC_K,           RCTL(KC_BSPC),  
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_M,           KC_N,           KC_E,           KC_O,           KC_I,           KC_HOME,        
    KC_LEFT_CTRL,   KC_Q,           LCTL(KC_C),     LCTL(KC_V),     KC_R,           KC_Z,                                           KC_J,           KC_L,           KC_COMMA,       KC_DOT,         KC_X,           KC_END,         
                                                    KC_SPACE,       OSL(2),                                         OSL(1),         MT(MOD_RSFT, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_GRAVE,                                       KC_PLUS,        KC_PIPE,        KC_COLN,        KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT, 
    KC_TAB,         KC_LCBR,        KC_LPRN,        KC_UNDS,        LCTL(KC_X),     KC_LBRC,                                        KC_PAGE_UP,     LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), RCTL(KC_SLASH), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BSLS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TILD,        KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, OSM(MOD_LSFT),                                  TO(0),          KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    TO(4),          KC_6,           KC_4,           KC_2,           KC_0,           KC_8,                                           KC_TRANSPARENT, ST_MACRO_0,     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, 
    KC_ESCAPE,      KC_V,           KC_W,           KC_D,           KC_C,           KC_B,                                           KC_TRANSPARENT, LCTL(KC_GRAVE), LCTL(KC_P),     LCTL(LSFT(KC_P)),KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TAB,         KC_A,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_TRANSPARENT, OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),  OSM(MOD_RGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_TRANSPARENT, KC_TRANSPARENT, KC_R,           KC_Z,                                           KC_TRANSPARENT, RCTL(KC_Y),     RCTL(KC_S),     RCTL(KC_Z),     KC_F2,          KC_TRANSPARENT, 
                                                    KC_SPACE,       TO(0),                                          OSL(3),         KC_ENTER
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_9,           KC_1,           KC_3,           KC_5,           KC_7,           KC_BSPC,        
    KC_TRANSPARENT, KC_F5,          KC_F12,         KC_LEFT_GUI,    LCTL(KC_X),     KC_TRANSPARENT,                                 KC_Y,           KC_F,           KC_U,           KC_P,           KC_K,           KC_BSPC,        
    KC_TAB,         OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  KC_TRANSPARENT,                                 KC_M,           KC_N,           KC_E,           KC_O,           KC_I,           KC_HOME,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_J,           KC_L,           KC_COMMA,       KC_DOT,         KC_X,           KC_END,         
                                                    KC_SPACE,       TO(0),                                          KC_TRANSPARENT, KC_ENTER
  ),
  [4] = LAYOUT_voyager(
    TO(0),          TOGGLE_LAYER_COLOR,RGB_SLD,        RGB_SPD,        RGB_SPI,        KC_TRANSPARENT,                                 KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          
    KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT,                                 KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_ENTER), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_RSFT, KC_ENTER), KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_PIPE, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_LCBR, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo4[] = { OSM(MOD_LSFT), KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_SPACE, KC_LEFT_SHIFT, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_SPACE, KC_TAB, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_COLN, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo8[] = { OSM(MOD_LSFT), KC_LPRN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_QUES),
    COMBO(combo1, KC_EXLM),
    COMBO(combo2, KC_ASTR),
    COMBO(combo3, KC_RCBR),
    COMBO(combo4, KC_RBRC),
    COMBO(combo5, LALT(KC_TAB)),
    COMBO(combo6, LALT(KC_TAB)),
    COMBO(combo7, KC_SCLN),
    COMBO(combo8, KC_RPRN),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {192,255,255}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {16,255,191}, {0,255,190} },

    [1] = { {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {16,255,191}, {0,243,196}, {16,255,191} },

    [2] = { {0,243,196}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {192,255,255}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,243,196}, {0,255,190}, {93,255,255}, {93,255,255}, {93,255,255}, {93,255,255}, {0,255,190}, {0,255,190}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,255,190}, {0,255,190}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,255,190}, {0,255,190}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,255,190}, {192,255,255}, {0,255,190} },

    [3] = { {0,255,190}, {0,255,190}, {0,255,190}, {93,255,255}, {0,255,190}, {0,255,190}, {0,255,190}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,255,190}, {0,255,190}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,243,196}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {0,255,190}, {42,255,255}, {0,255,190} },

    [4] = { {0,243,196}, {0,0,0}, {0,0,0}, {0,241,190}, {0,241,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_1));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_2));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}



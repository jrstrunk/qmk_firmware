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
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_LEFT_CTRL,   KC_6,           KC_4,           KC_2,           KC_0,           KC_8,                                           KC_9,           KC_1,           KC_3,           KC_5,           KC_7,           KC_BSPC,        
    KC_DELETE,      KC_V,           KC_COLN,        KC_UNDS,        KC_C,           KC_B,                                           KC_Y,           KC_F,           KC_COMMA,       KC_DOT,         KC_K,           RCTL(KC_BSPC),  
    KC_TAB,         KC_A,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_M,           KC_N,           KC_E,           KC_O,           KC_I,           KC_HOME,        
    KC_LEFT_SHIFT,  KC_Q,           KC_W,           KC_D,           KC_R,           KC_J,                                           KC_Z,           KC_L,           KC_U,           KC_P,           KC_X,           KC_END,         
                                                    KC_SPACE,       OSL(2),                                         TO(1),          MT(MOD_RSFT, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    ST_MACRO_0,     KC_AT,          KC_LABK,        KC_RABK,        KC_EQUAL,       KC_GRAVE,                                       KC_PAGE_UP,     KC_AMPR,        KC_PIPE,        KC_MINUS,       KC_HASH,        ST_MACRO_3,     
    ST_MACRO_1,     KC_PLUS,        LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_X),     KC_TILD,                                        KC_PGDN,        LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), RCTL(KC_SLASH), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ASTR,        KC_CIRC,        KC_DLR,         KC_SLASH,       KC_TRANSPARENT,                                 KC_SCLN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_BSLS,        KC_TRANSPARENT, 
                                                    ST_MACRO_2,     OSL(2),                                         TO(0),          ST_MACRO_4
  ),
  [2] = LAYOUT_voyager(
    TO(4),          KC_6,           KC_4,           KC_2,           KC_0,           KC_8,                                           KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ESCAPE,      KC_V,           KC_SCLN,        KC_MINUS,       KC_C,           KC_B,                                           KC_TRANSPARENT, LCTL(KC_SLASH), LCTL(KC_P),     LCTL(LSFT(KC_P)),KC_F2,          KC_TRANSPARENT, 
    KC_TAB,         KC_A,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_TRANSPARENT, OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),  OSM(MOD_RGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_D,           KC_R,           KC_J,                                           KC_TRANSPARENT, KC_TRANSPARENT, RCTL(KC_S),     RCTL(KC_Z),     KC_F12,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          TO(3),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_9,           KC_1,           KC_3,           KC_5,           KC_7,           KC_BSPC,        
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_X),     KC_TRANSPARENT,                                 KC_Y,           KC_F,           KC_COMMA,       KC_DOT,         KC_K,           KC_BSPC,        
    KC_TAB,         OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  KC_TRANSPARENT,                                 KC_M,           KC_N,           KC_E,           KC_O,           KC_I,           KC_HOME,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F5,          ST_MACRO_5,     ST_MACRO_6,     KC_TRANSPARENT,                                 KC_Z,           KC_L,           KC_U,           KC_P,           KC_X,           KC_END,         
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TO(0),          TOGGLE_LAYER_COLOR,RGB_SLD,        RGB_SPD,        RGB_SPI,        KC_TRANSPARENT,                                 KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          
    KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_TOG,        RGB_MODE_FORWARD,KC_TRANSPARENT,                                 KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_ENTER), KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_RSFT, KC_ENTER), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_SPACE, KC_TAB, COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_RSFT, KC_ENTER), KC_UNDS, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_SPACE, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_SPACE, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_RSFT, KC_ENTER), KC_COLN, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_UNDS, KC_SPACE, COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_RSFT, KC_ENTER), KC_F, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_SPACE, KC_COLN, COMBO_END};
const uint16_t PROGMEM combo10[] = { MT(MOD_RSFT, KC_ENTER), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_SPACE, MT(MOD_RSFT, KC_ENTER), KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_SPACE, MT(MOD_RSFT, KC_ENTER), KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_EXLM),
    COMBO(combo1, KC_QUES),
    COMBO(combo2, LALT(KC_TAB)),
    COMBO(combo3, KC_LPRN),
    COMBO(combo4, KC_RPRN),
    COMBO(combo5, KC_MINUS),
    COMBO(combo6, KC_DQUO),
    COMBO(combo7, KC_LCBR),
    COMBO(combo8, KC_RCBR),
    COMBO(combo9, KC_LBRC),
    COMBO(combo10, KC_RBRC),
    COMBO(combo11, KC_QUOTE),
    COMBO(combo12, KC_SLASH),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {192,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {42,255,255}, {0,255,255} },

    [1] = { {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255}, {192,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {42,255,255}, {0,255,255}, {0,255,255} },

    [2] = { {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {192,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {93,255,255}, {93,255,255}, {93,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,0,0}, {0,0,0}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,255,255}, {192,255,255}, {192,255,255}, {0,0,0}, {192,255,255}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,0,0}, {0,0,0}, {192,255,255}, {192,255,255}, {192,255,255}, {192,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {192,255,255}, {93,255,255}, {93,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {42,255,255}, {0,0,0} },

    [4] = { {0,241,190}, {0,0,0}, {0,0,0}, {0,241,190}, {0,241,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,241,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
      layer_off(1);
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      layer_off(1);
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      layer_off(1);
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      layer_off(1);
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER));
      layer_off(1);
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_LEFT_CTRL) SS_DELAY(100) SS_TAP(X_1));
    }
    break;
    case ST_MACRO_6:
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




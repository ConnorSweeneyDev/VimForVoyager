#include QMK_KEYBOARD_H
#include "version.h"
#include "qmk-vim/src/vim.h" // MANUALLY ADDED
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_SPOTLIGHT,
  VIM_MODE_TOGGLE, // MANUALLY ADDED
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NUM,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LGUI(KC_L),     
    KC_CAPS,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MAC_SPOTLIGHT,  
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           VIM_MODE_TOGGLE /* MANUALLY ADDED */, TT(2),          
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_RIGHT_CTRL,  KC_RIGHT_ALT,   KC_RIGHT_SHIFT, KC_RIGHT_GUI,   
                                                    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_ENTER),                                LT(1,KC_TAB),   MT(MOD_LALT, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_INSERT,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_LBRC,        KC_RBRC,        KC_UP,          KC_MINUS,       KC_EQUAL,       KC_GRAVE,       
    KC_ESCAPE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,                                           KC_QUOTE,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_SCLN,        KC_SLASH,       
    KC_LEFT_GUI,    KC_HOME,        KC_END,         KC_DELETE,      KC_PGDN,        KC_PAGE_UP,                                     KC_COMMA,       KC_DOT,         KC_RIGHT_CTRL,  KC_RIGHT_ALT,   KC_RIGHT_SHIFT, KC_BSLS,        
                                                    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_ENTER),                                KC_TRANSPARENT, MT(MOD_LALT, KC_BSPC)
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255} },

    [1] = { {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255} },

    [2] = { {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,0,128}, {0,255,255} },

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_vim_mode(keycode, record)) { //
    return false;                           // MANUALLY ADDED
  }                                         //

  switch (keycode) {
    case VIM_MODE_TOGGLE:        //
    if (record->event.pressed) { //
      toggle_vim_mode();         // MANUALLY ADDED
    }                            //
    return false;                //

    case MAC_SPOTLIGHT:
      HCS(0x221);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}




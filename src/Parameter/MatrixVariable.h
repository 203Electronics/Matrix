#ifndef MATRIX_VARIABLE
#define MATRIX_VARIABLE

#include <Arduino.h>
#include <FastLED.h>
#include "../Parameter/MatrixParameter.h"

//enum Modes {Normal, Fn, Animation, Boot, Ascii, App};
//DeviceSetting
extern u8 device_id; //0~255 0 for off
//extern char serial_number[25]; 
//extern Modes mode;
extern u8 current_keymap;
//extern u8 appID;
extern u8 bootAnimationSelector;
extern bool unipad_mode;
extern bool debug_mode;
extern bool fn_hold;
extern bool pro_input_mode;
extern u16 ui_fps;
extern u16 ui_fps_micros;

//LED setting
extern u8 brightness;
extern u16 max_mAh;
extern u8 brightness_level[8];
extern u16 fps;
extern u16 fps_micros;
extern u32 led_color_temperture;
extern bool desaturated_mode;
extern u8 desaturate_rate;

extern const CRGB pre_compilled_palette[2][128];
extern CRGB palette[4][128];

extern u8 color_correction_table[4][256];
extern u8 color_desaturate_table[256];
extern u8 low_brightness_table[256];
extern const u8 led_gamma[256];
//KeyPad
extern u16 keypad_scanrate;
extern u16 keypad_scanrate_micros;
extern u32 keymap_color[5];
extern u8 keymap [5][YSIZE][XSIZE];
extern u8 bottom_led_map [5][NUM_BOTTOM_LEDS];
extern u8 fn_keymap[5][2][XSIZE];
extern u32 fn_keymap_idle_color[5][2][XSIZE];
extern u32 fn_keymap_active_color[5][2][XSIZE];
extern u8 keymap_fn [5];
extern float velocity_threshold;
extern float aftertouch_threshold;
extern u16 debounce_threshold;

extern const u8 user1_keymap_optimized[64];

//TouchBar
extern bool touch_enable;
extern u8 touch_mode;
extern u8 touch_keymap[5][8];

//Sysex
extern u8 rotation;
extern u8 midi_channel;
extern bool gamma_enable; //Wont effect color palette
extern bool midi_enable;
extern bool m2p_enable;
extern bool powercord_enable;
extern bool midi_return;
extern bool midi_serial;
extern u8 stfu;

extern u8 cW;
extern u8 cR;
extern u8 cG;
extern u8 cB;

extern u8 report_code[10];
extern u8 available_report_code;

extern const u8 font[96][6];
extern const u8 half_height_num_font[10][3];

#endif

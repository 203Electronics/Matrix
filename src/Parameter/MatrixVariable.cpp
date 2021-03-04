#include "../Parameter/MatrixVariable.h"

//DeviceInfo
extern u8 device_id = 0; //0~255 0 for off
//extern Modes current_mode                                             = Normal;
extern u8 current_keymap = 0;
//extern u8 app_id                                                      = 0;
extern u8 bootAnimationSelector = 1; // 0 for off, 1 for kaskobi
extern bool unipad_mode = false;
extern bool debug_mode = false;
extern bool fn_hold = false;
extern bool pro_input_mode = false;
extern u16 ui_fps = 60;
extern u16 ui_fps_micros = 1000 / ui_fps; //Well I just realize that it's still mill not micro. TODO
//LED setting
extern u8 brightness = 128;
extern u16 max_mAh = 1000;
extern u8 brightness_level[8] = {8, 12, 24, 40, 64, 90, 128, 168};
extern u32 led_color_temperture = 0xFFFFFFFF;
extern bool desaturated_mode = false;
extern u8 desaturate_rate = 80; // 0~255
extern u16 fps = 120;
extern u16 fps_micros = 1000 / fps; //Well I just realize that it's still mill not micro. TODO

extern u16 keypad_scanrate = 120;
extern u16 keypad_scanrate_micros = 1000 / keypad_scanrate;

extern const CRGB pre_compilled_palette[2][128] = //color Palette
    {{
         //MatrixcolorPalette (Mat1s' Palette for now)
         0x00000000, //0
         0x003C0000, //1
         0x007D0000, //2
         0x00BE0000, //3
         0x00FF7D7D, //4
         0x00FF0000, //5
         0x003C0C00, //6
         0x007D1C00, //7
         0x00BE2C00, //8
         0x00FF9D7D, //9
         0x00FF3C00, //10
         0x003C1C00, //11
         0x007D3C00, //12
         0x00BE5D00, //13
         0x00FFBE7D, //14
         0x00FF7D00, //15
         0x003C2C00, //16
         0x007D5D00, //17
         0x00BE8D00, //18
         0x00FFDE7D, //19
         0x00FFBE00, //20
         0x003C3C00, //21
         0x007D7D00, //22
         0x00BEBE00, //23
         0x00FFFF7D, //24
         0x00FFFF00, //25
         0x002C3C00, //26
         0x005D7D00, //27
         0x008DBE00, //28
         0x00DEFF7D, //29
         0x00BEFF00, //30
         0x001C3C00, //31
         0x003C7D00, //32
         0x005DBE00, //33
         0x00BEFF7D, //34
         0x007DFF00, //35
         0x000C3C00, //36
         0x001C7D00, //37
         0x002CBE00, //38
         0x009DFF7D, //39
         0x003CFF00, //40
         0x00003C00, //41
         0x00007D00, //42
         0x0000BE00, //43
         0x007DFF7D, //44
         0x0000FF00, //45
         0x00003C0C, //46
         0x00007D1C, //47
         0x0000BE2C, //48
         0x007DFF9D, //49
         0x0000FF3C, //50
         0x00003C1C, //51
         0x00007D3C, //52
         0x0000BE5D, //53
         0x007DFFBE, //54
         0x0000FF7D, //55
         0x00003C2C, //56
         0x00007D5D, //57
         0x0000BE8D, //58
         0x007DFFDE, //59
         0x0000FFBE, //60
         0x00003C3C, //61
         0x00007D7D, //62
         0x0000BEBE, //63
         0x007DFFFF, //64
         0x0000FFFF, //65
         0x00002C3C, //66
         0x00005D7D, //67
         0x00008DBE, //68
         0x007DDEFF, //69
         0x0000BEFF, //70
         0x00001C3C, //71
         0x00003C7D, //72
         0x00005DBE, //73
         0x007DBEFF, //74
         0x00007DFF, //75
         0x00000C3C, //76
         0x00001C7D, //77
         0x00002CBE, //78
         0x007D9DFF, //79
         0x00003CFF, //80
         0x0000003C, //81
         0x0000007D, //82
         0x000000BE, //83
         0x007D7DFF, //84
         0x000000FF, //85
         0x000C003C, //86
         0x001C007D, //87
         0x002C00BE, //88
         0x009D7DFF, //89
         0x003C00FF, //90
         0x001C003C, //91
         0x003C007D, //92
         0x005D00BE, //93
         0x00BE7DFF, //94
         0x007D00FF, //95
         0x002C003C, //96
         0x005D007D, //97
         0x008D00BE, //98
         0x00DE7DFF, //99
         0x00BE00FF, //100
         0x003C003C, //101
         0x007D007D, //102
         0x00BE00BE, //103
         0x00FF7DFF, //104
         0x00FF00FF, //105
         0x003C002C, //106
         0x007D005D, //107
         0x00BE008D, //108
         0x00FF7DDE, //109
         0x00FF00BE, //110
         0x003C001C, //111
         0x007D003C, //112
         0x00BE005D, //113
         0x00FF7DBE, //114
         0x00FF007D, //115
         0x003C000C, //116
         0x007D001C, //117
         0x00BE002C, //118
         0x00FF7D9D, //119
         0x00FF003C, //120
         0x00242424, //121
         0x00484848, //122
         0x006D6D6D, //123
         0x00919191, //124
         0x00B6B6B6, //125
         0x00DADADA, //126
         0x00FFFFFF, //127
     },
     {
         //LaunchpadXcolorPalette (Legacy Palette)
         0x00000000, //0
         0x003F3F3F, //1
         0x007F7F7F, //2
         0x00FFFFFF, //3
         0x00FF3F3F, //4
         0x00FF0000, //5
         0x007F0000, //6
         0x003F0000, //7
         0x00FFBF6F, //8
         0x00FF3F00, //9
         0x007F1F00, //10
         0x003F0F00, //11
         0x00FFAF2F, //12
         0x00FFFF00, //13
         0x007F7F00, //14
         0x003F3F00, //15
         0x007FFF2F, //16
         0x004FFF00, //17
         0x002F7F00, //18
         0x00173F00, //19
         0x004FFF3F, //20
         0x0000FF00, //21
         0x00007F00, //22
         0x00003F00, //23
         0x004FFF4F, //24
         0x0000FF1F, //25
         0x00007F0F, //26
         0x00003F07, //27
         0x004FFF5F, //28
         0x0000FF5F, //29
         0x00007F2F, //30
         0x00003F17, //31
         0x004FFFBF, //32
         0x0000FF9F, //33
         0x00007F4F, //34
         0x00003F27, //35
         0x004FBFFF, //36
         0x0000AFFF, //37
         0x0000577F, //38
         0x00002F3F, //39
         0x004F7FFF, //40 
         0x000057FF, //41
         0x00002F7F, //42
         0x0000173F, //43
         0x002F1FFF, //44
         0x000000FF, //45
         0x0000007F, //46
         0x0000003F, //47
         0x005F3FFF, //48
         0x002F00FF, //49
         0x0017007F, //50
         0x000F003F, //51
         0x00FF3FFF, //52
         0x00FF00FF, //53
         0x007F007F, //54
         0x003F003F, //55
         0x00FF3F6F, //56
         0x00FF004F, //57
         0x007F002F, //58
         0x003F001F, //59
         0x00FF0F00, //60
         0x009F3F00, //61
         0x007F4F00, //62
         0x002F2F00, //63
         0x00003F00, //64
         0x00003F1F, //65
         0x00001F6F, //66
         0x000000FF, //67
         0x00003F3F, //68
         0x001F00BF, //69
         0x005F3F4F, //70
         0x001F0F17, //71
         0x00FF0000, //72
         0x00BFFF2F, //73
         0x00AFEF00, //74
         0x005FFF00, //75
         0x000F7F00, //76
         0x0000FF5F, //77
         0x00009FFF, //78
         0x00002FFF, //79
         0x001F00FF, //80
         0x005F00EF, //81
         0x00AF1F7F, //82
         0x002F0F00, //83
         0x00FF2F00, //84
         0x007FDF00, //85
         0x006FFF1F, //86
         0x0000FF00, //87
         0x003FFF2F, //88
         0x005FEF6F, //89
         0x003FFFCF, //90
         0x005F8FFF, //91
         0x002F4FCF, //92
         0x006F4FDF, //93
         0x00DF1FFF, //94
         0x00FF005F, //95
         0x00FF4F00, //96
         0x00BFAF00, //97
         0x008FFF00, //98
         0x007F5F00, //99
         0x003F2F00, //100
         0x0000470F, //101
         0x000F4F1F, //102
         0x0017172F, //103
         0x00171F5F, //104
         0x005F3717, //105
         0x007F0000, //106
         0x00DF3F2F, //107
         0x00DF470F, //108
         0x00FFBF1F, //109
         0x009FDF2F, //110
         0x006FAF0F, //111
         0x0017172F, //112
         0x00DFDF6F, //113
         0x007FEF8F, //114
         0x009F9FFF, //115
         0x008F6FFF, //116
         0x003F3F3F, //117
         0x006F6F6F, //118
         0x00DFFFFF, //119
         0x009F0000, //120
         0x00370000, //121
         0x0017CF00, //122
         0x00003F00, //123
         0x00BFAF00, //124
         0x003F2F00, //125
         0x00AF4F00, //126
         0x004F0F00  //127
     }};

extern CRGB palette[4][128] = {};

extern u8 color_correction_table[4][256] = {};

extern u8 color_desaturate_table[256] = {};

extern u8 low_brightness_table[256] = {};

extern const u8 led_gamma[256] =
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
     2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5,
     5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
     10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
     17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
     25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
     37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
     51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
     69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
     90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
     115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
     144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
     177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
     215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255};

extern u8 bottom_led_map[5][NUM_BOTTOM_LEDS] = //From Upper Right and clockwise
    {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}};

//KeyPad

extern u32 keymap_color[5] = //Keymap mode color ref in fn menu
    {0x00FF00FF, 0x00FF5400, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF};

extern u8 keymap[5][YSIZE][XSIZE] =
    {{{64, 65, 66, 67, 96, 97, 98, 99}, //Drum Rack
      {60, 61, 62, 63, 92, 93, 94, 95},
      {56, 57, 58, 59, 88, 89, 90, 91},
      {52, 53, 54, 55, 84, 85, 86, 87},
      {48, 49, 50, 51, 80, 81, 82, 83},
      {44, 45, 46, 47, 76, 77, 78, 79},
      {40, 41, 42, 43, 72, 73, 74, 75},
      {36, 37, 38, 39, 68, 69, 70, 71}},
     {{81, 82, 83, 84, 85, 86, 87, 88}, //Unmapped XY
      {71, 72, 73, 74, 75, 76, 77, 78},
      {61, 62, 63, 64, 65, 66, 67, 68},
      {51, 52, 53, 54, 55, 56, 57, 58},
      {41, 42, 43, 44, 45, 46, 47, 48},
      {31, 32, 33, 34, 35, 36, 37, 38},
      {21, 22, 23, 24, 25, 26, 27, 28},
      {11, 12, 13, 14, 15, 16, 17, 18}},
     {{64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 1
      {60, 61, 62, 63, 92, 93, 94, 95},
      {56, 57, 58, 59, 88, 89, 90, 91},
      {52, 53, 54, 55, 84, 85, 86, 87},
      {48, 49, 50, 51, 80, 81, 82, 83},
      {44, 45, 46, 47, 76, 77, 78, 79},
      {40, 41, 42, 43, 72, 73, 74, 75},
      {36, 37, 38, 39, 68, 69, 70, 71}},
     {{64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 2
      {60, 61, 62, 63, 92, 93, 94, 95},
      {56, 57, 58, 59, 88, 89, 90, 91},
      {52, 53, 54, 55, 84, 85, 86, 87},
      {48, 49, 50, 51, 80, 81, 82, 83},
      {44, 45, 46, 47, 76, 77, 78, 79},
      {40, 41, 42, 43, 72, 73, 74, 75},
      {36, 37, 38, 39, 68, 69, 70, 71}},
     {{64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 3
      {60, 61, 62, 63, 92, 93, 94, 95},
      {56, 57, 58, 59, 88, 89, 90, 91},
      {52, 53, 54, 55, 84, 85, 86, 87},
      {48, 49, 50, 51, 80, 81, 82, 83},
      {44, 45, 46, 47, 76, 77, 78, 79},
      {40, 41, 42, 43, 72, 73, 74, 75},
      {36, 37, 38, 39, 68, 69, 70, 71}}};

extern u8 keymap_fn[5] = {0, 0, 0, 0, 0};

extern const u8 user1_keymap_optimized[64] =
    {0x07, 0x17, 0x27, 0x37, 0x06, 0x16, 0x26, 0x36, 0x05, 0x15, 0x25, 0x35, 0x04, 0x14, 0x24, 0x34, 0x03, 0x13, 0x23, 0x33, 0x02, 0x12, 0x22, 0x32, 0x01, 0x11, 0x21, 0x31, 0x00, 0x10, 0x20, 0x30, 0x47, 0x57, 0x67, 0x77, 0x46, 0x56, 0x66, 0x76, 0x45, 0x55, 0x65, 0x75, 0x44, 0x54, 0x64, 0x74, 0x43, 0x53, 0x63, 0x73, 0x42, 0x52, 0x62, 0x72, 0x41, 0x51, 0x61, 0x71, 0x40, 0x50, 0x60, 0x70};

extern u8 fn_keymap[5][2][XSIZE] =              //Key session in fn menu ） 255 for disable
    {{{108, 109, 110, 111, 112, 113, 114, 115}, //Mapped MK2
      {100, 101, 102, 103, 104, 105, 106, 107}},
     {{104, 105, 106, 107, 108, 109, 110, 111}, // Mapped mk2
      {89, 79, 69, 59, 49, 39, 29, 19}},
     {{108, 109, 110, 111, 112, 113, 114, 115}, //User Custom1
      {100, 101, 102, 103, 104, 105, 106, 107}},
     {{108, 109, 110, 111, 112, 113, 114, 115}, //User Custom2
      {100, 101, 102, 103, 104, 105, 106, 107}},
     {{108, 109, 110, 111, 112, 113, 114, 115}, //User Custom3
      {100, 101, 102, 103, 104, 105, 106, 107}}};

extern u32 fn_keymap_idle_color[5][2][XSIZE]{{{0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF}, //Drum Rock
                                               {0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF}},
                                              {{0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400}, //Unmapped MK2
                                               {0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400}},
                                              {{0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 1
                                               {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}},
                                              {{0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 2
                                               {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}},
                                              {{0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 3
                                               {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}}};

extern u32 fn_keymap_active_color[5][2][XSIZE]{{{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //Drum Rock
                                                 {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}},
                                                {{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //Unmapped MK2
                                                 {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}},
                                                {{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 1
                                                 {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}},
                                                {{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 2
                                                 {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}},
                                                {{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 3
                                                 {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}}};

extern float velocity_threshold = 0;
extern float aftertouch_threshold = 0;
extern u16 debounce_threshold = 24;

//TouchBar
extern bool touch_enable = true;
extern u8 touch_mode = 0;
extern u8 touch_keymap[5][8] =
    {
        {100, 101, 102, 103, 104, 105, 106, 107},
        {89, 79, 69, 59, 49, 39, 29, 19},
        {100, 101, 102, 103, 104, 105, 106, 107},
        {100, 101, 102, 103, 104, 105, 106, 107},
        {100, 101, 102, 103, 104, 105, 106, 107}};

//System
extern u8 rotation = 0;
extern u8 midi_channel = 0;
extern bool gamma_enable = false; //Wont effect color palette
extern bool midi_enable = true;
extern bool m2p_enable = false;
extern bool powercord_enable = false;
extern bool midi_return = false;
extern bool midi_serial = false;
extern u8 stfu = 1;

extern u8 report_code[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
extern u8 available_report_code = 0;

extern const u8 font[96][6] = {
    {4, 0b00000000, 0b00000000, 0b00000000, 0b00000000},             // 32              = Space
    {1, 0b11111011},                                                 // 33                                                  = !
    {3, 0b11100000, 0b00000000, 0b11100000},                         // 34                          = "
    {5, 0b00101000, 0b11111110, 0b00101000, 0b11111110, 0b00101000}, // 35  = #
    {5, 0b00100100, 0b01010100, 0b11111110, 0b01010100, 0b01001000}, // 36  = $
    {5, 0b11000100, 0b11001000, 0b00010000, 0b00100110, 0b01000110}, // 37  = %
    {5, 0b01101100, 0b10010010, 0b10010010, 0b01101100, 0b00001010}, // 38  = &
    {2, 0b00100000, 0b11000000},                                     // 39                                      = '
    {2, 0b01111100, 0b10000010},                                     // 40                                      = (
    {2, 0b10000010, 0b01111100},                                     // 41                                      = )
    {5, 0b00101000, 0b00111000, 0b01111100, 0b00111000, 0b00101000}, // 42  = *
    {5, 0b00010000, 0b00010000, 0b01111100, 0b00010000, 0b00010000}, // 43  = +
    {4, 0b00000000, 0b00000101, 0b00000110, 0b00000000},             // 44              = ,
    {4, 0b00010000, 0b00010000, 0b00010000, 0b00010000},             // 45              = -
    {4, 0b00000000, 0b00000110, 0b00000110, 0b00000000},             // 46              = .
    {5, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000}, // 47  = /
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01111100}, // 48  = 0
    {3, 0b01000010, 0b11111110, 0b00000010},                         // 49                          = 1
    {5, 0b01001110, 0b10010010, 0b10010010, 0b10010010, 0b01100010}, // 50  = 2
    {5, 0b01000100, 0b10000010, 0b10010010, 0b10010010, 0b01101100}, // 51  = 3
    {5, 0b00011000, 0b00101000, 0b01001000, 0b11111110, 0b00001000}, // 52  = 4
    {5, 0b11100100, 0b10100010, 0b10100010, 0b10100010, 0b10011100}, // 53  = 5
    {5, 0b01111100, 0b10010010, 0b10010010, 0b10010010, 0b01001100}, // 54  = 6
    {5, 0b10000000, 0b10000110, 0b10011000, 0b10100000, 0b11000000}, // 55  = 7
    {5, 0b01101100, 0b10010010, 0b10010010, 0b10010010, 0b01101100}, // 56  = 8
    {5, 0b01100100, 0b10010010, 0b10010010, 0b10010010, 0b01111100}, // 57  = 9
    {4, 0b00000000, 0b00110110, 0b00110110, 0b00000000},             // 58              = :
    {4, 0b00000000, 0b00110101, 0b00110110, 0b00000000},             // 59              = ;
    {4, 0b00010000, 0b00101000, 0b01000100, 0b10000010},             // 60              = <
    {4, 0b00101000, 0b00101000, 0b00101000, 0b00101000},             // 61              = =
    {4, 0b10000010, 0b01000100, 0b00101000, 0b00010000},             // 62              = >
    {5, 0b01000000, 0b10000000, 0b10001010, 0b10010000, 0b01100000}, // 63  = ?
    {5, 0b01111100, 0b10000010, 0b10010010, 0b10101010, 0b01111000}, // 64  = @
    {5, 0b00000110, 0b00111000, 0b11001000, 0b00111000, 0b00000110}, // 65  = A
    {5, 0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b01101100}, // 66  = B
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01000100}, // 67  = C
    {5, 0b11111110, 0b10000010, 0b10000010, 0b01000100, 0b00111000}, // 68  = D
    {5, 0b11111110, 0b10010010, 0b10010010, 0b10010010, 0b10000010}, // 69  = E
    {5, 0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b10000000}, // 70  = F
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10010010, 0b10011110}, // 71  = G
    {5, 0b11111110, 0b00010000, 0b00010000, 0b00010000, 0b11111110}, // 72  = H
    {3, 0b10000010, 0b11111110, 0b10000010},                         // 73                          = I
    {4, 0b00000100, 0b00000010, 0b10000010, 0b11111100},             // 74              = J
    {5, 0b11111110, 0b00010000, 0b00101000, 0b01000100, 0b10000010}, // 75  = K
    {5, 0b11111110, 0b00000010, 0b00000010, 0b00000010, 0b00000010}, // 76  = L
    {5, 0b11111110, 0b01000000, 0b00110000, 0b01000000, 0b11111110}, // 77  = M
    {5, 0b11111110, 0b01100000, 0b00010000, 0b00001100, 0b11111110}, // 78  = N
    {5, 0b01111100, 0b10000010, 0b10000010, 0b10000010, 0b01111100}, // 79  = O
    {5, 0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b01100000}, // 80  = P
    {5, 0b01111100, 0b10000010, 0b10001010, 0b10000100, 0b01111010}, // 81  = Q
    {5, 0b11111110, 0b10010000, 0b10011000, 0b10010100, 0b01100010}, // 82  = R
    {5, 0b01100100, 0b10110010, 0b10010010, 0b10010010, 0b01001100}, // 83  = S
    {5, 0b10000000, 0b10000000, 0b11111110, 0b10000000, 0b10000000}, // 84  = T
    {5, 0b11111100, 0b00000010, 0b00000010, 0b00000010, 0b11111100}, // 85  = U
    {5, 0b11100000, 0b00011000, 0b00000110, 0b00011000, 0b11100000}, // 86  = V
    {5, 0b11110000, 0b00001110, 0b00110000, 0b00001110, 0b11110000}, // 87  = W
    {5, 0b11000110, 0b00101000, 0b00010000, 0b00101000, 0b11000110}, // 88  = X
    {5, 0b11000000, 0b00100000, 0b00011110, 0b00100000, 0b11000000}, // 89  = Y
    {5, 0b10000110, 0b10001010, 0b10010010, 0b10100010, 0b11000010}, // 90  = Z
    {3, 0b11111110, 0b10000010, 0b10000010},                         // 91                          = [
    {5, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100}, // 92  = Backslash
    {3, 0b10000010, 0b10000010, 0b11111110},                         // 93                          = ]
    {5, 0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000}, // 94  = ^
    {5, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00000010}, // 95  = _
    {2, 0b11000000, 0b00100000},                                     // 96                                      = `
    {5, 0b00000100, 0b00101010, 0b00101010, 0b00101010, 0b00011110}, // 97  = a
    {5, 0b11111110, 0b00100010, 0b00100010, 0b00100010, 0b00011100}, // 98  = b
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00100010}, // 99  = c
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b11111110}, // 100 = d
    {5, 0b00011100, 0b00101010, 0b00101010, 0b00101010, 0b00011010}, // 101 = e
    {4, 0b00010000, 0b01111110, 0b10010000, 0b10010000},             // 102             = f
    {5, 0b00011000, 0b00100101, 0b00100101, 0b00100101, 0b00111110}, // 103 = g
    {5, 0b11111110, 0b00100000, 0b00100000, 0b00100000, 0b00011110}, // 104 = h
    {2, 0b10111100, 0b00000010},                                     // 105                                     = i
    {3, 0b00000010, 0b00000001, 0b10111110},                         // 106                         = j
    {4, 0b11111110, 0b00001000, 0b00010100, 0b00100010},             // 107             = k
    {2, 0b11111100, 0b00000010},                                     // 108                                     = l
    {5, 0b00111110, 0b00100000, 0b00011110, 0b00100000, 0b00011110}, // 109 = m
    {5, 0b00111110, 0b00100000, 0b00100000, 0b00100000, 0b00011110}, // 110 = n
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00011100}, // 111 = o
    {5, 0b00111111, 0b00100100, 0b00100100, 0b00100100, 0b00011000}, // 112 = p
    {5, 0b00011100, 0b00100010, 0b00100010, 0b00100100, 0b00111111}, // 113 = q
    {4, 0b00111110, 0b00010000, 0b00100000, 0b00100000},             // 114             = r
    {5, 0b00010010, 0b00101010, 0b00101010, 0b00101010, 0b00100100}, // 115 = s
    {3, 0b00100000, 0b01111100, 0b00100010},                         // 116                         = t
    {5, 0b00111100, 0b00000010, 0b00000010, 0b00000100, 0b00111110}, // 117 = u
    {5, 0b00110000, 0b00001100, 0b00000010, 0b00001100, 0b00110000}, // 118 = v
    {5, 0b00111000, 0b00000110, 0b00111000, 0b00000110, 0b00111000}, // 119 = w
    {5, 0b00100010, 0b00010100, 0b00001000, 0b00010100, 0b00100010}, // 120 = x
    {5, 0b00111000, 0b00000101, 0b00000101, 0b00000101, 0b00111110}, // 121 = y
    {5, 0b00100010, 0b00100110, 0b00101010, 0b00110010, 0b00100010}, // 122 = z
    {3, 0b00010000, 0b01101100, 0b10000010},                         // 123                         = {
    {1, 0b11111111},                                                 // 124                                                 = |
    {3, 0b10000010, 0b01101100, 0b00010000},                         // 125                         = }
    {
        4,
        0b01000000,
        0b10000000,
        0b01000000,
        0b10000000,
    },                                                              // 126           = ~
    {5, 0b00111000, 0b00101000, 0b01101100, 0b00101000, 0b00010000} // 127  = DEL
};

extern const u8 half_height_num_font[10][3] = {
    {B1111, B1001, B1111}, //0
    {B0000, B0000, B1111}, //1
    {B0000, B1011, B1101}, //2
    {B1001, B1101, B1111}, //3
    {B1110, B0010, B0111}, //4
    {B0000, B1101, B1011}, //5
    {B0000, B1111, B0011}, //6
    {B0000, B1000, B1111}, //7
    {B1111, B1101, B1111}, //8
    {B0000, B1100, B1111}, //9
                           //{B0000, B0000, B0000},  //space
};

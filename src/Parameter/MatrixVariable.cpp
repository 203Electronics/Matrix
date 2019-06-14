#include "../Parameter/MatrixVariable.h"

//DeviceInfo
extern u8 device_id = 0; //0~255 0 for off
//extern Modes current_mode = Normal;
extern u8 current_keymap = 0;
//extern u8 app_id = 0;
extern u8 bootAnimationSelector = 1; // 0 for off, 1 for kaskobi
extern bool unipad_mode = false;
extern bool debug_mode = false;
extern bool fn_hold = false;
//LED setting
extern u8 brightness = 128;
extern u16 max_mAh = 1000;
extern u8 brightness_level[8] = {16,32,64,96,128,160,216,255};
extern u8 fps = 60;
extern u32 led_color_temperture = 0xFFFFFFFF;

extern u16 fps_micros = 1000 / fps;

extern u8 keypad_scanrate = 50;
extern u16 keypad_scanrate_micros = 1000 / keypad_scanrate;

extern u32 palette[4][128] =     //WRGB Colour Palette
{{            //MatrixColorPalette
  0x00000000, //0
  0x00050505, //1
  0x00101010, //2
  0x00242424, //3
  0x004E4E4E, //4
  0x00727272, //5
  0x00AFAFAF, //6
  0x00FFFFFF, //7
  0x00130000, //8
  0x00270000, //9
  0x005D0000, //10
  0x00A20000, //11
  0x00FF0000, //12
  0x00FF0C0C, //13
  0x00FF1F1F, //14
  0x00FF3F3F, //15
  0x00130500, //16
  0x00270A00, //17
  0x005D1700, //18
  0x00A22900, //19
  0x00FF4000, //20
  0x00FF490C, //21
  0x00FF571F, //22
  0x00FF6F3F, //23
  0x00130A00, //24
  0x00271400, //25
  0x005D2F00, //26
  0x00A25100, //27
  0x00FF8000, //28
  0x00FF860C, //29
  0x00FF8F1F, //30
  0x00FF9F3F, //31
  0x00130E00, //32
  0x00271D00, //33
  0x005D4600, //34
  0x00A27A00, //35
  0x00FFBF00, //36
  0x00FFC20C, //37
  0x00FFC71F, //38
  0x00FFCF3F, //39
  0x00131300, //40
  0x00272700, //41
  0x005D5D00, //42
  0x00A2A200, //43
  0x00FFFF00, //44
  0x00FFFF0C, //45
  0x00FFFF1F, //46
  0x00FFFF3F, //47
  0x000A1300, //48
  0x00142700, //49
  0x002F5D00, //50
  0x0051A200, //51
  0x0080FF00, //52
  0x0086FF0C, //53
  0x008FFF1F, //54
  0x009FFF3F, //55
  0x00001300, //56
  0x00002700, //57
  0x00005D00, //58
  0x0000A200, //59
  0x0000FF00, //60
  0x000CFF0C, //61
  0x001FFF1F, //62
  0x003FFF3F, //63
  0x0000130D, //64
  0x0000271A, //65
  0x00005D3E, //66
  0x0000A26C, //67
  0x0000FFAA, //68
  0x000CFFAE, //69
  0x001FFFB4, //70
  0x003FFFBF, //71
  0x00001113, //72
  0x00002727, //73
  0x00005D5D, //74
  0x0000A2A2, //75
  0x0000FFFF, //76
  0x000CFFFF, //77
  0x001FFFFF, //78
  0x003FFFFF, //79
  0x00000A13, //80
  0x00001427, //81
  0x00002F5D, //82
  0x000051A2, //83
  0x000080FF, //84
  0x000C86FF, //85
  0x001F8FFF, //86
  0x003F9FFF, //87
  0x00000013, //88
  0x00000027, //89
  0x0000005D, //90
  0x000000A2, //91
  0x000000FF, //92
  0x000C0CFF, //93
  0x001F1FFF, //94
  0x003F3FFF, //95
  0x000A0013, //96
  0x00140027, //97
  0x002F005D, //98
  0x005100A2, //99
  0x008000FF, //100
  0x00860CFF, //101
  0x008F1FFF, //102
  0x009F3FFF, //103
  0x00130013, //104
  0x00270027, //105
  0x005D005D, //106
  0x00A200A2, //107
  0x00FF00FF, //108
  0x00FF0CFF, //109
  0x00FF1FFF, //110
  0x00FF3F9F, //111
  0x0013000A, //112
  0x00270014, //113
  0x005D002F, //114
  0x00A20051, //115
  0x00FF0080, //116
  0x00FF0C86, //117
  0x00FF1F8F, //118
  0x00FF3F9F, //119
  0x00130005, //120
  0x0027000A, //121
  0x005D0017, //122
  0x00A20029, //123
  0x00FF0040, //124
  0x00FF0C49, //125
  0x00FF1F57, //126
  0x00FF3F6F  //127
},{           //LaunchpadColorPalette
  0x00000000, //0
  0x00606060, //1
  0x00B0B0B0, //2
  0x00FFFFFF, //3
  0x00FF4848, //4
  0x00FF0000, //5
  0x007D0000, //6
  0x003C0000, //7
  0x00FFBA69, //8
  0x00FF4400, //9
  0x00C23000, //10
  0x00401000, //11
  0x00FFA524, //12
  0x00FFFF00, //13
  0x00BEBE00, //14
  0x00616100, //15
  0x0085FF40, //16
  0x0050FF00, //17
  0x00307900, //18
  0x00205900, //19
  0x0048FF48, //20
  0x0000FF00, //21
  0x00007D00, //22
  0x00003C00, //23
  0x0048FF5D, //24
  0x0000FF18, //25
  0x0000710C, //26
  0x0000590C, //27
  0x003CFF3C, //28
  0x0000FF55, //29
  0x00007D20, //30
  0x00003C1C, //31
  0x0048FFFF, //32
  0x0000FF95, //33
  0x00006134, //34
  0x00004030, //35
  0x0059C2FF, //36
  0x003CE2FF, //37
  0x00006171, //38
  0x00003861, //39
  0x004885FF, //40
  0x000055FF, //41
  0x00003479, //42
  0x00001C3C, //43
  0x003020FF, //44
  0x000000FF, //45
  0x0000007D, //46
  0x0000003C, //47
  0x008548FF, //48
  0x002C00FF, //49
  0x00140071, //50
  0x00100038, //51
  0x00FF48FF, //52
  0x00FF00FF, //53
  0x005D005D, //54
  0x003C003C, //55
  0x00FF4885, //56
  0x00FF0048, //57
  0x005D001C, //58
  0x00300010, //59
  0x00FF1400, //60
  0x00953400, //61
  0x00755000, //62
  0x00204004, //63
  0x00003800, //64
  0x00005534, //65
  0x0000507D, //66
  0x000000FF, //67
  0x0000444C, //68
  0x002400CA, //69
  0x007D7D7D, //70
  0x001C1C1C, //71
  0x00FF0000, //72
  0x00BAFF2C, //73
  0x00AEEA04, //74
  0x0061FF08, //75
  0x000C8900, //76
  0x0000FF85, //77
  0x0000A5FF, //78
  0x000028FF, //79
  0x003C00FF, //80
  0x007900FF, //81
  0x00AE1879, //82
  0x003C2000, //83
  0x00FF4800, //84
  0x0085DE04, //85
  0x0071FF14, //86
  0x0000FF00, //87
  0x0038FF24, //88
  0x0055FF6D, //89
  0x0034FFCA, //90
  0x005989FF, //91
  0x003050C2, //92
  0x00857DE6, //93
  0x00D21CFF, //94
  0x00FF0059, //95
  0x00FF7D00, //96
  0x00B6AE00, //97
  0x008DFF00, //98
  0x00815904, //99
  0x00382800, //100
  0x0010480C, //101
  0x000C4C34, //102
  0x00141428, //103
  0x00141C59, //104
  0x00653818, //105
  0x00A50008, //106
  0x00DA503C, //107
  0x00D66918, //108
  0x00FFDE24, //109
  0x009DDE2C, //110
  0x0065B20C, //111
  0x001C1C2C, //112
  0x00DAFF69, //113
  0x007DFFBA, //114
  0x009995FF, //115
  0x008D65FF, //116
  0x003C3C3C, //117
  0x00717171, //118
  0x00DEFFFF, //119
  0x009D0000, //120
  0x00340000, //121
  0x0018CE00, //122
  0x00044000, //123
  0x00B6AE00, //124
  0x003C3000, //125
  0x00B25D00, //126
  0x00481400  //127
},{           //Custom Colour palette，Mat1's Palette for now
  0x00000000, //0
  0x003C0000, //1
  0x007D0000, //2
  0x00BE0000, //3
  0x00FF7D7D, //4
  0x00FF0000, //5
  0x003C000C, //6
  0x007D001C, //7
  0x00BE002C, //8
  0x00FF7D9D, //9
  0x00FF003C, //10
  0x003C001C, //11
  0x007D003C, //12
  0x00BE005D, //13
  0x00FF7DBE, //14
  0x00FF007D, //15
  0x003C002C, //16
  0x007D005D, //17
  0x00BE008D, //18
  0x00FF7DDE, //19
  0x00FF00BE, //20
  0x003C003C, //21
  0x007D007D, //22
  0x00BE00BE, //23
  0x00FF7DFF, //24
  0x00FF00FF, //25
  0x002C003C, //26
  0x005D007D, //27
  0x008D00BE, //28
  0x00DE7DFF, //29
  0x00BE00FF, //30
  0x001C003C, //31
  0x003C007D, //32
  0x005D00BE, //33
  0x00BE7DFF, //34
  0x007D00FF, //35
  0x000C003C, //36
  0x001C007D, //37
  0x002C00BE, //38
  0x009D7DFF, //39
  0x003C00FF, //40
  0x0000003C, //41
  0x0000007D, //42
  0x000000BE, //43
  0x007D7DFF, //44
  0x000000FF, //45
  0x00000C3C, //46
  0x00001C7D, //47
  0x00002CBE, //48
  0x007D9DFF, //49
  0x00003CFF, //50
  0x00001C3C, //51
  0x00003C7D, //52
  0x00005DBE, //53
  0x007DBEFF, //54
  0x00007DFF, //55
  0x00002C3C, //56
  0x00005D7D, //57
  0x00008DBE, //58
  0x007DDEFF, //59
  0x0000BEFF, //60
  0x00003C3C, //61
  0x00007D7D, //62
  0x0000BEBE, //63
  0x007DFFFF, //64
  0x0000FFFF, //65
  0x00003C2C, //66
  0x00007D5D, //67
  0x0000BE8D, //68
  0x007DFFDE, //69
  0x0000FFBE, //70
  0x00003C1C, //71
  0x00007D3C, //72
  0x0000BE5D, //73
  0x007DFFBE, //74
  0x0000FF7D, //75
  0x00003C0C, //76
  0x00007D1C, //77
  0x0000BE2C, //78
  0x007DFF9D, //79
  0x0000FF3C, //80
  0x00003C00, //81
  0x00007D00, //82
  0x0000BE00, //83
  0x007DFF7D, //84
  0x0000FF00, //85
  0x000C3C00, //86
  0x001C7D00, //87
  0x002CBE00, //88
  0x009DFF7D, //89
  0x003CFF00, //90
  0x001C3C00, //91
  0x003C7D00, //92
  0x005DBE00, //93
  0x00BEFF7D, //94
  0x007DFF00, //95
  0x002C3C00, //96
  0x005D7D00, //97
  0x008DBE00, //98
  0x00DEFF7D, //99
  0x00BEFF00, //100
  0x003C3C00, //101
  0x007D7D00, //102
  0x00BEBE00, //103
  0x00FFFF7D, //104
  0x00FFFF00, //105
  0x003C2C00, //106
  0x007D5D00, //107
  0x00BE8D00, //108
  0x00FFDE7D, //109
  0x00FFBE00, //110
  0x003C1C00, //111
  0x007D3C00, //112
  0x00BE5D00, //113
  0x00FFBE7D, //114
  0x00FF7D00, //115
  0x003C0C00, //116
  0x007D1C00, //117
  0x00BE2C00, //118
  0x00FF9D7D, //119
  0x00FF3C00, //120
  0x00242424, //121
  0x00484848, //122
  0x006D6D6D, //123
  0x00919191, //124
  0x00B6B6B6, //125
  0x00DADADA, //126
  0x00FFFFFF  //127
}};

extern u8 led_gamma[256] =
{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
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
  215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

extern u8 bottom_led_map [5][NUM_BOTTOM_LEDS] =
{
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35},
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35},
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35},
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35},
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35}
};


//KeyPad

extern u32 keymap_colour[5] = //Keymap mode color ref in fn menu
{0x00FF00FF, 0x00FF5400, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF};

extern u8 keymap [5][YSIZE][XSIZE] =
{{{64, 65, 66, 67, 96, 97, 98, 99}, //Drum Rock
{60, 61, 62, 63, 92, 93, 94, 95},
{56, 57, 58, 59, 88, 89, 90, 91},
{52, 53, 54, 55, 84, 85, 86, 87},
{48, 49, 50, 51, 80, 81, 82, 83},
{44, 45, 46, 47, 76, 77, 78, 79},
{40, 41, 42, 43, 72, 73, 74, 75},
{36, 37, 38, 39, 68, 69, 70, 71}
},{
  {81, 82, 83, 84, 85, 86, 87, 88}, //unmapped XY
  {71, 72, 73, 74, 75, 76, 77, 78},
  {61, 62, 63, 64, 65, 66, 67, 68},
  {51, 52, 53, 54, 55, 56, 57, 58},
  {41, 42, 43, 44, 45, 46, 47, 48},
  {31, 32, 33, 34, 35, 36, 37, 38},
  {21, 22, 23, 24, 25, 26, 27, 28},
  {11, 12, 13, 14, 15, 16, 17, 18}
},{
  {64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 1
  {60, 61, 62, 63, 92, 93, 94, 95},
  {56, 57, 58, 59, 88, 89, 90, 91},
  {52, 53, 54, 55, 84, 85, 86, 87},
  {48, 49, 50, 51, 80, 81, 82, 83},
  {44, 45, 46, 47, 76, 77, 78, 79},
  {40, 41, 42, 43, 72, 73, 74, 75},
  {36, 37, 38, 39, 68, 69, 70, 71}
},{
  {64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 2
  {60, 61, 62, 63, 92, 93, 94, 95},
  {56, 57, 58, 59, 88, 89, 90, 91},
  {52, 53, 54, 55, 84, 85, 86, 87},
  {48, 49, 50, 51, 80, 81, 82, 83},
  {44, 45, 46, 47, 76, 77, 78, 79},
  {40, 41, 42, 43, 72, 73, 74, 75},
  {36, 37, 38, 39, 68, 69, 70, 71}
},{
  {64, 65, 66, 67, 96, 97, 98, 99}, //User Custom 3
  {60, 61, 62, 63, 92, 93, 94, 95},
  {56, 57, 58, 59, 88, 89, 90, 91},
  {52, 53, 54, 55, 84, 85, 86, 87},
  {48, 49, 50, 51, 80, 81, 82, 83},
  {44, 45, 46, 47, 76, 77, 78, 79},
  {40, 41, 42, 43, 72, 73, 74, 75},
  {36, 37, 38, 39, 68, 69, 70, 71}
}};

extern u8 keymap_fn [5] = {0, 0, 0, 0, 0};

extern u8 user1_keymap_optimized[64] =
{0x07, 0x17, 0x27, 0x37, 0x06, 0x16, 0x26, 0x36, 0x05, 0x15, 0x25, 0x35, 0x04, 0x14, 0x24, 0x34, 0x03, 0x13, 0x23, 0x33, 0x02, 0x12, 0x22, 0x32, 0x01, 0x11, 0x21, 0x31, 0x00, 0x10, 0x20, 0x30, 0x47, 0x57, 0x67, 0x77, 0x46, 0x56, 0x66, 0x76, 0x45, 0x55, 0x65, 0x75, 0x44, 0x54, 0x64, 0x74, 0x43, 0x53, 0x63, 0x73, 0x42, 0x52, 0x62, 0x72, 0x41, 0x51, 0x61, 0x71, 0x40, 0x50, 0x60, 0x70};



extern u8 fn_keymap[5][2][XSIZE] = //Key session in fn menu ） 255 for disable
{{{108, 109, 110, 111, 112, 113, 114, 115}, //Mapped MK2
{100, 101, 102, 103, 104, 105, 106, 107}
},{
  {104, 105, 106, 107, 108, 109, 110, 111}, // mapped mk2
  {89, 79, 69, 59, 49, 39, 29, 19}
},{
  {108, 109, 110, 111, 112, 113, 114, 115}, //User Custom1
  {100, 101, 102, 103, 104, 105, 106, 107}
},{
  {108, 109, 110, 111, 112, 113, 114, 115}, //User Custom2
  {100, 101, 102, 103, 104, 105, 106, 107}
},{
  {108, 109, 110, 111, 112, 113, 114, 115}, //User Custom3
  {100, 101, 102, 103, 104, 105, 106, 107}
}};

extern u32 fn_keymap_idle_color[5][2][XSIZE]
{{{0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF}, //Drum Rock
{0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF}
},{
  {0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400}, //Unmapped MK2
  {0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400, 0x00FF5400}
},{
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 1
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}
},{
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 2
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}
},{
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}, //User custom 3
  {0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040, 0x00404040}
}};

extern u32 fn_keymap_active_color[5][2][XSIZE]
{{{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //Drum Rock
{0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}
},{
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //Unmapped MK2
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}
},{
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 1
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}
},{
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 2
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}
},{
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}, //User Custom 3
  {0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF}
}};

extern float velocity_threshold = 0;
extern float aftertouch_threshold = 0;


//TouchBar
extern s16 touch_threshold = 60;
extern u8 touch_keymap[5][8] =
{
  {100, 101, 102, 103, 104, 105, 106, 107},
  {89, 79, 69, 59, 49, 39, 29, 19},
  {100, 101, 102, 103, 104, 105, 106, 107},
  {100, 101, 102, 103, 104, 105, 106, 107},
  {100, 101, 102, 103, 104, 105, 106, 107}
};



//System
extern u8 rotation = 0;
extern u8 midi_channel = 0;
extern bool gamma_enable = false; //Wont effect colour palette
extern bool midi_enable = true;
extern bool m2p_enable = false;
extern bool powercord_enable = false;
extern bool massage_return = false;
extern u8 stfu = 2;

extern u8 cW = 255;
extern u8 cR = 255;
extern u8 cG = 255;
extern u8 cB = 255;

extern u8 report_code[10] = {1,1,1,1,1,1,1,1,1,1};
extern u8 available_report_code = 0;

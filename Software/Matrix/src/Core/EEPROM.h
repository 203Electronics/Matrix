#ifndef EEPROM_H
#define EEPROM_H

#include "../Parameter/MatrixVariable.h"
#include "../Parameter/MatrixParameter.h"
#include <EEPROM.h>

extern EEPROMClass EEPROM_USER;
extern EEPROMClass EEPROM_PALETTE;
extern EEPROMClass EEPROM_SYS;

void setupEEPROM();

void variableLoad();

void loadSetting();
void loadKeyMap();
void loadPalette();

void initEEPROM();
void saveSetting();
void saveKeyMap();
void savePalette();

enum EEPROM_USER_MAP
{
  E_INIT = 0,
  E_DEVICE_ID = 1,
  E_ROTATION = 2,
  E_BRIGHTNESS = 3,
  E_MAX_MA = 4,
  E_FPS = 5,
  E_GAMMA_ENABLE = 6,
  E_MIDI_ENABLE = 7,
  E_M2P_ENABLE = 8,
  E_RETURN_ENABLE = 9,
  E_UNIPAD_MODE = 10,
  E_BOOTANIMATION = 11,
  E_DEBUG_ENABLE = 12,
  E_CURRENT_KEYMAP = 13,

  //RESERVED 13~127
  E_CUSTOM_KEYMAP_1 = 128,//32 128~159 //2x8
  E_CUSTOM_FN_KEYMAP_1 = 160, //8 160~167
  E_CUSTOM_BOTTOM_KEYMAP_1 = 168,//18 168~185
  E_CUSTOM_KEYMAP_1_COLOR = 186, //2 186~187
  E_CUSTOM_KEYMAP_1_IDLE = 188, //32 188~219
  E_CUSTOM_KEYMAP_1_ACTIVE = 220, //32 220~251
  //RESERVED 252~255
  E_CUSTOM_KEYMAP_2 = 256,//32 256~288
  E_CUSTOM_FN_KEYMAP_2 = 288, //8 288~295
  E_CUSTOM_BOTTOM_KEYMAP_2 = 296,//18 296~313
  E_CUSTOM_KEYMAP_2_COLOR = 314, //2 314~315
  E_CUSTOM_KEYMAP_2_IDLE = 316, //32 316~347
  E_CUSTOM_KEYMAP_2_ACTIVE = 348 , //32 348~379
  //RESERVED 380~383
  E_CUSTOM_KEYMAP_3 = 384,//32 384~415
  E_CUSTOM_FN_KEYMAP_3 = 416, //8 416~423
  E_CUSTOM_BOTTOM_KEYMAP_3 = 424,//18 424~441
  E_CUSTOM_KEYMAP_3_COLOR = 442, //2 442~443
  E_CUSTOM_KEYMAP_3_IDLE = 444, //32 444~475
  E_CUSTOM_KEYMAP_3_ACTIVE = 476 , //32 476~507
  //RESERVED 508~511
};

enum EEPROM_PALETTE_MAP//16BIT*2
{
  E_CUSTOM_PALETTE_1 = 0, //0~255
  E_CUSTOM_PALETTE_2 = 256, //256~511
};

enum EEPROM_SYS_MAP//WRITE ONCE,READ ONLY
{

};


#endif

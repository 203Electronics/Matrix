//#define DEBUG

#include "DeviceSelector.h"

#ifdef DEBUG
#include <USBComposite.h>
#endif

#define MXPT 0x4D585054 
#define MXFE 0x4D584645

extern u8 device_config = 0;

extern String device_name = "Unknown Matrix";

extern u8 led_pin = 0;
extern u8 powercord_pin = 0;
extern u8 powercord_detection = 0;

extern u32 led_color_correction = 0xFFFFFFFF;

//KeyPad
extern u8 keypad_type = 1;
extern u8 keypad_pins[16] = {0};
extern u8 velocity_sensitivity = 1;  //for velocity sensitivy, bit 1 for no velocity (binary) 8 for 8 bit(0~255)

extern u8 fn_pin = 0;
extern bool fn_press_state = HIGH;

//analog(TouchBar)
extern u8 analog0 = PA3;
extern u8 analog1 = PA4;
extern u8 analog2 = PA5;
extern u8 analog3 = PA6;
extern u8 analog4 = PA7;
extern u8 analog5 = PC4;
extern u8 analog6 = PC5;
extern u8 analog7 = PB0;
extern u8 analog8 = PB1;
extern u8 analog9 = PA0;
extern u8 analog10 = PA1;
extern u8 analog11 = PA2;
//I2C
extern u8 i2c_scl = 0;
extern u8 i2c_sda = 0;
//SPI
extern u8 spi_sck = 0;
extern u8 spi_miso = 0;
extern u8 spi_mosi= 0;
extern u8 spi_cs1 = 0;
extern u8 spi_cs2 = 0;
//Serial1 (USB-C)
extern u8 tx1 = 0;
extern u8 rx1 = 0;
//Serial3 (Matrix Mod)
extern u8 tx3 = 0;
extern u8 rx3 = 0;
//Serial2/4/5 (m2p futureproof)
extern u8 tx2 = 0;
extern u8 rx2 = 0;
extern u8 tx4 = 0;
extern u8 rx4 = 0;
extern u8 tx5 = 0;
extern u8 rx5 = 0;

//SerialAvailabble
extern bool usbmidi_available = 0;
extern bool usbcdc_available = 0;
extern bool serial1_available = 0;
extern bool serial2_available = 0;
extern bool serial3_available = 0;
extern bool serial4_available = 0;
extern bool serial5_available = 0;

extern bool support_wrgb = 0;

//EEPROM
extern bool eeprom_enable = 0;
extern u32 eeprom_user_adds_0 = 0;
extern u32 eeprom_user_adds_1 = 0;
extern u32 eeprom_palette_adds_0 = 0;
extern u32 eeprom_palette_adds_1 = 0;
extern u32 eeprom_sys_adds_0 = 0;
extern u32 eeprom_sys_adds_1 = 0;
extern u32 eeprom_pagesize = 0;

extern u8 touch_type = 0;
extern u8 touch_length = 0;
extern u8 touch_pins[2] = {0};

void loadDeviceConfig()
{
  switch(MATRIX_MODEL)
  {
    // case MXPT:
    //   switch(MATRIX_VERSION)
    //   {
    //     case 120:
    //     #ifdef DEBUG
    //     CompositeSerial.print("Device: Matrix Prototype V1.2");
    //     #endif
    //     loadConfigMXPTV120();
    //     break;

    //     case 150:
    //     #ifdef DEBUG
    //     CompositeSerial.print("Device: Matrix Prototype V1.5");
    //     #endif
    //     loadConfigMXPTV150();
    //     break;

    //     case 210:
    //     #ifdef DEBUG
    //     CompositeSerial.print("Device: Matrix Prototype V2.1");
    //     #endif
    //     loadConfigMXPTV210();
    //     break;
    //   }
    // break;
    // case MXFE:
    //   switch(MATRIX_VERSION)
    //   {
    //     case 1:
    //       #ifdef DEBUG
    //       CompositeSerial.print("Device: Matrix Founder Edition 1");
    //       #endif
    //       loadConfigMXFE1();
    //     break;
    //   }
    default:
      #ifdef DEBUG
        CompositeSerial.print("No valid device config found");
        #endif
      loadConfigMXFE1();
  }
}

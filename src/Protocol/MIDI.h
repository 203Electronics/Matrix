#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>
#include <USBComposite.h>
#include "../HAL/LED.h"
#include "../Parameter/MatrixVariable.h"
#include "../Parameter/MatrixParameter.h"
#include "../Core/MatrixSystem.h"
#include "../Components/UI.h"

class MIDI: public USBMIDI
{
public:
  //MIDI();
  void noteOn(u8 channel, u8 note, u8 velocity);
  void noteOff(u8 channel, u8 note, u8 velocity);
  void sendXYon(u8 xy, u8 velocity);
  void sendXYoff(u8 xy, u8 velocity);
  void sendSysexWithHeader(u8 *sysex, u8 len);

  //handle
  void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity) override;
  void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity) override;
  void handleSysExData(unsigned char data) override;
  void handleSysExEnd(void) override;
  // void handleVelocityChange(u8 channel, u8 note, u8 velocity) override;
  // void handleControlChange(u8 channel, u8 controller, u8 value) override;
  // void handleProgramChange(u8 channel, u8 program) override;
  // void handleAfterTouch(u8 channel, u8 velocity) override;
  // void handlePitchChange(u16 pitch) override;
  // void handleSongPosition(u16 position) override;
  // void handleSongSelect(u8 song) override;
  // void handleTuneRequest() override;
  // void handleSync() override;
  // void handleStart() override;
  // void handleContinue() override;
  // void handleStop() override;
  // void handleActiveSense() override;
  // void handleReset() override;

  //From parrent
  //void registerComponent();
  //bool available();
  void poll();

  void sendNoteOn(u8 channel, u8 note, u8 velocity = 127);
  void sendNoteOff(u8 channel, u8 note, u8 velocity = 0);
  // void sendVelocityChange(u8 channel, u8 note, u8 velocity);
  // void sendControlChange(u8 channel, u8 controller, u8 value);
  // void sendProgramChange(u8 channel, u8 program);
  // void sendAfterTouch(u8 channel, u8 velocity);
  // void sendPitchChange(u16 pitch);
  // void sendSongPosition(u16 position);
  // void sendSongSelect(u16 song);
  // void sendTuneRequest();
  // void sendSync();
  // void sendStart();
  // void sendContinue();
  // void sendStop();
  // void sendActiveSense();
  // void sendReset();

  void handleSysEx();

  void offScan();

  //Sysex action
  void replyIdentity();
  void replyDeviceName();
  void replySerialNumber();
  void replyFirmwareVersion(u8 mode);
  void replyDeviceID();

  void scrollText(u8 *sysexBuffer, uint16_t len);
  void setLED(u8 *sysexBuffer, uint16_t len);
  void fillLEDArea(u8 *sysexBuffer, uint16_t len);
  void serialFillLED(uint8_t *sysexBuffer, uint16_t len);
  void writePalette(u8 *sysexBuffer, uint16_t len);

private:
  s8 offMap[128];
  u8 sysexBuffer[1024];
  byte lastStatusOutput;
  u16 sysexLength;
};

#endif

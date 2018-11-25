#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>
#include <USBMIDI.h>
#include "MatrixVariable.h"
#include "MatrixParameter.h"
#include "MatrixSystem.h"
#include "LED.h"

//usbmidi usbmidi;

class MIDI
{
public:
  MIDI();
  void Begin();
  void NoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void NoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  void Poll();
  void SentNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  void SentNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
};

#endif
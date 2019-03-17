#include "../UI.h"

extern KeyPad KeyPad;
extern LED LED;
extern MIDI Midi;

void UI::kaskobiWaitAnimation()
{
  if(uiTimer.tick(500))
  {
    if(LED.readXYLED(0x07))
    {
      LED.offXY(0x07, true);
    }
    else
    {
        LED.onXY(0x07, true);
    }
    LED.update();
  }
}

void UI::kaskobiBootAnimation() //8x8 only
{
  LED.enableOverlayMode();
  //StageOne
  u16 delay = 60;
  for(s8 y = 7; y >= 0; y--)
  {
    for(u8 x = 0; x < 8; x++)
    {
      while(!uiTimer.isLonger(delay))
      {
        if(Midi.available())
        {
          LED.disableOverlayMode();
          return;
        }

        KeyPad.scan();
        if(KeyPad.fnChanged)
        {
          if(!KeyPad.fn)
          {
            LED.disableOverlayMode();
            return;
          }
        }
      }
      uiTimer.recordCurrent();
      LED.onXY(xytoxy(x, y), true);
      LED.update();
    }
    delay *= 0.8;
  }

  // uiTimer.recordCurrent();
  // while(!uiTimer.isLonger(30))
  // {
  //   KeyPad.scan();
  //   if(KeyPad.fnChanged)
  //   {
  //     if(!KeyPad.fn)
  //     {
  //       LED.disableOverlayMode();
  //       return;
  //     }
  //   }
  // }

  //Stage2
  delay = 25;

  //shuffle the array
  u8 shuffle[NUM_LEDS];
  for(u8 i = 0; i < NUM_LEDS; i++)
  {
    shuffle[i] = i;
  }
  randomSeed(analogRead(PC3) * analogRead(PC4) * analogRead(PC5) );
  u8 n = sizeof(shuffle) / sizeof(shuffle[0]);
  for (u8 i = 0; i < n - 1; i++)
  {
    u8 j = random(0, n - i);
    u8 t = shuffle[i];
    shuffle[i] = shuffle[j];
    shuffle[j] = t;
  }

  for(int i = 0; i <NUM_LEDS+5; i++)
  {

    while(!uiTimer.isLonger(delay))
    {
      if(Midi.available())
      {
        LED.disableOverlayMode();
        return;
      }

      KeyPad.scan();
      if(KeyPad.fnChanged)
      {
        if(!KeyPad.fn)
        {
            LED.disableOverlayMode();
            return;
        }
      }
    }
    uiTimer.recordCurrent();
    if(i < NUM_LEDS)
    LED.setPalette(shuffle[i], 0, 44, true);
    if(i > 0 && i < NUM_LEDS + 1)
    LED.setPalette(shuffle[i-1], 0, 28, true);
    if(i > 1 && i < NUM_LEDS + 2)
    LED.setPalette(shuffle[i-2], 0, 12, true);
    if(i > 2 && i < NUM_LEDS + 3)
    LED.setPalette(shuffle[i-3], 0, 116, true);
    if(i > 3 && i < NUM_LEDS + 4)
    LED.setPalette(shuffle[i-4], 0, 102, true);
    if(i > 4 && i < NUM_LEDS + 5)
    LED.off(shuffle[i-5], true);
    LED.update();
  }
  //end
  LED.disableOverlayMode();
  return;
}

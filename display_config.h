#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H

#include <Arduino_GFX_Library.h>

// CONFIGURE BACKLIGHT PIN HERE
#define GFX_BL 1

class DisplayConfig {
  public:
    Arduino_GFX* gfx;

    DisplayConfig() {
      Arduino_DataBus *bus = new Arduino_ESP32QSPI(
          45 /* cs */, 47 /* sck */, 21 /* d0 */, 
          48 /* d1 */, 40 /* d2 */, 39 /* d3 */);
      Arduino_GFX *g = new Arduino_NV3041A(bus, GFX_NOT_DEFINED /* RST */, 0 /* rotation */, true /* IPS */);
      gfx = new Arduino_Canvas(480 /* width */, 272 /* height */, g);
    }

    bool begin() {
      if (!gfx->begin()) {
        return false;
      }
      pinMode(GFX_BL, OUTPUT);
      digitalWrite(GFX_BL, HIGH);
      return true;
    }
};

#endif

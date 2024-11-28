
#include "display_config.h"
#include "touch_config.h"
#include "button_layout.h"

DisplayConfig display;
TouchConfig touch;
ButtonLayout buttons(&display);

void setup() {
  Serial.begin(115200);

  if (!display.begin()) {
    Serial.println("Error initializing display!");
    while (1);
  }

  if (!touch.begin()) {
    Serial.println("Error initializing touch!");
    while (1);
  }

  display.gfx->fillScreen(BLACK);
  buttons.drawButtons();
}

void loop() {
  if (touch.isTouched()) {
    int x, y, z;
    touch.getScaledPoint(x, y, z);

    int buttonPressed = buttons.checkButton(y, x);
    if(buttonPressed >= 0) {
      display.gfx->fillScreen(buttons.getButtonColor(buttonPressed));
      buttons.drawButtons();
      delay(200);
    }
  }
}
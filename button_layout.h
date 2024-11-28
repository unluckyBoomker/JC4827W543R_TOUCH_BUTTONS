#ifndef BUTTON_LAYOUT_H
#define BUTTON_LAYOUT_H

#include "display_config.h"
#include "touch_config.h"

struct Button {
  int x;
  int y;
  int width;
  int height;
  uint16_t color;
};

class ButtonLayout {
  private:
    DisplayConfig* display;
    static const int BUTTON_COUNT = 6;
    Button buttons[BUTTON_COUNT];

  public:
    ButtonLayout(DisplayConfig* disp) {
      display = disp;
      initButtons();
    }

    void initButtons() {
      const int buttonWidth = 140;
      const int buttonHeight = 80;
      const int spacing = 20;
      const uint16_t colors[6] = {RED, GREEN, BLUE, YELLOW, PURPLE, CYAN};

      for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 3; col++) {
          int index = row * 3 + col;
          buttons[index].x = spacing + col * (buttonWidth + spacing);
          buttons[index].y = spacing + row * (buttonHeight + spacing);
          buttons[index].width = buttonWidth;
          buttons[index].height = buttonHeight;
          buttons[index].color = colors[index];
        }
      }
    }

    void drawButtons() {
      for(int i = 0; i < BUTTON_COUNT; i++) {
        display->gfx->fillRect(buttons[i].x, buttons[i].y, 
                           buttons[i].width, buttons[i].height, 
                           buttons[i].color);
      }
      display->gfx->flush();
    }

    int checkButton(int touchX, int touchY) {
      for(int i = 0; i < BUTTON_COUNT; i++) {
        if(touchX >= buttons[i].x && touchX <= buttons[i].x + buttons[i].width &&
           touchY >= buttons[i].y && touchY <= buttons[i].y + buttons[i].height) {
          return i;
        }
      }
      return -1;
    }

    uint16_t getButtonColor(int index) {
      if(index >= 0 && index < BUTTON_COUNT) {
        return buttons[index].color;
      }
      return BLACK;
    }
};

#endif

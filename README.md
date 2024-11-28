# JC4827W543R GUITION LCD Touch Screen Test Project

## Description
This project is a basic test implementation for the Guition ESP32-S3 JC4827W543R LCD module with resistive touch screen. It implements a simple interface with 6 colored buttons that change the background color when touched.

## Hardware
- Guition ESP32-S3 JC4827W543R
- 4.3-inch IPS LCD (480x272 pixels)
- Resistive Touch Panel (RTP)
- 8M PSRAM
- 4M Flash
- Built-in WiFi and Bluetooth [^1][^2]

## Pin Configuration
### LCD
- LCD_CS: IO45
- LCD_CLK: IO47
- LCD_A0: IO21
- LCD_A1: IO48
- LCD_A2: IO40
- LCD_A3: IO39

### Touch Panel (RTP)
- RTP_CS: IO38
- RTP_IRQ: IO3
- RTP_CLK: IO12
- RTP_DIN: IO11
- RTP_DIO: IO13

## Project Structure
The project is organized into three main files:
- ```display_config.h```: LCD hardware configuration
- ```touch_config.h```: Touch panel hardware configuration
- ```button_layout.h```: UI management (buttons)

## Features
- LCD and touch panel initialization
- Display of 6 colored buttons (2 rows x 3 columns)
- Touch detection with X/Y coordinates
- Background color change when touching buttons

## Dependencies
- Arduino_GFX_Library
- XPT2046_Touchscreen
- SPI

## Arduino IDE Settings
- Board: "ESP32S3 Dev Module"
- USB CDC On Boot: "Enabled"
- CPU Frequency: "240MHz (WiFi)"
- Flash Size: "4MB"
- PSRAM: "OPI PSRAM"
- Upload Speed: 921600

## Notes
This project serves as a foundation to test the proper functioning of both the LCD and touch panel. It can be used as a starting point for more complex projects requiring a touch interface.

## Repository Contents
- ```display_config.h```: LCD configuration file
- ```touch_config.h```: Touch panel configuration file
- ```button_layout.h```: Button management file
- ```main.ino```: Main program file
- ```README.md```: Project documentation

[^1]: [GUITION Official Store - AliExpress](https://www.aliexpress.com/store/1102410813#:~:)
[^2]: [Guition ESP32-S3 8M PSRAM 4M FLspatule 4.3 pouces IPS 480*272 module d ...](https://fr.aliexpress.com/item/1005006729377800.html#:~:)
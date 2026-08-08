# SonicOnArduino Version 2

This folder contains SonicOnArduinoVersion2 — a continuation and upgrade of the original SonicOnArduino project. It ports and expands the retro Sonic-style game for small microcontroller-based displays (SSD1306 128x64) and adds new sprites, a boss fight, hitboxes, and basic level elements.

This README documents the goals, hardware, wiring, dependencies and how to build and run the project.

## What this project is

- An embedded, retro-style Sonic-like demo/game written in Arduino/C++ targeting small microcontroller boards (ESP32/Arduino) and an SSD1306 128x64 OLED display.
- Continuation / upgrade of the original `SonicOnArduino` project: new sprite sheets, boss animations, hitboxes, ring collection, improved game state and UI elements.
- Intended as both a learning project for microcontroller graphics and a playful demo you can run on a handheld or breadboard setup.

## Features

- Multiple sprite bitmaps stored in PROGMEM for the player, enemies and boss.
- Boss fight with multiple animation frames and a per-frame hitbox configuration.
- Ring placement and collection (simple score mechanic).
- Health system and basic physics (jumping / gravity) for the player.
- Sound feedback via a buzzer pin.
- Uses an SSD1306 (Adafruit_SSD1306 / Adafruit_GFX) for display drawing.

## Hardware

Recommended: ESP32 development board. Compatible with many Arduino boards with small changes to analog/digital pin choices.

Minimum hardware list:

- ESP32 or Arduino (Uno/Nano/Pro Mini etc.)
- SSD1306 128x64 I2C OLED display
- Small passive buzzer
- Momentary push button (for e.g. jump/start)
- 2-axis analog joystick or two potentiometers (for left/right and optional vertical input)
- Breadboard and jumper wires

## Wiring (as used in code)

The code in Source-code references the following pins and interfaces. Adjust pins for your specific board if necessary.

- SSD1306: I2C (Wire). Connect to your board's SDA / SCL pins.
  - Arduino UNO: SDA = A4, SCL = A5
  - ESP32 (typical): SDA = 21, SCL = 22 (or whichever pins you configured for Wire)
  - SSD1306 address typically 0x3C (no change in code unless required)

- Buzzer: BUZZER_PIN (digital pin 3 in code) -> buzzer (use series resistor if using active buzzer or as required)

- Button: BUTTON (digital pin 4 in code) -> button to ground (use pull-up or enable internal pull-up in code)

- Joystick / analog inputs: A0 and A1 (analogRead(A0) / analogRead(A1) in code)
  - On ESP32, you may need to change these to an actual ADC-capable pin (e.g., GPIO34, GPIO35) or use the Arduino mapping. On AVR Arduinos these are the A0, A1 pins.

Note: If you use a board that doesn't expose A0/A1 by those names, map them to ADC-capable pins in the code.

## Dependencies

Install these Arduino libraries (Library Manager or PlatformIO):

- Adafruit GFX Library
- Adafruit SSD1306

Make sure the SSD1306 library is configured for a 128x64 display in the example or in the library settings if required.

## Building and uploading

Using Arduino IDE:

1. Install the dependencies (Adafruit GFX, Adafruit SSD1306).
2. Open the sketch (the main .ino file) located in SonicOnArduinoVersion2/ (or create an Arduino sketch if files are .cpp/.h).
3. Select the correct board (ESP32 Dev Module or your Arduino model) and the correct COM port.
4. Compile and Upload.

Using PlatformIO (VSCode):

1. Create a project for your board (select the board ID matching your ESP32 or Arduino).
2. Add the Adafruit libraries to platformio.ini or include them via lib_deps.
3. Build and upload from PlatformIO.

## Controls

- Left/Right: joystick analog X (A0)
- Up/Down or secondary input: joystick analog Y (A1) — used where appropriate
- Button: jump / action (digital BUTTON) — wired as momentary button
- Buzzer: used for simple sound effects on events

Adjust control mapping inside the sketch if you prefer different pins or input method.

## Configuration / Tips

- If you see compile errors about `Adafruit_SSD1306` constructor parameters, make sure the display width/height in the library matches 128x64 and that the Wire instance is used correctly for your board.
- If analog inputs act strangely on ESP32, remap A0/A1 to ADC-capable pins and update the code.
- The project stores sprites in PROGMEM to reduce RAM use — do not move large bitmaps into regular variables unless you know the memory implications.

## Project structure

- SonicOnArduinoVersion2/Source-code/ — main game source (sprites, logic, hitboxes)
- (This README) — overview and quickstart

## Changelog / Upgrade notes

This version (Version 2) is a continuation and upgrade of the original SonicOnArduino project:

- Added boss animations and per-frame hitboxes
- More sprite frames and grouped sprite arrays
- Ring placement, score and simple health system
- More enemies (meat bugs, motor bugs) and floor/level assets

If you forked the original project, compare the sprite arrays and hitbox definitions to merge customizations.

## Known issues and TODO

- Pin mappings for ESP32 are left generic (A0/A1). Update them for your board.
- Consider adding a configuration header to centralize pin definitions and screen size constants.
- Add a proper license file (MIT recommended) if you want to open-source the code.
- Improve audio (use PWM or DAC for richer sounds on supported boards).

## Credits

- Original SonicOnArduino author and contributors
- Adafruit for GFX and SSD1306 libraries and example code used as a base

## License

No license file included by default. If you want this project to be open source, add a LICENSE (for example, the MIT License).

---

If you'd like, I can:
- add a LICENSE (MIT) to the repository,
- add this README to the project (I will commit it for you),
- or update pin mappings to target ESP32 specifically.


# Mega Man On Arduino

A Mega Man-inspired action game built for Arduino/ESP32 with an SSD1306 128x64 OLED display. This project is a compact platformer/shooter demo featuring sprite animations, enemy patterns, hit detection, and simple sound effects using a passive buzzer.

## 📋 Overview

This project ports classic Mega Man-style gameplay to a microcontroller and small OLED display. It includes player movement, jumping, shooting, simple enemy AI (ninja, burger enemies), collision detection via hitboxes, and score/life tracking.

## 🎮 Game Features

- Player movement left/right and jumping
- Shooting projectiles
- Multiple enemy types and states (hidden, attacking, jumping, shooting)
- Hitbox-based collision detection
- Simple HUD showing score and lives
- Bitmap sprites stored in PROGMEM for efficient display
- Sound effects via passive buzzer
## ▶️Demo
- Link: https://youtube.com/shorts/n5QhOsj3owc?si=HiZ63yME2TeshqBR

## 🛠️ Hardware Requirements

- Arduino (Uno/Nano) or ESP32
- SSD1306 128x64 OLED display (I2C)
- Push buttons for controls (or a small joystick)
- Passive buzzer for sound effects
- Wires and breadboard

### Typical Wiring

| Component | Pin |
|-----------|-----|
| OLED SDA  | A4 (or I2C SDA) |
| OLED SCL  | A5 (or I2C SCL) |
| Buzzer    | D3 |
| Button A  | D4 (left) |
| Button B  | D5 (right) |
| Button Jump | D6 |
| Button Shoot | D7 |

Note: Pin numbers may vary by board. On ESP32 use the board's I2C pins and adjust button/buzzer pins accordingly.

## 📦 Software Dependencies

Install via the Arduino Library Manager:

- Adafruit GFX Library
- Adafruit SSD1306

## 📁 Project Structure

- `source_code/` — main sketch and C/C++ source files, sprite bitmaps in PROGMEM
- `README.md` — this file

## ❓How to Use

1. Open the `source_code` folder in the Arduino IDE or PlatformIO.
2. Install the dependencies listed above.
3. Connect the hardware and upload the sketch to your board.
4. Use the buttons or joystick to move, jump and shoot.

## 🕹️ Controls

- Move Left/Right — left/right buttons or joystick
- Jump — jump button
- Shoot — shoot button

## ⚠️ Notes

- The game is designed for small displays — some sprites are optimized for 128x64 resolution.
- Adjust pin definitions at the top of the sketch to match your wiring.
- Sound uses a passive buzzer on pin 3 by default.

## 👨‍💻 Author

Sanelemthembu1 as Part of the DIY Arduino/ESP32 Projects collection.

---

Happy gaming! 

# Dino Run Game

A fun dinosaur-themed endless runner game built for Arduino/ESP32 with an OLED display and joystick controls.

## 📋 Overview

Dino Run is an interactive game where you control a dinosaur that must avoid incoming obstacles and cars while accumulating points. The game features physics-based movement, collision detection, and sound effects.

## 🎮 Game Mechanics

- **Movement:** Use joystick left/right to move the dinosaur
- **Jumping:** Push joystick up to jump and avoid obstacles
- **Scoring:** Points increase continuously; bonus sounds play when you successfully pass obstacles
- **Obstacles:** Three types of obstacles move across the screen from right to left
- **Hazards:** Cars also appear as moving obstacles
- **Game Over:** Collision with any obstacle or car ends the game

## 🛠️ Hardware Requirements

- Arduino or ESP32 microcontroller
- 128x64 SSD1306 OLED display
- Analog joystick (2-axis with X/Y inputs)
- Buzzer (for sound effects)

### Wiring

| Component | Pin |
|-----------|-----|
| OLED SDA | A4 (or I2C SDA) |
| OLED SCL | A5 (or I2C SCL) |
| Joystick X | A0 |
| Joystick Y | A1 |
| Buzzer | 3 |

## 📦 Dependencies

- `Adafruit_GFX.h` - Graphics library
- `Adafruit_SSD1306.h` - OLED display driver

## 🎨 Game Assets

The game includes pre-rendered bitmap sprites for:
- **Dinosaur:** 3 animation frames (20x19 px)
- **Obstacles:** 3 different types (10x21, 6x11 px)
- **Cars:** 3 variants including player car (28-29x17 px)
- **Background elements:** Clouds, stars, ground tiles
- **UI:** "Game Over" text bitmap

## 🔊 Audio Feedback

- **Success sound:** 1200 Hz beep when passing obstacles
- **Game Over sound:** Descending tone sequence (1000 → 800 → 600 → 300 Hz)

## 🎯 Physics

- **Gravity:** 0.4 m/s²
- **Jump force:** -4.5 units
- **Movement speed:** 0.5 units/frame
- **Friction:** 0.9x velocity damping

## 🕹️ Controls

| Action | Input |
|--------|-------|
| Move Left | Joystick X < 400 |
| Move Right | Joystick X > 600 |
| Jump | Joystick Y > 600 |
| Start Game | Move joystick left/right |

## 📊 Game Variables

- `score` - Running score value
- `Dino_x, Dino_y` - Dinosaur position
- `obstacle[1-3]_x, _y` - Obstacle positions
- `car[1-3]_x, _y` - Car positions
- `gameStarted`, `gameEnded`, `gameOverSoundPlayed` - State flags

## 🚀 How to Use

1. Upload the sketch to your Arduino/ESP32
2. Ensure all hardware is connected properly
3. Open the serial monitor (optional)
4. Move the joystick left/right to start the game
5. Avoid obstacles and cars while the game scrolls
6. Track your score as it increases

## 🐛 Collision Detection

Hitbox detection includes:
- Dinosaur hitbox: slightly inset (5px padding on sides, 3px on top/bottom)
- Obstacles: precise bounding box collision
- Cars: 29x17 pixel collision area

## 📝 Notes

- Display refresh rate: ~33ms (30 FPS)
- Game over sound is played only once per game session
- Screen wraps horizontally for infinite scrolling effect
- Score precision: 1 decimal place (0.1 increments per frame)

## 👨‍💻 Author

Created as part of the DIY Arduino/ESP32 Projects collection.

---

**Happy gaming! 🦖**

# Mario on Arduino 🎮

A **Super Mario-style platformer game** running on an Arduino with an OLED display, joystick controls, and sound effects.

## Features

### Gameplay
- **Character Control**: Move Mario left/right with smooth camera scrolling
- **Physics System**: Gravity, jumping, falling mechanics
- **Enemies**: 
  - Tortoises (slow-moving horizontal threats)
  - Bugs (animated, scrolling threats)
- **Obstacles**: Destructible bricks and power-up blocks
- **Collectibles**: Animated flowers with pause/resume behavior
- **Winning Condition**: Reach the castle and flag to complete the level

### Hardware
- **Display**: Adafruit SSD1306 OLED (128x64 pixels)
- **Input**: Analog joystick (X/Y axes)
- **Audio**: Buzzer with sound effects
- **Microcontroller**: Arduino or ESP32

### Audio
- **Sound Effects**:
  - Stomp sound (descending tones)
  - Brick break sound (descending burst)
- **Victory Jingle**: 16-note winning melody (≈3.5 seconds)

## Hardware Wiring

```
Joystick:
  - X-axis → Analog Pin A0
  - Y-axis → Analog Pin A1
  - GND → Ground

OLED Display (I2C):
  - SDA → SDA (I2C)
  - SCL → SCL (I2C)
  - GND → Ground
  - VCC → 5V

Buzzer:
  - Signal → Digital Pin 3
  - GND → Ground
```

## Controls

| Input | Action |
|-------|--------|
| **Joystick Right** | Move Mario right / Scroll screen |
| **Joystick Left** | Move Mario left / Scroll screen |
| **Joystick Up** | Jump |

## Game Mechanics

### Camera System
- Mario stays within a viewport window (CAMERA_X = 30)
- When Mario reaches the edge, the world scrolls instead
- Seamless parallax background scrolling with tile-based terrain

### Physics Parameters
```
Gravity: 0.3 px/frame²
Move Speed: 0.3 px/frame
Jump Force: -3.0 px/frame
```

### Enemy Behavior
- **Tortoises**: Animate through 3 frames, move left with scrolling
- **Bugs**: Animate through 3 frames, move left with scrolling
- **Flowers**: Pause 3 seconds at bottom/top, animate upward/downward

### Collision Detection
- Mario vs. Bricks
- Mario vs. Enemies
- Mario vs. Power-ups
- Mario vs. Stairs (final screen)

## File Structure

```
Mario on Arduino/
├── Source_Code          # Main Arduino sketch
├── README.md           # This file
└── [Hardware docs]     # (Optional: circuit diagrams, schematics)
```

## Sprite Assets

The sketch includes 28+ bitmap sprites:
- **Mario**: Standing, jumping, walking left/right, various poses (18×24 px)
- **Enemies**: Tortoises (15×9 px), Bugs (10×8 px)
- **Obstacles**: Bricks (25×5 px), power blocks (9×5 px)
- **Decorations**: Flowers (15×23 px), stairs, castle, flag, clouds
- **Backgrounds**: Parallax layers (128×64 px)

All assets are stored in PROGMEM (program memory) to conserve RAM.

## Code Highlights

### Key Functions
- `moveMario()` - Handles input and Mario movement
- `playStompSound()` - Plays stomp SFX
- `playBreakSound()` - Plays brick break SFX
- `startWinJingle()` / `updateWinJingle()` - Victory audio sequence
- `getStairTreadY()` - Stair collision logic
- `randomizeScreenObjects()` - Spawns enemies/items per screen
- `createBug()`, `createTotoise()`, `createFlower()` - Enemy/object rendering

### Game States
- **gameStarted**: Game is in progress
- **gameEnded**: Mario died
- **gameWon**: Reached the goal
- **killed**: Mario death animation (falling)
- **pendingRespawn**: Waiting to respawn after death

## Customization

### Adjust Difficulty
```cpp
const float gravity = 0.3;        // Increase for harder gravity
const float moveSpeed = 0.3;      // Decrease for slower movement
const float jumpForce = -3.0;     // Adjust jump height
```

### Add More Levels
```cpp
const int FINAL_SCREEN = 1;       // Change to add more screens
```

### Modify Sprite Positions
```cpp
int stairXStart[NUM_STAIRS] = {36, 42, 48, 54, 60};
int stairXEnd[NUM_STAIRS]   = {42, 48, 54, 60, 66};
int stairTreadY[NUM_STAIRS] = {49, 43, 37, 31, 25};
```

## Dependencies

- **Adafruit GFX Library** - Graphics rendering
- **Adafruit SSD1306** - OLED display driver
- Arduino IDE (1.8.13+)

## Installation

1. Open the `Source_Code` file in Arduino IDE
2. Install required libraries via Library Manager:
   - Adafruit GFX
   - Adafruit SSD1306
3. Connect hardware per wiring diagram
4. Select board type and COM port
5. Upload sketch

## Performance Notes

- Display refresh rate: ~30 FPS
- Memory usage: Most sprites in PROGMEM
- Sound is non-blocking (jingle runs concurrently with game loop)
- Camera scrolling uses modular world tiling

## Future Enhancements

- [ ] Multiple levels with increasing difficulty
- [ ] High-score storage (EEPROM)
- [ ] Additional enemy types
- [ ] Power-up mechanics (invincibility, speed boost)
- [ ] Animated backgrounds
- [ ] Level editor

## License

Open source - feel free to modify and improve!

---

**Enjoy the game! 🍄**

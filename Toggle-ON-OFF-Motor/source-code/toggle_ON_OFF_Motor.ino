// Toggle motor via relay with button (debounced)
// Arduino Uno example
// Button wired to pin 2 -> GND (using INPUT_PULLUP). Relay IN on pin 8.
// Toggle on button release.

const uint8_t BUTTON_PIN = 2;
const uint8_t RELAY_PIN  = 8;
const uint8_t LED_PIN    = 13; // optional indicator

// Debounce parameters
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

int lastButtonState = HIGH; // because INPUT_PULLUP
int buttonState = HIGH;
bool toggledState = false; // false = motor off, true = motor on

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Ensure initial state: relay off
  digitalWrite(RELAY_PIN, LOW); // If your relay is active LOW, see note below
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  Serial.println("Toggle motor example starting");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // If the switch changed, reset the debounce timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // If the reading has been stable for longer than debounce delay, take it as actual
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // We toggle on the button RELEASE (i.e., when state goes from LOW -> HIGH)
      // With INPUT_PULLUP: pressed = LOW, released = HIGH
      if (buttonState == HIGH) {
        toggledState = !toggledState;
        applyMotorState(toggledState);
      }
    }
  }

  lastButtonState = reading;
}

// Helper: set relay and LED according to state
void applyMotorState(bool on) {
  Serial.print("Motor ");
  Serial.println(on ? "ON" : "OFF");

  // Most relay modules are active LOW on IN (i.e., drive LOW to energize)
  // If your relay is active HIGH, swap LOW <-> HIGH here.
  if (on) {
    digitalWrite(RELAY_PIN, HIGH); // <-- change to LOW if your module is active LOW
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);  // <-- change to HIGH if active LOW
    digitalWrite(LED_PIN, LOW);
  }
}
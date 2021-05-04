#include <Analog4x4Keypad.h>
#define KEYBOARD_PIN A10
#include <Keyboard.h>

void setup() {
  Serial.begin(9600);
  pinMode(KEYBOARD_PIN, INPUT);
  Keyboard.begin();
}

void loop() {
  if (analogRead(KEYBOARD_PIN) > 0) {
    Serial.print(analogRead(KEYBOARD_PIN));
    AnalogKeypad a = AnalogKeypad{KEYBOARD_PIN};
    Keyboard.press(a.getbutton() + 240);
    Keyboard.releaseAll();
    Serial.print(a.getbutton());
  }
}

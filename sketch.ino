#include <Analog4x4Keypad.h>
#define KEYBOARD_PIN A10
#include <Keyboard.h>

const int analogKeyValues[12] = {240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251};
void setup() {
  Serial.begin(9600);
  pinMode(KEYBOARD_PIN, INPUT);
  Keyboard.begin();
}

void loop() {
  if (analogRead(KEYBOARD_PIN) > 0) {
    Serial.print(analogRead(KEYBOARD_PIN));
    AnalogKeypad a = AnalogKeypad{KEYBOARD_PIN};
    Keyboard.press(analogKeyValues[a.getbutton()]);
    Keyboard.releaseAll();
    Serial.print(a.getbutton());
  }
}

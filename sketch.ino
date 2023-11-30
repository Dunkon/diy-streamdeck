#define ANALOGPORT    A10
#define DEBOUNCE 700
#define DEBOUNCE_RELEASE 15
#define ZERO_BUTTON 239
#include <Keyboard.h>
#include "AnalogKeypad.h"

AnalogKeypad AKP(ANALOGPORT);
uint32_t start, stop;

void setup()
{
  Serial.begin(115200);
  pinMode(ANALOGPORT, INPUT);
  Keyboard.begin();
}

void loop()
{
  int button = AKP.pressed();
  if (button > 0) {
    Serial.print(AKP.pressed());
    Keyboard.press(button + ZERO_BUTTON);
    delay(DEBOUNCE_RELEASE);
    Keyboard.releaseAll();
    delay(DEBOUNCE);
  }
}

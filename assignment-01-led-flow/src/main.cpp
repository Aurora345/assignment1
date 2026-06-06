#include <Arduino.h>

const int ledPins[] = {32, 25, 27, 12, 1, 23};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
int delayTime = 200;

void setup()
{
  for (int i = 0; i < numLeds; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{
  for (int i = 0; i < numLeds; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}

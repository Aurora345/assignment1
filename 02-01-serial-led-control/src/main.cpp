#include <Arduino.h>

const int ledPins[] = {32, 25, 27, 12, 1, 23};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
bool ledStates[] = {false, false, false, false, false, false};

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < numLeds; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{
  if (Serial.available() <= 0)
  {
    return;
  }

  String input = Serial.readStringUntil('\n');
  input.trim();

  if (input.length() == 0)
  {
    return;
  }

  Serial.print("收到: ");
  Serial.println(input);

  if (input.length() != 1)
  {
    Serial.println("无效指令");
    return;
  }

  char command = input.charAt(0);

  if (command < '1' || command > '6')
  {
    Serial.println("无效指令");
    return;
  }

  int ledIndex = command - '1';
  ledStates[ledIndex] = !ledStates[ledIndex];
  digitalWrite(ledPins[ledIndex], ledStates[ledIndex] ? HIGH : LOW);

  Serial.print("LED");
  Serial.print(ledIndex + 1);
  Serial.println(ledStates[ledIndex] ? "亮" : "灭");
}

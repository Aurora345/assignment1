#include <Arduino.h>

const String password[] = {"AA", "BB", "CC", "DD"};
const int passwordLength = sizeof(password) / sizeof(password[0]);
int passwordIndex = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() <= 0)
  {
    return;
  }

  String input = Serial.readStringUntil('\n');
  input.trim();
  input.toUpperCase();

  if (input.length() == 0)
  {
    return;
  }

  Serial.print("收到: ");
  Serial.println(input);

  if (input == password[passwordIndex])
  {
    passwordIndex++;

    if (passwordIndex == passwordLength)
    {
      Serial.println("密码正确");
      passwordIndex = 0;
    }
  }
  else
  {
    Serial.println("密码错误");
    passwordIndex = 0;
  }
}

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int screenWidth = 128;
const int screenHeight = 64;
const int oledReset = -1;
const int oledAddress = 0x3C;
const int sdaPin = 21;
const int sclPin = 22;

Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, oledReset);

void setup()
{
  Serial.begin(115200);
  Wire.begin(sdaPin, sclPin);

  if (!display.begin(SSD1306_SWITCHCAPVCC, oledAddress))
  {
    Serial.println("OLED初始化失败");
    while (true)
    {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(10, 12);
  display.println("Aurora345");
  display.setTextSize(1);
  display.setCursor(28, 42);
  display.println("Hello World!");
  display.display();
}

void loop()
{
}

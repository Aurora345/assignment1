# 作业四：OLED 显示

使用 ESP32 驱动 4 针 I2C SSD1306 OLED 屏幕，显示自定义文字。

默认接线：

| OLED | ESP32 |
| --- | --- |
| VCC | 3V3 |
| GND | GND |
| SCL | GPIO22 |
| SDA | GPIO21 |

默认参数：

- 分辨率：128 x 64
- I2C 地址：0x3C
- 驱动库：Adafruit SSD1306

屏幕显示：

```text
Aurora345
Hello World!
```

Root command: `platformio run -e oled-display`

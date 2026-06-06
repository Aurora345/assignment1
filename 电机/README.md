# 电机作业

使用 ESP32 搭配 ULN2003 驱动板控制 28BYJ-48 步进电机。

效果：

1. 正转一圈
2. 停顿
3. 反转一圈
4. 循环执行

默认接线：

| ESP32 | ULN2003 |
| --- | --- |
| GPIO16 | IN1 |
| GPIO17 | IN2 |
| GPIO18 | IN3 |
| GPIO19 | IN4 |

ULN2003 的 `5V` 接外部 5V 电源，`GND` 接电源负极，同时 ESP32 的 `GND` 要和 ULN2003 的 `GND` 共地。

Root command: `platformio run -e stepper-motor`

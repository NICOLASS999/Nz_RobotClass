#include <Arduino.h>

#define Motor0_Pin_0 9
#define Motor0_Pin_1 10
#define Motor1_Pin_0 5
#define Motor1_Pin_1 6

void dc_motor_drive(motor_number, direction, time)
{
    /******
     * 直流电机驱动函数
     * motor_number{0, 1}
     * direction{front, back, right, left}
     ******/

    int pin0, pin1;

    // 根据原理图，
    // motor0位于Bigfish拓展板左侧，连接引脚为9、10
    // motor1位于Bigfish拓展板右侧，连接引脚为5、6
    if (motor_number == 0)
    {
        pin0 = Motor0_Pin_0;
        pin1 = Motor0_Pin_1;
    }
    else
    {
        pin0 = Motor1_Pin_0;
        pin1 = Motor1_Pin_1;
    }

    switch (direction)
    {
    case front:
    {
        digitalWrite(pin0, HIGH);
        digitalWrite(pin1, HIGH);
        delay(time);
    }
    case back:
    {
        digitalWrite(pin0, LOW);
        digitalWrite(pin1, LOW);
        delay(time);
    }
    case right:
    {
        digitalWrite(pin0, HIGH);
        digitalWrite(pin1, LOW);
        delay(time);
    }
    case left:
    {
        digitalWrite(pin0, LOW);
        digitalWrite(pin1, LOW);
        delay(time);
    }
    }
}

void setup()
{
    // 直流电机输出引脚配置
    // Motor0:
    pinMode(Motor0_Pin_0, OUTPUT);
    pinMode(Motor0_Pin_1, OUTPUT);
    // Motor1:
    pinMode(Motor1_Pin_0, OUTPUT);
    pinMode(Motor1_Pin_1, OUTPUT);
}

void loop()
{
}
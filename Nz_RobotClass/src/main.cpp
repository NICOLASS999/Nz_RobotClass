#include <Arduino.h>

#define Motor0_Pin_0 9
#define Motor0_Pin_1 10
#define Motor1_Pin_0 5
#define Motor1_Pin_1 6

#define Sensor0 
#define Sensor1
#define Sensor2

/*----------------------------------------------------------------
 * 直流电机驱动函数
 * direction{front, back, right, left}
 * time(ms)
----------------------------------------------------------------*/
void dc_motor_drive(direction, time) {

    // 根据原理图，
    // motor0位于Bigfish拓展板左侧，连接引脚为9、10
    // motor1位于Bigfish拓展板右侧，连接引脚为5、6

    switch (direction) {
        // 向前
        case front:{
            digitalWrite(Motor0_Pin_0, HIGH);
            digitalWrite(Motor0_Pin_1, HIGH);
            digitalWrite(Motor1_Pin_0, HIGH);
            digitalWrite(Motor1_Pin_1, HIGH);
            delay(time);
        }
        // 向后
        case back:{
            digitalWrite(Motor0_Pin_0, LOW);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, LOW);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
        // 向右
        case right:{
            digitalWrite(Motor0_Pin_0, LOW);
            digitalWrite(Motor0_Pin_1, HIGH);
            digitalWrite(Motor1_Pin_0, LOW);
            digitalWrite(Motor1_Pin_1, HIGH);
            delay(time);
        }
        //向左
        case left:{
            digitalWrite(Motor0_Pin_0, HIGH);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, HIGH);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
    }
}

/*---------------------------------------------------------------
 * 传感器数据追踪函数
 * 默认使用3个传感器巡线，从左到右依次为0、1、2
---------------------------------------------------------------*/
void track() {
    int data[3];

    //读取三个传感器值
    data[0] = digitalRead(sensor0);
    data[1] = digitalRead(sensor1);
    data[2] = digitalRead(sensor2);

    //左右都没有检测到，直行
    if(!data[0] && !data[1] && !data[2]) {
        dc_motor_drive(front, 50);
    }

    //左边检测到黑线
    if(data[0] || data[1]) {
        dc_motor_drive(left, 50);
    }
    
    //右边检测到黑线
    if(data[1] || data[2]) {
        dc_motor_drive(right, 50);
    }
}

void setup() {
    // 直流电机输出引脚配置
    // Motor0:
    pinMode(Motor0_Pin_0, OUTPUT);
    pinMode(Motor0_Pin_1, OUTPUT);
    // Motor1:
    pinMode(Motor1_Pin_0, OUTPUT);
    pinMode(Motor1_Pin_1, OUTPUT);
}

void loop() {
    track();
}
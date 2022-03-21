#include <Arduino.h>

#define Motor0_Pin_0 9
#define Motor0_Pin_1 10
#define Motor1_Pin_0 5
#define Motor1_Pin_1 6

#define Front 1
#define Back 2
#define Left 3
#define Right 4
#define Stop 0

// #define Sensor0 
// #define Sensor1
// #define Sensor2

#define Sensor3_pin 14

/*----------------------------------------------------------------
 * 直流电机驱动函数
 * direction{front==1, back==2, left==3, right==4, stop==0}
 * time(ms)
----------------------------------------------------------------*/
void dc_motor_drive(int direction, int time) {

    // 根据原理图，
    // motor0位于Bigfish拓展板左侧，连接引脚为9、10
    // motor1位于Bigfish拓展板右侧，连接引脚为5、6

    switch (direction) {
        // 向前
        case Front:{
            digitalWrite(Motor0_Pin_0, HIGH);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, HIGH);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
        // 向后
        case Back:{
            digitalWrite(Motor0_Pin_0, LOW);
            digitalWrite(Motor0_Pin_1, HIGH);
            digitalWrite(Motor1_Pin_0, LOW);
            digitalWrite(Motor1_Pin_1, HIGH);
            delay(time);
        }
        // 向左
        case Left:{
            digitalWrite(Motor0_Pin_0, HIGH);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, LOW);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
        //向右
        case Right:{
            digitalWrite(Motor0_Pin_0, LOW);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, HIGH);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
        //停止
        case Stop:{
            digitalWrite(Motor0_Pin_0, LOW);
            digitalWrite(Motor0_Pin_1, LOW);
            digitalWrite(Motor1_Pin_0, LOW);
            digitalWrite(Motor1_Pin_1, LOW);
            delay(time);
        }
    }
}

/*---------------------------------------------------------------
 * 传感器数据追踪函数
 * 默认使用3个传感器巡线，从左到右依次为0、1、2
---------------------------------------------------------------*/
/*void track() {
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
}*/

void setup() {
    // 直流电机输出引脚配置
    // Motor0:
    pinMode(Motor0_Pin_0, OUTPUT);
    pinMode(Motor0_Pin_1, OUTPUT);
    // Motor1:
    pinMode(Motor1_Pin_0, OUTPUT);
    pinMode(Motor1_Pin_1, OUTPUT);
    //Sensor3:
    pinMode(Sensor3_pin, INPUT);
}

void loop() {
    //track();
    delay(500);
    if(!digitalRead(Sensor3_pin)){
        dc_motor_drive(Stop, 500);
        dc_motor_drive(Back, 1000);
        dc_motor_drive(Left, 500);
    } else {
        dc_motor_drive(Front, 500);
    }
}
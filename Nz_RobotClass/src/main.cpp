#include <Arduino.h>
#include <Servo.h>

// #define Sensor0 
// #define Sensor1
// #define Sensor2

#define Sensor3_pin 14

Servo servo_pin_3;

#define TRIG_Pin 15
#define ECHO_Pin 14

/*---------------------------------------------------------------
* 直流电机驱动函数：前进
* time:ms
---------------------------------------------------------------*/
void front(int time)
{
    digitalWrite(5 , HIGH);
    digitalWrite(6 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(10 , LOW);
    delay(time);
}

/*---------------------------------------------------------------
* 直流电机驱动函数：后退
* time:ms
---------------------------------------------------------------*/
void back(int time)
{
    digitalWrite(5 , LOW);
    digitalWrite(6 , HIGH);
    digitalWrite(9 , LOW);
    digitalWrite(10 , HIGH);
    delay(time);
}

/*---------------------------------------------------------------
* 直流电机驱动函数：向左
* time:ms
---------------------------------------------------------------*/
void left(int time)
{
    digitalWrite(5 , HIGH);
    digitalWrite(6 , LOW);
    digitalWrite(9 , LOW);
    digitalWrite(10 , LOW);
    delay(time);
}

/*---------------------------------------------------------------
* 直流电机驱动函数：向右
* time:ms
---------------------------------------------------------------*/
void right(int time)
{
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(9 , HIGH);
    digitalWrite(10 , LOW);
    delay(time);
}

/*---------------------------------------------------------------
* 直流电机驱动函数：前进
* time:ms
---------------------------------------------------------------*/
void stop(int time)
{
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(9 , LOW);
    digitalWrite(10 , LOW);
    delay(time);
}

/*---------------------------------------------------------------
* 超声波传感器函数
---------------------------------------------------------------*/
float SR04() {
    digitalWrite(TRIG_Pin, LOW);
    delayMicroseconds(2);
    digitalWrite(TTIG_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_Pin, LOW);
}

/*---------------------------------------------------------------
* 传感器数据追踪函数
* 默认使用3个传感器巡线，从左到右依次为0、1、2
---------------------------------------------------------------*/
// void track() {
//     int data[3];

//     //读取三个传感器值
//     data[0] = digitalRead(sensor0);
//     data[1] = digitalRead(sensor1);
//     data[2] = digitalRead(sensor2);

//     //左右都没有检测到，直行
//     if(!data[0] && !data[1] && !data[2]) {
//         dc_motor_drive(front, 50);
//     }

//     //左边检测到黑线
//     if(data[0] || data[1]) {
//         dc_motor_drive(left, 50);
//     }
    
//     //右边检测到黑线
//     if(data[1] || data[2]) {
//         dc_motor_drive(right, 50);
//     }
// }

/*---------------------------------------------------------------
* 初始化
---------------------------------------------------------------*/
void setup() {

    // 直流电机输出引脚配置
    // Motor0:
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    // Motor1:
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    //Sensor3:
    pinMode(Sensor3_pin, INPUT);

    //SR04:
    Serial.begin(9600);
    pinMode(TRIG_Pin, OUTPUT);
    pinMode(ECHO_Pin, INPUT);

    //Servo:
    servo_pin_3.attach(3);
}

/*---------------------------------------------------------------
* 主循环
----------------------------------------------------------------*/
void loop() {
    servo_pin_3.write(90);
    delay(1000);
    servo_pin_3.write(120);
    delay(1000);
    servo_pin_3.write(30);
    delay(1000);
}
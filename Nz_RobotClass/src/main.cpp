#include <Arduino.h>
#define LED_pin 13

void dc_motor_drive(, mode1, mode2) {
    //直流电机驱动函数

}

void setup() {
    // put your setup code here, to run once:
    pinMode(LED_pin, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(LED_pin, HIGH);
    delay(2000);
    digitalWrite(LED_pin, LOW);
    delay(2000);
}
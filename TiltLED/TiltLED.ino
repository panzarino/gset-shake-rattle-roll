#include "Wire.h"
#include "ADXL345.h"

ADXL345 accel;
int16_t ax, ay, az;
#define LED_PIN 13

void setup() {
    Wire.begin();
    accel.initialize();
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    accel.getAcceleration(&ax, &ay, &az);
    if (abs(ax)>20 && abs(ay)>20){
      digitalWrite(LED_PIN, true);
    }
    else {
      digitalWrite(LED_PIN, false);
    }
    delay(500);
}

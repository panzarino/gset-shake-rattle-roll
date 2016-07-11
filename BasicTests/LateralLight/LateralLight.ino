#include "Wire.h"
#include "ADXL345.h"

ADXL345 accel;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  accel.initialize();
}

void loop() {
  accel.getAcceleration(&ax, &ay, &az);
  if ((abs(ax) > 40 || abs(ay) > 40) && abs(az)<260){
    analogWrite(13, 255);
  }
  else {
    analogWrite(13, 0);
  }
}

#include "Wire.h"
#include "ADXL345.h"

ADXL345 accel;
int16_t ax, ay, az;

void setup() {
  Wire.begin();
  accel.initialize();
}

void loop() {
  accel.getAcceleration(&ax, &ay, &az);
  float mag = sqrt(sq(ax)+sq(ay)+sq(az));
  if (!isnan(mag)){
    float bright = map(mag, 0, 200, 0, 255);
    analogWrite(13, bright);
  }
}

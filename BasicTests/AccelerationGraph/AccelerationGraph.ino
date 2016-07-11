#include "Wire.h"
#include "ADXL345.h"

ADXL345 accel;
int16_t ax, ay, az;

void setup() {
  Wire.begin();
  accel.initialize();
  Serial.begin(9600);
  while (!Serial) {}
}

void loop() {
  accel.getAcceleration(&ax, &ay, &az);
  Serial.println(sqrt(sq(ax)+sq(ay)+sq(az)));
}

#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>
#include <ITG3200.h>

ADXL345 acc;
ITG3200 gyro;
#define TIME_STEP 100
float roll = 0;
float pitch = 0;
double axsum = 0;
double aysum = 0;
double azsum = 0;
double gxsum = 0;
double gysum = 0;
double gzsum = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  acc.initialize();
  gyro.initialize();
}

void loop() {
  int16_t aX, aY, aZ;
  acc.getAcceleration(&aX, &aY, &aZ);
  int16_t gx, gy, gz;
  gyro.getRotation(&gx, &gy, &gz);
  axsum += aX;
  aysum += aY;
  azsum += aZ;
  gxsum += gx;
  gysum += gy;
  gzsum += gz;
  count++;
  delay(TIME_STEP);
  Serial.print("AX: ");
  Serial.println(axsum/count);
  Serial.print("AY: ");
  Serial.println(aysum/count);
  Serial.print("AZ: ");
  Serial.println(azsum/count);
  Serial.print("GX: ");
  Serial.println(gxsum/count);
  Serial.print("GY: ");
  Serial.println(gysum/count);
  Serial.print("GZ: ");
  Serial.println(gzsum/count);
  // AX: 20.09
  // AY: 7.69
  // AZ: 245.04
  // GX: -10.12
  // GY: -26.32
  // GZ: 11.66
}

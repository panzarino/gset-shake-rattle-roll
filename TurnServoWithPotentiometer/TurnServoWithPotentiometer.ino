#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  int val = analogRead(A0);
  val = map(val, 0, 1023, 0, 180);
  servo.write(val);
  delay(15);
}

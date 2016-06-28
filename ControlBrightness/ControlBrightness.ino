void setup() {}

void loop() {
  int val = analogRead(A0);
  val = 1023-val;
  int output = map(val, 0, 1023, 0, 255);
  analogWrite(3, output);
}

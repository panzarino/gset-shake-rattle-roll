void setup() {
  Serial.begin(9600);
  while (!Serial){}
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
}

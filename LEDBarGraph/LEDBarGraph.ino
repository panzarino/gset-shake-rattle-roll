void setup() {}

void loop() {
  int val = analogRead(A0);
  val = 1023-val;
  int converted = map(val, 0, 1023, 0, 255);
  int output1 = 0, output2 = 0, output3 = 0;
  if (converted <= 85){
    output1 = converted;
  }
  else if (converted <= 170){
    output1 = 85;
    output2 = converted-85;
  }
  else {
    output1 = 85;
    output2 = 85;
    output3 = converted-170;
  }
  output1 = map(output1, 0, 85, 0, 255);
  output2 = map(output2, 0, 85, 0, 255);
  output3 = map(output3, 0, 85, 0, 255);
  analogWrite(3, output1);
  analogWrite(6, output2);
  analogWrite(11, output3);
}

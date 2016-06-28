// run on board power on
void setup() {
  // pin 13 is output
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  while (!Serial){}
}

void loop() {
  // read data
  String val = Serial.readString();
  // check if says on or off
  if (val == "on"){
    digitalWrite(13, HIGH);
  }
  else if (val == "off"){
    digitalWrite(13, LOW);
  }
}

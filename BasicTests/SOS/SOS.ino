// run on board power on
void setup() {
  // pin 13 is output
  pinMode(13, OUTPUT);
}

// blink led
void blink(int len, int wait){
  digitalWrite(13, HIGH);
  delay(len);
  digitalWrite(13, LOW);
  delay(wait);
}

// keeps looping resulting in blink
void loop() {
  // S
  for (int x = 0; x < 3; x++) {
    blink(150, 150);    
  }
  delay(300);
  // O
 for (int x = 0; x < 3; x++) {
    blink(400, 150);    
  }
  delay(300);
  // S
  for (int x = 0; x < 3; x++) {
    blink(150, 150);
  }
  delay(800);
}

import processing.serial.*;

Serial serial;
int x = 1;
float inByte = 0;

void setup() {
  size(400, 300);
  serial = new Serial(this, Serial.list()[0], 9600);
  serial.bufferUntil('\n');
  background(69, 139, 116);
}

void draw() {
  stroke(0, 80, 80);
  line(x, height, x, height - inByte);
  if (x >= width) {
    x = 0;
    background(69, 139, 116);
  } else {
    x++;
  }
}

void serialEvent(Serial serial) {
  String inString = serial.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    inByte = float(inString);
    inByte = map(inByte, 0, 1023, 0, height);
  }
}
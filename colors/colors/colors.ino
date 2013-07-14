const int rLed = 9;
const int gLed = 10;
const int bLed = 11;

const int rSensor = A2;
const int gSensor = A1;
const int bSensor = A0;

void setup() {
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  Serial.begin(9600);
}

int scaleToRGB(int rawValue, int maxValue) {
  return ((float) rawValue / maxValue) * 255;
}

int getValue(int sensor) {
  int val = analogRead(sensor);
  delay(5);
  return val;
}

void loop() {
  int rVal = scaleToRGB(getValue(rSensor), 1023);
  int gVal = scaleToRGB(getValue(gSensor), 1023);
  int bVal = scaleToRGB(getValue(bSensor), 1023);
  Serial.print("\nR:");
  Serial.print(rVal);
  Serial.print("G:");
  Serial.print(gVal);
  Serial.print("B:");
  Serial.print(bVal);
  analogWrite(rLed, rVal);
  analogWrite(gLed, gVal);
  analogWrite(bLed, bVal);
}

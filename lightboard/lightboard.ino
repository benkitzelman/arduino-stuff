#include "lightboard.h";
int switchState = 0;
LedState ledStates[3];
LedState redA = {3, 100, 0};
LedState redB = {4, 250, 0};
LedState blue = {5, 500, 0};
  
void setup () {
  ledStates[0] = redA;
  ledStates[1] = redB;
  ledStates[2] = blue;

  pinMode(2, INPUT);
  pinMode(redA.pinNumber, OUTPUT);
  pinMode(redB.pinNumber, OUTPUT);
  pinMode(blue.pinNumber, OUTPUT);

  Serial.begin(9600);
  Serial.write("\nSetup complete...");
}

void loop() {
  switchState = digitalRead(2);
  Serial.print("\nSwitch state:");
  Serial.print(switchState);
  (switchState == 0) ? stopBlink() : startBlink();
}

bool isLedOn(LedState *led) {
  !!digitalRead(led->pinNumber);
}

void turnOn(LedState *led) {
  digitalWrite(led->pinNumber, HIGH);
//  Serial.print("\nON:");
//  print_led(led);
}

void turnOff(LedState *led) {
  digitalWrite(led->pinNumber, LOW);
//  Serial.print("\nOFF:");
//  print_led(led);
}

void toggle(LedState *led) {
  int ts = millis();
  if((ts - led->lastChangeTS) < led->delayMS) return;
  
  digitalWrite( led->pinNumber, !digitalRead(led->pinNumber));
  led->lastChangeTS = ts;
}

void print_led(LedState *led) {
  Serial.print("PIN:");
  Serial.print(led->pinNumber);
  Serial.print(" DELAY (ms):");
  Serial.print(led->delayMS);
  Serial.print(" LastChange (ms):");
  Serial.print(led->lastChangeTS);
  Serial.print(" ON?:");
  Serial.print(isLedOn(led));
  Serial.print(bitRead(PORTD, led->pinNumber));
}

void startBlink() {
  int currentMS = millis();
  int i;
  for(i=0; i < sizeof(ledStates) / sizeof(LedState); i++) {
    LedState *led = &ledStates[i];
    toggle(led);
  }  
}

void stopBlink() {
//  Serial.print("\nStopBlink:");
  int i;
  for(i=0; i < sizeof(ledStates) / sizeof(LedState); i++) {
    LedState *led = &ledStates[i];
    turnOff(led);
    led->lastChangeTS = millis();
  }
}


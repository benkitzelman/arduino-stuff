const int tempSensor = A0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.begin(9600);
  Serial.println("Setup complete....");
}

float getTemp() {
  int val       = analogRead(tempSensor);
  float voltage = val / 1024.0 * 5.0;
  return (voltage - 0.5) * 100;
}

void loop() {
  float temp = getTemp();
  Serial.print(temp);
  Serial.print("C\n");

  if(temp < 18.0){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else if(temp < 30.0){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
}

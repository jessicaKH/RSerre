const int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humidity = analogRead(0); 
  Serial.println(humidity);
  delay(2000);

  if (humidity==1023){
    digitalWrite(relayPin, HIGH); // on allume la pompe
    
  } else {
    digitalWrite(relayPin, LOW); // on éteint la pompe
    
  }

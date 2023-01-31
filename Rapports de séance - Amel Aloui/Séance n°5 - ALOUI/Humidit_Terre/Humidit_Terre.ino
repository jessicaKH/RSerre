// CODE POUR LE CAPTEUR D'HUMIDITÉ DE LA TERRE
void setup() {
  Serial.begin(9600);

}

void loop() {
  int humidity = analogRead(0); 
  Serial.println(humidity);
  delay(2000);

}

// inclure les librairies
#include <DHT.h> // librairie pour le capteur de température DHT22
#include <LiquidCrystal_I2C.h> // librairie pour l'écran LCD
#define DHTPIN 2 // Definit la broche de l'Arduino sur laquelle la broche DATA du capteur est reliee -> broche 2 
#define DHTTYPE DHT22 // Definit le type de capteur utilisé

#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
int mess = 0;

DHT dht(DHTPIN,DHTTYPE); // Déclare un objet de type DHT, Il faut passer en parametre du constructeur de l'objet la broche et le type de capteur

#define ventilateurPIN 4 // broche 4 de l'arduino -> pour ventilateur 
LiquidCrystal_I2C lcd(0x27,16,2); //16 colonnes et 2 lignes pour l'écran LCD

void setup(){  
  pinMode(ventilateurPIN,OUTPUT); //règle la broche 1 de l'arduino en mode sortie
  lcd.init(); // initialisation de l’afficheur 
  lcd.backlight(); //lumière pour l'écran
  dht.begin(); // Initialise le capteur DHT22
  Serial.begin(9600);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(9600);
  digitalWrite(ventilateurPIN,LOW);
} 

void loop(){
  
  float t = dht.readTemperature(); // récupération de la température
  float h = dht.readHumidity(); // récupération de l'humidité de l'air
  
  //............
  lcd.clear(); // initialisation de l'écran LCD  
  lcd.setCursor(2,0); //initialisation des lignes et colonnes de l'écran lCD -> affichage température   
  lcd.print("temperature : "); 
  lcd.setCursor(2,1);
  lcd.print(t);  
  lcd.print(" degres"); 
  //............

  if(mess==49){ // SI on allume le vent sur l'appli -> on active le ventilateur
   digitalWrite(ventilateurPIN,HIGH); // le ventilateur se met à tourner
  } else { // SI la temp <= 25 degrés -> on éteint le ventilateur
      digitalWrite(ventilateurPIN,LOW); // le ventilateur s'arrête
  }

  if(mess==54||mess==0){ // AUTOMATISATION DU VENTILATEUR : QUAND ON ALLUME LA SERRE OU QUAND ON ACTIVE L'AUTOMATISATION
    if(t>19.5){ // SI la temp > 19.5 degrés -> on active le ventilateur
      digitalWrite(ventilateurPIN,HIGH); // le ventilateur se met à tourner
    } else{ // SI la temp <= 25 degrés -> on éteint le ventilateur
      digitalWrite(ventilateurPIN,LOW); // le ventilateur s'arrête
    }
  }
 
     
  delay(2000);  // Attend 2 secondes avant de reboucler

  
  //.............

  while (BlueT.available()>0) {
    mess=BlueT.read();
    Serial.print("Bluetooth lit : ");
    Serial.println(mess);
  }  

  BlueT.print(t);
  BlueT.print(":");
  BlueT.print(h);
  BlueT.println(" ");

  Serial.print(t);
  Serial.print(":");
  Serial.print(h);
  Serial.println(" ");
   
} 

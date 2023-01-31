// inclure les librairies
#include <DHT.h> // librairie pour le capteur de température DHT22
#include <LiquidCrystal_I2C.h> // librairie pour l'écran LCD
#define DHTPIN 2 // Definit la broche de l'Arduino sur laquelle la broche DATA du capteur est reliee -> broche 2 
#define DHTTYPE DHT22 // Definit le type de capteur utilisé

DHT dht(DHTPIN,DHTTYPE); // Déclare un objet de type DHT, Il faut passer en parametre du constructeur de l'objet la broche et le type de capteur

#define ventilateurPIN 1 // broche 1 de l'arduino -> pour ventilateur 
LiquidCrystal_I2C lcd(0x27,16,2); //16 colonnes et 2 lignes pour l'écran LCD

void setup(){  
  pinMode(ventilateurPIN,OUTPUT); //règle broche 1 de l'arduino en mode sortie
  lcd.init(); // initialisation de l’afficheur 
  lcd.backlight(); //lumière pour l'écran
  dht.begin(); // Initialise la capteur DHT22
} 

void loop(){ 
  float t = dht.readTemperature(); // récupération de la température
  lcd.clear(); // initialisation de l'écran LCD  
  lcd.setCursor(2,0); //initilisation des lignes et colonnes de l'écran lCD -> affichage température   
  lcd.print("temperature : "); 
  lcd.setCursor(2,1);
  lcd.print(t);  
  lcd.print(" degres");  
  //digitalWrite(ventilateurPIN,HIGH);
  //delay(2000);
  //digitalWrite(ventilateurPIN,LOW);

  
  if (t > 10) { // si la température est supérieure à 25 degrés, on active le ventilateur
    digitalWrite(ventilateurPIN,HIGH); // le ventilateur se met à tourner 
  } else { // si la température est est inférieure ou égale à 25 degrés, on éteins le ventilateur
    digitalWrite(ventilateurPIN,LOW); // le ventilateur s'arrête
  
  } 
  
  delay(2000);  // Attend 2 secondes avant de reboucler
} 

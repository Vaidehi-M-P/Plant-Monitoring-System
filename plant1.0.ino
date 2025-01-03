
#include "DHT.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN D3  
#define DHTTYPE DHT11   // DHT 11


const int buzzer=D6;
const int LED=D7;
int i;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

    pinMode(buzzer,OUTPUT);
    pinMode(D4,INPUT);  

    pinMode(D5,INPUT);
    pinMode(LED,OUTPUT);

  dht.begin();

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PLANT MONITORING");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  
  delay(3000);
  lcd.clear();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  if(digitalRead(D4)==1)
{
  digitalWrite(buzzer,LOW);
  
}

else
{
  digitalWrite(buzzer,HIGH);
  delay(500);
}

int sensorValue = digitalRead(D5);   // read the input on analog pin 0

  float voltage = sensorValue;   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)

  Serial.println(voltage); // print out the value you read

  if(voltage==1)
{
  digitalWrite(LED,LOW);
  
}

else
{
  digitalWrite(LED,HIGH);
  delay(100);
}
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  lcd.setCursor(0,0);
  lcd.print("HUM");
   lcd.setCursor(7, 0);
  lcd.print(h);
   lcd.setCursor(0,1);
  lcd.print("TEMP");
  lcd.setCursor(7, 1);
  lcd.print(t);



}

#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;

#define DHT11_PIN 2

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(DHT11_PIN, INPUT);
  lcd.begin(16, 2);
  lcd.print("Sicaklik: ");
  lcd.setCursor(0, 1);
  lcd.print("Nem: ");
}

void loop() {
  int readData = DHT.read11(DHT11_PIN);

  if (readData == DHTLIB_OK) {
    float temperature = DHT.temperature;
    float humidity = DHT.humidity;

    displayTemperature(temperature);
    displayHumidity(humidity);
  }

  delay(2000);
}

void displayTemperature(float temperature) {
  lcd.setCursor(10, 0);
  lcd.print(temperature);
  lcd.print(" C");
}

void displayHumidity(float humidity) {
  lcd.setCursor(6, 1);
  lcd.print(humidity);
  lcd.print("%");
}

const int pinLM35 = 34;

float llegirTemperatura() {
  int lectura = analogRead(pinLM35);
  float voltatge = lectura * (3.3 / 4095.0);
  float temperatura = voltatge * 100.0;
  return temperatura;
}

void setup() {
  Serial.begin(115200);
  Serial.println("GreenFarm Monitor iniciat!");
}

void loop() {
  float temp = llegirTemperatura();
  Serial.print("Temperatura: ");
  Serial.print(temp, 1);
  Serial.println(" °C");
  delay(2000);
}

#include <WiFi.h>

const char* ssid = "El_teu_WiFi";
const char* password = "La_teva_contrasenya";
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
  WiFi.begin(ssid, password);
  Serial.print("Connectant");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnectat! IP: " + WiFi.localIP().toString());
}

void loop() {
  float temp = llegirTemperatura();
  Serial.print("Temperatura: ");
  Serial.print(temp, 1);
  Serial.println(" °C");
  delay(2000);
}

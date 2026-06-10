#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "El_teu_WiFi";
const char* password = "La_teva_contrasenya";
const int pinLM35 = 34;
WebServer server(80);

float llegirTemperatura() {
  int lectura = analogRead(pinLM35);
  float voltatge = lectura * (3.3 / 4095.0);
  float temperatura = voltatge * 100.0;
  return temperatura;
}

void handleRoot() {
  server.send(200, "text/plain", "Hola des de GreenFarm!");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("IP: " + WiFi.localIP().toString());
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

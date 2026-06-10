#include <WiFi.h>
#include <WebServer.h>

// =====================
// CONFIGURACIÓ
// =====================
const char* ssid = "El_teu_WiFi";
const char* password = "La_teva_contrasenya";
const int pinLM35 = 34;

WebServer server(80);

// =====================
// ISSUE #2 - Lectura LM35
// =====================
float llegirTemperatura() {
  int lectura = analogRead(pinLM35);
  float voltatge = lectura * (3.3 / 4095.0);
  float temperatura = voltatge * 100.0;
  return temperatura;
}

// =====================
// ISSUE #5 #6 #7 - Pàgina web amb dades i alertes
// =====================
void handleRoot() {
  float temp = llegirTemperatura();

  String color, missatge;
  if (temp >= 35) {
    color = "#ef4444";
    missatge = "⚠️ Temperatura crítica! Reg urgent!";
  } else if (temp >= 28) {
    color = "#f97316";
    missatge = "🌡️ Temperatura alta. Considera regar aviat.";
  } else {
    color = "#4ade80";
    missatge = "✅ Temperatura correcta. No cal regar.";
  }

  String html = "<!DOCTYPE html><html lang='ca'><head><meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>GreenFarm Monitor</title><style>";
  html += "body{font-family:Arial;background:#0f172a;color:white;text-align:center;padding:30px;}";
  html += "h1{color:#4ade80;}";
  html += ".card{background:#1e293b;border-radius:12px;padding:30px;display:inline-block;margin-top:20px;}";
  html += ".valor{font-size:56px;font-weight:bold;color:" + color + ";}";
  html += ".etiqueta{color:#94a3b8;font-size:14px;margin-bottom:10px;}";
  html += ".alerta{margin-top:25px;font-size:20px;color:" + color + ";}";
  html += "</style></head><body>";
  html += "<h1>🌱 GreenFarm Monitor</h1>";
  html += "<div class='card'>";
  html += "<div class='etiqueta'>Temperatura actual</div>";
  html += "<div class='valor'>" + String(temp, 1) + "°C</div>";
  html += "</div>";
  html += "<div class='alerta'>" + missatge + "</div>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// =====================
// ISSUE #1 #3 #4 - Setup
// =====================
void setup() {
  Serial.begin(115200);
  Serial.println("GreenFarm Monitor iniciat!");

  // Connexió WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connectant");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnectat! IP: " + WiFi.localIP().toString());

  // Servidor web
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor web iniciat!");
}

// =====================
// LOOP
// =====================
void loop() {
  server.handleClient();

  // Mostrar temperatura pel Serial Monitor
  float temp = llegirTemperatura();
  Serial.print("Temperatura: ");
  Serial.print(temp, 1);
  Serial.println(" °C");

  delay(2000);
}

void handleRoot() {
  float temp = llegirTemperatura();

  String html = "<!DOCTYPE html><html lang='ca'><head><meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>GreenFarm Monitor</title><style>";
  html += "body{font-family:Arial;background:#0f172a;color:white;text-align:center;padding:30px;}";
  html += "h1{color:#4ade80;}";
  html += ".card{background:#1e293b;border-radius:12px;padding:30px;display:inline-block;margin-top:20px;}";
  html += ".valor{font-size:56px;font-weight:bold;color:#4ade80;}";
  html += ".etiqueta{color:#94a3b8;font-size:14px;margin-bottom:10px;}";
  html += "</style></head><body>";
  html += "<h1>🌱 GreenFarm Monitor</h1>";
  html += "<div class='card'>";
  html += "<div class='etiqueta'>Temperatura actual</div>";
  html += "<div class='valor'>" + String(temp, 1) + "°C</div>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

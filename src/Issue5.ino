void handleRoot() {
  String html = R"(
<!DOCTYPE html><html lang='ca'>
<head>
  <meta charset='UTF-8'>
  <title>GreenFarm Monitor</title>
  <style>
    body { font-family: Arial; background: #0f172a; color: white; text-align: center; padding: 30px; }
    h1 { color: #4ade80; }
    .card { background: #1e293b; border-radius: 12px; padding: 30px; display: inline-block; margin-top: 20px; }
    .valor { font-size: 56px; font-weight: bold; color: #4ade80; }
    .etiqueta { color: #94a3b8; font-size: 14px; margin-bottom: 10px; }
  </style>
</head>
<body>
  <h1>🌱 GreenFarm Monitor</h1>
  <div class='card'>
    <div class='etiqueta'>Temperatura actual</div>
    <div class='valor'>--°C</div>
  </div>
</body></html>
  )";
  server.send(200, "text/html", html);
}

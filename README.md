GreenFarm Monitor IoT

Projecte IoT per a la monitoritzacio de temperatura en una granja intel·ligent.

Descripcio

Sistema de monitoritzacio de temperatura en temps real utilitzant una ESP32 i un sensor LM35.
Quan la temperatura es massa alta, el sistema avisa a traves d'una pagina web accessible
des de qualsevol dispositiu connectat a la mateixa xarxa WiFi.

Hardware necessari

Component       Quantitat
ESP32           1
Sensor LM35     1
Cables          3

Logica d'alertes

Temperatura     Estat       
Menys de 28C    Normal      
28C - 34C       Alta        
35C o mes       Critica     

Com executar-lo

Obre src/main.ino amb Arduino IDE.
Canvia el WiFi i la contrasenya al codi.
Selecciona la placa ESP32.
Puja el codi a la placa.
Obre el Serial Monitor a 115200 baud.
Accedeix a la IP que apareix pel navegador.

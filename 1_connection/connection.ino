#include <ESP8266WiFi.h>
void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("Start");
   WiFi.begin("<SSID>","<Password">);
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");
  }
  Serial.println("Connected");
}
void loop() { }
 

 

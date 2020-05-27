#include "ESP8266WiFi.h"

void setup() {
Serial.begin(9600);
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Setup done");
  Serial.println("scan start");
  
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  
  if (n == 0) {
    Serial.println("no networks found");
  } 
  else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.println(")");
      delay(10);
  }
}

void loop() { }
 

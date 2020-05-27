#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "8ab230325f254db18793cbe60350ec45";
char ssid[] = "Riverboat";
char pass[] = "Riverboat@456";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

#include <ESP8266WiFi.h>
#include <CayenneMQTTESP8266.h>

char Cayenneusername[] = "051f2a20-9c98-11e7-8802-49bbc5641530";
char Cayennepassword[] = "6da08bfe890ba9cfba3bccb233d93ff89bbe1905";
char CayenneclientID[] = "78d4c6d0-9e55-11e9-9636-f9904f7b864b";

void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("PLATFORUMA", "platforuma@123");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  Cayenne.begin(Cayenneusername, Cayennepassword, CayenneclientID);
}

void loop() {
  Cayenne.virtualWrite(0, (random(0, 100)));
  delay(1000);
  Cayenne.virtualWrite(1, (random(500, 1000)));
  delay(1000);
  Cayenne.virtualWrite(2, (random(5000, 10000)));
}

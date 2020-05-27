#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  delay(3000);
   WiFi.begin("Platforuma","LtwoItwo");
  Serial.println("Start");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("Host Name: ");
  Serial.println((WiFi.hostname()));
  Serial.print("Local IP: ");
  Serial.println((WiFi.localIP().toString()));
  Serial.print("Gateway IP: ");
  Serial.println((WiFi.gatewayIP().toString().c_str()));

}


void loop()
{


}

#include <ESP8266WiFi.h>

IPAddress staticIP(192,168,1,17); 
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup(){
  Serial.begin(9600);
  delay(3000);
  WiFi.disconnect();
  Serial.println("Start");
   WiFi.begin("Platforuma","LtwoItwo");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("Connected");
  
  WiFi.config(staticIP, gateway, subnet);
  WiFi.hostname("<name>") ;
  delay(2000);
  
  Serial.print("Host Name: ");
  Serial.println((WiFi.hostname()));
  Serial.print("Local IP: ");
  Serial.println((WiFi.localIP().toString()));
  Serial.print("Gateway IP: ");
  Serial.println((WiFi.gatewayIP().toString().c_str()));
}

void loop(){}

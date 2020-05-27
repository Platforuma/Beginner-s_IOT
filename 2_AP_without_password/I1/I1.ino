#include <ESP8266WiFi.h>
void setup(){
  Serial.begin(9600);
  WiFi.softAP("MODI");
  Serial.println((WiFi.softAPIP()));
  Serial.println((WiFi.softAPmacAddress()));
}
void loop(){
    Serial.println(" Connected System: ");
    Serial.println((WiFi.softAPgetStationNum()));
    delay(3000);
}

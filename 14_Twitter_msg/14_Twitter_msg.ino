#include <ESP8266WiFi.h>

WiFiClient client;

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "8Y8YRDUTZZ5CZYXO";
String tsData;

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("PLATFORUMA","platforuma@123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
}
void loop(){
    if (client.connect("api.thingspeak.com",80)) {
      tsData = "api_key=";
      tsData += thingtweetAPIKey;
      tsData += "&status=";
      tsData += "19th Feb. Back for IOT training at #platforuma";
      client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(tsData.length());
      client.print("\n\n");
      client.print(tsData);
    }

}

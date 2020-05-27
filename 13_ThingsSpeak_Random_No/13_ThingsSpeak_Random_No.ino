#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

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
}


void loop()
{
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "A6HVER6015TUHY74";
      request_string += "&";
      request_string += "field1";
      request_string += "=";
      request_string += (random(1,3));
      http.begin(request_string);
      http.GET();
      http.end();

    }
    delay(15000);

}

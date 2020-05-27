#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <ESP8266WiFi.h>

String  button;
String  slider;

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "Platforuma"
#define AIO_KEY  "c796c3685b4f47468dcf2df4013a982e"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Feed_slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Feed_slider");
Adafruit_MQTT_Subscribe Feed_button = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Feed_button");
boolean MQTT_connect();

boolean MQTT_connect() {  int8_t ret; if (mqtt.connected()) {    return true; }  uint8_t retries = 3;  while ((ret = mqtt.connect()) != 0) { mqtt.disconnect(); delay(2000);  retries--;if (retries == 0) { return false; }} return true;}

void setup()
{
  button = "";

slider = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("Hathaway satyam","Satyam@1");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));

  mqtt.subscribe(&Feed_slider);

  mqtt.subscribe(&Feed_button);

}


void loop()
{

    if (MQTT_connect()) {
      Adafruit_MQTT_Subscribe *subscription_name;
      while ((subscription_name = mqtt.readSubscription(5000))) {
        if (subscription_name == &Feed_button) {
          button = ((char *)Feed_button.lastread);
          Serial.println("Valaue for feed_button is:");
          Serial.println(button);

        }
        if (subscription_name == &Feed_slider) {
          slider = ((char *)Feed_slider.lastread);
          Serial.println("Valaue for feed_slider is:");
          Serial.println(slider);

        }

      }

    }

}

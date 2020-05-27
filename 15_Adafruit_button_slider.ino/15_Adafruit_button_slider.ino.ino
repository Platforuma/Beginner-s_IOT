#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <ESP8266WiFi.h>

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "vaibhavjain_02"
#define AIO_KEY  "aade172cab5049f1ba7cda137c08df25"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe button_feb = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/button_feb");
Adafruit_MQTT_Subscribe slider_feb = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/slider_feb");

boolean MQTT_connect();

boolean MQTT_connect() {
  int8_t ret;
  if (mqtt.connected()) {
    return true;
  }
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {
    mqtt.disconnect();
    delay(2000);
    retries--;
    if (retries == 0) {
      return false;
    }
  }
  return true;
}

void setup()
{
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
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));

  mqtt.subscribe(&button_feb);

  mqtt.subscribe(&slider_feb);

}


void loop()
{

  if (MQTT_connect()) {
    Adafruit_MQTT_Subscribe *subscription_name;
    while ((subscription_name = mqtt.readSubscription(5000))) {
      if (subscription_name == &button_feb) {
        Serial.println("Valaue for feed_button is:");
        Serial.println(((char *)button_feb.lastread));

      }
      if (subscription_name == &slider_feb) {
        Serial.println("Valaue for feed_slider is:");
        Serial.println(((char *)slider_feb.lastread));

      }

    }

  }

}

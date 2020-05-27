#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#include <ESP8266WiFi.h>

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "Platforuma"
#define AIO_KEY  "c08d06e381004506aec34e2e4cdf7ce1"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

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
  } return true;
}

Adafruit_MQTT_Publish Feed_num = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Feed_num");
Adafruit_MQTT_Publish Feed_text = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Feed_text");

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Platforuma", "LtwoItwo");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
}
void loop()
{
  if (MQTT_connect()) {
    if (Feed_num.publish(17)) {
      Serial.println("Feed Sent! :)");
    }
  } else {
    Serial.println("Feed not Sent! ");
  }
  if (MQTT_connect()) {
    if (Feed_text.publish("Platforuma is practicing Iot")) {
      Serial.println("Feed Sent! :)");
    }
  } else {
    Serial.println("Feed not Sent! ");
  }
  delay(15000);
  if (MQTT_connect()) {
    if (Feed_num.publish(51)) {
      Serial.println("Feed Sent! :)");
    }
  } else {
    Serial.println("Feed not Sent! ");
}
  if (MQTT_connect()) {
    if (Feed_text.publish("IoT is so cool")) {
      Serial.println("Feed Sent! :)");

    }

  } else {
    Serial.println("Feed not Sent! ");

  }
  delay(15000);

}

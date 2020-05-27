#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <ESP8266WiFi.h>

String  val_slider;
String  val_button;

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "Platforuma"
#define AIO_KEY  "c796c3685b4f47468dcf2df4013a982e"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/slider");
Adafruit_MQTT_Subscribe button = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/button");
boolean MQTT_connect();

boolean MQTT_connect() {  int8_t ret; if (mqtt.connected()) {    return true; }  uint8_t retries = 3;  while ((ret = mqtt.connect()) != 0) { mqtt.disconnect(); delay(2000);  retries--;if (retries == 0) { return false; }} return true;}

void setup()
{
  val_slider = "";

val_button = "";

pinMode(16,OUTPUT);
pinMode(5,OUTPUT);

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
  mqtt.subscribe(&slider);
  mqtt.subscribe(&button);
}


void loop(){
    if (MQTT_connect()) {
      Adafruit_MQTT_Subscribe *subscription_name;
      while ((subscription_name = mqtt.readSubscription(5000))) {
        if (subscription_name == &slider) {
          val_slider = ((char *)slider.lastread);
          Serial.println("Value of feed 1: ");
          Serial.println(val_slider);
          analogWrite(16,val_slider.toInt());
        }
        if (subscription_name == &button) {
          val_button = ((char *)button.lastread);
          Serial.println("Value of feed 2: ");
          Serial.println(val_button);
          if(val_button == "ON"){
            digitalWrite(5,HIGH);
            }
            else{
              digitalWrite(5,LOW);
            }
      }
    }}}

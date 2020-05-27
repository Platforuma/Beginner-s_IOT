#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0c68f7c1027a4a6d87e1f3743d0ecd2b";
char ssid[] = "Platforuma";
char pass[] = "LtwoItwo";

WidgetLED led1(V1);

BlynkTimer timer;

void blinkLedWidget(){
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}

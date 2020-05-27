#include <ESP8266WiFi.h>
#include <CayenneMQTTESP8266.h>

String  channel0_val;
String  channel1_val;

char Cayenneusername[] = "999f4ef0-523c-11e8-aa1d-033d1c994768";
char Cayennepassword[] = "1692d65f16b883d36b78917a68a8f258ad2d4960";
char CayenneclientID[] = "d04f7b10-52b8-11e8-8826-d779b3efe574";

CAYENNE_IN(0) {
  channel0_val = getValue.asString();
}

CAYENNE_IN(1) {
  channel1_val = getValue.asString();
}

void setup() {
  channel0_val = "";
  channel1_val = "";

 Serial.begin(9600);
  pinMode(16, OUTPUT);
  pinMode(0, OUTPUT);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Platforuma", "LtwoItwo");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");

  Cayenne.begin(Cayenneusername, Cayennepassword, CayenneclientID);
}

void loop() {

  Cayenne.loop();
  if (channel0_val == "1") {
    digitalWrite(16, HIGH);
  }
  else {
    digitalWrite(16, LOW);
  }

  Cayenne.loop();
  if (channel1_val == "1") {
    digitalWrite(0, HIGH);
  }
  else {
    digitalWrite(0, LOW);
  }
}

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
  httpurl = "http://";
  httpurl += IPcache;
  httpurl += "/";
  httpurl += monmessagecache;
  http.begin(httpurl);
  http.GET();
  TheHiddenAnswerOfClient = (http.getString());
  http.end();
  return TheHiddenAnswerOfClient;
}

DynamicJsonBuffer jsonBuffer(3000);
int parsing_result (JsonObject& monparam) {
  if (!monparam.success())return 0;
  else
    return 1;
}

void setup() {
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
  JsonObject& indore_condition = jsonBuffer.parseObject((SendWithAnswer("api.wunderground.com", "api/45efe88a45842f89/conditions/q/India/Indore.json")));
  if ((parsing_result(indore_condition)) == 1) {
    Serial.println("Parsing Inodre_cindition Success!");
    Serial.println("Location: ");
    Serial.println(indore_condition["current_observation"]["display_location"]["full"].as<char*>());
    Serial.println("Weather: ");
    Serial.println(indore_condition["current_observation"]["weather"].as<char*>());
    Serial.println("Temperature: ");
    Serial.println(indore_condition["current_observation"]["temperature_string"].as<char*>());
    Serial.println("Wind: ");
    Serial.println(indore_condition["current_observation"]["wind_string"].as<char*>());
  } else {
    Serial.println("Parsing Indore_condition Fail!");
  }
}

void loop() {}

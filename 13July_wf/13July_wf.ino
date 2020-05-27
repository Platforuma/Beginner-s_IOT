#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

DynamicJsonBuffer jsonBuffer(3000);
int parsing_result (JsonObject& monparam){
if (!monparam.success())return 0;
else
return 1;
}

void setup(){
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
  JsonObject& IndoreCondition = jsonBuffer.parseObject((SendWithAnswer("api.wunderground.com","api/1dd55a9762940b82/forecast/q/India/Indore.json")));
  if ((parsing_result(IndoreCondition)) == 1) {
    Serial.println("Parsing IndoreCondition Success!");
    Serial.println("Location");
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][0]["title"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][0]["fcttext"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][1]["title"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][1]["fcttext"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][2]["title"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][2]["fcttext"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][3]["title"].as<char*>());
    Serial.println(IndoreCondition["forecast"]["txt_forecast"]["forecastday"][3]["fcttext"].as<char*>());
  } else {
    Serial.println("Error!");
  }
}

void loop() {}

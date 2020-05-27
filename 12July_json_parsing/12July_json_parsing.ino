#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


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

  JsonObject& myobject = jsonBuffer.parseObject((SendWithAnswer("arduinojson.org","example.json")));
  if (1 == (parsing_result(myobject))) {
    Serial.println("Parsing successful!");
    Serial.println(myobject["sensor"].as<char*>());
    Serial.println(myobject["time"].as<char*>());
    Serial.println(myobject["data"][0].as<char*>());
    Serial.println(myobject["data"][1].as<char*>());
   } 
  else {
    Serial.println("ERROR!!");
  }
}


void loop(){}

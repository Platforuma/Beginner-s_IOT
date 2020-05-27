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

int i;
void setup()
{
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
  JsonObject& indore_condition = jsonBuffer.parseObject((SendWithAnswer("api.wunderground.com","api/235c5dcc6608a83c/forecast/q/India/Indore.json")));
  if ((parsing_result(indore_condition)) == 1) {
    Serial.println("Parse Success!");
    for (i = 0; i <= 10; i++) {
      Serial.println(indore_condition["forecast"]["txt_forecast"]["forecastday"][i]["title"].as<char*>());
      Serial.println(indore_condition["forecast"]["txt_forecast"]["forecastday"][i]["fcttext_metric"].as<char*>());
    }

  } else {
    Serial.println("Parse Fail!");

  }

}


void loop()
{


}

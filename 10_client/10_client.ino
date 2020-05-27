#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

String  i;
long  newvar;
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

void setup()
{
  i = "";
  newvar = 0;
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Hathaway satyam", "Satyam@1");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");

}


void loop()
{

  i = (SendWithAnswer("<Server_IP_address>", "Yes"));
  Serial.println("Before clear");
  Serial.println(i);
  i.remove(0, 25);
  i.remove(i.length() - 11, 11);
  Serial.println("After clear");
  Serial.println(i);
  newvar = i.toInt();
  Serial.println((2000 + newvar));
  delay(5000);

}

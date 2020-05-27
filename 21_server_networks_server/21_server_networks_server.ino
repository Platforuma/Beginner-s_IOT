#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  sensor_1;
String  sensor_2;
WiFiServer server(80);

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

void setup()
{
  sensor_1 = "";

sensor_2 = "";

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
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    
    sensor_1 = (SendWithAnswer("192.168.1.8","Yes"));
    sensor_1.remove(0, 25);
    sensor_1.remove(sensor_1.length()-11,11);
    sensor_2 = (SendWithAnswer("192.168.1.6","Yes"));
    sensor_2.remove(0, 25);
    sensor_2.remove(sensor_2.length()-11,11);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<title>Sensor Network!</title>");
    client.println("</head>");
    client.println("<body>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("Sensor Network Page");
      client.println("</h1>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println("The program started since: ");
      client.println("</span>");
      client.println("<span style=""color:#330000;font-size:14px"">");
      client.println((millis()/1000));
      client.println("</span>");
      client.println("<h1 style=""color:#ff9966"">");
      client.println("Sensor 1: ");
      client.println("</h1>");
      client.println("<span style=""color:#cc9933;font-size:14px"">");
      client.println(sensor_1);
      client.println("</span>");
      client.println("<h1 style=""color:#996633"">");
      client.println("Sensor 2: ");
      client.println("</h1>");
      client.println("<span style=""color:#333399;font-size:14px"">");
      client.println(sensor_2);
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);

}

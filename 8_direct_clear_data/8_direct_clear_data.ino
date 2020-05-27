#include <ESP8266WiFi.h>

String  client_request;
WiFiServer server(80);

void setup()
{
  client_request = "";

Serial.begin(9600);
  delay(3000);
  WiFi.disconnect();
  Serial.println("Start");
   WiFi.begin("PLATFORUMA","platforuma@123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client_request = (client.readStringUntil('\r'));
    client_request.remove(0, 5);
    client_request.remove(client_request.length()-9,9);
    Serial.println(client_request);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html> Welcome </html>");
    //client.println("Welcome");
    //client.println("</html>");
    client.stop();
    delay(1);

}

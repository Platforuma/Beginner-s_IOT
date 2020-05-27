#include <ESP8266WiFi.h>

String  ClientRequest;
WiFiServer server(80);

void setup()
{
  ClientRequest = "";

  Serial.begin(9600);
  pinMode(16, OUTPUT);
  pinMode(2, OUTPUT);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("OnePlus5T");
  while ((!(WiFi.status() == WL_CONNECTED))) {
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
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
  ClientRequest = (client.readStringUntil('\r'));
  client.flush();
  if (ClientRequest.indexOf("LED1=ON") > 0) {
    digitalWrite(16, HIGH);

  }
  if (ClientRequest.indexOf("LED1=OFF") > 0) {
    digitalWrite(16, LOW);

  }
  if (ClientRequest.indexOf("LED2=ON") > 0) {
    digitalWrite(2, HIGH);

  }
  if (ClientRequest.indexOf("LED2=OFF") > 0) {
    digitalWrite(2, LOW);

  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<h1 style=""color:#000099"">");
  client.println("LED CONTROL");
  client.println("</h1>");
  client.println("</head>");
  client.println("<body>");
  client.println("Room: 1  ");
  client.println("<a href=");
  client.println("LED1=ON");
  client.println("><button>");
  client.println("ON");
  client.println("</button></a>");
  client.println("<a href=");
  client.println("LED1=OFF");
  client.println("><button>");
  client.println("OFF");
  client.println("</button></a>");
  client.println("<br>");
  client.println("Room: 2  ");
  client.println("<a href=");
  client.println("LED2=ON");
  client.println("><button>");
  client.println("ON");
  client.println("</button></a>");
  client.println("<a href=");
  client.println("LED2=OFF");
  client.println("><button>");
  client.println("OFF");
  client.println("</button></a>");
  client.println("</body>");
  client.println("</html>");
  client.stop();
  delay(1);

}

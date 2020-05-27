#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN D1
#define ECHOPIN    D2

char auth[] = "909adc7cbb4648ecbae9872f12ff86c6";
char ssid[] = "Hathaway satyam";
char pass[] = "Satyam@1";
WidgetLCD lcd(V1);

void setup(){
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.clear(); 
  lcd.print(0, 0, "Distance in cm");
  }

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance in cm");
  long duration, distance;
  
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  digitalWrite(TRIGGERPIN, LOW);
  
  duration = pulseIn(ECHOPIN, HIGH);
  
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);
  Blynk.run();
  delay(200);
}

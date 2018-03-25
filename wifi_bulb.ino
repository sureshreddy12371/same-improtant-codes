#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip=Adafruit_NeoPixel(10,12,NEO_GRB + NEO_KHZ800);
ESP8266WebServer server(80);

void red()
{
  for(uint16_t i=0;i<10;i++)
  {
   strip.setPixelColor(i,strip.Color(255,0,0));
  }
strip.show();
}
void blue()
{
  for(uint16_t i=0;i<10;i++)
  {
   strip.setPixelColor(i,strip.Color(0,0,255));
  }
strip.show();
}void green()
{
  for(uint16_t i=0;i<10;i++)
  {
   strip.setPixelColor(i,strip.Color(0,255,0));
  }
strip.show();
}void yellow()
{
  for(uint16_t i=0;i<10;i++)
  {
   strip.setPixelColor(i,strip.Color(255,0,255));
  }
strip.show();
}
void red1()
{
  for(uint16_t i=0;i<10;i++)
  {
   strip.setPixelColor(i,strip.Color(0,0,0));
  }
strip.show();
}
void mylight()
{ 

  if(server.arg("state")=="red")
  {
    red();
   
    server.send(200,"text/plain","sucess");
    
  }
  else if(server.arg("state")=="off")
  {
   red1();    
    server.send(200,"text/plain","sucess");
  }
  else if(server.arg("state")=="green")
  {
    green();
    server.send(200,"text/plain","sucess");
  }
  else if(server.arg("state")=="blue")
  {
    blue();
    server.send(200,"text/plain","sucess");
  }
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
 strip.begin();
WiFi.begin("Jack", "na manasu2");
while(WiFi.status() !=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
  
}
Serial.println("IP Address:");
Serial.println(WiFi.localIP());

server.begin();
server.on("/light",mylight);

}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}



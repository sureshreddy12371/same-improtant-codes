#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include<Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip=Adafruit_NeoPixel(10,12,NEO_GRB + NEO_KHZ800);
BLYNK_WRITE(V0)
{
  int x=param[0].asInt();
  int y=param[1].asInt();
  int z=param[2].asInt();
for(uint16_t i=0;i<10;i++)
{
  strip.setPixelColor(i,strip.Color(x,y,z));
  
}
strip.show();
}
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
strip.begin();
Blynk.begin("1197548bb0de4f6e883106d8400d7699","Honor 7X","prasad11");

}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}

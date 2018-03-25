#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Blynk.begin("1197548bb0de4f6e883106d8400d7699","Honor 7X","prasad11");
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}

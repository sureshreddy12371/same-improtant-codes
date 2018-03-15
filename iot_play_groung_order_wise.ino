#include <ESP8266WiFi.h>
#include <MQTT.h>
#define AP_SSID     "Jnr"
#define AP_PASSWORD "venkatesh"  
#define EIOTCLOUD_USERNAME "21111112"
#define EIOTCLOUD_PASSWORD "suresh"
#define EIOT_CLOUD_ADDRESS "cloud.iot-playground.com"
#define DO_TOPIC        "/Sensor.Parameter1"
#define PIN_DO_0         D0 
#define MODULE_ID_0     0
#define PIN_DO_1         D1 
#define MODULE_ID_1     1
#define PIN_DO_2         D2  
#define MODULE_ID_2     2
#define PIN_DO_3         D3 
#define MODULE_ID_3     3
#define PIN_DO_4         D4 
#define MODULE_ID_4     4
#define PIN_DO_5         D5  
#define MODULE_ID_5     5
#define PIN_DO_6         D6 
#define MODULE_ID_6     6
#define PIN_DO_7         D7  
#define MODULE_ID_7     7



MQTT myMqtt("", EIOT_CLOUD_ADDRESS, 1883);


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  
  WiFi.begin(AP_SSID, AP_PASSWORD);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(AP_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  };

  Serial.println("WiFi connected");
  Serial.println("Connecting to MQTT server");  
  String clientName;
  uint8_t mac[6];
  WiFi.macAddress(mac);
  clientName += macToStr(mac);
  clientName += "-";
  clientName += String(micros() & 0xff, 16);
  myMqtt.setClientId((char*) clientName.c_str());
  Serial.print("MQTT client id:");
  Serial.println(clientName);
  myMqtt.onConnected(myConnectedCb);
  myMqtt.onDisconnected(myDisconnectedCb);
  myMqtt.onPublished(myPublishedCb);
  myMqtt.onData(myDataCb);
  myMqtt.setUserPwd(EIOTCLOUD_USERNAME, EIOTCLOUD_PASSWORD);  
  myMqtt.connect();
  delay(500);
  pinMode(PIN_DO_0, OUTPUT); 
  pinMode(PIN_DO_1, OUTPUT); 
  pinMode(PIN_DO_2, OUTPUT); 
  pinMode(PIN_DO_3, OUTPUT); 
  pinMode(PIN_DO_4, OUTPUT); 
  pinMode(PIN_DO_5, OUTPUT);  
  pinMode(PIN_DO_6, OUTPUT); 
  pinMode(PIN_DO_7, OUTPUT); 
 

  subscribe();
}
void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}
String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}
void subscribe()
{
    myMqtt.subscribe("/" + String(MODULE_ID_0) + DO_TOPIC);
    myMqtt.subscribe("/" + String(MODULE_ID_1) + DO_TOPIC); 
    myMqtt.subscribe("/" + String(MODULE_ID_2) + DO_TOPIC);
    myMqtt.subscribe("/" + String(MODULE_ID_3) + DO_TOPIC); 
    myMqtt.subscribe("/" + String(MODULE_ID_4) + DO_TOPIC);
    myMqtt.subscribe("/" + String(MODULE_ID_5) + DO_TOPIC);
    myMqtt.subscribe("/" + String(MODULE_ID_6) + DO_TOPIC); 
    myMqtt.subscribe("/" + String(MODULE_ID_7) + DO_TOPIC); 
   

}
void myConnectedCb() {
  Serial.println("connected to MQTT server");
  subscribe();
}
void myDisconnectedCb() {
  Serial.println("disconnected. try to reconnect...");
  delay(500);
  myMqtt.connect();
}

void myPublishedCb() {
  Serial.println("published.");
}

void myDataCb(String& topic, String& data) {  
  if (topic == String("/"+String(MODULE_ID_1)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_1, HIGH);     
    else
      digitalWrite(PIN_DO_1, LOW);
    Serial.print("D1 1:");
    Serial.println(data);
  }

if (topic == String("/"+String(MODULE_ID_0)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_0, HIGH);     
    else
      digitalWrite(PIN_DO_0, LOW);
    Serial.print("D0 0:");
    Serial.println(data);
  }
  if (topic == String("/"+String(MODULE_ID_2)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_2, HIGH);     
    else
      digitalWrite(PIN_DO_2, LOW);
    Serial.print("D2 2:");
    Serial.println(data);
  }
  if (topic == String("/"+String(MODULE_ID_3)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_3, HIGH);     
    else
      digitalWrite(PIN_DO_3, LOW);
    Serial.print("D3 3:");
    Serial.println(data);
  }
  if (topic == String("/"+String(MODULE_ID_4)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_4, HIGH);     
    else
      digitalWrite(PIN_DO_4, LOW);
    Serial.print("D4 4:");
    Serial.println(data);
     }
   if (topic == String("/"+String(MODULE_ID_5)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_5, HIGH);     
    else
      digitalWrite(PIN_DO_5, LOW);
    Serial.print("D5 5:");
    Serial.println(data);
  }
   if (topic == String("/"+String(MODULE_ID_6)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_6, HIGH);     
    else
      digitalWrite(PIN_DO_6, LOW);
    Serial.print("D6 1:");
    Serial.println(data);
  }
   if (topic == String("/"+String(MODULE_ID_7)+ DO_TOPIC))
  {
    if (data == String("1"))
      digitalWrite(PIN_DO_7, HIGH);     
    else
      digitalWrite(PIN_DO_7, LOW);
    Serial.print("D7 1:");
    Serial.println(data);
  }
   

}


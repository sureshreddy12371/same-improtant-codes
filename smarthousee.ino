#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo1;
const int buttonPin = 2;    
const int ledPin =  13;      
int buttonState = 0;  
int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;
int sensorPin4 = A3;
int sensorValue1 = 100; 
int sensorValue2 = 10;
int sensorValue3 = 50;
int sensorValue4 = 5;
int led1 = 3;
int fantemp = 4;
int plant = 5;
int theif = 6;
 void setup() 

 {
 pinMode(led1, OUTPUT);
  pinMode(plant, OUTPUT);
  pinMode(fantemp, OUTPUT);
   pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  myservo1.attach(A0);
Serial.begin(9600); 

}

void loop()

{

Serial.println("Welcome to smart house");

buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  { 
    digitalWrite(ledPin, HIGH);
    myservo1.write(90); 
    Serial.println("Now gate is open");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    myservo1.write(0); 
     Serial.println("Now gate is closed");
  }


sensorValue1 = analogRead(sensorPin1);

Serial.println(sensorValue1);
if (sensorValue1 >100)

{

Serial.println("street lights is on");

digitalWrite(led1,HIGH);

delay(1000);

}
else
{
digitalWrite(led1,LOW);

delay(sensorValue1);

}
sensorValue4 = analogRead(sensorPin4);

Serial.println(sensorValue4);
if (sensorValue4 >100)

{

Serial.println("some body enterr to to screet room");

digitalWrite(theif,HIGH);

delay(1000);

}
else
{
digitalWrite(theif,LOW);

delay(sensorValue1);

}
Serial.println("Tempeature more than narmal state");

sensorValue2 = analogRead(sensorPin2);


Serial.println(sensorValue2);
if (sensorValue2 <60)

{

Serial.println("fan is on");

digitalWrite(fantemp,HIGH);

delay(1000);

}
else
{
digitalWrite(fantemp,LOW);

delay(sensorValue2);

}
sensorValue3 = analogRead(sensorPin3);


Serial.println(sensorValue3);
if (sensorValue3 >100)

{

Serial.println("plant required water");

digitalWrite(plant,HIGH);

delay(1000);

}
else
{
digitalWrite(plant,LOW);

delay(sensorValue3);

}
}

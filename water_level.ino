int a=1;
int b=2;
int c=3;
int d=4;
int e=5;
int f=6;
int g=7;
int sensorPin = A0;
int sensorValue=0;
void setup() {
  // put your setup code here, to run once:
pinMode(1,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);

}


void loop()
{
  // put your main code here, to run repeatedly:

    Serial.println("welcome to water level indicator");
    sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);
if (sensorValue >100)

{

Serial.println("water level low");

digitalWrite(a,HIGH);

delay(1000);

}
else
{
digitalWrite(a,LOW);
delay(1000);

  



                                                                                                                                                       



}}




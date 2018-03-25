#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 10, 5, 4, 3, 2);//RS,EN,D4-D7

SoftwareSerial GPRS(11, 12); //11 = TX, 12 = RX
unsigned char buffer[64]; //port



#define fire 6
#define dc_motor1 7
#define dc_motor2 8
#define buzzer 13
int s=0;
void setup(){

pinMode(fire,INPUT);

pinMode(dc_motor1,OUTPUT);
pinMode(dc_motor2,OUTPUT);
pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
  GPRS.begin(9600); // the GPRS baud rate
  lcd.begin(16, 2);
  lcd.clear(); lcd.setCursor(4, 0);        lcd.print("WELCOME"); delay(2000);

  lcd.clear();          lcd.print("SMART GAS    ");
  lcd.setCursor(0, 1);  lcd.print("DETECTION  SYS");  delay(2000);


}

void loop()
{

  Serial.println("Gas status = ");
    Serial.println(digitalRead(fire));




if(digitalRead(fire)==0)
{
  digitalWrite(buzzer,LOW);

lcd.clear();          lcd.print("Fire detected..    ");
 // lcd.setCursor(0, 1);  lcd.print("DETECTION  SYS");


 Serial.println("d_motor ON");
     GPRS.write("AT+CMGF=1\r"); //sending SMS in text mode
    delay(1000);
    Serial.println("AT+CMGF=1\r");
    GPRS.write("AT+CMGS=\"+919966109280\"\r"); // phone number
    delay(1000);
    Serial.println("AT+CMGS=\"+919966109280\"\r");
    GPRS.write("Alert!!, Gas leakage Detected...\r"); // message
    delay(1000);
    delay(1000);
    GPRS.write(0x1A);
    //send a Ctrl+Z (end of the message)
    delay(3000);
    Serial.println("SMS sent successfully");
lcd.clear();          lcd.print("SMS sent..    ");
    digitalWrite(dc_motor1,HIGH);
    digitalWrite(dc_motor2,LOW);
       Serial.println("Door opened");
       lcd.clear();          lcd.print("Door opened");
    delay(1000);
     digitalWrite(buzzer,HIGH);
     digitalWrite(dc_motor1,LOW);
digitalWrite(dc_motor2,LOW);
delay(3000);
digitalWrite(dc_motor1,LOW);
    digitalWrite(dc_motor2,HIGH);
     Serial.println("Door closed");
      lcd.clear();          lcd.print("Door closed");
    delay(1000);

}

else
{
     lcd.clear();          lcd.print("Monitoring...");
    Serial.println("Monitoring...");
   digitalWrite(buzzer,HIGH);
  digitalWrite(dc_motor1,LOW);
digitalWrite(dc_motor2,LOW);
delay(1000);
 Serial.println("d_motor OFF");

}

}

github

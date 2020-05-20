#include<SoftwareSerial.h>
#include <Servo.h>
Servo meuServo;
SoftwareSerial meuSerial(2, 3); // RX, TX
int status = 0;

void setup() 
{  
  meuServo.attach(11);  
  meuSerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if (meuSerial.available()>0)
    status = meuSerial.read();
 if(status == '0')
 { 
      meuServo.write(80);  
 }
 else if(status == '1'){
      meuServo.write(50);
 }
}      

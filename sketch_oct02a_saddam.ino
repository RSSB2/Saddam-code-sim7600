#include<SoftwareSerial.h>
SoftwareSerial Serial1(3, 2);

#define relay 13


int sms_flag;
int relay_flag0;

void setup()
{
  delay(15000);
  Serial.begin(9600);
  Serial1.println("AT+IPR=9600");
  Serial1.end();
  Serial1.begin(9600);
  Serial1.println("ATE0");
  delay(500);
  pinMode(relay, OUTPUT);
  

}

void loop()
{
  //Serial1.println("AT");
  //delay(500);
  serialEvent();

  

  
  









}

void serialEvent()
{
  String str = "";
  while (Serial1.available())
  {
    char ch = Serial1.read();
    str += ch;I
    Serial.print(ch);

    if (str.indexOf("*LIGHT ON#") >= 0)
    {
      digitalWrite(relay, HIGH);
      relay_flag = 1;
    }

    else if (str.indexOf("*LIGHT OFF#")>=0)
    {
      digitalWrite(relay, LOW);
      relay_flag = 0;
    }


    }
  }
}

void senssms(String msg)
{
  Serial.println("Sending SMS");
  Serial1.println("AT+CMGF=1");
  delay(500);
  Serial1.println("AT+CMGS=\"8802313594\""); // ;put numbner hrer
  delay(500);
  Serial1.print(msg);
  Serial1.write(26);
  delay(5000);
}

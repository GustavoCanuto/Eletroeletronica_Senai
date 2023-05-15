/*
Teste esse circuito:
https://www.tinkercad.com/things/gmnGU03Y2lm
*/

#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//LiquidCrystal lcd(2, 3, 4, 5, 11, 12);
#define pino A0	

float temp=0.0, ultimatemp=0.0;
int temperatura = 0;


  void setup ()
{
  lcd.begin(16,2);
  lcd.clear();
  pinMode(pino, INPUT);
  
  Serial.begin(9600);
}
void lcdmsg1()
  {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print(temp);
    delay(1000);
    for (int pos=0;pos<3;pos++)
    {
      lcd.scrollDisplayLeft();
      delay(50);
  }
  for (int pos=0;pos<5;pos++)
  {
    lcd.scrollDisplayRight();
    delay(50);
  }
  lcd.noDisplay();
  delay(100);
  lcd.display();
  delay(100);
  }
void loop()
{
temp=(analogRead(pino)*(5.0/1023))/0.01;
    if (temp!=ultimatemp)
      
    {
      ultimatemp=temp;
      Serial.print ("temp: ");
      Serial.print (temp);
      Serial.print (" C");
    }
  {
lcdmsg1();
}
}
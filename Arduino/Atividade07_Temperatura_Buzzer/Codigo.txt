/*
Teste esse circuito:
https://www.tinkercad.com/things/4ovoK6gCKID
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define ledR 12
#define ledB 11
#define ledG 10
#define btn 8
#define max 4
#define pino A2
#define buzzer 9
#define ldr A0
#define led 13

float temp=0.0, ultimatemp=0.0;
int btnclicado=0, btnliberado=0, ciclo=0, vldr=0;


void setup() {
  
  lcd.begin(16,2);
  lcd.clear();

  Serial.begin(9600);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(btn, INPUT);
  pinMode(ldr, INPUT);
  
  
}

void lcdmsg(){
 
  lcd.setCursor(3,0);
  lcd.print("ATENCAO");
  lcd.setCursor(4,1);
  lcd.print("TEMPERATURA");
  delay(3000);
}

void buzze(){
  
 //tone(porta, freq, duracao);
  //notone(porta);
  //faixa freq 31hz até 4978hz
  
  tone(buzzer,500,500);
  delay(800);
}

void vermelho()
{
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, LOW);
}

void azul()
{
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
}

void verde()
{
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
}

void amarelo()
{
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
}

void trocaled()
{
  if(ciclo==0){
    vermelho();
  }
  else if(ciclo==1)
    {
    verde();
  }
  else if(ciclo==2)
    {
    azul();
  }
  else if(ciclo==3)
    {
    amarelo();
  }
  
  ciclo++;
  if(ciclo>max-1)
  {
    ciclo=0;
  }
}

void verificabtn()
{
 if(digitalRead(btn)==HIGH)
 {
	btnclicado=1;
   btnliberado=0;
 }
  else{
    btnliberado=1  ;    
  }
  if((btnclicado==1)and(btnliberado==1))
  {
    btnclicado=0;
    btnliberado=0;
    trocaled();
  }
}


void loop() {
  
  vldr=analogRead(ldr);
  if(vldr>900)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
 
  temp=(analogRead(pino)*(5.0/1023))/0.01;
        if(temp!=ultimatemp)
        {
          ultimatemp=temp;
          Serial.print("temp: ");
          Serial.print(temp);
          Serial.println(" C");
          
        }
  delay(1000);
  if(temp>90.0)
  {
    lcdmsg();
    trocaled();
    buzze();
    
  }
  else if(temp>70.0)
  {
    vermelho();
  }
  else if(temp>50.0)
  {
    amarelo();
  }
  else if(temp<49.0)
  {
    verde();
  }
  
 
}
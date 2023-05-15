/*
Teste esse circuito:
https://www.tinkercad.com/things/dhxp38ookep
*/

#define ledR 4
#define ledB 3
#define ledG 2
#define botao 7
#define maximo 3

int btnclicado=0;
int btnliberado=0;
int ciclo=0;

void setup ()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(botao, INPUT);
}
          
void vermelho ()
{
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, LOW);
}
          
void azul ()
{
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, LOW);
}
          
void verde ()
{
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, HIGH);
}

void trocaled ()
{
 if(ciclo==0)
 {
vermelho();
 }

  else if(ciclo==1)
  {
    azul();
  }
  else if(ciclo==2)
  {
    verde();
  }
ciclo++;

if (ciclo>maximo-1)  
{
ciclo=0;
}
}
          
void verificabtn()  
{
if(digitalRead(botao)==HIGH)
{
 btnclicado=1;
 btnliberado=0;
}
else
{
  btnliberado=1;
}
if((btnclicado==1)and(btnliberado==1))
{
  btnclicado=0;
  btnliberado=0;
  trocaled();
}
}

          
void loop ()
{
 verificabtn();
}
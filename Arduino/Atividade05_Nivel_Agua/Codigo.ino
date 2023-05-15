/*
Teste esse circuito:
https://www.tinkercad.com/things/3DNm8EOxGW7
*/

#define btnLiga 10
#define btnAumenta 11
#define btnDiminui 12
#define btnNvAgua 13
#define Aguagreen 2
#define AguaBlue 3
#define AguaRed 4
#define LedLiga 5
#define LedAumenta 6
#define LedDiminui 7
#define maximo 3

int estado = 0; // variável para leitura do pushbutton
int guarda_estado = LOW;
int ligado = 0;
int ciclo = 0,btnclicado=0, btnliberado=0;

void setup()
{
  pinMode(btnLiga, INPUT);
  pinMode(btnAumenta, INPUT);
  pinMode(btnDiminui, INPUT);
  pinMode(btnNvAgua, INPUT);
  pinMode(Aguagreen, OUTPUT);
  pinMode(AguaBlue, OUTPUT);
  pinMode(AguaRed, OUTPUT);
  pinMode(LedLiga, OUTPUT);
  pinMode(LedAumenta, OUTPUT);
  pinMode(LedDiminui, OUTPUT);
}


void vermelho()
{
  digitalWrite(AguaRed, HIGH);
  digitalWrite(AguaBlue, LOW);
  digitalWrite(Aguagreen, LOW);
}
          
void azul()
{
  digitalWrite(AguaRed, LOW);
  digitalWrite(AguaBlue, HIGH);
  digitalWrite(Aguagreen, LOW);
}
          
void verde()
{
  digitalWrite(AguaRed, LOW);
  digitalWrite(AguaBlue, LOW);
  digitalWrite(Aguagreen, HIGH);
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
if(digitalRead(btnNvAgua)==HIGH)
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


void loop(){

   
  
 estado = digitalRead(btnLiga);
 
// verifica se o botão (pushbutton) está pressionado
  if (estado == HIGH) {
// inverte valor da variável variable_buttonEstado
guarda_estado = !guarda_estado;
//esperera o tempo de 500ms para evitar que haja várias vezes alterações
delay(100);

  }
  if (guarda_estado == HIGH) {
// liga o led
digitalWrite(LedLiga, HIGH);
    ligado=1;
  }
  else {
// desliga o led
digitalWrite(LedLiga, LOW);
    ligado=0;
    
  }
  
  
  
  if(ligado==1)
  {
    
    verificabtn();
    
    if(digitalRead(btnAumenta) == HIGH) {

digitalWrite(LedAumenta, HIGH);
    
  }
  else if(digitalRead(btnDiminui) == HIGH) {

digitalWrite(LedDiminui, HIGH);
     
  }
    else{
      digitalWrite(LedAumenta, LOW);
      digitalWrite(LedDiminui, LOW);
    }
  
}
}
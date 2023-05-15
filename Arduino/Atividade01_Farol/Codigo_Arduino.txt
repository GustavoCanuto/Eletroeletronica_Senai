/*
Teste esse circuito:
https://www.tinkercad.com/things/6kXqx5LGCLl
*/

//varaiveis global

int red = 13,yellow = 10,green = 7;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
}

void loop()
{
  digitalWrite(green, HIGH);
  delay(10000); // 10 segundos verde ligado
  digitalWrite(green, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(2000);  // 2 segundos amarelo ligado
  digitalWrite(yellow, LOW);
  
  digitalWrite(red, HIGH);
  delay(7000);  // 7 segundos vermelho ligado
  digitalWrite(red, LOW);
  
  
}
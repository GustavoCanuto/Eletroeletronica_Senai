/*
Teste esse circuito:
https://www.tinkercad.com/things/ggQ8CwsSxeT
*/

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop()
{
  digitalWrite(12, HIGH);
   delay(500); 
  digitalWrite(12, LOW);
   delay(500); 
  
  digitalWrite(11, HIGH);
    delay(500); 
   digitalWrite(11, LOW);
   delay(500); 
  
   digitalWrite(10, HIGH);
     delay(500); 
  digitalWrite(10, LOW);
   delay(500); 
  
   digitalWrite(9, HIGH);
    delay(500);
  digitalWrite(9, LOW);
   delay(500); 
  
   digitalWrite(8, HIGH);
     delay(500); 
  
  digitalWrite(8, LOW);
   delay(500); 
  
   digitalWrite(7, HIGH);
    delay(500); 
  digitalWrite(7, LOW);
   delay(500); 
  
   digitalWrite(3, HIGH);
    delay(500); 
   digitalWrite(3, LOW);
    delay(500); 
  

  
}
/*
Teste esse circuito:
https://www.tinkercad.com/things/gmnGU03Y2lm
*/


//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int maxC=0, minC=0, maxF=0, minF=0;
int ini = 0;
const int buttonPin=8;

void setup() {
    lcd.begin(16, 2); // Define o display com 16 colunas e 2 linhas
    analogReference(INTERNAL);
    pinMode(buttonPin, INPUT_PULLUP);
    lcd.clear();
}

void loop() {  
    int sensor = analogRead(0); // Lê a temperatura do sensor
    // Define a temperatura mínima incial
    if (ini==0) {
        minC = sensor * 0.1075268817204301; // Converte para Celsius
        minF = ((sensor * 0.1075268817204301) * 1.8)+32; // Converte para Fahrenheit
        ini = 1;
    }
    int buttonState = digitalRead(buttonPin); // Verifica se o botão foi pressionado
    delay(250);
    if (buttonState == 1) {
        lcd.clear();
        celsius(sensor);
    } else {
        lcd.clear();
        fahrenheit(sensor);
    }
}

void celsius(int sensor) {
    lcd.setCursor(0,0); // Define o cursor na posição de início
    int temp = sensor * 0.1075268817204301; // Converte para Celsius
    lcd.print(temp);
    // Símbolo de grau
    lcd.print("C ");
    if (temp>maxC) {maxC=temp;}
    if (temp<minC) {minC=temp;}
    lcd.setCursor(0,1);
    lcd.print("Mx=");
    lcd.print(maxC);
    
    lcd.print("C Mn=");
    lcd.print(minC);
   
    lcd.print("C ");
}

void fahrenheit(int sensor) {
    lcd.setCursor(0,0);
    float temp = ((sensor * 0.1075268817204301) * 1.8)+32; // Converte para Fahrenheit
    lcd.print(int(temp));
    lcd.write(B11011111); // Imprime o símbolo de grau
    lcd.print("F ");
    if (temp>maxF) {maxF=temp;}
    if (temp<minF) {minF=temp;}
    lcd.setCursor(0,1);
    lcd.print("Mx=");
    lcd.print(maxF);
    lcd.write(B11011111);
    lcd.print("F Mn=");
    lcd.print(minF);
    lcd.write(B11011111);
    lcd.print("F ");
}

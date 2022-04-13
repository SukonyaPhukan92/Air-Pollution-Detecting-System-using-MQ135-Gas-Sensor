#include <LiquidCrystal.h>      //Header file for LCD
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2; //pins of LCD connected to NodeMCU
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); //lcd function from LiquidCrystal


const int aqsensor = A0;  //output of MQ135 connected to A0 pin of NodeMCU
int threshold = 250;      //Threshold level for Air Quality

void setup() {

  pinMode (aqsensor,INPUT); // MQ135 is connected as INPUT to NodeMCU 

  Serial.begin (9600);      //begin serial communication with baud rate of 9600

  lcd.clear();              // clear lcd
  lcd.begin (16,2);         // consider 16,2 lcd
}

void loop() {

  int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A0 and store it in ppm

  Serial.print("Pollution: ");  //print message in serail monitor
  Serial.print(ppm);            //print value of ppm in serial monitor
  Serial.println("%"); 
  lcd.setCursor(0,0);             // set cursor of lcd to 1st row and 1st column
  lcd.print("Pollution: ");      // print message on lcd
  lcd.print(ppm);                 // print value of MQ135


  delay (500);
}

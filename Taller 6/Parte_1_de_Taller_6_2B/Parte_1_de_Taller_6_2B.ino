#include <LiquidCrystal.h>

/*

   Fundacion Kinal
   Centro educativo técnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y visualizadores
   Paulo Calito 2020265
   Fecha: 09 de mayo 2024
   
*/

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup(){

  lcd.begin(16,2);
  lcd.setCursor(0,0);

}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Paulo");
  delay(250);
  lcd.setCursor(0,1);
  lcd.print("2020265");

}

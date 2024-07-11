/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador de revoluciones
   Dev: Paulo Calito - 2020265 
   Fecha: Jue- 02/07/2024
*/


#include <Wire.h>    
#include <LiquidCrystal_I2C.h>  

#define sensor_IR 2
#define sensor_hall 3

LiquidCrystal_I2C lcdpaulo(0x27, 16, 2); 

bool state_sensor;
volatile int  contador;
int pote;
int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

 int Interrupcion(){
  contador++ ;
 }

void setup()
{
  lcdpaulo.init(); 
  lcdpaulo.backlight(); 
  lcdpaulo.print("Contador de rev.");  
  lcdpaulo.setCursor(0, 1);
  lcdpaulo.print("No. de rev:"); 
  lcdpaulo.setCursor(13, 1);
  lcdpaulo.print("rpm"); 
  Serial.begin(9600); 
  
  
  pinMode(sensor_IR, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}
 
  
void loop()
{ 
  
  
  //parte del hall
  attachInterrupt(digitalPinToInterrupt(sensor_hall), Interrupcion, FALLING);
  lcdpaulo.setCursor(11,1);
  lcdpaulo.print(contador);  

  // PARTE DEL INFRA
 state_sensor = digitalRead(sensor_IR);

 
  if(state_sensor == LOW){
 pote = map(analogRead(A0), 0, 1023, 1, 5);
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(9, paso[i][0]);
      digitalWrite(10, paso[i][1]);
      digitalWrite(11, paso[i][2]);
      digitalWrite(12, paso[i][3]);
      delay(pote);
    }
    }
}

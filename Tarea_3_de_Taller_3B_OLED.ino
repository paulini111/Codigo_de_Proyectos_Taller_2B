
/*
   Fundacion Kinal
   Centro educativo técnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Pantalla OLED 
   Paulo Calito 2020265
   Fecha: Jue- 18/072024
*/

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
//Directivas del preprocesador

#define pot_pin       A0        //pin A0 donde conectare el potenciometro

//Constructores
Adafruit_SSD1306 oledpaulo(128,64,&Wire, -1);

//Variables
unsigned int adc_valor;

//Configuraciones
void setup() 
{

 Serial.begin(9600);  //Inicio la comunicación serial
 delay(100);          //pausa de 100 milisegundos
 Serial.println("Uso de la pantalla oled - practica 3 parte 2");
 pinMode(A0, INPUT);

 if(!oledpaulo.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   //Ciclo infinito
 }
}

void loop() 
{
  
  oledpaulo.setTextSize(1);
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 oledpaulo.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 oledpaulo.setCursor(0, 0);
 //Imprimo la cadena de texto
 oledpaulo.println("Valor del ADC");
 oledpaulo.display();
  adc_valor = analogRead(A0);       //leo el valor del canal 0 del ADC
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  oledpaulo.setTextSize(3);
  oledpaulo.setTextColor(SSD1306_WHITE);
  oledpaulo.setCursor(0,18);
  oledpaulo.println(adc_valor);
  oledpaulo.display();
  delay(150);
  oledpaulo.clearDisplay();
}

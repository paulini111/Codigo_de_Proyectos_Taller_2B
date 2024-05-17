/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6
   Dev: Paulo calito 2020265
   Fecha: 16 de mayo de 2024
*/


//Librerias a utilizar
#include <Wire.h>               
#include <LiquidCrystal_I2C.h>  
#include <Servo.h>             
#include <Keypad.h>            


//Directivas de preprocesador para la LCD
#define direccion_lcd 0x27     
#define filas 2                
#define columnas 16           

//Directicas de proceprocesador para el teclado matricial
#define filas_teclado 4       
#define columnas_teclado 4  
#define f1_teclado 9  
#define f2_teclado 8       
#define f3_teclado 7      
#define f4_teclado 6     
#define c1_teclado 5        
#define c2_teclado 4          
#define c3_teclado 3         
#define c4_teclado 2         

//Directicas de proceprocesador para el servomotor, leds y buzzer
#define pin_servo 11         
#define pin_buzz  10        
#define led_rojo  A3           
#define led_amar  A1           
#define led_verd  A2           
#define ON(pin)     digitalWrite(pin, HIGH);
#define OFF(pin)    digitalWrite(pin, LOW);


//Variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};


//Variables para el uso del servomotor
const int lock_pos = 0;      
const int unlock_pos = 90;       


//Variables donde almacenare las contraseñas
String contrasenaCerradura = "2502*";   //Variable donde almaceno la contraseña definida por el sistema
String info_recibida = "";                //Variable donde voy a ir guardando los caracteres que ingreso por medio del teclado

//variables auxiliares
byte pos_lcd = 0;     


//Constructor
LiquidCrystal_I2C lcdCerradura(direccion_lcd, columnas, filas);   
Servo ServoCerradura;                                    
Keypad tecladoCerradura = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);  


//Funciones
//Funcion utiliza para configurar pines de entrada y salida
void config_outputs(void);

//Funcion que realiza las configuraciones de la interfaz hombre - maquina
void config_HMI(void);
const float pinBuzzer = 10;

void setup()
{
  Serial.begin(9600);             //Inicio la comunicacion serial
  Serial.println("Practica 6 - Parte 2"); 
  config_outputs();           
  config_HMI();                 
  ON(led_amar);                 
  ON(led_rojo);                
  OFF(led_verd);                 
  ServoCerradura.write(0);

}



void loop()
{
  //Obtengo el valor de la tecla presionada
  char key= tecladoCerradura.getKey(); 
  
  if(key)
  {
    
    info_recibida = info_recibida + key;
    Serial.println(key);
    lcdCerradura.setCursor(pos_lcd,1);
    lcdCerradura.print("*           ");
    pos_lcd++;
    if(key == '*')
    {
      lcdCerradura.setCursor(0,1);
      lcdCerradura.print("               ");
      Serial.println(info_recibida);
      if(info_recibida == contrasenaCerradura)
      {
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Contrasena nice");
        ServoCerradura.write(90);
        delay(1000);
        ServoCerradura.write(0);
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Pue. Abierta          ");
        ON(led_verd);
        OFF(led_rojo);
        tone (pinBuzzer, 391.995, 353);
        delay(400);
        noTone(pinBuzzer);
        delay(100);
        tone (pinBuzzer, 391.995, 353);
        delay(400);
        noTone(pinBuzzer);
        delay(85);

        Serial.println("Contrasena nice");
      }
      else
      {
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Contrasena bad");
        delay(1000);
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Pue. Cerrada      ");
        OFF(led_verd);
        ON(led_rojo);
  tone (pinBuzzer, 311.127, 118); 
  delay(235);
  noTone(pinBuzzer);
  delay(50);
  tone (pinBuzzer, 466.164, 118); 
  delay(225); 
  noTone(pinBuzzer);
  delay(65);   
  tone (pinBuzzer, 391.995, 353);  
  delay(510);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 391.995, 353);
        delay(400);
        noTone(pinBuzzer);
        delay(100);
        tone (pinBuzzer, 391.995, 353);
        delay(400);
        noTone(pinBuzzer);
        delay(85);
  
        Serial.println("Contrasena bad");
        ServoCerradura.write(0);
      }
      info_recibida = "";     //limpio el string
      delay(1000);
      lcdCerradura.setCursor(0,1);
      lcdCerradura.print("Pue. Cerrada      ");
      pos_lcd = 0;
      ON(led_rojo);
      OFF(led_verd);
      ServoCerradura.write(0);
    }
  }

}


void config_outputs(void)
{
  pinMode(pin_servo, OUTPUT);
  pinMode(pin_buzz, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verd, OUTPUT);
}

void config_HMI(void)
{
  ServoCerradura.attach(pin_servo);
  lcdCerradura.init();
  lcdCerradura.backlight();
  lcdCerradura.setCursor(2,0);
  lcdCerradura.print("Bienvenidos");
  lcdCerradura.setCursor(0,1);
  lcdCerradura.print("Pue. Cerrada      ");
}

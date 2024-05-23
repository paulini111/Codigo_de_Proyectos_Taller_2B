/*

   Fundacion Kinal
   Centro educativo técnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Final de Bimestre 2
   Dev: Paulo Calito 2020265
   Fecha: Vie-24/05/2024
   
*/

//Librerias a utilizar
#include <Wire.h>               
#include <LiquidCrystal_I2C.h>  
#include <Servo.h>              
#include <Keypad.h>             


//Directivas de preprocesador para la LCD
#define direccion_lcd 0x20   
#define filas 2                //Cantidad de filas que posee la pantalla LCD
#define columnas 16            //Cantidad de columnas que posee la pantalla LCD 

//Directicas de proceprocesador para el teclado matricial
#define filas_teclado 4        //cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4     //cantidad de columnas que posee el teclado matricial.
#define f1_teclado 9          //pin conectado a la fila 1
#define f2_teclado 8         //pin conectado a la fila 2
#define f3_teclado 13         //pin conectado a la fila 2
#define f4_teclado 6         //pin conectado a la fila 4
#define c1_teclado 5           //pin conectado a la columna 1
#define c2_teclado 4           //pin conectado a la columna 2
#define c3_teclado 3          //pin conectado a la columna 3
#define c4_teclado 2           //pin conectado a la columna 4

//Directicas de proceprocesador para el servomotor, leds y buzzer
#define pin_servo 11            //pin9 conectado al servomotor

#define led_rojo  A3            //pin conectado al led rojo
#define led_amar  A1           //pin conectado al led amarillo
#define led_verd  A2            //pin conectado al led verde
#define led_azul  A0            //pin conectado al led azul

#define pin_a 7 //pin del display a 
#define pin_b 10 //pin del display f
#define pin_a 12 //pin del display g celeste

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
const int lock_pos = 0;             //posicion de 0 grados para indicar que la puerta se encuentra cerrada
const int unlock_pos = 180;          //posicion de 90 grados para indicar que la puerta se encuentra abierta


//variables auxiliares
byte pos_lcd = 0;      //posición del cursor


//Constructor
LiquidCrystal_I2C lcdK(direccion_lcd, columnas, filas);   //LCD con direccion 0x20 y tamanio 16x2
Servo ServoK;                                             //Servomotor controlado por medio del PWM en el pin9
Keypad tecladoK = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);   //teclado matricial 4x4 conectado al arduino por diversos pines


//Funciones
//Funcion utiliza para configurar pines de entrada y salida
void config_outputs(void);

//Funcion que realiza las configuraciones de la interfaz hombre - maquina
void config_HMI(void);

int contador = 0 ;
int pines[] = {A0, A1, A2, A3}; 


void setup()
{
  Serial.begin(9600);             //Inicio la comunicacion serial
  Serial.println("Practica Final");   //Envio el mensaje al monitor serie
  config_outputs();               //Realizo las configuraciones de los pines de salida
  config_HMI();                   //configuro e inicializo la pantalla LCD y el servomotor
  ServoK.write(0);
  pinMode(7, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(12, OUTPUT); 

  for (int p = 0; p < 9; p++) {
  pinMode(pines[p], OUTPUT);}
   
}

void loop()
{
  //Obtengo el valor de la tecla presionada
  char key= tecladoK.getKey(); 
  
  if (key == '1') {
     Serial.println("Contador de 0 a 99");
    
      for(int num = 0; num<=99; num++){
    contador = 300;
      
    Serial.println(num);
    delay(contador);    
    } // ofr 
    Serial.println("Conteo Finalizado");

  } // if
  
  else if (key == '2') {
    Serial.println("Contador de 99 a 0");

    for(int num = 99; num>=0; num--){
    contador = 300;
      
    Serial.println(num);
    delay(contador);
      
    } //for
    Serial.println("Conteo Finalizado");

  }  // if
  
  else if (key == '3') {
    
    Serial.println("Secuencia del Auto Fantastico");
    for (int p = 0; p<4 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(400);
    digitalWrite(pines[p], LOW);
    delay(400);}
    
    for (int p = 4; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(400);
    digitalWrite(pines[p], LOW);
    delay(400);}
    
        Serial.println("Secuencia Terminada");

    
  } // if

    else if (key == '4') {
    Serial.println("Animacion del Display");

    digitalWrite(7, HIGH);  // a
    delay(500);
    digitalWrite(7, LOW);  // a

    digitalWrite(10, HIGH);  // f
    delay(500);
    digitalWrite(10, LOW);  // f

    digitalWrite(12, HIGH);  // g
    delay(500);
    digitalWrite(12, LOW);  // g 

          Serial.println("Animacion terminada");

      }

    else if (key == '5') {
        Serial.println("Movimiento del Servo");
        ServoK.write(180);
        delay(2000);
        ServoK.write(0);
        Serial.println("Movimiento Realizado");
      }
}


void config_outputs(void)


{
  pinMode(pin_servo, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verd, OUTPUT);
  pinMode(led_azul, OUTPUT);
}

void config_HMI(void)
{
  ServoK.attach(pin_servo);
  lcdK.init();
  lcdK.backlight();
  lcdK.setCursor(4,0);
  lcdK.print("Paulo C.");
  lcdK.setCursor(0,1);
  lcdK.print("Proyecto Final2B");
}

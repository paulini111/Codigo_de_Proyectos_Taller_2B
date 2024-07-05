
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

#include <LiquidCrystal_I2C.h>
//Directivas de preprocesador para la LCD

#define direccion_lcd 0x20   
#define filas 2                //Cantidad de filas que posee la pantalla LCD
#define columnas 16            //Cantidad de columnas que posee la pantalla LCD 

#define sensor_IR 2 // sensor infra

#define canal0_pot A0 // parte del ACD Y PWM 
#define led_pwm3  3 

#define sensor_hall 4 // PARTE DEL HALL 


LiquidCrystal_I2C lcdpaulo(direccion_lcd, columnas, filas);   //LCD con direccion 0x20 y tamanio 16x2
 
//pIN DE ENTRADA DEL POTENMCIOEMTEO 
 
//Variable donde guardo el valor digital convertido por el ADC del arduino
unsigned int valor_adc_pot; 
//Variable que controle la intensidad a la que brilla el led
unsigned char brillo_led; 

bool state_sensor;   //variable donde guardo el estado logico del sensor de obstaculos Y ES PARTE DEL INFRA

bool statehall_sensor;   //variable donde guardo el estado logico del sensor de efecto hall PARTE DEL HALL 

// cosos del stepper 
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
 
void setup()
{
   Serial.begin(9600);  //Inicio la comunicación serial
  // Todos los pines en modo salida del motor
  pinMode(9, OUTPUT); //in1
  pinMode(10, OUTPUT); //in 2
  pinMode(11, OUTPUT);  //in3
  pinMode(12, OUTPUT); //in4 

  pinMode(sensor_IR, INPUT); // pin 2 como entrado. PARTE DEL INFRA

   pinMode(sensor_hall, INPUT); // PARTE DEL HALL

  pinMode(led_pwm3, OUTPUT);          //pin3 como salida // parte del adc 
  pinMode(canal0_pot, INPUT);         //pinA0 como entrada ACA VA EL POTENCIOMETRO 
  
  lcdpaulo.init(); //parte del lcd
  lcdpaulo.backlight(); 
  lcdpaulo.setCursor(0,0);
  lcdpaulo.print("Contador de revs");  

}
 
  
void loop()
{ 
     state_sensor = digitalRead(sensor_IR); ///////////////////////////////////////////// parte del infra  
     if(state_sensor == LOW) {} /////////////////---------------- DENTRO DE ESTO VA TODO LO DEMÁS PORQUE SI 
     delay(100);   

    for (int i = 0; i < 8; i++)  // parte del tormo  ESTA PARTE TIENE QUE IR DEPENDIENDO AL ADC 
    {
      digitalWrite(9, paso[i][0]);  //in 1
      digitalWrite(10, paso[i][1]);
      digitalWrite(11, paso[i][2]);
      digitalWrite(12, paso[i][3]);  //in 4
      delay(1);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     statehall_sensor = digitalRead(sensor_hall);                      //guardo el estado del pin donde tengo conectado el sensor de efecto hall
    if(statehall_sensor == LOW)
  {
    delay(10);
  }

     //guardo el valor leido por el cana analogico A0 del arduino  // PARTE DEL ADC DONDE FALTA EL CONECTADO HACIA LA VELOCIDAD DEL MOTOR 
  valor_adc_pot = analogRead(canal0_pot);   //Leo el voltaje en el pin A0 del arduino
  brillo_led = map(valor_adc_pot,0,1023,0,255);     //lo linealizo (escalo) a un valor entre 0 y 255 para poder escribirlo en el pin PWM
  analogWrite(led_pwm3, brillo_led);                //vario la intensidad del led por medio del PWM   TENER OJO CON ESTO ////////////////////////////
  delay(100);  


}

/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Proyecto Final de Taller 
    Dev: Paulo Calito 2020265
    Fecha: Jue- 27/09/2024
*/

#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define direccion_lcd 0x27    
#define filas 2               
#define columnas 16

Servo servoMotor;
LiquidCrystal_I2C lcd_paulo(direccion_lcd, columnas, filas);   

const int trigPinServo = 7;  // Pines del sensor ultrasónico para el servo
const int echoPinServo = 6;
const int trigPinComida = 5;  // Pines del sensor ultrasónico para la comida
const int echoPinComida = 4;
const int buzzerPin = 8;      

const int pulsadormanu = 2;  // Pulsador rojo
const int pulsadorauto = 3;  // Pulsador negro

int estadoPulsador = 0;
int estadoPulsador2 = 0;
long tiempoDeteccion = 0;
bool objetoDetectado = false;
bool enEspera = false;  // variable para controlar si está en espera
long tiempoEspera = 0;
bool buzzerActivado = false;  // variable para controlar el estado del buzzer
unsigned long tiempoUltimaMedida = 0;  // variable para almacenar el tiempo de la última medida

void setup() {
  lcd_paulo.init();
  lcd_paulo.backlight();
  lcd_paulo.setCursor(0, 0);
  lcd_paulo.print("Dispen. Comida");


  servoMotor.attach(9);

// pines del pulsador 
  pinMode(pulsadormanu, INPUT);
  pinMode(pulsadorauto, INPUT);

  // pines de los sensores y buzzer 
  pinMode(trigPinServo, OUTPUT);
  pinMode(echoPinServo, INPUT);
  pinMode(trigPinComida, OUTPUT);
  pinMode(echoPinComida, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // coloca el servo en la posición inicial de 0 ° 
  servoMotor.write(0);
}

void loop() {
  // esto lee los estados de los pulsadores
  estadoPulsador = digitalRead(pulsadormanu);
  estadoPulsador2 = digitalRead(pulsadorauto);

  //  control del servo en modo manual 
  if (estadoPulsador == HIGH) {
    servoMotor.write(90);  // Mueve el servo a 90 grados
    lcd_paulo.setCursor(0, 1);
    lcd_paulo.print("Manual: Activado");
  }
  else {
    servoMotor.write(0);  // Vuelve el servo a 0 grados
    lcd_paulo.setCursor(0, 1);
    lcd_paulo.print("                   ");  // 
  }

  // Control del servo en modo automático 
  if (estadoPulsador2 == HIGH) {
    servoMotor.write(90);  // Mueve el servo a 90 grados
    lcd_paulo.setCursor(0, 1);
    lcd_paulo.print("Auto: Activado ");
    delay(2000);  // Mantiene la posición durante 2 segundos
    servoMotor.write(0);  // Regresa a la posición inicial (0 grados)
    lcd_paulo.setCursor(0, 1);
    lcd_paulo.print("             ");  
  }

  // sensor de la comida 
  long duracionComida, distanciaComida;

  // Solo si han pasado 10 segundos desde la última medida
  if (millis() - tiempoUltimaMedida >= 10000) {
    // Envía un pulso de 10 microsegundos al sensor de comida
    digitalWrite(trigPinComida, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinComida, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinComida, LOW);

    duracionComida = pulseIn(echoPinComida, HIGH);
    distanciaComida = duracionComida * 0.034 / 2;

    // Solo si la distancia es de 15 cm o menos se procesa el sensor de comida
    if (distanciaComida <= 13) {
      // Si la distancia está entre 10 cm y 15 cm y el buzzer no está ya activado
      if (distanciaComida > 10 && !buzzerActivado) {
        digitalWrite(buzzerPin, HIGH);   
        lcd_paulo.setCursor(0, 1);
        lcd_paulo.print("Nivel Bajo!");
        buzzerActivado = true;  
        delay(10000);          
        digitalWrite(buzzerPin, LOW);    // Apagar el buzzer
        buzzerActivado = false; // Resetear el estado del buzzer
        lcd_paulo.setCursor(0, 1);
        lcd_paulo.print("                "); 
      }
    }
    
    // Actualiza el tiempo de la última medida
    tiempoUltimaMedida = millis();
  }

  // servo de con el ultrasonico
  long duracion, distancia;

  // Si está en espera, verificar si han pasado los 5 segundos de pausa
  if (enEspera) {
    if (millis() - tiempoEspera >= 5000) {
      enEspera = false;  // Salir del modo de espera
    }
    return;  // Si está en espera, no seguir procesando el sensor ultrasónico
  }

  digitalWrite(trigPinServo, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinServo, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinServo, LOW);

  // Lee el tiempo del pulso de retorno en el pin Echo
  duracion = pulseIn(echoPinServo, HIGH);

  distancia = duracion * 0.034 / 2;

  // Si el objeto está entre 10 cm y 20 cm
  if (distancia >= 10 && distancia <= 20) {
    if (!objetoDetectado) {
      objetoDetectado = true;
      tiempoDeteccion = millis(); 
    }

    if (millis() - tiempoDeteccion >= 2000) {
      servoMotor.write(90);  // Mueve el servo a 90 grados
      lcd_paulo.setCursor(0, 1);
      lcd_paulo.print("Perrito Act.");
      delay(2000);  // Mantiene el servo en 90 grados por 2 segundos
      servoMotor.write(0);  // Regresa a la posición inicial (0 grados)
      lcd_paulo.setCursor(0, 1);
      lcd_paulo.print("                ");  

      // Activar el modo de espera durante 5 segundos
      enEspera = true;
      tiempoEspera = millis();  // Registra el tiempo en que empieza la espera
      objetoDetectado = false;  // Reiniciar la detección de objetos
    }
  }
  else {
    objetoDetectado = false;
    tiempoDeteccion = 0;
  }

  delay(100); 

  // por si lo hago bad
}

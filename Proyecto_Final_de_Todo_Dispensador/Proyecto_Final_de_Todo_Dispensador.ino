#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define direccion_lcd 0x27    // Dirección I2C de la pantalla LCD
#define filas 2               // Cantidad de filas que posee la pantalla LCD
#define columnas 16

const int trigPinServo = 7;  // Pines del sensor ultrasónico para el servo
const int echoPinServo = 6;
const int trigPinComida = 5;  // Pines del sensor ultrasónico para la comida
const int echoPinComida = 4;
const int buzzerPin = 8;      // Pin del buzzer

Servo servoMotor;
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);   // Inicializa el objeto LCD

const int pulsadormanu = 2;  // Primer pulsador
const int pulsadorauto = 3;  // Segundo pulsador

int estadoPulsador = 0;
int estadoPulsador2 = 0;
long tiempoDeteccion = 0;
bool objetoDetectado = false;
bool enEspera = false;  // Variable para controlar si está en espera
long tiempoEspera = 0;
bool buzzerActivado = false;  // Variable para controlar el estado del buzzer
unsigned long tiempoUltimaMedida = 0;  // Variable para almacenar el tiempo de la última medida

void setup() {
  // Inicializa la pantalla LCD y muestra el mensaje inicial
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Dispen. Comida");

  // Configura el servo motor
  servoMotor.attach(9);

  // Configura los pines de los pulsadores como entrada
  pinMode(pulsadormanu, INPUT);
  pinMode(pulsadorauto, INPUT);

  // Configura los pines del sensor ultrasónico y buzzer
  pinMode(trigPinServo, OUTPUT);
  pinMode(echoPinServo, INPUT);
  pinMode(trigPinComida, OUTPUT);
  pinMode(echoPinComida, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Coloca el servo en la posición inicial
  servoMotor.write(0);
}

void loop() {
  // Lee los estados de los pulsadores
  estadoPulsador = digitalRead(pulsadormanu);
  estadoPulsador2 = digitalRead(pulsadorauto);

  // Control del servo en modo manual (primer pulsador)
  if (estadoPulsador == HIGH) {
    servoMotor.write(90);  // Mueve el servo a 90 grados
    lcd.setCursor(0, 1);
    lcd.print("Manual: Activado");
  }
  else {
    servoMotor.write(0);  // Vuelve el servo a 0 grados
    lcd.setCursor(0, 1);
    lcd.print("                   ");  // Borra la línea
  }

  // Control del servo en modo automático (segundo pulsador)
  if (estadoPulsador2 == HIGH) {
    servoMotor.write(90);  // Mueve el servo a 90 grados
    lcd.setCursor(0, 1);
    lcd.print("Auto: Activado ");
    delay(2000);  // Mantiene la posición durante 2 segundos
    servoMotor.write(0);  // Regresa a la posición inicial (0 grados)
    lcd.setCursor(0, 1);
    lcd.print("             ");  // Borra la línea
  }

  // Sensor ultrasónico para medir la comida
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
        digitalWrite(buzzerPin, HIGH);   // Activar el buzzer
        lcd.setCursor(0, 1);
        lcd.print("Nivel Bajo!");
        buzzerActivado = true;  // Marcar el buzzer como activado
        delay(10000);           // Mantenerlo activo por 10 segundos
        digitalWrite(buzzerPin, LOW);    // Apagar el buzzer
        buzzerActivado = false; // Resetear el estado del buzzer
        lcd.setCursor(0, 1);
        lcd.print("                ");  // Borra el mensaje
      }
    }
    
    // Actualiza el tiempo de la última medida
    tiempoUltimaMedida = millis();
  }

  // Control del servo mediante sensor ultrasónico
  long duracion, distancia;

  // Si está en espera, verificar si han pasado los 5 segundos de pausa
  if (enEspera) {
    if (millis() - tiempoEspera >= 5000) {
      enEspera = false;  // Salir del modo de espera
    }
    return;  // Si está en espera, no seguir procesando el sensor ultrasónico
  }

  // Envía un pulso de 10 microsegundos al pin Trig
  digitalWrite(trigPinServo, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinServo, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinServo, LOW);

  // Lee el tiempo del pulso de retorno en el pin Echo
  duracion = pulseIn(echoPinServo, HIGH);

  // Calcula la distancia (velocidad del sonido: 34300 cm/s)
  distancia = duracion * 0.034 / 2;

  // Si el objeto está entre 10 cm y 20 cm
  if (distancia >= 10 && distancia <= 20) {
    if (!objetoDetectado) {
      objetoDetectado = true;
      tiempoDeteccion = millis();  // Registra el tiempo en que se detecta el objeto
    }

    // Si se ha detectado el objeto por más de 2 segundos
    if (millis() - tiempoDeteccion >= 2000) {
      servoMotor.write(90);  // Mueve el servo a 90 grados
      lcd.setCursor(0, 1);
      lcd.print("Perrito Act.");
      delay(2000);  // Mantiene el servo en 90 grados por 2 segundos
      servoMotor.write(0);  // Regresa a la posición inicial (0 grados)
      lcd.setCursor(0, 1);
      lcd.print("                ");  // Borra el mensaje

      // Activar el modo de espera durante 5 segundos
      enEspera = true;
      tiempoEspera = millis();  // Registra el tiempo en que empieza la espera
      objetoDetectado = false;  // Reiniciar la detección de objetos
    }
  }
  else {
    // Si no se detecta el objeto o está fuera del rango, resetea la detección
    objetoDetectado = false;
    tiempoDeteccion = 0;
  }

  delay(100);  // Pequeño retardo para evitar lecturas erráticas
}

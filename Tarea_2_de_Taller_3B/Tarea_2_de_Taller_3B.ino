 /*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Tarea 2 de Taller 3B 
   Dev: Paulo Calito 2020265
   Fecha: Mie- 17/07/2024

   Link de Esquematico: https://cetkinal-my.sharepoint.com/:b:/g/personal/pcalito-2020265_kinal_edu_gt/EQKAS4tN0RBNhGYeS6KAO4cBPwc75WGPdlRUGSzoWPCODw?e=KEGZ2V 

*/

#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h>


ADXL345 acelerometro_paulo = ADXL345();
SoftwareSerial DFPlayerSerial(10, 11); // RX, TX
DFRobotDFPlayerMini Sonido;

int x, y, z;
float SloadR, valx, valy, valz, valorRES;
int Medidas;

void setup() {
  Serial.begin(9600);
  Serial.println("Uso del acelerometro ADXL345");

  acelerometro_paulo.powerOn();
  acelerometro_paulo.setRangeSetting(2);

  DFPlayerSerial.begin(9600);
  Sonido.begin(DFPlayerSerial);
  Sonido.volume(29);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
}

void loop() {


  acelerometro_paulo.readAccel(&x, &y, &z);
  valx = x * 0.04;
  valy = y * 0.04;
  valz = z * 0.04;
  SloadR = ((valx * valx) + (valy * valy) + (valz * valz));
  valorRES = sqrt(SloadR);
  Serial.println(valorRES);
  delay(200);

  Medidas = map(valorRES, 8, 25.70, 0, 10);

  if (Medidas == 1)
  {
    Serial.println("LED 1 on");
    digitalWrite(3, HIGH);
    delay(2000);
    digitalWrite(3, LOW);
  }


  if (Medidas == 2)
  {
    Serial.println("LED 2 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(2000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }


  if (Medidas == 3)
  {
    Serial.println("LED 3 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);

    delay(2000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

  }


  if (Medidas == 4)
  {
    Serial.println("LED 4 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);


    delay(2000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

  }


  if (Medidas == 5)
  {
    Serial.println("LED 5 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);

    delay(2000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

  }

  if (Medidas == 6)
  {
    Serial.println("LED 6 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    Sonido.play(1);
    delay(5000);

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    Sonido.stop();


    // DESDE ACA VA LO DE LA MUSICA ///////////////////////////////////////
  }


  if (Medidas == 7)
  {
    Serial.println("LED 7 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    Sonido.play(1);
    delay(5000);

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    Sonido.stop();

  }


  if (Medidas == 8)
  {
    Serial.println("LED 8 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    Sonido.play(1);
    delay(5000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    Sonido.stop();

  }


  if (Medidas == 9)
  {
    Serial.println("LED 9 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    analogWrite(A1, LOW);
    Sonido.play(1);
    delay(5000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    analogWrite(A1, LOW);
    Sonido.stop();

  }

  if (Medidas == 10)
  {
    Serial.println("LED 10 on");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    analogWrite(A1, LOW);
    analogWrite(A0, HIGH);
    Sonido.play(1);
    delay(5000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    analogWrite(A1, LOW);
    analogWrite(A0, LOW);
    Sonido.stop();

  }

}

/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Como leer un pin digital 
    Dev: Paulo calito 2020265
    Fecha: 12 de Abril
*/

//Directivas del Procesador 
#define LedNaranja  4     //pin4 conectado a una led
#define tiempo_espera 500   //Tiempo entre estados de led 

void setup() 
{
  pinMode(LedNaranja, OUTPUT);  //pin 4 como salida.
  digitalWrite(LedNaranja, LOW);  //led conectado al pin 13 inicia apagado
}

void loop() 
{
  digitalWrite(LedNaranja, HIGH);  //Enciendo el led conectado al pin
  delay(tiempo_espera);   //espera de 500 milisegundos
  digitalWrite(LedNaranja, LOW);  //Apago el led conectado al pin 4 
  delay(tiempo_espera);   //espera de 500 milisegundos
}

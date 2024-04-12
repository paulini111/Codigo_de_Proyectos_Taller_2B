/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Como leer un pin digital 
    Dev: Paulo Calito 2020265
    Fecha: 12 de Abril
*/

//Directivas del procesador
#define push_button 2 //Push button conectado al pin 2
#define led 3

void setup() {
  pinMode(push_button, INPUT); //Pin 2 como entrada
  pinMode(led,OUTPUT); 
  Serial.begin(9600);             //Inicio la comunicación Serial
  Serial.println("Lectura de un pulsador");   //Envio el Texto entre comillas al puerto serie
}

void loop() {
  //Variable local, que se encarga de almacenar el valor (abierto o cerrado)
  //del pulsador conectado al pin2 
  bool estado_boton = digitalRead(push_button);
  if (estado_boton == HIGH) //¿He presionado el interrruptor?
  {
    //Si lo he presionado
    digitalWrite(led, LOW); //apago el led
  } else {
    //si no lo he presionado
    digitalWrite(led, HIGH); //mantengo encendido el led
  }
}

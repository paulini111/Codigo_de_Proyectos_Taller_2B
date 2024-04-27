/*

   Fundacion Kinal
   Centro Educativo tecnico laboral Kinal
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Comunicaciónserial y visualizadores
   Paulo Calito 2020265
   Fecha: 26 de abril de 2024
*/


int pines[] = {4, 5, 6, 7, 8, 9, 10, 11, 12}; 
int time = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
  for (int p = 0; p < 9; p++) {
    pinMode(pines[p], OUTPUT);}
}

void loop() {

  if(digitalRead(2)==HIGH){
    time = 500;
    Serial.println("Secuencia - Velocidad 1");
    
    for (int p = 0; p<9 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}
    
    for (int p = 9; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}
  }

  if(digitalRead(3)==HIGH){
    time = 1000;
    Serial.println("Secuencia - Velocidad 2");
    
    for (int p = 0; p<9 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}

    for (int p = 9; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}
  }

}  



    


 
   
 
 

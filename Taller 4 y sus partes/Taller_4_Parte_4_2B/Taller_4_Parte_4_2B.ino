/*

   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Comunicaciónserial y visualizadores
   Paulo Calito 2020265
   Fecha: 19 de abril
*/

void setup() {
  Serial.begin(9600);     
  Serial.println("Inicio de Contador");          
  pinMode(2, INPUT);     
  pinMode(3, INPUT);     
  
}


int contador = 0;

void loop() {
  if
    (digitalRead(2)==HIGH){ 
   delay(350);
   contador = contador+1; 
     if (contador == 100){
      contador = 0;}
    Serial.println(contador);}
    
    else if(digitalRead(3)==HIGH) 
  {
   delay(350);
      contador = contador-1;
      if (contador <0){
      contador = 99;}
     Serial.println(contador);}
    
     
    }

    


 
   
 
 

/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador ascendente de 0 a 9
   Dev: Paulo calito 2020265
   Fecha: 25/04/2024

*/
 
int contador = 0;

void setup() {
  Serial.begin(9600);     
  Serial.println("Contador de 0 a 9");     
  pinMode(2, INPUT);     
  pinMode(3, INPUT);   
  pinMode(4, INPUT);
}
 
void loop(){

  for(int num = 0; num<=9; num++){
    contador = 500;
    
    if(digitalRead(2)==HIGH){
       contador = 1000;}
    
    else if (digitalRead(3)==HIGH){
      contador = 2000;}
      
   else if (digitalRead(4)==HIGH){
       contador =3000;} 
    
    if (digitalRead(2)==HIGH && digitalRead(3)==HIGH && digitalRead(4)==HIGH){
      contador = 500;} 
    
    Serial.println(num);
    delay(contador);
    
  }

} 
    


 
   
 
 

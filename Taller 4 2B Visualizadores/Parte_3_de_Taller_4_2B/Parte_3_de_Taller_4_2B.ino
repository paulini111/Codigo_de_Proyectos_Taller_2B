
/*

   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Comunicaciónserial y visualizadores
   Paulo Calito 2020265
   Fecha: 26 de abril 2024
*/
int pines[] = {2, 3, 4, 5, 6}; 
int time = 0;



void setup() {
  Serial.begin(9600);     
  Serial.println("Inicio del Programa");          
  pinMode(A0, INPUT);     
  pinMode(A1, INPUT);    
  pinMode(A2, INPUT);    
  pinMode(A3, INPUT); 
  for (int p = 0; p < 9; p++) {
    pinMode(pines[p], OUTPUT);}
}




void loop() { //pulsador 1
  if (digitalRead(A0)==HIGH && !digitalRead(A2)){ 
   delay(350);
   Serial.println("Practica No 4 - Paulo Calito");
  }
  
  
  if(digitalRead(A1)==HIGH && !digitalRead(A3)){  //pulsador 2
    time = 500;
    Serial.println("Secuencia");
    
    for (int p = 0; p<5 ; p++){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}
    
    for (int p = 5; p>=0 ; p--){
    digitalWrite(pines[p], HIGH);
    delay(time);
    digitalWrite(pines[p], LOW);
    delay(time);}
  }
  
  
    if (digitalRead(A2)==HIGH && !digitalRead(A0)){ //pulsador 3
       Serial.println("Palabra Cuatro");
      
      digitalWrite(7, HIGH); // C
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      delay(2000);
      digitalWrite(7, LOW); // C
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      
      digitalWrite(9, HIGH); //U 
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(2000);
       digitalWrite(9, LOW); //U 
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      
      digitalWrite(9, HIGH); // A
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(2000);
      digitalWrite(9, LOW); // A
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);

      digitalWrite(13, HIGH);  // T
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(2000);
      digitalWrite(13, LOW);  // T
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      
      digitalWrite(9, HIGH);  // R
      digitalWrite(7, HIGH);
      delay(2000);
      digitalWrite(9, LOW);  // R
      digitalWrite(7, LOW);

      
      digitalWrite(9, HIGH);  //O
      digitalWrite(7, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      delay(2000);} 
      digitalWrite(9, LOW);  //O
      digitalWrite(7, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);


  // pulsador 4 
  if (digitalRead(A0)==HIGH && digitalRead(A2)==HIGH ){ 
     delay(350);
   Serial.println("Gracias por su atencion");
  }
  
  else if (digitalRead(A1)==HIGH && digitalRead(A3)==HIGH ){ 
     delay(350);
   Serial.println("Gracias por su atencion");
  }
    
   }
  
     


 
   
 
 

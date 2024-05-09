/*

   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y visualizadores
   Paulo Calito 2020265
   Fecha: 03 de mayo 2024
   
*/

      const int pinBuzzer = 3;

void setup (){
Serial.begin(9600);
Serial.println("Conteo Iniciado ");
pinMode(4, OUTPUT); 
  
display ();
}
  
  
void loop() {  
}

  
int display ()
{
  digitalWrite(13, HIGH); // 9
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(13, LOW); // 9
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
  
  
  
    digitalWrite(13, HIGH); // 8
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
      delay(1000);
      digitalWrite(13, LOW); // 8
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
    digitalWrite(9, LOW);
  
  
  
      digitalWrite(13, HIGH); //7
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
       digitalWrite(13, LOW); //7
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
  
  
  
    digitalWrite(13, HIGH); // 6
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(13, LOW); // 6
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);

  
  
      digitalWrite(13, HIGH); // 5
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(13, LOW); // 5
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
  
  
  
      digitalWrite(12, HIGH);  //4
      digitalWrite(7, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      delay(1000); 
      digitalWrite(12, LOW);  //4
      digitalWrite(7, LOW);
      digitalWrite(11, LOW);
      digitalWrite(8, LOW);
  
  
  
      digitalWrite(12, HIGH);  //3
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(13, HIGH);
    digitalWrite(7, HIGH);
      delay(1000); 
      digitalWrite(12, LOW);  //3
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(13, LOW);
      digitalWrite(7, LOW);
  
  
  
    digitalWrite(13, HIGH); // 2
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(13, LOW); // 2
      digitalWrite(12, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);
  
  
  
      digitalWrite(12, HIGH);  // 1
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(12, LOW);  // 1
      digitalWrite(11, LOW);
  

    digitalWrite(13, HIGH); // 0
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
      delay(1000);
  


 if (digitalRead(13)==HIGH && digitalRead(12)==HIGH && digitalRead(11)==HIGH) digitalRead(10)==HIGH && digitalRead(9)==HIGH && digitalRead(8)==HIGH;{
   delay(100);
   Serial.println("Lanzamiento Realizado");
   tone (pinBuzzer, 250, 500); // buzzer
   delay(530);
   digitalWrite(4, HIGH);
   delay(1000);
   digitalWrite(4, LOW);

 }
}

  
  
  
  
  
  
  
  
  
  

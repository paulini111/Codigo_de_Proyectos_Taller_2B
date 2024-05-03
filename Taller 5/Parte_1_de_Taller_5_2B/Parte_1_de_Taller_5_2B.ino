/*

   Fundacion Kinal
   Centro educativo técnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y visualizadores
   Paulo Calito 2020265
   Fecha: 03 de mayo 2024
   
*/

float val_peso = 0;
float kilos = 23.19;

float val_ene= 0;
float joules = 15.89;



void setup (){
  
Serial.begin(9600);
Serial.println("Conversiones");
val_peso = kg2(kilos);
Serial.print(kilos);
Serial.print(" Kilogramos es igual a ");
Serial.print(val_peso);
Serial.println(" Libras ");
Serial.println(" y ");

  
val_ene = amp_mic(joules);
Serial.print(joules);
Serial.print(" Amperios es igual a ");
Serial.print(val_ene);
Serial.print(" Microamperios ");
  

  
}
  
  
  float kg2 (float kg) {
    float resultadoC;
    resultadoC = kg * 2.2041;
    return resultadoC; 
  }

  float amp_mic (float ma) {
    float resultadoD;
    resultadoD = ma *   1000000;
    return resultadoD; 
  }

 
  

  
  
void loop() { 
  
  // onican
  
  // onichan 
  
      digitalWrite(12, HIGH); // 1
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(12, LOW); // 1
      digitalWrite(11, LOW);
  
  
      digitalWrite(13, HIGH);  //3
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(13, LOW);  //3
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, HIGH);
  
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
  
      digitalWrite(13, HIGH); //7 
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(13, LOW); //7
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
  
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
  

  
}
  
  
  
  
  

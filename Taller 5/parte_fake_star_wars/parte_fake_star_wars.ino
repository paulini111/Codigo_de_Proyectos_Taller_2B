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
const float tonos[] = {391.995, 391.995, 391.995, 311.127, 466.164, 391.995, 311.127, 466.164, 391.995, 293.665, 293.665, 293.665, 311.127, 466.164, 369.994, 311.127, 466.164, 369.994, 391.995, 391.995, 391.995, 391.995, 369.994, 349.228, 329.628, 311.127, 329.628, 415.305, 277.183, 261.626, 493.883, 466.164, 440.000, 466.164, 311.127, 369.994, 311.127, 369.994, 466.164, 391.995, 466.164, 293.665, 391.995, 391.995, 391.995, 391.995, 369.994, 349.228, 329.628, 311.127, 329.628, 415.305, 277.183, 261.626, 493.883, 466.164, 440.000, 466.164, 311.127, 369.994, 311.127, 466.164, 391.995, 311.127, 466.164, 391.995};


const int countTonos = 66;

void setup() {
  Serial.begin(9600);     
  Serial.println("Inicio de Cancion");       }

void loop() {

     
    for (int iTono = 0; iTono < countTonos; iTono++) {
      tone(pinBuzzer, tonos[iTono]);
      delay(650);
      noTone(pinBuzzer);}
      
      
}  // loop
    
  
  
  
  

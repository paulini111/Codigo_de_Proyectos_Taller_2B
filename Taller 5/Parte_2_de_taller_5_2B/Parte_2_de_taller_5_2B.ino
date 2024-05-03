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


const float pinBuzzer = 3; 

void setup() {
  Serial.begin(9600);     
  Serial.println("Inicio de Cancion");   
tone (pinBuzzer, 329.628, 650); //sol 
  delay(680);
  tone (pinBuzzer, 329.628, 650);
  delay(680);
  tone (pinBuzzer, 329.628, 650);
  delay(680);


  tone (pinBuzzer, 261.626, 520); //do
  delay(540);
  tone (pinBuzzer, 329.628, 400);
  delay(450); // sol
  tone (pinBuzzer, 329.628, 530); //mi
  delay(470);


  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 329.628, 400);
  delay(450); // sol
  tone (pinBuzzer, 329.628, 530); //mi
  delay(540);


   tone (pinBuzzer, 498.883, 530); //si
  delay(560);
   tone (pinBuzzer, 498.883, 530); //si
  delay(560);
     tone (pinBuzzer, 498.883, 530); //si
  delay(560);


  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 329.628, 330); // sol
  delay(360); 
  tone (pinBuzzer, 311.127, 330); // re#
  delay(360); // sol
   tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 329.628, 330); //mi
  delay(390);


  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);


  tone (pinBuzzer, 311.127, 330); // re#
  delay(360); 
  tone (pinBuzzer, 293.665, 330); // re
  delay(360); 
  tone (pinBuzzer, 277.183, 530); //do #
  delay(560);
  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 277.183, 530); //do #
  delay(560);


  tone (pinBuzzer, 349.228, 530); //fa 
  delay(560);
  tone (pinBuzzer, 466.164, 530); //la #
  delay(560);
  tone (pinBuzzer, 440.000, 530); //la 
  delay(560);
  tone (pinBuzzer, 415.305, 530); //sol #
  delay(560);
  tone (pinBuzzer, 329.628, 330); // sol
  delay(360);
  tone (pinBuzzer, 369.994, 330); // fa #
  delay(360);
  tone (pinBuzzer, 329.628, 330); // sol
  delay(360);


  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 311.127, 330); // re#
  delay(360);
  tone (pinBuzzer, 261.626, 530); //do
  delay(560); 
  tone (pinBuzzer, 311.127, 330); // re#
  delay(360);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 329.628, 330); //mi
  delay(390);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 493.883, 330); //si
  delay(390);


  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 329.628, 420); //mi
  delay(500);
  tone (pinBuzzer, 311.127, 330); // re#
  delay(360);
  tone (pinBuzzer, 293.665, 330); // re
  delay(360);
  tone (pinBuzzer, 277.183, 530); //do #
  delay(560);
  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 277.183, 530); //do #
  delay(560);


  tone (pinBuzzer, 349.228, 530); //fa 
  delay(560);
  tone (pinBuzzer, 466.164, 530); //la #
  delay(560);
  tone (pinBuzzer, 440.000, 530); //la 
  delay(560);
  tone (pinBuzzer, 415.305, 530); //sol #
  delay(560);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 369.994, 330); // fa #
  delay(360);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360);


  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 311.127, 330); // re#
  delay(360);
  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 329.628, 330); //mi
  delay(390);
  tone (pinBuzzer, 261.626, 530); //do
  delay(560);
  tone (pinBuzzer, 329.628, 330);  // sol
  delay(360); 
  tone (pinBuzzer, 329.628, 330); //mi
  delay(390);
      
  }


void loop() {
 
  
  }

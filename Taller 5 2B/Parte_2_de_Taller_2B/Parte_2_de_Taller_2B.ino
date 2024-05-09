/*

   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y visualizadores
   Paulo Calito 2020265
   Fecha: 3 de Mayo 2024
   
*/

const float pinBuzzer = 3; 

void setup() {
  Serial.begin(9600);     
  Serial.println("Inicio de Cancion");
  

  tone (pinBuzzer, 391.995, 353);  // sol
  delay(400);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 391.995, 353);
  delay(400);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 391.995, 353);
  delay(400);
  noTone(pinBuzzer);
  delay(85);

  
  
  tone (pinBuzzer, 311.127, 118); //mib
  delay(235);
  noTone(pinBuzzer);
  delay(50);
  tone (pinBuzzer, 466.164, 118); //sib
  delay(225); 
  noTone(pinBuzzer);
  delay(65);   
  tone (pinBuzzer, 391.995, 353);  //sol
  delay(510);
  noTone(pinBuzzer);
  delay(100);
  
  

  tone (pinBuzzer, 311.127, 118); //mib
  delay(235);
  noTone(pinBuzzer);
  delay(50);
  tone (pinBuzzer, 466.164, 118); //sib
  delay(225); 
  noTone(pinBuzzer);
  delay(65);
  tone (pinBuzzer, 391.995, 706);  //sol
  delay(806);
  noTone(pinBuzzer);
  delay(100);
  
  
  
  tone (pinBuzzer, 587.330, 353);  //re#
  delay(500);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 587.330, 353);
  delay(500);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 587.330, 353);
  delay(506);
  noTone(pinBuzzer);
  delay(100);
  

  tone (pinBuzzer, 622.254, 118); //mib
  delay(235);
  noTone(pinBuzzer);
  delay(50);
  tone (pinBuzzer, 466.164, 118);  //sib
  delay(225); 
  noTone(pinBuzzer);
  delay(65);      
  tone (pinBuzzer, 369.994, 353);  //solb
  delay(350); 
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 466.164, 353);  //mib
  delay(353);
  noTone(pinBuzzer);
  delay(50);
  
  
  tone (pinBuzzer, 466.164, 353); //sib
  delay(225); 
  noTone(pinBuzzer);
  delay(65); 
   tone (pinBuzzer, 391.995, 706); // sol
  delay(706);
  noTone(pinBuzzer);
  delay(100);
  
  
  tone (pinBuzzer, 783.991, 353);  // sol #
  delay(706);
  noTone(pinBuzzer);
  delay(100);
  tone (pinBuzzer, 391.995, 190); // sol
  delay(300);
  noTone(pinBuzzer);
  delay(85);
  tone (pinBuzzer, 391.995, 118);  
  delay(235);
  noTone(pinBuzzer);
  delay(65);
  
  
  tone (pinBuzzer, 783.991, 353);  //sol#
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 739.989, 353);  // sol #
  delay(400);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 608.456, 200);  // fa#
  delay(300);
  noTone(pinBuzzer);
  delay(85);
  
  
  tone (pinBuzzer, 659.255, 118); //mi#
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 622.254, 353);  //re# 
  delay(400);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 659.255, 450);  //mi#
  delay(353);
  noTone(pinBuzzer);
  delay(353);
  
  
  tone (pinBuzzer, 415.305, 130);  //sol#
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 554.365, 130);  //do#
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 523.251, 180);  //do#
  delay(353);
  noTone(pinBuzzer);
  delay(85);
  
  
  tone (pinBuzzer, 493.883, 177);  // si
  delay(353);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 466.164, 353);  //sib
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 440.000, 200);  //la
  delay(300);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 466.164, 130);  //sib
  delay(235);
  noTone(pinBuzzer);
  delay(65);
  
  
  tone (pinBuzzer, 311.127, 353); //mib
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 369.994, 353);  // solb
  delay(706);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 311.127, 130);  //mib
  delay(235);
  noTone(pinBuzzer);
  delay(65);
  
  
  tone (pinBuzzer, 369.994, 353);  //solb
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 466.164, 200);  //sib
  delay(300);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 391.995, 130);  //sol
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 466.164, 353);  //sib 
  delay(353);
  noTone(pinBuzzer);
  delay(100);
  
  
  tone (pinBuzzer, 587.330, 353); //re#
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 783.991, 353);  // sol#
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 391.995, 130);  // sol
  delay(300);
  noTone(pinBuzzer);
  delay(85);
  tone (pinBuzzer, 391.995, 130);
  delay(300);
  noTone(pinBuzzer);
  delay(85);
  
  
  tone (pinBuzzer, 783.991, 180);  //sol#
  delay(353);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 739.989, 353);  //fa#
  delay(400);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 608.456, 200);  //mi
  delay(300);
  noTone(pinBuzzer);
  delay(85);
  
  
  tone (pinBuzzer, 659.255, 118);  // mi#
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 622.254, 353);  // re#
  delay(400);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 659.255, 450);  //mi #
  delay(353);
  noTone(pinBuzzer);
  delay(353);  
  tone (pinBuzzer, 415.305, 130);  //sol#
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 554.365, 130);  //do#
  delay(235);
  noTone(pinBuzzer);
  delay(65);
  
  
  tone (pinBuzzer, 523.251, 180);  //do #
  delay(353);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 493.883, 177); //si
  delay(353);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 466.164, 353); //sib
  delay(353);
  noTone(pinBuzzer);
  delay(100);
  
  
  tone (pinBuzzer, 440.000, 200); //la
  delay(300);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 466.164, 130); //sib
  delay(235);
  noTone(pinBuzzer);
  delay(65);
  tone (pinBuzzer, 311.127, 353); //mib
  delay(353);
  noTone(pinBuzzer);
  delay(100);
  
  
  tone (pinBuzzer, 369.994, 353);  //solb
  delay(706);
  noTone(pinBuzzer);
  delay(100);  
  tone (pinBuzzer, 311.127, 130); // mib
  delay(235);
  noTone(pinBuzzer);
  delay(65);  
  tone (pinBuzzer, 466.164, 180); //sib
  delay(353);
  noTone(pinBuzzer);
  delay(85);
  
  
  tone (pinBuzzer, 391.995, 353); //sol
  delay(353);
  noTone(pinBuzzer);
  delay(100);
  
  
  tone (pinBuzzer, 311.127, 200); //mib
  delay(300);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 466.164, 130); //  sib
  delay(235);
  noTone(pinBuzzer);
  delay(85);  
  tone (pinBuzzer, 391.995, 353); //sol
  delay(353);
  noTone(pinBuzzer);
  delay(100);
  }


void loop() {
 
  
  }

/*
   Fundacion Kinal
   Centro educativo técnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: RFID y su uso
   Dev: Paulo Calito 2020265
   Fecha: Vie-25/07/2024
   
*/

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9        
#define SS_PIN          10        
#define ledVerde        4          
#define ledRojo         5          


MFRC522 mfrc522(SS_PIN, RST_PIN);   //
MFRC522::MIFARE_Key key;


byte tag1[4] = {0x43, 0xAE, 0x27, 0x1A};
byte tag2[4] = {0x70, 0x78, 0x70, 0xA4};  // Valor correcto del llavero para cambiarlo   0xA3, 0xCE, 0x08, 0x0E   // valor "x"  0x70, 0x78, 0x70, 0xA4

byte tagActual[4];

const int buzzer = 6; 

void setup() {
  Serial.begin(9600); 
  while (!Serial);    // comprobar si ya ha iniciado
  SPI.begin();        // inicia la comunicacion SPI
  mfrc522.PCD_Init(); //inicia la comunicacion con el modulo RFID
  pinMode(ledVerde, OUTPUT); 
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzer, OUTPUT); 

}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;

  // Selecciona una tarjeta
  if ( ! mfrc522.PICC_ReadCardSerial())       // leer la tarjeta
    return;

  Serial.print(F("Card UID:"));
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);   // obtiene los valores leidos de la tarjeta

  digitalWrite(ledVerde, LOW);      
  digitalWrite(ledRojo, LOW);
}

void dump_byte_array(byte *buffer, byte bufferSize) {     
  for (byte i = 0; i < bufferSize; i++) {       
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
    tagActual[i] = buffer[i];
  }
  if (compararArray(tagActual, tag1)) {          
    Serial.println(" Acceso Permitido...");
    digitalWrite(ledVerde, HIGH);
    tone (buzzer, 200);
    delay(4000);
    noTone(buzzer); 
  }
  else if (compararArray(tagActual, tag2)) {       
    Serial.println(" Acceso Permitido...");
    digitalWrite(ledVerde, HIGH);
    tone (buzzer, 200);
    delay(4000);
    noTone(buzzer); 
  }
  else {
    Serial.println(" Desconocido" );            
    digitalWrite(ledRojo, HIGH);
    tone (buzzer, 400);
    delay(4000);
    noTone(buzzer); 
  }
}


boolean compararArray(byte array1[], byte array2[]) {  

  if (array1[0] != array2[0]) return (false);
  if (array1[1] != array2[1]) return (false);
  if (array1[2] != array2[2]) return (false);
  if (array1[3] != array2[3]) return (false);
  return (true);
}

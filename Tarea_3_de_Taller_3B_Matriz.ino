
#include <LedControl.h>

//Directivas de pre
#define din_matrix  3  //Pin 3 del ardu al din 
#define cs_matrix   2  //Pin 2 del ardu al cs
#define clk_matrix  4  //Pin 4 del ardu al clk

// Constructores

LedControl matrixpaulo = LedControl(din_matrix, clk_matrix, cs_matrix, 1);

int pote;


// Variables

byte pacman_wow[8] = { // REAL RONDON
  B00111000,
  B01000100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000,
};

byte pacman_wownt[8] = { // falso rondon
  B00111000,
  B01000100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000,
};

void setup() {
  Serial.begin(9600);
  matrixpaulo.shutdown(0, false);
  matrixpaulo.setIntensity(0, 15);
  matrixpaulo.clearDisplay(0);
  Serial.println("Uso de matrriz");

}

void loop() {
  pote = map(analogRead(A0), 0, 1023, 100, 1000);

  for (int i = 0; i < 8; i++) {
    matrixpaulo.setRow(0, i, pacman_wow[i]);
  }
 delay(pote);
  for (int i = 0; i < 8; i++) {
    matrixpaulo.setRow(0, i, pacman_wownt[i]);
  }
  delay(pote);
}

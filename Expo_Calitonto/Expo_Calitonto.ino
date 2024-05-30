/* Proyecto de la expo De Calito, Dani, Colop y Mayorga 
 Dispara Dardos
 */
#include <Servo.h>

//-----Declaracion de servos y variables
Servo recoil_servo;
Servo pan_servo;
Servo tilt_servo;

const byte pan_limit_1 = 0;
const byte pan_limit_2 = 180;
const byte tilt_limit_1 = 65;
const byte tilt_limit_2 = 180;
const byte recoil_rest = 180;    // Ángulo del servo en reposo
const byte recoil_pushed = 125;  // Ángulo que el servo debe alcanzar para empujar el dardo

//-----Variables relacionadas con el manejo de datos seriales.
byte byte_from_app;
const byte buffSize = 30;
byte inputBuffer[buffSize];
const byte startMarker = 255;
const byte endMarker = 254;
byte bytesRecvd = 0;
boolean data_received = false;

//-----Variable relacionada con la sincronización y el disparo del motor.
bool is_firing =  false;
bool can_fire =  false;
bool recoiling = false;

unsigned long firing_start_time = 0;
unsigned long firing_current_time = 0;
const long firing_time = 150;

unsigned long recoil_start_time = 0;
unsigned long recoil_current_time = 0;
const long recoil_time = 2 * firing_time;

const byte motor_pin =  12;
boolean motors_ON = false;

//8=========================================================

void setup()
{
  //-----define en el pin del motor 
  pinMode(motor_pin, OUTPUT);
  digitalWrite(motor_pin, LOW);

  //----- conecta el servo a los pines
  recoil_servo.attach(9);
  pan_servo.attach(10);
  tilt_servo.attach(11);

  //-----inicio de secuencia 
  recoil_servo.write(recoil_rest);
  pan_servo.write(90);
  //tilt_servo.write(tilt_limit_2);
  delay(1000);
  //tilt_servo.write(tilt_limit_2 + abs((tilt_limit_2 - tilt_limit_1)/2));
  tilt_servo.write(105);


  Serial.begin(9600);  // 
}

//8=============================================================

void loop()
{
  getDataFromPC();
    set_motor();
  if (data_received) {
    move_servo();
    set_recoil();
      set_motor();
  }
  fire();
}

//8============================================================

void getDataFromPC() {
  
  //estructura esperada de datos [byte de inicio, cantidad de giro, cantidad de inclinación, motor encendido, botón de disparo presionado, byte de finalización]
  //inicio del byte = 255
  //pan amount = byte entre 0 and 253
  //tilt amount = byte entre 0 and 253
  //motor on = 0 for off - 1 on
  //firing boton presionado = 0 for not presionado y 1 for presionado
  //fin del  byte = 254

  if (Serial.available()) {  // Si los datos están disponibles en serie

    byte_from_app = Serial.read();   //lee el siguiente caracter disponible

    if (byte_from_app == 255) {     //busque el byte de inicio, si lo encuentra:
      bytesRecvd = 0;                    //restablecer el byte recibido a 0 (para comenzar a llenar el inputBuffer desde el inicio)
      data_received = false;
    }

    else if (byte_from_app == 254) {    // busca el byte final, si lo encuentra:
      data_received = true;               // establece data_received en verdadero para que los datos puedan usarse 
    }

    else {                            // agrega los bytes recibidos al buffer
      inputBuffer[bytesRecvd] = byte_from_app;     //añadir carácter al buffer de entrada
      bytesRecvd++;                                // incrementa el byte recibido (esto actúa como un índice)
      if (bytesRecvd == buffSize) {    // solo una seguridad en caso de que el inputBuffer se llene (no debería suceder)
        bytesRecvd = buffSize - 1;   // si bytesReceived > tamaño del búfer establece bytesReceived más pequeño que el tamaño del búfer
      }
    }
  }
}

//8============================================================

void move_servo() {
  
  byte pan_servo_position = map(inputBuffer[0], 0, 253, pan_limit_2, pan_limit_1);//convierte el valor del buffer de entrada al valor de posición del servo
  pan_servo.write(pan_servo_position); //set pan servo position
  byte tilt_servo_position = map(inputBuffer[1], 0 , 253, tilt_limit_2, tilt_limit_1);  //convierte el valor del buffer de entrada al valor de posición del servo
  tilt_servo.write(tilt_servo_position); //set pan servo position
}

//8===================================================================

void set_recoil() {

  if (inputBuffer[3] == 1) {       //si se presiona el botón de disparo
    if (!is_firing && !recoiling) { //y aún no disparando ni retrocediendo
      can_fire = true;              //establece can fire en true (ver efecto en void fire())
    }
  }
  else {                  // si el botón de disparo no está presionado
    can_fire = false;     //se puede activar en falso (ver efecto en void fire())
  }
}

//8======================================================

void set_motor() {
  //-----start and stop motors using TIP120 transisitor .

  if (inputBuffer[2] == 1) {                //if screen touched
    digitalWrite(motor_pin, HIGH);          //turn motor ON
    motors_ON = true;
  }
  else {                                   //if screen not touched
    digitalWrite(motor_pin, LOW);          //turn motor OFF
    motors_ON = false;

  }
}
//8======================================================

void fire() {  //si el byte del motor está activado, encienda el motor y compruebe el tiempo que ha estado activado

  if (can_fire && !is_firing && motors_ON) {
    //if (can_fire && !is_firing) {
    firing_start_time = millis();
    recoil_start_time = millis();
    is_firing = true;
  }

  firing_current_time = millis();
  recoil_current_time = millis();

  if (is_firing && firing_current_time - firing_start_time < firing_time) {
    recoil_servo.write(recoil_pushed);
  }
  else if (is_firing && recoil_current_time - recoil_start_time < recoil_time) {
    recoil_servo.write(recoil_rest);
  }
  else if (is_firing && recoil_current_time - recoil_start_time > recoil_time) {
    is_firing = false;
  }

}

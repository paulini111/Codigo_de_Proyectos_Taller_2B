/* Proyecto de la expo De Calito, Dani, Colop y Mayorga 
 Dispara Dardos
 */
#include <Servo.h>

//-----Declaracion de servos y variables
Servo recorrido_servo;
Servo pan_servo;
Servo inclinacion_servo;

const byte pan_limite_1 = 0;
const byte pan_limite_2 = 180;
const byte inclinacion_limite_1 = 65;
const byte inclinacion_limite_2 = 180;
const byte recorrido_reposo = 180;    // Ángulo del servo en reposo
const byte recorrido_empujar = 125;  // Ángulo que el servo debe alcanzar para empujar el dardo

//-----Variables relacionadas con el manejo de datos seriales.
byte byte_from_app;
const byte buffTamano = 30;
byte inputBuffer[buffTamano];
const byte inicioMarker = 255;
const byte finMarker = 254;
byte bytesRecvd = 0;
boolean data_received = false;

//-----Variable relacionada con la sincronización y el disparo del motor.
bool esta_firing =  false;
bool puede_fire =  false;
bool recoiling = false;

unsigned long firing_inicio_tiempo = 0;
unsigned long firing_actual_tiempo = 0;
const long firing_time = 150;

unsigned long recorrido_inicio_tiempo = 0;
unsigned long recorrido_actual_tiempo = 0;
const long recorrido_time = 2 * firing_time;

const byte motor_pin =  12;
boolean motors_ON = false;

//8=========================================================

void setup()
{
  //-----define en el pin del motor 
  pinMode(motor_pin, OUTPUT);
  digitalWrite(motor_pin, LOW);

  //----- conecta el servo a los pines
  recorrido_servo.attach(9);
  pan_servo.attach(10);
  inclinacion_servo.attach(11);

  //-----inicio de secuencia 
  recorrido_servo.write(recorrido_reposo);
  pan_servo.write(90);
  //tilt_servo.write(tilt_limit_2);
  delay(1000);
  //tilt_servo.write(tilt_limit_2 + abs((tilt_limit_2 - tilt_limit_1)/2));
  inclinacion_servo.write(105);


  Serial.begin(9600);  // 
}

//8=============================================================

void loop()
{
  getDataFromPC();
    set_motor();
  if (data_received) {
    move_servo();
    set_recorrido();
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
      if (bytesRecvd == buffTamano) {    // solo una seguridad en caso de que el inputBuffer se llene (no debería suceder)
        bytesRecvd = buffTamano - 1;   // si bytesReceived > tamaño del búfer establece bytesReceived más pequeño que el tamaño del búfer
      }
    }
  }
}

//8============================================================

void move_servo() {
  
  byte pan_servo_position = map(inputBuffer[0], 0, 253, pan_limite_2, pan_limite_1);//convierte el valor del buffer de entrada al valor de posición del servo
  pan_servo.write(pan_servo_position); //set pan servo position
  byte inclinacion_servo_position = map(inputBuffer[1], 0 , 253, inclinacion_limite_2, inclinacion_limite_1);  //convierte el valor del buffer de entrada al valor de posición del servo
  inclinacion_servo.write(inclinacion_servo_position); //set pan servo position
}

//8===================================================================

void set_recorrido() {

  if (inputBuffer[3] == 1) {       //si se presiona el botón de disparo
    if (!esta_firing && !recoiling) { //y aún no disparando ni retrocediendo
      puede_fire = true;              //establece can fire en true (ver efecto en void fire())
    }
  }
  else {                  // si el botón de disparo no está presionado
    puede_fire = false;     //se puede activar en falso (ver efecto en void fire())
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

  if (puede_fire && !esta_firing && motors_ON) {
    //if (can_fire && !is_firing) {
    firing_inicio_tiempo = millis();
    recorrido_inicio_tiempo = millis();
    esta_firing = true;
  }

  firing_actual_tiempo = millis();
  recorrido_actual_tiempo = millis();

  if (esta_firing && firing_actual_tiempo - firing_inicio_tiempo < firing_time) {
    recorrido_servo.write(recorrido_empujar);
  }
  else if (esta_firing && recorrido_actual_tiempo - recorrido_inicio_tiempo < recorrido_time) {
    recorrido_servo.write(recorrido_reposo);
  }
  else if (esta_firing && recorrido_actual_tiempo - recorrido_inicio_tiempo > recorrido_time) {
    esta_firing = false;
  }

}

/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Catálogo de productos
    Dev: Paulo Calito 2020265
    Fecha: 18 de abril de 2024
*/ 

struct datos_dulce
{
  char nombre_dulces[50];     //Variable tipo char donde se almacenan los nombres de los dulces
  byte cantidad_de_dulces;           //Variable tipo byte donde almacenare la edad de los alumnos.
};

//Creo los dulces que se van a usar
datos_dulce dulce1 = {"Chocolate", 25};
datos_dulce dulce2 = {"Dulce de miel", 30};
datos_dulce dulce3 = {"Chicles", 25};
datos_dulce dulce4 = {"Paletas", 31};



//Funcion donde se realizan las configuraciones
void setup() {
  Serial.begin(9600);     //Inicio la comunicación serial.
  Serial.println("Tipos de datos - Structs");     //Envio el siguiente mensaje al monitor serial.
    Serial.begin(9600);     //Inicio la comunicación serial.
  pinMode(2, INPUT);     //Pin 2 del arduino como entrada.
  pinMode(3, INPUT);     //Pin 3 del arduino como entrada.
  
  //Muestro los datos contenidos en los datos de los dulces
  Serial.print("El Dulce 1 es: ");
  Serial.println(dulce1.nombre_dulces);
  Serial.print("La cantidad del dulce 1 es: ");
  Serial.println(dulce1.cantidad_de_dulces);
  
  //Muestro los datos contenidos en los datos de los dulces
  Serial.print("El Dulce 2 es: ");
  Serial.println(dulce2.nombre_dulces);
  Serial.print("La cantidad del dulce 2 es: ");
  Serial.println(dulce2.cantidad_de_dulces);
  
  //Muestro los datos contenidos en los datos de los dulces
  Serial.print("El Dulce 3 es: ");
  Serial.println(dulce3.nombre_dulces);
  Serial.print("La cantidad del dulce 3 es: ");
  Serial.println(dulce3.cantidad_de_dulces);

  //Muestro los datos contenidos en los datos de los dulces
  Serial.print("El Dulce 4 es: ");
  Serial.println(dulce4.nombre_dulces);
  Serial.print("La cantidad del dulce 4 es: ");
  Serial.println(dulce4.cantidad_de_dulces);
  
  
}

//variable donde almaceno el valor del contador
byte contador = 0;




//Funcion donde se ejecutan de manera "infinita" el código. 
void loop() {
  if(digitalRead(2)==HIGH)  //Leo el estado digital del pin 2 y si este es bajo.
  {
   delay(350);
   contador = contador+1;   //aumento en uno el contador
    Serial.println(contador);
    
    if(contador == 1){
       Serial.print("el producto es ");
      Serial.println(dulce1.nombre_dulces);
       Serial.print("la cantidad es:  ");
      Serial.println(dulce1.cantidad_de_dulces);}    
      
      if(contador == 2){
       Serial.print("el producto es ");
        Serial.println(dulce2.nombre_dulces);
      Serial.print("la cantidad es:  ");
        Serial.println(dulce2.cantidad_de_dulces);} 
        
      if(contador == 3){
       Serial.print("el producto es ");
          Serial.println(dulce3.nombre_dulces);
    Serial.print("la cantidad es:  ");
    Serial.println(dulce3.cantidad_de_dulces);}
          
          if(contador == 4){
       Serial.print("el producto es ");
            Serial.println(dulce4.nombre_dulces);
      Serial.print("la cantidad es:  ");
      Serial.println(dulce4.cantidad_de_dulces);} 
    }
  


  else if(digitalRead(3)==HIGH) //Leo el estado digital del pin 3 y si este es bajo.
  {
   delay(350);
   contador = contador-1;   //disminuyo en uno el contador
   
    if(contador == 1){
       Serial.print("el producto es ");
      Serial.println(dulce1.nombre_dulces);
      Serial.print("la cantidad es:  ");
      Serial.println(dulce1.cantidad_de_dulces);} 
      
      if(contador == 2){
       Serial.print("el producto es ");
        Serial.println(dulce2.nombre_dulces); 
        Serial.print("la cantidad es:  ");
      Serial.println(dulce2.cantidad_de_dulces);} 
        
        if(contador == 3){
       Serial.print("el producto es ");
          Serial.println(dulce3.nombre_dulces); 
          Serial.print("la cantidad es:  ");
      Serial.println(dulce3.cantidad_de_dulces);} 
          
          if(contador == 4){
       Serial.print("el producto es ");
            Serial.println(dulce4.nombre_dulces); 
            Serial.print("la cantidad es:  ");
      Serial.println(dulce4.cantidad_de_dulces);} 
  }
        }
    
  
  
  

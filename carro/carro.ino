#include <SoftwareSerial.h>
#include "Lista.h"

SoftwareSerial mySerial(11,10);  
char inputByte;
Lista lista;

void setup() {
  
  mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(lista.movimiento.Pin_2, OUTPUT);      
  pinMode(lista.movimiento.Pin_3, OUTPUT);     
  pinMode(lista.movimiento.Pin_4, OUTPUT);    
  pinMode(lista.movimiento.Pin_5, OUTPUT); 
  
}

void loop() {
 
  if(mySerial.available()){

    inputByte = mySerial.read();
    //Serial.print(inputByte);
    if(inputByte == 'X'){
      lista.limpiarPunteros();
    }

    lista.movimiento.moverCarrito(inputByte);

    if(lista.movimiento.sePuedeGrabar == true && inputByte == 'S'){
      lista.movimiento.cronometro();
      lista.agregar(lista.movimiento.ultimaLetra, lista.movimiento.tiempoTranscurrido);
    }

    if(lista.movimiento.sePuedeEjecutar == true ){
      lista.movimiento.sePuedeEjecutar = false;
      lista.presentarI();
    }
  }
}
#include <SoftwareSerial.h>
#include "Lista.h"
#include "Movimiento.h"

SoftwareSerial mySerial(11,10);  

char inputByte = "";
Lista listaDoblementeEnlazada;
Movimiento movimiento;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  
  movimiento.setupVariables();
  movimiento.setupPines();
}

void loop() {
   if(mySerial.available()){
      inputByte = mySerial.read();
      
      movimiento.moverCarrito(inputByte);
      if(movimiento.sePuedeGrabar && inputByte == 'S'){
        guardarValorEnLista();
      }

      if(movimiento.sePuedeEjecutar){
        listaDoblementeEnlazada.presentarI();
      }
   }
}

void guardarValorEnLista(){
  if((movimiento.ultimoMovimiento=='B' || movimiento.ultimoMovimiento=='F' || 
    movimiento.ultimoMovimiento=='L' || movimiento.ultimoMovimiento=='R') && 
    movimiento.tiempoDuracion >0){
 
    // Serial.println(movimiento.tiempoDuracion);  
    // Serial.println(movimiento.ultimoMovimiento); 
    listaDoblementeEnlazada.agregar(movimiento.ultimoMovimiento, movimiento.tiempoDuracion);
  }
}

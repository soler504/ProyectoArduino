#include <SoftwareSerial.h>
#include "Lista.h"
#include "Movimiento.h"

SoftwareSerial mySerial(11,10);  

char inputByte = "";
Lista listaDoblementeEnlazada;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  
  listaDoblementeEnlazada.move.setupVariables();
  listaDoblementeEnlazada.move.setupPines();
}

void loop() {
   if(mySerial.available()){
      inputByte = mySerial.read();
      
      listaDoblementeEnlazada.move.moverCarrito(inputByte);
      if(listaDoblementeEnlazada.move.sePuedeGrabar && inputByte == 'S'){
        guardarValorEnLista();
      }

      if(listaDoblementeEnlazada.move.sePuedeEjecutar){
        listaDoblementeEnlazada.presentarI();
        listaDoblementeEnlazada.move.sePuedeEjecutar = false;
      }
   }
}

void guardarValorEnLista(){
  if((listaDoblementeEnlazada.move.ultimoMovimiento=='B' || listaDoblementeEnlazada.move.ultimoMovimiento=='F' || 
    listaDoblementeEnlazada.move.ultimoMovimiento=='L' || listaDoblementeEnlazada.move.ultimoMovimiento=='R') && 
    listaDoblementeEnlazada.move.tiempoDuracion >0){
 
    // Serial.println(movimiento.tiempoDuracion);  
    // Serial.println(movimiento.ultimoMovimiento); 
    listaDoblementeEnlazada.agregar(listaDoblementeEnlazada.move.ultimoMovimiento, listaDoblementeEnlazada.move.tiempoDuracion);
  }
}

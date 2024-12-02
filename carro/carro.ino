#include <SoftwareSerial.h>
#include "Lista.h"

SoftwareSerial mySerial(11,10);  
char inputByte;
Lista  lista;

void setup() {
  
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(lista.movimient.Pin_2, OUTPUT);      
  pinMode(lista.movimient.Pin_3, OUTPUT);     
  pinMode(lista.movimient.Pin_4, OUTPUT);    
  pinMode(lista.movimient.Pin_5, OUTPUT); 
  
}

void loop() {
 
  if(mySerial.available()){

    inputByte = mySerial.read();
    Serial.println(inputByte);
    lista.movimient.movimiento(inputByte);
    if(lista.movimient.grabar_u == true && inputByte == 'S'){
      
      lista.movimient.cronometro();
      lista.agregar(lista.movimient.ultimaLetra, lista.movimient.contador);

    }
    lista.movimient.contador = 0;
    if(lista.movimient.ejecutar_w == true ){

      lista.movimient.ejecutar_w = false;
      lista.presentarI();
  
    }
  }
}
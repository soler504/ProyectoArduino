#include "Movimiento.h"
void moverCarrito(char letra){
  if(letra=='S'){
    stop();
    calcularTiempoDuracion();
  }

  if(letra=='B'){
    asignarValores(letra);
    back();
  }

  if(letra=='F'){
    asignarValores(letra);
    front();
  }

  if(letra=='L'){
    asignarValores(letra);
    left();
  }

  if(letra=='R'){
    asignarValores(letra);
    right();
  }
}

void calcularTiempoDuracion(){
  tiempoDuracion = millis() - tiempoInicio;
}

void asignarValores(char letra){
  tiempoInicio = millis();
  ultimoMovimiento = letra;
}

void stop(){
  digitalWrite(Pin_2,LOW);
  digitalWrite(Pin_4,LOW);
  digitalWrite(Pin_3,LOW);
  digitalWrite(Pin_5,LOW);  
}

void back(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_3,HIGH);
}

void front(){
  digitalWrite(Pin_2,HIGH);
  digitalWrite(Pin_5,HIGH);
}

void left(){
  digitalWrite(Pin_5,HIGH); 
  digitalWrite(Pin_3,HIGH);
}

void right(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_2,HIGH);
}s
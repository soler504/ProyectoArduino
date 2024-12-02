#include "Movimiento.h"
Movimiento::Movimiento(){

}

void Movimiento::setupVariables(){
  ultimoMovimiento = "";

  sePuedeGrabar = false;
  sePuedeEjecutar = false;

  Pin_2 = 4;
  Pin_3 = 2;
  Pin_4 = 6;
  Pin_5 = 7;

  tiempoInicio = 0;
  tiempoDuracion = 0;
}

void Movimiento::setupPines(){
  pinMode(Pin_2, OUTPUT);      
  pinMode(Pin_3, OUTPUT);     
  pinMode(Pin_4, OUTPUT);    
  pinMode(Pin_5, OUTPUT); 
}

void Movimiento::moverCarrito(char letra){
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

  if(letra == 'M'){
    sePuedeGrabar = true;
    sePuedeEjecutar = false;
  }

  if(letra == 'm'){
    sePuedeGrabar = false;
  }

  if(letra == 'N'){
    sePuedeGrabar = false;
    sePuedeEjecutar = true;
  }

  if(letra == 'n'){
    sePuedeEjecutar = false;
  }
}

void Movimiento::calcularTiempoDuracion(){
  tiempoDuracion = millis() - tiempoInicio;
}

void Movimiento::asignarValores(char letra){
  tiempoInicio = millis();
  ultimoMovimiento = letra;
}

void Movimiento::stop(){
  digitalWrite(Pin_2,LOW);
  digitalWrite(Pin_4,LOW);
  digitalWrite(Pin_3,LOW);
  digitalWrite(Pin_5,LOW);  
}

void Movimiento::back(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_3,HIGH);
}

void Movimiento::front(){
  digitalWrite(Pin_2,HIGH);
  digitalWrite(Pin_5,HIGH);
}

void Movimiento::left(){
  digitalWrite(Pin_5,HIGH); 
  digitalWrite(Pin_3,HIGH);
}

void Movimiento::right(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_2,HIGH);
}
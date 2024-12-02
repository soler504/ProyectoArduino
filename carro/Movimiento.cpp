#include "Movimiento.h"

void Movimiento::moverCarrito(char letra){

  if(letra == 'S'){         
    stop();
  }

  if(letra == 'B'){
    tiempo_anterior = millis();
    ultimaLetra = letra;
    back();
  }

  if(letra == 'F'){
    tiempo_anterior = millis();
    ultimaLetra = letra;
    front();
  }

  if(letra == 'L'){
    tiempo_anterior = millis();
    ultimaLetra = letra;
    left();
  }

  if(letra == 'R'){
    tiempo_anterior = millis();
    ultimaLetra = letra;
    right();
  }

  if(letra == 'M'){
    sePuedeGrabar = true;
  }

  if(letra == 'm'){
    sePuedeGrabar = false;
  }

  if(letra == 'N'){
    sePuedeEjecutar = true;
  }

  if(letra == 'n'){
    sePuedeEjecutar = false;
  }
}

void Movimiento::stop(){

  digitalWrite(Pin_2,LOW);
  digitalWrite(Pin_4,LOW);
  digitalWrite(Pin_3,LOW);
  digitalWrite(Pin_5,LOW);  

}

void Movimiento::back(){

  digitalWrite(Pin_2,HIGH);
  digitalWrite(Pin_5,HIGH);
  
}

void Movimiento::front(){

  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_3,HIGH);
  
}

void Movimiento::left(){

  digitalWrite(Pin_5,HIGH);
  digitalWrite(Pin_3,HIGH);

}

void Movimiento::right(){

  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_2,HIGH);
  
}
void Movimiento::cronometro(){

  tiempo_actual = millis();
  delta_tiempo = tiempo_actual - tiempo_anterior;
  contador = int(delta_tiempo);

}
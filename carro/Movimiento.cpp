#include "Movimiento.h"
void Movimiento::movimiento(char m){

  if(m == 'S'){         
    stop();
  }
  if(m == 'B'){
    tiempo_anterior = millis();
    ultimaLetra = m;
    back();
  }
  if(m == 'F'){
    tiempo_anterior = millis();
    ultimaLetra = m;
    front();
  }
  if(m == 'L'){
    tiempo_anterior = millis();
    ultimaLetra = m;
    left();
  }
  if(m == 'R'){
    tiempo_anterior = millis();
    ultimaLetra = m;
    right();
  }
  if(m == 'M'){
    grabar_u = true;
  }
  if(m == 'm'){
    grabar_u = false;
  }
  if(m == 'N'){
    ejecutar_w = true;
  }
  if(m == 'n'){
    ejecutar_w = false;
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
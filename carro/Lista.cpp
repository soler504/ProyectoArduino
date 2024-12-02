
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Lista.h"

using namespace std;

Lista::Lista(){
  I = NULL;
  F = NULL;
  T = NULL;
}

void Lista::agregar(char letra, int tiempo){
  T = new Nodo();
	T -> letra = letra;
  T -> tiempo = tiempo;
	T -> sig = NULL;
	T -> ant = NULL;
  
	if(I == NULL){
		I = T;
	}else{
    T -> ant = F;
		F -> sig = T;
	}
	F = T;
}

void Lista::presentarF(){
  T = F;
	while (T != NULL){
		Serial.print(T->letra);
    Serial.print("-");
    Serial.println(T->tiempo);

		T = T->ant;
	}
}
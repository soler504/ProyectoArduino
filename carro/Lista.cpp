#include "Lista.h"

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

void Lista::presentarI(){
  T = I;
	while (T != NULL){
    Serial.println(T->letra);  
    Serial.println(T->tiempo); 

    move.moverCarrito(T->letra);
    delay(T->tiempo);
		T = T->sig;
	}
}

void Lista::presentarF(){
  T = F;
	while (T != NULL){
		T = T->ant;
	}
}


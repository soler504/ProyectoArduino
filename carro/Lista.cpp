#include "Lista.h"

Lista::Lista(){

  I = NULL;
  F = NULL;
  T = NULL;
  
}

void Lista::agregar(char letra, int tiempo){

  T = new Nodo();
	T->letra = letra;
  T->tiempo = tiempo;
	T->sig = NULL;
  T->ant = NULL;
	if(I == NULL){
		I = T;
	}else{
    F -> sig = T;
    T -> ant = F;
		
	}
	F = T;

}

void Lista::presentarI(){

  T = I;
  Serial.println("Aqui empieza la lista");
	while (T != NULL){

    Serial.print(T->letra);
    Serial.print(" - ");
    Serial.println(T->tiempo);
    movimient.movimiento(T->letra);
    delay(T->tiempo);
    movimient.movimiento('S');
		T = T->sig;

	}
/*
  T = F->ant;
  while (T != NULL){
    Serial.print(T->letra);
    Serial.print(" - ");
    Serial.println(T->tiempo);
    switch(T->letra){
      case 'L':
        movimient.movimiento('R');
        break;
      case 'R':
        movimient.movimiento('L');
        break;
      default:
        movimient.movimiento(T->letra);
        break;
    }
    delay(T->tiempo);
    movimient.movimiento('S');
		T = T->ant;
	}
  Serial.println("Final");
	*/
  
}
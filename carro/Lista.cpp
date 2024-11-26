#include <SoftwareSerial.h>
#include "Lista.h"
using namespace std;
Lista::Lista(){
  I = NULL;
  F = NULL;
  T = NULL;
  A = NULL;
  T2 = NULL;
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
		F -> sig = T;
		T -> ant = F;
	}
	F = T;
}
void Lista::presentarF(){
  T = F;
	while (T != NULL){
		printf(T->letra + "-" + T->tiempo);
		T = T->ant;
	}
}
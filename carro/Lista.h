#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#define NULL 0
class Lista
{
	public:
		Lista();
		Nodo *I, *F, *T, *A, *T2;
		void agregar(char, int);
		void presentarI();
		void presentarF();
};

#endif

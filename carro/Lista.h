#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Movimiento.h"
#include <Arduino.h>

class Lista{

	public:
		Lista();
		Nodo *I, *F, *T;
    Movimiento movimiento;
    
		void agregar(char, int);
		void presentarI();
		void presentarF();
    void limpiarVariables()
};

#endif
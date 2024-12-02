#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Movimiento.h"
#include <Arduino.h>

class Lista{
  private:
    Nodo *I, *F, *T;

	public:
    Movimiento movimiento;

    Lista();
		void agregar(char, int);
		void presentarI();
		void presentarF();
    void limpiarPunteros();
};

#endif
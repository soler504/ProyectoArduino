#ifndef LISTA_H
#define LISTA_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Movimiento.h"
#include "Nodo.h"

class Lista
{
	public:
		Lista();
		Nodo *I, *F, *T;
    Movimiento move;

		void agregar(char, int);
		void presentarI();
		void presentarF();
};

#endif

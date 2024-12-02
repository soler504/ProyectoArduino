#include "Nodo.h"
#define NULL 0
#include "Movimiento.h"
#include <Arduino.h>

class Lista{

	public:
		Lista();
		Nodo *I, *F, *T;
    Movimiento movimient;
		void agregar(char, int);
		void presentarI();
		void presentarF();
};

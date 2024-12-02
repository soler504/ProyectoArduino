#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <Arduino.h>
class Movimiento{

  public:

    int contador = 0;
    char ultimaLetra;

    bool sePuedeGrabar = false;
    bool sePuedeEjecutar = false;

    int Pin_2 = 4;          
    int Pin_3 = 2;        
    int Pin_4 = 6;
    int Pin_5 = 7;

    unsigned long tiempo_actual;
    unsigned long tiempo_anterior = 0;
    unsigned long delta_tiempo;

    void moverCarrito(char);
    void stop();
    void back();
    void front();
    void left();
    void right();
    void cronometro();
};

#endif
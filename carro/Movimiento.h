#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <Arduino.h>
class Movimiento{

  public:
    char ultimaLetra;

    bool sePuedeGrabar;
    bool sePuedeEjecutar;

    int Pin_2;          
    int Pin_3;        
    int Pin_4;
    int Pin_5;

    unsigned long tiempoInicial;
    unsigned long tiempoTranscurrido;

    Movimiento();
    void inicializarVariables(char);
    void moverCarrito(char);
    void stop();
    void back();
    void front();
    void left();
    void right();
    void cronometro();
};

#endif
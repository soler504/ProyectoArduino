#include <Arduino.h>
class Movimiento{

  public:

    int contador = 0;
    char ultimaLetra;

    bool grabar_u = false;
    bool ejecutar_w = false;

    int Pin_2 = 4;          
    int Pin_3 = 2;        
    int Pin_4 = 6;
    int Pin_5 = 7;

    unsigned long tiempo_actual;
    unsigned long tiempo_anterior = 0;
    unsigned long delta_tiempo;

    void movimiento(char m);
    void stop();
    void back();
    void front();
    void left();
    void right();
    void cronometro();
    
};
#include <Arduino.h>
class Movimiento{

  public:

    char ultimoMovimiento = '';

    bool sePuedeGrabar = false;
    bool sePuedeEjecutar = false;

    int Pin_2 = 4;          
    int Pin_3 = 2;        
    int Pin_4 = 6;
    int Pin_5 = 7; 

    unsigned long tiempoInicio = 0;
    unsigned long tiempoDuracion = 0;

    void moverCarrito(char letra);
    void calcularTiempoDuracion();
    void asignarValores(char letra);

    void stop();
    void back();
    void front();
    void left();
    void right();
};
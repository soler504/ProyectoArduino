#include <Arduino.h>
class Movimiento{

  public:
    char ultimoMovimiento;

    bool sePuedeGrabar;
    bool sePuedeEjecutar;

    int Pin_2;          
    int Pin_3;        
    int Pin_4;
    int Pin_5; 

    unsigned long tiempoInicio;
    unsigned long tiempoDuracion;

    Movimiento();
    void moverCarrito(char letra);
    void calcularTiempoDuracion();
    void asignarValores(char letra);
    void setupPines();
    void setupVariables();

    void stop();
    void back();
    void front();
    void left();
    void right();
};
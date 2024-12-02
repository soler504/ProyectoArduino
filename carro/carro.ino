#include <SoftwareSerial.h>
#include "Lista.h"

SoftwareSerial mySerial(11,10);  
char inputByte = "";
bool sePuedeGrabar = false;
bool sePuedeEjecutar = false;

int Pin_2 = 4;          
int Pin_3 = 2;        
int Pin_4 = 6;
int Pin_5 = 7;

Lista  listaDoblementeEnlazada;
unsigned long tiempoInicio = 0;
unsigned long tiempoDuracion = 0;
char ultimoMovimiento = 'S';


void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(Pin_2, OUTPUT);      
  pinMode(Pin_3, OUTPUT);     
  pinMode(Pin_4, OUTPUT);    
  pinMode(Pin_5, OUTPUT); 
}

void loop() {

   if(mySerial.available()){
      inputByte = mySerial.read();
      
      if(inputByte == 'M'){
        sePuedeGrabar = true;
        sePuedeEjecutar = false;
      }

      if(inputByte == 'N'){
        sePuedeGrabar = false;
        sePuedeEjecutar = true;
      }

      if(sePuedeGrabar){
        moverCarrito(inputByte);
      }
   }
}

void guardarValorEnLista(){
  if((ultimoMovimiento=='B' || ultimoMovimiento=='F' || ultimoMovimiento=='L' || ultimoMovimiento=='R') && 
    tiempoDuracion >0){
    listaDoblementeEnlazada.agregar(ultimoMovimiento, tiempoDuracion);
  }
}

void moverCarrito(char letra){
  if(letra=='S'){
    stop();
    calcularTiempoDuracion();
    guardarValorEnLista();
  }

  if(letra=='B'){
    asignarValores(letra);
    back();
  }

  if(letra=='F'){
    asignarValores(letra);
    front();
  }

  if(letra=='L'){
    asignarValores(letra);
    left();
  }

  if(letra=='R'){
    asignarValores(letra);
    right();
  }
}

void calcularTiempoDuracion(){
  tiempoDuracion = millis() - tiempoInicio;
}

void asignarValores(char letra){
  tiempoInicio = millis();
  ultimoMovimiento = letra;
}

void stop(){
  digitalWrite(Pin_2,LOW);
  digitalWrite(Pin_4,LOW);
  digitalWrite(Pin_3,LOW);
  digitalWrite(Pin_5,LOW);  
}

void back(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_3,HIGH);
}

void front(){
  digitalWrite(Pin_2,HIGH);
  digitalWrite(Pin_5,HIGH);
}

void left(){
  digitalWrite(Pin_5,HIGH); 
  digitalWrite(Pin_3,HIGH);
}

void right(){
  digitalWrite(Pin_4,HIGH);
  digitalWrite(Pin_2,HIGH);
}

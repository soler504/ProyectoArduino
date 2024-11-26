#include <SoftwareSerial.h>
#include "Lista.h"

SoftwareSerial mySerial(11,10);  
char inputByte = "";
char ul = "";
bool grabar_u=false;
bool ejecutar_w=false;

int Pin_2 = 4;          
int Pin_3 = 2;        
int Pin_4 = 6;
int Pin_5 = 7;

Lista  move;
unsigned long tiempo_actual;
unsigned long tiempo_anterior = 0;
unsigned long delta_tiempo;

int contador = 0;
int opcion = 0;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(Pin_2, OUTPUT);      
  pinMode(Pin_3, OUTPUT);     
  pinMode(Pin_4, OUTPUT);    
  pinMode(Pin_5, OUTPUT); 
  
}

void loop() {
 // Esperamos 1 segundo
 // delay(1000);
  cronometro();

    if(mySerial.available()){
      inputByte = mySerial.read();
      if(inputByte == 'M'){
        grabar_u == true;
      }else if(inputByte == 'm'){
        grabar_u == false;
      }

      if(inputByte == 'N'){
        ejecutar_w == true;
      }else if('n'){
        ejecutar_w == false;
      }

      if(grabar_u == true){
          Serial.println(inputByte);
          movimiento(inputByte);
          if(inputByte == 'S'){
            move.agregar(ul, contador);
          }
          contador = 0;
      }

      if(ejecutar_w == true){
          move.presentarF();
      }

      Serial.println(inputByte);
      movimiento(inputByte);
          
      //move.agregar(ul, contador);
      contador = 0;
      ul = inputByte;    
   }
   
}
void movimiento(char m){
    if(m=='S'){         
       stop();
    }

    if(m=='B'){
      back();
    }
    
    if(m=='F'){
      front();
    }

    if(m=='L'){
     left();
    }

    if(m=='R'){
      right();
    }
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

void cronometro(){
  tiempo_actual = millis();
    delta_tiempo = tiempo_actual - tiempo_anterior;
    if(delta_tiempo == 1000){
      contador = contador + 1;
      //Serial.println(contador);
      tiempo_anterior = tiempo_actual;
    }
}
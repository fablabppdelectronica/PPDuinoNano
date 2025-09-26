#define   pinPulsador   17
#define   pinSalida     9

#include "mqttLib.h"
void mqttExecute(){
  if (mqttExecutingFlag){
    mqttExecutingFlag = false;
    if (topico == "codigo/relay"){
      if (mensaje == "ON"){
        digitalWrite(pinSalida,HIGH);
      }
      else if (mensaje == "OFF"){
        digitalWrite(pinSalida,LOW);
      }
    }
  }
}
bool statePulsador;
void checkPulsador(){
  if (mqttPublisherFlag){
    if (statePulsador != digitalRead(pinPulsador)){
      statePulsador = digitalRead(pinPulsador);
      if (statePulsador){
        // Solto el pulsador
        wifiSerial.println("codigo/sensor>0");
        Serial.println("codigo/sensor>0");
      }
      else{
        // Presiono el pulsador
        wifiSerial.println("codigo/sensor>1023");
        Serial.println("codigo/sensor>1023");
      }
    }
  }  
}
void setup() {
  mqttBegin();
  Serial.begin(9600);       // monitor serie
  pinMode(pinSalida,OUTPUT);
  digitalWrite(pinSalida,LOW);
  pinMode(pinPulsador,INPUT);
  statePulsador = digitalRead(pinPulsador);
}
void loop() {
  mqttLoop();
  mqttExecute();
  checkPulsador();
}

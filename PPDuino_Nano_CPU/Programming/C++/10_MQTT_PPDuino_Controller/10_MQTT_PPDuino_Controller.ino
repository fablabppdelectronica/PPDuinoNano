#include "mqttLib.h"

void mqttExecute(){
  if (mqttExecutingFlag){
    if (topico == "codigo/relay"){
      if (mensaje == "ON"){
        digitalWrite(9,HIGH);
      }
      else if (mensaje == "OFF"){
        digitalWrite(9,LOW);
      }
    }
  }
}

void setup() {
  mqttBegin();
  Serial.begin(9600);       // monitor serie
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
}

void loop() {
  mqttLoop();
  mqttExecute();
}

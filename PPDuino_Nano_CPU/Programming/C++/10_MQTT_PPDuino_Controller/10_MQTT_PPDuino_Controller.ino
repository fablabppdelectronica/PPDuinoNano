#include "mqttLib.h"

void mqttExecute(){
  if (mqttExecutingFlag){
    if (topico == "codigo/relay"){
      if (mensaje == "ON"){
        digitalWrite(13,HIGH);
      }
      else if (mensaje == "OFF"){
        digitalWrite(13,LOW);
      }
    }
  }
}

void setup() {
  mqttBegin();
  Serial.begin(9600);       // monitor serie
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  mqttLoop();
  mqttExecute();
}

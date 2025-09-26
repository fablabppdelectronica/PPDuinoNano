#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(2 , 4); // Rx y Tx
String buffer = "";
String mqttMessage;
String topico = "";
String mensaje = "";
bool wifiConnectFlag   = false, wifiConnectingFlag  = false;
bool mqttConnectFlag   = false, mqttConnectingFlag  = false;
bool mqttSubscribeFlag = false, mqttSubscribingFlag = false;
bool mqttPublisherFlag = false, wifiSerialFlag      = false;
bool mqttExecutingFlag = false;

void separateString(){
  int pos = mqttMessage.indexOf('<');
  if (pos != -1) {
    topico = mqttMessage.substring(0, pos);
    mensaje = mqttMessage.substring(pos + 1);
  }
}
void mqttBegin(){
  delay(7000);
  wifiSerial.begin(9600);   // puerto por software
  wifiConnectFlag = true;
}
void mqttLoop(){
  if (wifiConnectFlag){
    wifiSerial.println("wifi/connect>ON");
    Serial.println("wifi/connect>ON");
    wifiConnectFlag = false;
    wifiConnectingFlag = true;
  }
  else if (mqttConnectFlag){
    wifiSerial.println("mqtt/connect>ON");
    Serial.println("mqtt/connect>ON");
    mqttConnectFlag = false;
    mqttConnectingFlag = true;
  }
  else if (mqttSubscribeFlag){
    wifiSerial.println("codigo/relay<SUBSCRIBE");
    Serial.println("codigo/relay<SUBSCRIBE");
    mqttSubscribeFlag = false;
    mqttSubscribingFlag = true;
  }
  while (wifiSerial.available()) {
    char c = wifiSerial.read();
    buffer += c;
    if (buffer.endsWith("\r\n")) {
      buffer.trim();
      Serial.println(buffer);
      mqttMessage = buffer;
      buffer = "";
      wifiSerialFlag = true;
    }
  }
  if (wifiSerialFlag){
    wifiSerialFlag = false;
    if (wifiConnectingFlag){
      wifiConnectingFlag = false;
      mqttConnectFlag = true;
    }
    if (mqttConnectingFlag){
      mqttConnectingFlag = false;
      mqttSubscribeFlag = true;
    }
    if (mqttSubscribingFlag){
      mqttSubscribingFlag = false;
      mqttPublisherFlag = true;
    }
    if (mqttPublisherFlag){
      separateString();
      mqttExecutingFlag = true;
    }
  }
}

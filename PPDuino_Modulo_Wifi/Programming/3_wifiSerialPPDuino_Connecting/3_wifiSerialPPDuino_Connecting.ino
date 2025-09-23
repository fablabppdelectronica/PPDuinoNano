#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(2 , 4); // Rx y Tx
String buffer = "";
bool wifiConnectFlag, wifiConnectingFlag , mqttConnectFlag, mqttConnectingFlag;
bool mqttSubscribeFlag, mqttSubscribingFlag, mqttPublisherFlag, wifiSerialFlag;

void setup() {
  delay(7000);
  wifiSerial.begin(9600);   // puerto por software
  Serial.begin(9600);       // monitor serie
  wifiConnectFlag = true;
  mqttConnectFlag = false;
}

void loop() {
  if (wifiConnectFlag){
    wifiSerial.println("wifi/connect>ON");
    Serial.println("wifi/connect>ON");
    wifiConnectFlag = false;
    wifiConnectingFlag = true;
  }
  if (mqttConnectFlag){
    wifiSerial.println("mqtt/connect>ON");
    Serial.println("mqtt/connect>ON");
    mqttConnectFlag = false;
    mqttConnectingFlag = true;
  }
  if (mqttSubscribeFlag){
    wifiSerial.println("codigo/relay<SUBSCRIBE");
    Serial.println("codigo/relay<SUBSCRIBE");
    mqttSubscribeFlag = false;
    mqttSubscribingFlag = true;
  }
  if (Serial.available()) {
    wifiSerial.write(Serial.read());
  }
  while (wifiSerial.available()) {
    char c = wifiSerial.read();
    buffer += c;
    if (buffer.endsWith("\r\n")) {
      buffer.trim();
      Serial.println(buffer);
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
    }
  }
}

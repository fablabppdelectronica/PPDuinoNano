/*
Test with the following commands:
wifi/connect>ON
mqtt/connect>ON
codigo/relay<SUSBCRIBE
*/
#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(2, 4);  // Rx, Tx
void setup() {
  Serial.begin(9600); 
  wifiSerial.begin(9600);
}
void loop() {
  if (wifiSerial.available()) {
    Serial.write(wifiSerial.read());
  }
  if (Serial.available()) {
    wifiSerial.write(Serial.read());
  }
}

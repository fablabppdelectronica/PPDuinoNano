#define   pinPulsador   17
#define   pinSalida     9
void setup(){
  pinMode(pinPulsador,INPUT);
  pinMode(pinSalida,OUTPUT);
}
void loop(){
  if (!digitalRead(pinPulsador)) {
    digitalWrite(pinSalida,HIGH);
    delay(500);
    digitalWrite(pinSalida,LOW);
    delay(500);
  }
  else {
    digitalWrite(pinSalida,LOW);
  }
}

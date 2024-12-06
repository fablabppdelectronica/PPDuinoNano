#define   pinQ0   13
void setup() {
  pinMode(pinQ0, OUTPUT);
}

void loop() {
  digitalWrite(pinQ0, !digitalRead(pinQ0));
  delay(1000);
}

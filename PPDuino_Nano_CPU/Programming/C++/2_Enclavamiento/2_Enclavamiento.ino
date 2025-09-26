const int pinPulsador = 17; // cambia según tu placa
const int pinSalida   = 9;  // cambia según lo que necesites
// variables anti-rebote
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms
int lastButtonState = HIGH; // porque usamos INPUT
int buttonState = HIGH;
bool salidaLatched = false; // estado enclavado (false = apagado)

void setup() {
  pinMode(pinPulsador, INPUT);
  pinMode(pinSalida, OUTPUT);
  digitalWrite(pinSalida, LOW); // estado inicial
}

void loop() {
  int reading = digitalRead(pinPulsador);
  if (reading != lastButtonState) {
    // reiniciar contador de rebote
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // si ha pasado el tiempo de debounce y cambió el estado real
    if (reading != buttonState) {
      buttonState = reading;
      // detectar flanco de presionado (HIGH -> LOW con INPUT_PULLUP)
      if (buttonState == LOW) {
        // cambiar (toggle) el estado de la salida
        salidaLatched = !salidaLatched;
        digitalWrite(pinSalida, salidaLatched ? HIGH : LOW);
      }
    }
  }
  lastButtonState = reading;
}

const int buzzer_pin = 8;
void setup() {
  pinMode(buzzer_pin, OUTPUT);
}
void loop() {
  for (int i = 0; i < 22000; i++) {
    tone(buzzer_pin, i, 1);
  }
}

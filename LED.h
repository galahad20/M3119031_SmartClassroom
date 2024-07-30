
void KartuSalah () {
  digitalWrite(LedTerkunci, HIGH);
  digitalWrite(LedTerbuka,  HIGH);
  LED_PintuTerkunci.on();
  LED_PintuTerbuka.on();
  delay(100);
  digitalWrite(LedTerkunci, LOW);
  digitalWrite(LedTerbuka,  LOW);
  LED_PintuTerkunci.off();
  LED_PintuTerbuka.off();
  delay(100);
  digitalWrite(LedTerkunci, HIGH);
  digitalWrite(LedTerbuka,  HIGH);
  LED_PintuTerkunci.on();
  LED_PintuTerbuka.on();
  delay(100);
  digitalWrite(LedTerkunci, LOW);
  digitalWrite(LedTerbuka,  LOW);
  LED_PintuTerkunci.off();
  LED_PintuTerbuka.off();
}

void pintuTerbuka () {
  digitalWrite(LedTerkunci, LOW);
  digitalWrite(LedTerbuka,  HIGH);
  LED_PintuTerkunci.off();
  LED_PintuTerbuka.on();
}

void pintuTertutup () {
  digitalWrite(LedTerkunci, HIGH);
  digitalWrite(LedTerbuka,  LOW);
  LED_PintuTerkunci.on();
  LED_PintuTerbuka.off();
}


void PintuTerbuka() {
  lcd.setCursor(0, 0);
  lcd.print("  Pintu Terbuka ");
  lcd.setCursor(0, 1);
  lcd.print(" Silahkan Masuk ");
  Serial.println("Pintu Terbuka");
}

void KartuBenar() {
  cardState = 1;
  lcd.setCursor(0, 0);
  lcd.print("   Kartu Benar  ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  Serial.println("Kartu benar");
}

void KartuSalah() {
  cardState = 1;
  lcd.setCursor(0, 0);
  lcd.print("  Kartu  Salah  ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  Serial.println("Kartu salah");
}

void tempelKartu() {
  lcd.setCursor(0, 0);
  lcd.print("  Tempel Kartu  ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

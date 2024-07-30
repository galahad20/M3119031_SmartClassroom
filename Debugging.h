// -------------- Serial Monitor ---------------
long SM;
long previousMillis_SM;
const long interval_SM = 1000;

//--------------- PUSH DATA -----------------
void SerialMonitor () {
  SM = millis() ;
  if (SM - previousMillis_SM > interval_SM) {
    previousMillis_SM = SM;
    Serial.println("");

    Serial.print("IDTAG: ");
    Serial.println(IDTAG);

    Serial.print(F("cardState   :  "));
    Serial.println(cardState);

    Serial.print(F("doorFlag    :  "));
    Serial.print(doorFlag);
    Serial.println(hasilDoorlock);

    Serial.print("manualDoorlock_BUTTON: ");
    Serial.println(manualDoorlock_BUTTON);

    Serial.print("manualDoorlock_BLYNK: ");
    Serial.println(manualDoorlock_BLYNK);

    currentPerson >= 1 ? 
    Serial.println("Kondisi Lampu dan Pengharum ON") :
    Serial.println("Kondisi Lampu dan Pengharum OFF");

    Serial.print("PIR 1: "); Serial.println(Deteksi_Orang1);
    Serial.print("PIR 2: "); Serial.println(Deteksi_Orang2);
    Serial.print("Jumlah Orang Sekarang: "); Serial.println(currentPerson);
    Serial.print("Sequence: "); Serial.println(sequence);
    Serial.println("----------------------------------");

  }
}

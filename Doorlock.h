//--------------- GET DATA -----------------
BLYNK_WRITE(V5) {
  manualDoorlock_BLYNK = param.asInt();
}

//--------------- Push Button Manual -----------------
void PushButtonManual() {
  // --------------- MANUAL : BUTTON
  PBManual = millis() ;
  if (PBManual - previousMillis_PBManual > interval_PBManual) {
    manualDoorlock_BUTTON = digitalRead(ButtonManualPIN);
    if (manualDoorlock_BUTTON != lastButton) {
      previousMillis_PBManual = PBManual;
      lastButton = manualDoorlock_BUTTON;
      if (manualDoorlock_BUTTON == LOW) {
        doorFlag = (doorFlag == HIGH) ? LOW : HIGH;
        digitalWrite(RelayDoorlock, doorFlag);
      }
    }
  }

  if (manualDoorlock_BLYNK != lastButton) {
    lastButton = manualDoorlock_BLYNK;
    if (manualDoorlock_BLYNK == LOW) {
      doorFlag = (doorFlag == HIGH) ? LOW : HIGH;
      digitalWrite(RelayDoorlock, doorFlag);
    }
  }


}


//---------------- BACA RFID -----------------
void readCard() {
  if ( ! rfid.PICC_IsNewCardPresent()) {
    return;
  } if ( ! rfid.PICC_ReadCardSerial()) {
    return;
  }
  for (byte i = 0; i < rfid.uid.size; i++) {
    IDTAG += rfid.uid.uidByte[i];
  }
  if (doorFlag == HIGH) {
    if (IDTAG == "17950139167" || IDTAG == "8320423850" || IDTAG == "672336250") {
      cardState = 1;
      doorFlag = LOW;
      digitalWrite(RelayDoorlock, doorFlag);
      IDTAG = "";
    } else if (IDTAG != "17950139167" && IDTAG != "8320423850" && IDTAG != "672336250" && IDTAG != "") {
      cardState = 0;
      IDTAG = "";
    }
  } else {
    IDTAG = "";
  }
}

// TAG kartu       17950139167
// TAG gantungan   3245136152

// TAG kartu tambahan 1   8320423850
// TAG kartu tambahan 2   672336250









//--------------- PUSH DATA -----------------
void DoorLock() {

  // ------ Pintu Terkunci dan Kartu Di Tempel
  readCard();

  if (doorFlag == 1 ) {
    hasilDoorlock = " --> RELAY ON  --> PINTU TERKUNCI" ;
    if (cardState == 0) {
      KartuSalah ();
      timer.setTimeout(2000, []() {
        pintuTertutup ();
        cardState = 1;
      });
    } else {
      pintuTertutup ();
    }
  } else {
    hasilDoorlock = " --> RELAY OFF --> PINTU TERBUKA";
    pintuTerbuka ();
  }

  // ------ Push Button Manual Kunci / Buka Pintu
  PushButtonManual();

  // ------ Notif di BLYNK
  if (doorFlag == LOW  && Notif == HIGH) {
    Blynk.logEvent("notifPintuBuka", "Pintu Terbuka, Silahkan Masuk !");
    Notif = LOW;
  }
  if (doorFlag == HIGH) {
    Notif = HIGH;
  }
}


//RELAY AKTIF HIGH
// Di beri HIGH --> Relay ON --> NC dan COM tidak terhubung --->
// karena Doorlock dan 12VDC menggunakan pin NC dan COM --> Doorlock OFF / Doorlock Ke Luar --> Mengunci Pintu

// Di beri LOW --> Relay OFF --> NC dan COM terhubung --->
// karena Doorlock dan 12VDC menggunakan pin NC dan COM --> Doorlock ON / Doorlock Ke Dalam --> Membuka Pintu

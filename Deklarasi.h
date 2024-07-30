#include <Arduino.h>
// ----------------- RFID ------------------
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 49
#define RST_PIN 48
MFRC522 rfid(SS_PIN, RST_PIN);
bool Notif;
bool doorFlag;
String IDTAG = "";
bool cardState = 1;

// ----------------- PIR ------------------
#define PIR1_PIN 6
#define PIR2_PIN 7
int Deteksi_Orang1;
int Deteksi_Orang2;
int Deteksi_Orang;
String sequence = "";
int currentPerson = 0;
int timeoutCounter = 0;

// -------------- Relay Lampu ---------------
#define RelayLampu 9
bool lampState = false;

// -------------- Relay Pengharum Ruangan ---------------
#define RelayHarum 10

// -------------- Relay Doorlock ---------------
#define RelayDoorlock 8
String hasilDoorlock;

// -------------- Button Manual ---------------
#define ButtonManualPIN 11
bool manualDoorlock_BUTTON, manualDoorlock_BLYNK;
long PBManual;
long previousMillis_PBManual;
const long interval_PBManual = 300;
bool lastButton;

// -------------- LED ---------------
#define  LedTerbuka   12
#define  LedTerkunci  13

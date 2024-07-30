//---------------  BLYNK  -------------------
#define BLYNK_TEMPLATE_ID "TMPLzkJofCRI"
#define BLYNK_DEVICE_NAME "Smart Class"
#define BLYNK_AUTH_TOKEN "kxjPw4mvRvWnm-lkE2IYz7-585z1fnBT"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ZTE 67653W3R3";
char pass[] = "uptoyouu";
char server[] = "blynk-cloud.com";
int port = 8080;
int ReCnctFlag;       // Reconnection Flag
int ReCnctCount = 0;  // Reconnection counter
#define EspSerial Serial3
#define ESP8266_BAUD 115200
ESP8266 wifi(&EspSerial);

// ----------------- LED BLYNK ------------------
WidgetLED LED_PintuTerkunci (V0);
WidgetLED LED_PintuTerbuka  (V1);
WidgetLED LED_Deteksi_Orang (V2);
WidgetLED LED_Indikasi_Lampu(V3);
WidgetLED LED_Indikasi_Harum(V4);

//--------------- TAB LAIN -----------------
#include "Deklarasi.h"
#include "Koneksi_BLYNK.h"
#include "LED.h"
#include "Doorlock.h"
#include "Lampu.h"
#include "PengharumRuangan.h"
#include "PIR.h"
#include "Debugging.h"



// ----------------------------------------
void setup() {
  // -------- BLYNK
  Serial.begin(115200);
  Serial3.begin(115200);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  wifi.setDHCP(1, 1, 1);
  Blynk.config(wifi, auth, server);
  if (Blynk.connectWiFi(ssid, pass)) {  // If connected to WiFi...
    //    Blynk.connect();  // ...connect to Server
    Blynk.begin(auth, wifi, ssid, pass);
  }
  timer.setInterval(400L, DoorLock);
  timer.setInterval(400L, AksesPIR);


  // -------- RFID
  SPI.begin();
  rfid.PCD_Init(); // Init MFRC522

  // -------- PIR
  pinMode(PIR1_PIN, INPUT_PULLUP);
  pinMode(PIR2_PIN, INPUT_PULLUP);

  // -------- RelayDoorlock
  pinMode(RelayDoorlock, OUTPUT);

  // -------- ButtonManualPIN
  pinMode(ButtonManualPIN, INPUT);

  // -------- LedTerkunci & LedTerbuka
  pinMode(LedTerkunci,    OUTPUT);
  pinMode(LedTerbuka,     OUTPUT);

  // -------- RelayLampu & RelayHarum
  pinMode(RelayLampu,    OUTPUT);
  pinMode(RelayHarum,    OUTPUT);

  // -------- KONDISI AWAL
  doorFlag = HIGH;
  digitalWrite(RelayDoorlock, HIGH);  // Relay Mati / Pintu Terbuka
  digitalWrite(RelayLampu,    LOW);  // Relay Mati
  digitalWrite(RelayHarum,    LOW);  // Relay Mati

}




void loop() {
  CheckConnection();
  timer.run();
  SerialMonitor();

  if ( Serial3.available() )   {
    Serial.write( Serial3.read() );
  }
  if ( Serial.available() )       {
    Serial3.write( Serial.read() );
  }
}

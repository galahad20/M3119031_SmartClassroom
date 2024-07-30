
void CheckConnection() {
  if (Blynk.connected()) {  // If connected run as normal
    Blynk.run();
  } else if (ReCnctFlag == 0) {  // If NOT connected and not already tring to reconnect, set timer to try to reconnect in 60 seconds
    ReCnctFlag = 1;  // Set reconnection Flag
    Serial.println("Starting reconnection timer in 30 seconds...");
    timer.setTimeout(30000L, []() {  // Lambda Reconnection Timer Function
      ReCnctFlag = 0;  // Reset reconnection Flag
      ReCnctCount++;  // Increment reconnection Counter
      Serial.print("Attempting reconnection #");
      Serial.println(ReCnctCount);
      wifi.setDHCP(1, 1, 1); //Enable dhcp in station mode and save in flash of esp8266
      Blynk.config(wifi, auth, server, port);
      Blynk.connect();  // Try to reconnect to the server
      if (Blynk.connectWiFi(ssid, pass)) {
        Blynk.begin(auth, wifi, ssid, pass);
      }
    });  // END Timer Function
  }
}

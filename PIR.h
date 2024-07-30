void AksesPIR() {
  // ------------------------------------------- PIR

  Deteksi_Orang1 = digitalRead(PIR1_PIN);
  Deteksi_Orang2 = digitalRead(PIR2_PIN);

//  if (Deteksi_Orang1 == HIGH || Deteksi_Orang2 == HIGH) {
//    Deteksi_Orang = HIGH;
//    LED_Deteksi_Orang.on();
//  }  else {
//    Deteksi_Orang = LOW ;
//    LED_Deteksi_Orang.off();
//  }

if (Deteksi_Orang1 == 1 && sequence.charAt(0) != '1') {  //initial 17
        sequence += "1";
        delay(2000);
        //doorTimer-=500;
    
      } else if (Deteksi_Orang2 == 1 && sequence.charAt(0) != '2') {  //initial 17
        sequence += "2";
        delay(2000);
        //doorTimer-=500;
      }
    
      if (sequence == "12") {
        //personChange(currentPerson+1);
        
        if((currentPerson+1)<0)currentPerson = 0;
        else if((currentPerson+1)>=0)currentPerson=currentPerson+1;
        Serial.print("CurrentPerson = ");Serial.println(currentPerson);
        sequence = "";
        
      } else if (sequence == "21" && currentPerson > 0) {
        sequence = "";
        if((currentPerson-1)<0)currentPerson = 0;
        else if((currentPerson-1)>=0)currentPerson=currentPerson-1;
        Serial.print("CurrentPerson = ");Serial.println(currentPerson);
        //personChange(currentPerson-1);
        
      }
    
      // Resets the sequence if it is invalid or timeouts
      if (sequence.length() > 2 || sequence.equals("11") || sequence.equals("22") || timeoutCounter > 1) {
        sequence = "";
      }
    
      if (sequence.length() == 1) {  //
        timeoutCounter++;
      } else {
        timeoutCounter = 0;
      }
        
  Lampu();
  PengharumRuangan();
  
}

void personChange(int x) {
  
  if(x<0)currentPerson = 0;
  else if(x>=0)currentPerson=x;
  Serial.println("ganti");
  char message[15];
  //send rid;count_person;lamp_status
  if (currentPerson >= 1) sprintf(message, "1;%d;true", currentPerson);
  else sprintf(message, "1;%d;false", currentPerson);
  //publishMessage(message);
}

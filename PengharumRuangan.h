void PengharumRuangan() {
 if (currentPerson >= 1) 
      {  
        digitalWrite(RelayHarum,HIGH );
        LED_Indikasi_Harum.on();
      } else if (currentPerson == 0) 
      {
        digitalWrite(RelayHarum,LOW );
        LED_Indikasi_Harum.off();
      }
       
//  if (Deteksi_Orang == HIGH ) {
//    digitalWrite(RelayHarum, HIGH);
//    LED_Indikasi_Harum.on();
//  } else {
//    digitalWrite(RelayHarum, LOW);
//    LED_Indikasi_Harum.off() ;
//  }

}


//RELAY AKTIF HIGH
// Di beri HIGH --> Relay ON --> NO dan COM terhubung --->
// karena Pengharum Ruangan dan Battery menggunakan pin NO dan COM --> Pengharum Ruangan ON

// Di beri LOW --> Relay OFF --> NO dan COM tidak terhubung --->
// karena Pengharum Ruangan dan Battery menggunakan pin NO dan COM --> Pengharum Ruangan OFF

void Lampu() {
  
//  if (Deteksi_Orang == HIGH ) {
//    digitalWrite(RelayLampu, HIGH);
//    LED_Indikasi_Lampu.on();
//  } else {
//    digitalWrite(RelayLampu, LOW);
//    LED_Indikasi_Lampu.off() ;
//  }
// 
      if (currentPerson >= 1) 
      {  
        digitalWrite(RelayLampu,HIGH );
        LED_Indikasi_Lampu.on();
      } else if (currentPerson == 0) 
      {
        digitalWrite(RelayLampu,LOW );
        LED_Indikasi_Lampu.off() ;
      } 
}

// RELAY AKTIF HIGH
// Di beri HIGH --> Relay ON --> NO dan COM terhubung ---> 
// karena Lampu dan 220VAC menggunakan pin NO dan COM --> Lampu ON

// Di beri LOW --> Relay OFF --> NO dan COM tidak terhubung ---> 
// karena Lampu dan 220VAC menggunakan pin NO dan COM --> Lampu OFF

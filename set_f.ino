


void set_f2160() {                  // Set the frequency to 2160 - Direct 2304 LO
   band_str_update();
#ifdef DEBUG
  Serial.print("enter 2160\n");
#endif  
  // Transfer all 6 registers starting with R5 and going down to R0. MSB first
  digitalWrite(A4350_CS, LOW);
  delay(1);
  
  #ifdef REF25M                 // define reference as 10MHz or 25MHz at compile time to save code space.
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x9C);
  SPI.transfer(0x82);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x9E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0xce);
  SPI.transfer(0x21);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0x56);
  SPI.transfer(0x3e);
  SPI.transfer(0x80);
  digitalWrite(A4350_CS, HIGH);
  #endif
  
  #ifdef REF10M
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x95);
  SPI.transfer(0x02);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x9f);
  SPI.transfer(0x41);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0xd8);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif

#ifdef REF8M
#ifdef DEBUG
  Serial.print("enter 8M\n");
#endif 
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x94);
  SPI.transfer(0x00);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  SPI.transfer(0x11);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x01); // R0
  SPI.transfer(0x0e);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif

  while(!digitalRead(A4350_LOCK)) {
 #ifdef DEBUG   
  Serial.print("Waiting for lock 2160\n");
  lock_led(0);    // Turn the lock LED off
 #endif
    delay(50);
  }
  lock_led(1);    // Turn the LED back on
}

void set_f2808() {        // Set the frequency to 2808 - 5G transverter LO/2
  int j;
   band_str_update();

  // Transfer all 6 registers starting with R5 and going down to R0. MSB first
  digitalWrite(A4350_CS, LOW);
  delay(1);
  
  #ifdef REF25M                 // define reference as 10MHz or 25MHz at compile time to save code space.
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0xBC);
  SPI.transfer(0x82);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0xce);
  SPI.transfer(0x21);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0x38);
  SPI.transfer(0x19);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif
  
  #ifdef REF10M
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x85);
  SPI.transfer(0x02);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x9f);
  SPI.transfer(0x41);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0x8c);
  SPI.transfer(0x19);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif

#ifdef REF8M
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x84);
  SPI.transfer(0x00);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  SPI.transfer(0x11);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0xAF);
  SPI.transfer(0x80);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif

j=0;
 while(!digitalRead(A4350_LOCK)) {
 #ifdef DEBUG   
    Serial.print("Waiting for lock 2808\n");
  lock_led(0);    // Turn the lock LED off
 #endif
    delay(50);
    j++;
    if(j >= 1000) {
      lock_led(1);    // Turn the LED back on
      Serial.print("I can't wait anymore\n");
      return;
    }
  }
  lock_led(1);    // Turn the LED back on
}

void set_f3312() {    // Set the Frequency to 3312 - Direct LO for 3456
   band_str_update();

  // Transfer all 6 registers starting with R5 and going down to R0. MSB first
  digitalWrite(A4350_CS, LOW);
  delay(1);
  
  #ifdef REF25M                 // define reference as 10MHz or 25MHz at compile time to save code space.
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x8C);
  SPI.transfer(0x82);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x9f);
  SPI.transfer(0x41);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0x42);
  SPI.transfer(0x0F);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif
  
  #ifdef REF10M
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x85);
  SPI.transfer(0x02);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x9f);
  SPI.transfer(0x41);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0xa5);
  SPI.transfer(0x86);
  SPI.transfer(0x40);
  digitalWrite(A4350_CS, HIGH);
  #endif

#ifdef REF8M
  SPI.transfer(0x00); // R5
  SPI.transfer(0x58);
  SPI.transfer(0x00);
  SPI.transfer(0x05);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00);  // R4
  SPI.transfer(0x84);
  SPI.transfer(0x00);
  SPI.transfer(0x3C);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R3
  SPI.transfer(0x00);
  SPI.transfer(0x04);
  SPI.transfer(0xB3);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x78); //R2
  SPI.transfer(0x00);
  SPI.transfer(0x4E);
  SPI.transfer(0x42);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x08); //R1
  SPI.transfer(0x00);
  SPI.transfer(0x80);
  SPI.transfer(0x11);
  digitalWrite(A4350_CS, HIGH);
  
  delay(1);
  digitalWrite(A4350_CS, LOW);
  SPI.transfer(0x00); // R0
  SPI.transfer(0xcf);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  digitalWrite(A4350_CS, HIGH);
  #endif

 while(!digitalRead(A4350_LOCK)) {
 #ifdef DEBUG   
    Serial.print("Waiting for lock 3312\n");
  lock_led(0);    // Turn the lock LED off
 #endif
    delay(50);
  }
  lock_led(1);    // Turn the LED back on
}

void lock_led(bool led_state) {       // Set the PLL LED Lock on or off
    digitalWrite(PLL_LOCK_LED,led_state);
}  

void band_str_update(){
    switch(band) {
    case 0:
      strcpy(band_str,"2GHz");
      strcpy(lo_str,"2160");
      break;
    case 1:
      strcpy(band_str,"5GHz");
      strcpy(lo_str,"2808");
      break;
    case 2:
      strcpy(band_str,"3GHz");
      strcpy(lo_str,"3312");
      break;
    default:
      strcpy(band_str,"ERROR");
      strcpy(lo_str,"ERROR");
      break;
  }
}


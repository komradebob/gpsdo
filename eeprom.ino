
void eeprom_initialize() {               // if the first two bytes are not BB, erase the eeprom and set the first two bytes
  byte first,second;
  int address = 0;
  first=EEPROM.read(address);
  address++;
  second=EEPROM.read(address);
  if((first != 0xb) && (second != 0xb)) {
    lcd.home();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Initializing EEPROM");
    for (int i = 0 ; i < EEPROM.length() ; i++) {
     EEPROM.write(i, 0);
    }
    address=0;
    EEPROM.write(address,0xb);
    address++;
    EEPROM.write(address,0xb);
  }
  else {
    lcd.clear();
    lcd.home();
    lcd.setCursor(0,0);
    lcd.print("EEPROM Good");
    delay(500);
    return;
  }
  lcd.setCursor(0,0);
  lcd.print("EEPROM Initialized");
  delay(1000); 
  
}
void eeprom_update() {              // Update the systems state
  int address = 2;
  EEPROM.update(address,band);
  address++;
}

void eeprom_read() {                  // Get the system last state from eeprom
  int address = 2;
  band=EEPROM.read(address);
  address++;
  switch(band) {
    case 0:
      strcpy(band_str,"2160");
      break;
    case 1:
      strcpy(band_str,"2808");
      break;
    case 2:
      strcpy(band_str,"3312");
      break;
    default:
      strcpy(band_str,"ERROR");
      break;
  }
 #ifdef DEBUG
  Serial.print("Band=");
  Serial.print(band);
 #endif
}


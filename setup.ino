
void setup() {    // Setup Routine. Setup for all the elements goes here.

  int error, i;


  eeprom_initialize();
  eeprom_read();
  Serial.begin(SERIAL_BAUD);           // open the serial port at 9600 bps:
  while (!Serial) {              // Wait for the carrier pidgeons to wake up
#ifdef DEBUG   
  Serial.print("Waiting for Serial\n");
#endif
    delay(10);
  }

  ss.begin(GPS_BAUD);                        // Set the speed of GPS serial port

  // Set up for the 4350/4351

  pinMode(A4350_CS, OUTPUT);          // Chip Select is an output
  pinMode(A4350_LOCK, INPUT);         // Lock Detect
  pinMode(GPS_LOCK, INPUT);           // GPS Lock Detect from GPS uP
  pinMode(PLL_LOCK_LED, OUTPUT);      // Use the onboard LED as lock indication

  digitalWrite(A4350_CS, HIGH); // Select the 4350
  delay(500);                   // wait for the gerbils to wake up

  SPI.begin();                  // Get the SPI bus ready and configured
  SPI.setClockDivider(4);
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  digitalWrite(A4350_CS, LOW); // De-Select the 4350

  digitalWrite(PLL_LOCK_LED, 0); // Set the PLL lock LED off.

#ifdef DEBUG
  Serial.println("DEBUG: Check for LCD");
#endif

  Wire.begin();                             // Set up I2C
  Wire.beginTransmission(LCD_SPI_ADDR);     // LCD adapter location
  error = Wire.endTransmission();

#ifdef DEBUG
  Serial.print("Error: ");
  Serial.print(error);
#endif

  if (error == 0) {
#ifdef DEBUG
    Serial.println(": LCD found.");
#endif
    lcd.begin(DISP_COL, DISP_ROWS); // initialize the lcd as a DISP_COL char x DISP_ROWS lines

  } else {
#ifdef DEBUF
    Serial.println(": LCD not found.");
#endif
  } // if

  lcd.setBacklight(128);              // Let there be light
  lcd.home();                         // Go home
  lcd.clear();                        // Clear LCD
  lcd.setCursor(0, 0);                // Start at the beginning
  lcd.print(PRODUCT);
  lcd.setCursor(0, 1);
  lcd.print(VERSION);

  delay(3000);

  //    for(i=0;i<10;i++) {
  //      lcd.scrollDisplayLeft();
  //      delay(500);
  //    }

  attachInterrupt(digitalPinToInterrupt(interruptPin), button_interrupt_handler, FALLING);

  lcd.home();
  lcd.clear();
  i=0;
  while(i<GPS_INIT_WAIT) {
    lcd.setCursor(0,0);
    lcd.print("GPS Initializing"); 
    lcd.setCursor(0,1);
    lcd.print("   Seconds");
    lcd.setCursor(0,1);
    lcd.print(GPS_INIT_WAIT-i);
    delay(1000);
    i++;
  }

//  Wait for the GPS to lock up.

  int row = 0;
  i=0;
  // If !gps_lock display 'Waiting for GPS' on LCD, otherwise loop
  while (!digitalRead(GPS_LOCK)) {
    display_waiting(row);
    row++;
    if (row == DISP_ROWS) {
      row = 0;
    }
    delay(1000); 
  }
  
  lcd.home();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GPS Locked");
  set_pll();
  delay(2000);

}


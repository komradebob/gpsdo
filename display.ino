


void display() {

}


void update_display(int freq)
{

  char freq_string[8];

  sprintf(freq_string, "%d", freq);

  //Serial.print("%d\n",freq);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(freq_string);

  lcd.setCursor(0, 1);
  if (!digitalRead(A4350_LOCK))
    lcd.print("PLL:Un");
  else {
    lcd.print("PLL:Locked");

  }
  lcd.setCursor(11, 1);
  if (!digitalRead(GPS_LOCK)) {
    lcd.print("GPS:Un");
    lcd.setCursor(0,3);
    lcd.print("waiting");
  }
  else {
    lcd.print("GPS:Lock");
    lcd.setCursor(0, 3);
//    GPS_Time(1);
  }
  lcd.setCursor(0, 0);
}


void display_waiting(int row) {
  lcd.clear();
  lcd.home();
  lcd.setCursor(0,row);
  lcd.print("Waiting for GPS Lock");
}



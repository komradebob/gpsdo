
/*
    Called when button is pressed. If button has been down for > DOWN_TIME increment band
*/


void button_interrupt_handler()
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 300)
  {
    band++;
    if (band > band_count)
      band = 0;

  }
  last_interrupt_time = interrupt_time;
  set_pll();
}

void set_pll() {
#ifdef DEBUG
  Serial.print("Button pushed. band = ");
  Serial.print(band);
  Serial.print("\n");
#endif
  switch (band) {
    case (0):
      set_f2160();
      break;
    case (1):
      set_f2808();
      break;
    case (2):
      set_f3312();
      break;
    default:
      lcd.home();
      lcd.clear();
      lcd.setCursor(0, 2);
      lcd.print("ERROR SETTING PLL");
      //delay(10000);
      break;
  }
  band_str_update();
}



/* ******************************************************************************
 *  
 *  Transverter LO/GPS lock/Sequencer/kitchen sink 
 *  
 *  Procssor: Arduino Pro Micro 3.3V/8MHz
 *  Synth:  ADF-4350 SPI board from China 35-4.4GHz
 *  GPS:  Generic GPS module using uBLOX 7M
 *  
 *  History
 *  date      who description
 *  12/31/20  rmb initial save - LO locks to external 10MHz or internal 25MHz reference
 *  2/14/21   rmb Added in LCD code
 *  2/20/21   rmb Added in GPS Code, rewrote loop from demo mode
 *  4/17/21   rmb comments reflecting dual processor architecture for gpsdlo board
 *  
 *  This code is for UP2, which drives the display and the PLL
 *  
 */


#define DEBUG       // turn debugging code on/off

 #define VERSION20 "Version 0.3 4/19/21"
 #define PRODUCT20 "FastBob's Controller"

 #define VERSION16 "Ver. 0.3 4/19/21"
 #define PRODUCT16 "FastBob's Ctlr"

#define VERSION VERSION16
#define PRODUCT PRODUCT16
 
/* AD4350 to Pro Micro Pin Assignments:
    ADF4350 <-> Pro Micro 3.3V 8MHz
     DAT (5) = MOSI (11)  SPI Data
     CLK (4) = SCLK (13)  SPI Clock - Same as onboard LED, so no blinkies
     LE (6)  = D3 (3)     SPI Chip Select
     MUX (3) = D2 (2)     Output to Pro Micro used for lock detect

     gps tx/rx
      * GPS_TX is digital pin 17 (connect to TX of gps device)
      * GPS_RX is digital pin 16 (connect to RX of gps device)
*/

#include <SoftwareSerial.h>           // Load the Serial library
#include <TinyGPS.h>
#include <SPI.h>
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
#include <EEPROM.h>


//#define sprnt

LiquidCrystal_PCF8574 lcd(0x3F); // set the LCD address to 0x3F for a display

//int show = -1;

int addr = 0;
int band_count=2;

static byte band;   //band values
                              // 0 = 2160
                              // 1 = 2808
                              // 3 = 3312

                              
char band_str[6];
char lo_str[6];

int LAT_LONG_ADDR=addr+sizeof(unsigned char);
float flat, flon;
char lardir, longdir;
unsigned long age, date, time, chars = 0;
unsigned short sentences = 0, failed = 0;
char grid[10];
char my_date[9];
char my_time[9];

/****************************************
 * OLED Display Pins
 * Pin - OLED
 * D5 - PWM for brightness
 * D4 - SD Card Chip Select
 * D8 - DC pin
 * D10 - TFTCS
 * D11 - MOSI
 * D13 - SCLK
 *  
 */

char spinnie=0;

#define A4350_CS 4 // whatever pin you're using as chip select
#define A4350_LOCK 5 // Lock indication
#define PLL_LOCK_LED 10

#define SERIAL_BAUD 9600
#define GPS_BAUD  9600                    // speed of the GPS 
#define GPS_LOCK 6                        // input from the GPSDO indicating lock

#define GPS_TX 16                         // GPS TX connected here
#define GPS_RX 17                         // GPS RX connected here

#define GPS_INIT_WAIT 35                  // seconds to wait for the initial search for the GPS to settle down

SoftwareSerial ss(GPS_RX, GPS_TX);        //Set up pins for GPS comms
TinyGPS gps;


static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);


/*  +++ These two variables need to be manually set for the current time and location +++
 Local_Offset of -5 subtracts 5 hours to GMT, valid for Eastern Standard time.
 DST of 1 adds an extra hour in summer but is not automatically set. 
 */

int DST          =  1;                // Daylight Savings Offset
int Local_Offset = -5;                // Hours local time is offset from GMT

const byte interruptPin = 2;
volatile byte state = LOW;

#define LCD_SPI_ADDR  0x3F            // Address on the SPI bus of the LCD
#define DISP_ROWS 2
#define DISP_COL 16
//#define REF8M  // 10MHz Reference
#define REF10M  // 10MHz Reference
//#define REF25M  // define for 25MHz Clock

//////////////////////// CODE BEGINS HERE ////////////////////////





void loop() {
  char tmp[20];
char *junk;
  float flat, flon;
    unsigned long age;
  lcd.clear();
  lcd.setCursor(0,0);
  gps.f_get_position(&flat, &flon, &age);
  junk = deg_to_grid(flat,flon);
  print_date(gps);
  lcd.setCursor(0,0);
  sprintf(tmp,"%s %s",my_time,grid);
  lcd.setCursor(0,0);
  lcd.print(tmp);
  lcd.setCursor(0,1);
  sprintf(tmp,"%s Lo:%s",band_str,lo_str);
  lcd.print(tmp);
  smartdelay(1000);
                                            //  Get location, convert to grid

 // lcd.setCursor(1,2);
//  lcd.print(grid);
}
/*
//  set output 
// put your main code here, to run repeatedly:
#ifdef DEBUG
  Serial.print("loop\n");
#endif
  Serial.print("2160\n");
  update_display(2160);
  set_f2160();
  delay(10000);
  
  update_display(2808);
  Serial.print("2808\n");
  set_f2808();
  delay(10000);

  update_display(3312);
  Serial.print("3312\n");
  set_f3312();
  delay(10000);
  
  }

  */

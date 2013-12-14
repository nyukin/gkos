/*
 December 10th, 2013
 Wade Smith
 Test a Gkos keyboard on the Nokia 5100 series LCD
 Use this code for the powers of good
*/

// include libraries:
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Gkos.h>

  char* gEntry = ""; 

// initialize libraries with numbers of the interface pins
// pin 7 on Arduino is pin 3 on LCD
// pin 6 on Arduino is pin 4 on LCD 
// pin 5 on Arduino is pin 5 on LCD
// pin 4 is N.C. to CS on LCD
// pin 3 on Arduino is pin 7 on LCD
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
Gkos gkos(14, 15, 16, 17, 18, 19);

void setup(){

  // set up the display
  display.begin();
  delay(2000);
  display.clearDisplay();
  display.setContrast(100);
  display.setCursor(0,0);

}

void loop(){

  gEntry = gkos.entry(); // Will return empty immediately if no entry
  if (gEntry != 0){gPrint();}

}

void gPrint(){ // Convert commands depending on your application
  
  if (strcmp(gEntry, "_Enter") == 0){
      //Serial.println("");
      Serial.write( byte(10) ); Serial.write( byte(13) ); return;
  }
  if (strcmp(gEntry, "_BS") == 0){
      Serial.write( byte(8) ); return;
  }
  if (strcmp(gEntry, "_Del") == 0){
      Serial.write( byte(127) ); return;
  }
  if (strcmp(gEntry, "_Tab") == 0){
      Serial.write(byte (9) ); return;
  }
  
  // Put text on the screen 
  display.display();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.print(gEntry); 
}

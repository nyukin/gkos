/* Test your Gkos with the Serial Monitor of the Arduino IDE

This is a simple test to check that your GKOS keypad is
working, by showing on serial monitor the text you type.

*/

#include <Gkos.h>

  char* gEntry = ""; 

// Initialize Gkos library with pin numbers for keys A to F.
// Digital pins 14...19 are the same as analog pins 0...5
  Gkos gkos(14, 15, 16, 17, 18, 19);

void setup(){

  Serial.begin(9600); // Set up Serial library at 9600 bps.
  // Use the Arduino SDE Serial Monitor to view the output! 

}

void loop(){

  gEntry = gkos.entry(); // Will return empty immediately if no entry
  if (gEntry != 0){gPrint();}

  // Add your other code here

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

  // Default  
  Serial.write(gEntry);
  
}


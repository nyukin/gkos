// Test of Gkos and LiquidCrystal libraries together

// include libraries:
#include <LiquidCrystal.h>
#include <Gkos.h>


// initialize libraries with numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Gkos gkos(14, 15, 16, 17, 18, 19);

void setup(){

  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  lcd.cursor();

  // Print a message to the LCD.
  lcd.print("GKOS Keypad Test");
  lcd.setCursor(0, 1); // Move to second line (= 1)
}

void loop(){

  // What you type is shown on LCD
  lcd.print(gkos.entry()); 
  
  // Add your other code here, like:


}

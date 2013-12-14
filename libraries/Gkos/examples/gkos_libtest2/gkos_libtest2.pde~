// First test of Gkos library with LCD

// include libraries:
//#include <string.h>
#include <LiquidCrystal.h>
#include <Gkos.h>


char str1[] = "test";

char* gEntry = "";
char* gCompa = "12345678";
int test = 0;

// initialize libraries with numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Gkos gkos(14, 15, 16, 17, 18, 19);

void setup(){
  
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  lcd.cursor();
  // Print a message to the LCD.
  lcd.print("GKOS Keypad Test");
  //lcd.print("GKOS >");
  lcd.setCursor(0, 1); // Move to second line (= 1)
  //lcd.autoscroll(); 

}

void loop(){

  gEntry = gkos.entry(); // Will return empty immediately if no entry
  //if (gEntry[0] != gCompa[0]){  // Not NULL or:
  if (gEntry[0] != 0){  // Not NULL

  gCompa = "_BS";
  if (gEntry[1] == gCompa[1]){ // B == B ?
       lcd.rightToLeft(); // Looks strange but works!
       lcd.print(" "); 
       lcd.leftToRight();
       lcd.print(" "); 
       lcd.rightToLeft();
       lcd.print(" "); 
       lcd.leftToRight();
  } else {lcd.print(gEntry);}

    
  }

/*
    test = gkos.reference();
  if (test != 0){  // Not NULL
    lcd.print(test);
  }
 */

  
  // Add your other code here


}

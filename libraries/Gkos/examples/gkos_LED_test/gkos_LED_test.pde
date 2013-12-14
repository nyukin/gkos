/* Test of the Gkos library with the LED

This is a simple test to check
that your GKOS keypad is working,
by controling the LED on pin 13.

Press "a" => LED on
Press "b" => LED blinks a while
Press backspace => LED off
Press space => LED on for one second
*/

#include <Gkos.h>

char* gEntry = "";
char* gCompa1 = "a";   // Key A
char* gCompa2 = "_BS"; // Keys A+B+C = backspace
char* gCompa3 = "b";   // Key B
char* gCompa4 = " ";   // Keys D+E+F = space
int ledPin = 13;       // select the pin for the LED

// initialize library with numbers of the interface pins
Gkos gkos(14, 15, 16, 17, 18, 19);
// digital pins 14...19 are the same as analog pins 0...5

void setup(){
  
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 

}

void loop(){

  gEntry = gkos.entry(); // Will return empty immediately if no entry

  if (gEntry[0] == gCompa1[0]){  // "a" pressed, LED on
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  }

  if (gEntry[1] == gCompa2[1]){ // Backspace pressed, LED off
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);
  }


  if (gEntry[0] == gCompa3[0]){ // "b" pressed, LED blinks
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);
  delay(500);
    // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(500);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(500);      
    // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(500);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(500);      
    // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(500);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  }

   if (gEntry[0] == gCompa4[0]){  // space pressed, LED on and off
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  delay(1000);   
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  }
 
  // Add your other code here


}

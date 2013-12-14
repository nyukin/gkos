/*
  Gkos.h - Library for reading a GKOS keyboard.
  Created by Seppo Tiainen, March 28, 2010.
  Released into the public domain.
*/

#ifndef Gkos_h
#define Gkos_h

#include "Arduino.h"
//#include <string.h>
//#include <inttypes.h>
//#include "Print.h"

// Declaring functions and variables //////////////////////
class Gkos
{
  public:
    // Initialize I/O pin numbers for GKOS keys A to F
    Gkos(uint8_t APin, uint8_t BPin, uint8_t CPin, uint8_t DPin, uint8_t EPin, uint8_t FPin);
    char* entry();  // gkos.entry(), returns the character
    int reference(); // gkos.reference, returns gRef 
  private:
    bool gScanKeys();
    int _gRef;             // the GKOS Reference number (also for Shift/CAPS, Symb, 123abc)
    uint8_t _key_pins[8];  // Inputs of keys
    uint8_t _key_down[8];  // Status of keys (1 = pressed)
    uint8_t _shifts;    // 1=Shift, 2=Caps, 4=Nums, 8=Symb 

    static char* gOutput[10]; // for storing character

    int _time;
    int _previousTime;
    uint8_t _gChord; // GKOS final chord value (0...63) for the character
    uint8_t _firstChord; // First chord in a Chordon, if any 
    uint8_t _firstCounter; // Detect first chord in a Chordon
    uint8_t _previousChord; // to compare chord change
    uint8_t _presentChord; // the chord of the keypad at present
    uint8_t _autoRepeat;   // Repeat the character if pressed long (0 or 1)
    uint8_t _autoCounter;  // Typamatic delay counter (n x 10 ms)
    bool _gNew; // a new character is expected soon because new keys were pressed

};

#endif



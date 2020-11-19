#ifndef CandyCanonLib_Magazijn_h
#define CandyCanonLib_Magazijn_h

#include "Arduino.h"

#define UPPERSOLENOID 1
#define LOWERSOLENOID 2

class Magazijn
{
private:
    bool emptyMagazin();
    void solenoid(int solenoid, int solenoidState) 
public:
    void init();
    bool candyLaunched();
};

extern Magazijn Magazine;
#endif
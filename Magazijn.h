#ifndef CandyCanonLib_Magazijn_h
#define CandyCanonLib_Magazijn_h

#include "Arduino.h"

//solenoid states
#define OPEN 1
#define CLOSED 0

//delays 
#define shootingDelay 500
#define magazineDelay 500

class Magazijn
{
private:
    
    void solenoid(int solenoid, int solenoidState);  
public:
    static void emptyMagazine();    //interupt activates when magazin is empty   run "noInterrupts()" to overwrite it
    void init();                    //inittializes magazine module, should be put in setup
    void launchCandy();             //launch a candy
};

extern Magazijn Magazine;
#endif
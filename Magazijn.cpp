#include "Magazijn.h"

//pins of teensy
#define upperSolenoid
#define lowerSolenoid
#define emptySensor

Magazijn::Magazijn() {

}

//initializes Magazine should be put in the setup
void Magazijn::init() {

    //inittialize pinmodes
    pinMode(emptySensor, INPUT);
    pinMode(upperSolenoid, OUTPUT);
    pinMode(lowerSolenoid, OUTPUT);
    attachInterupt

    //close solenoids
    solenoid(upperSolenoid, CLOSED);
    solenoid(lowerSolenoid, CLOSED);
    
    attachInterrupt(emptySensor, emptyMagazine, RISING)
}

//interupt checks if the magazin is empty
static void emptyMagazine() {
    
    while(digitalread(emptySensor))
    {
        //magazine is empty
        //give alarm / error
    }
}

#include "Magazijn.h"

//pins of teensy
#define upperSolenoid
#define lowerSolenoid
#define emptySensor

//initializes Magazine should be put in the setup
void Magazijn::init() {

    //inittialize pinmodes
    pinMode(emptySensor, INPUT);
    pinMode(upperSolenoid, OUTPUT);
    pinMode(lowerSolenoid, OUTPUT);

    //close solenoids
    solenoid(upperSolenoid, CLOSED);
    solenoid(lowerSolenoid, CLOSED);
    
    attachInterrupt(emptySensor, emptyMagazine, RISING);
}

//interupt checks if the magazin is empty
static void emptyMagazine() {
    
    while(digitalRead(emptySensor))
    {
        //magazine is empty
        //give alarm / error
    }
}

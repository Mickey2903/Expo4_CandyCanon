#include "Magazijn.h"
#include "2DOFBASE.h"
#include "Shooter.h"

#define SERVOPINX 8;
#define SERVOPINY 9;

int state = 0;

void setup()
{
    Serial.begin(9600);
    Shooter_Init();
    Magazine.init();
    2DOFBase CandyCanon(SERVOPINX, SERVOPINY);




}

void loop() 
{

    switch(state)
    {
        case 0: 
            Read_Serial();
            Calculation();
            state =1;
        break;
        
        case 1:
        // Set angle
        // Servo.goTo(x,y)
        state = 2;
        break;

        case 2:
        SHOOTER();
        state = 3;
        break;

        case 3:
        // if(Up2Speed = high)
        // Duw het balletje vanuit magazijn
        state = 1;
        break;

        default:
        // Default state
        break;
    }



}
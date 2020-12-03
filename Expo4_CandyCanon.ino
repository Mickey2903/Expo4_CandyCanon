#include "Magazijn.h"
#include "2DOFBASEV2.h"
#include "Shooter.h"

#define SERVOPINX 8
#define SERVOPINY 9

int state = 0;
double homingX = 90, homingY = 22.5;

void setup()
{
    Serial.begin(9600);
    Shooter_Init();
    Magazine.init();
}

void loop() 
{
    switch(state)
    {
        case 0: 
            Read_Serial();
            Calculation();
            homing(homingX,homingY);
            state =1;
        break;
        
        case 1:
        goTo(90, Angle);
        state = 2;
        break;

        case 2:
        SHOOTER();                              //EXTRA check
        
        if(readytoshoot == true)                // if the speed is right go to next state
            {
                state = 3;
            }
        else
            {
                SHOOTER();
            }
        
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
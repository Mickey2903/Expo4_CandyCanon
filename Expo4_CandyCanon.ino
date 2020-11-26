#include "Magazijn.h"
#include "2DOFBASE.h"

#define SERVOPINX 8;
#define SERVOPINY 9;

void setup()
{
    Serial.begin(9600);

    Magazine.init();
    2DOFBase CandyCanon(SERVOPINX, SERVOPINY);



///////////////////////////SHOOTER/////////////////////////////////////

    pinMode(Safety_switch_1, INPUT);
    pinMode(Input_S1, INPUT);
    pinMode(Input_S2, INPUT);
    pinMode(Motor_01, OUTPUT);
    pinMode(Motor_02, OUTPUT);


}

void loop() 
{
    Motor_Speed()
}
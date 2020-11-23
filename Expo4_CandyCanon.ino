#include "Magazijn.h"
#include "2DOFBASE.h"

#define SERVOPINX 8;
#define SERVOPINY 9;

void setup()
{
    Serial.begin(9600);

    Magazine.init();
    2DOFBase CandyCanon(SERVOPINX, SERVOPINY);
}

void loop() 
{
    
}
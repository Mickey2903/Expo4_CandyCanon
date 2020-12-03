#include "2DOFBase.h"

#define SERVOPINX 8;
#define SERVOPINY 9;

void setup()
{
    Serial.begin(9600);
    2DOFBase TestBase(SERVOPINX, SERVOPINY);
    TestBase.homing(90, 22.5);
}

void loop()
{
}

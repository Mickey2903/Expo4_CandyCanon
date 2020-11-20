#include "2DOFBASE.h"

2DOFBase::2DOFBase(double x, double y)
{
  myservoX.attach(x);
  myservoY.attach(y);

  Serial.print("2 DOF BASE CREATED..");
}

void 2DOFBase::homing(int x, int y)
{
        if(myservoX.read() != homePosX)
        {
        myservoX.write(x);
        }
        if(myservoX.read() == homePosX)
        {
        myservoY.write(y);
        }

}

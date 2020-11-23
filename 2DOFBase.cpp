#include "2DOFBASE.h"

2DOFBase::2DOFBase(double x, double y)
{
  myservoX.attach(x);
  myservoY.attach(y);

  Serial.print("2 DOF BASE CREATED..");
}

void 2DOFBase::homing(double x, double y)
{
  int state = 0;
  double xPos = x, yPos = y;

  switch(state){
    case 0: Serial.print("Homing started..");
            state = 1;
    break;
    case 1: if (myservoX.read() != homePosX)
            {
              myservoX.write(xPos);
              Serial.print("X Pos: ");
              Serial.print(xPos);
              Serial.println(" degrees.");
            }
            else
            {
              state = 2;
            }
    break;  

    case 2: if(myservoX.read() == homePosX)
            {
              myservoY.write(yPos);
              Serial.print(" Y Pos: ")
              Serial.print(yPos);
              Serial.println(" degrees.")
            }
            else
            {
              state = 3;
            }
    break;

    case 3: Serial.println("Homing completed!");
    break;
  }
}

void 2DOFBase::goTo(double x, double y)
{
  double xPos = x, yPos = y;

  myservoX.write(xPos);
  Serial.print("X position: ")
  Serial.print(xPos);

  delay(1000);

  myservoY.write(yPos);
  Serial.print("Y position: ")
  Serial.print(yPos);

}
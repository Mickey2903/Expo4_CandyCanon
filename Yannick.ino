#include <Servo.h>

 Servo myServoX;
 Servo myServoY;

int homePosX = 90;
int homePosY = 22.5;

void homing(int x, int y);
void servoInit(int x, int y);

void setup()
{
    servoInit(8,9);
    homing(90,22.5);
}

void main()
{ /*
switch (var) {
  case label1:
    // statements
    break;
  case label2:
    // statements
    break; */
}

void homing(int x, int y)
{
    while (myservoX.read() =! x)
    {
        myservoX.write(x);
    }

    while (myservoY.read() =! y)
    {
         myservoY.write(y);
    }
}

void servoInit(int x, int y)
{
    myservoX.attach(x);
    myservoY.attach(y);
}





}
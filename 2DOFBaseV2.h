#include <Servo.h>

Servo myServoX;
Servo myServoY1;
Servo myServoY2;

double homeX = 0, homeY = 0;
double xPos = 45, yPos = 90;

void homing(double x, double y);
void goTo(double x, double y);
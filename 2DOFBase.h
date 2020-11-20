#include "Arduino.h"
#include <Servo.h>


class 2DOFBase {
    public:  
        Servo myservoX;
        Servo myservoY;

        void homing(double x, double y);

        2DOFBase(double x, double y);

    private:
        int servoPinX = 8, servoPinY = 9;
        double homePosX = 90, homePosY = 22.5;
};
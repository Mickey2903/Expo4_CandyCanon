#include "Arduino.h"
#include <Servo.h>


class 2DOFBase {
    public:  
        Servo myservoX;                                 // Define
        Servo myservoY;                                 

        2DOFBase(double x, double y);                   // Constructor for 2 DOF Base.

        void homing(double x, double y);                // A method that homes the 2 DOF Base by inputting the home x and y coordinates.
        void goTo(double x, double y);        // A method where you can put in 2 values for x and y to move the 2 DOF Base.
     
        double homePosX = 90, homePosY = 22.5;

    private:

};
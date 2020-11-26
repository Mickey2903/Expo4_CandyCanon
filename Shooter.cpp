#include "Shooter.h"


int Input_S1;               //RPM from encoder MOTOR 1
int Input_S2;               //RPM from encoder MOTOR 2
int Safety_switch_1 = 0;    //Safety switch for the motors

int Motor_01;               //OUT RPM Motor 1
int Motor_02;               //OUT RPM Motor 2

int Speed1 = 100;            //initial speed of the Motor 1, 0-255
int Speed2 = 100;            //initial speed of the Motor 2, 0-255

int Calculated_RPM;         //Calculated RPM;


int Motor1Up2speed;          // motor 1 has the desired speed?
int Motor2Up2speed;          // motor 2 has the desired speed?

// Dit is de code van Quido Joebens uit Snobbicht, ik ben 16 jaar oud en mijn hobby is motoren slopen


void Motor_Speed()
{
int time1d;     //time motor 1 down
int time1u;     //time motor 1 up
int time2d;     //time motor 2 down
int time2u;     //time motor 2 up

////////////////////////////////////MOTOR1////////////////////////////////////////////////////
    if (Calculated_RPM < Input_S1 && Safety_switch_1 == HIGH && (time1d + 50) <= millis())              //Motor 1 slowing down
    {   
        Speed1 = Speed1 - 1;
        analogWrite(Motor_01, Speed1);
        time1d = millis();                                                                              // timer, otherwise the motor would overshoot its desired speed
    }

    else if (Calculated_RPM > Input_S1 && Safety_switch_1 == HIGH && (time1u + 50) <= millis())              //motor 1 speeding up
    {   
        Speed1 = Speed1 + 1;
        analogWrite(Motor_01, Speed1);
        time1u = millis();                                                                             // timer, otherwise the motor would overshoot its desired speed
        }
    }

    else if (Calculated_RPM + 20 >= Input_S1 && Calculated_RPM - 20 <= Input_S1)             // Motor 1 on desired RPM
    {
        Motor1Up2speed = 1;
    }


////////////////////////////////////MOTOR2////////////////////////////////////////////////////
    if (Calculated_RPM < Input_S2 && Safety_switch_1 == HIGH && (time2d + 50) <= millis())              //Motor 2 slowing down
    {   
        Speed2 = Speed2 - 1;
        analogWrite(Motor_02, Speed2);
        time2d = millis();                                                                             // timer, otherwise the motor would overshoot its desired speed
    }

    else if (Calculated_RPM > Input_S2 && Safety_switch_1 == HIGH && (time2u + 50) <= millis())              //motor 2 speeding up
    {   
        Speed2 = Speed2 + 1;
        analogWrite(Motor_02, Speed2);
        time2u = millis();                                                                             // timer, otherwise the motor would overshoot its desired speed
    }
    
    else if (Calculated_RPM + 20 >= Input_S2 && Calculated_RPM - 20 <= Input_S2)             // Motor 2 on desired RPM
    {
        Motor2Up2speed = 1;
    }


///////////////////////////////////////////Shoot//////////////////////////////////////////////////////
    if(Calculated_RPM + 20 < Input_S1 || Calculated_RPM - 20 > Input_S1)
    {
        Motor1Up2speed = 0;
    }

    if(Calculated_RPM + 20 < Input_S2 || Calculated_RPM - 20 > Input_S2)
    {
        Motor2Up2speed = 0;
    }

    if(Motor1Up2speed == 1 && Motor2Up2speed == 1)
    {
        int Shoot = 1;
    }
}
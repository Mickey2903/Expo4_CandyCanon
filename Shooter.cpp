#include "Shooter.h"


#define Input_S1  ;               //RPM from encoder MOTOR 1                  IN
#define Input_S2 ;               //RPM from encoder MOTOR 2                  IN

int Motor1RPM;
int Motor2RPM;

#define Safety_switch_1 ;    //Safety switch for the motors                  IN
int Safety_switch;

int Motor_01;               //OUT RPM Motor 1                               OUT
int Motor_02;               //OUT RPM Motor 2                               OUT

int Speed1 = 100;            //initial speed of the Motor 1, 0-255
int Speed2 = 100;            //initial speed of the Motor 2, 0-255

bool readytoshoot;

float r = 5;                   // Wheel R in Meters
float X;                        //Bowl distance
float Y0 = 20;                  //begin heigth in CM
float Y1;                       //ceiling height
float Y2;                       //Bowl height

float V0x;
float V0y;
float V0;
int Calculated_RPM;             //Calculated RPM;                               Calculated


bool Ask = false;
bool Tell = false;



void Read_Serial() {

  if (Ask == false)
  {
    Ask = true;
    Serial.println(" Write down 'Bowlheight Bowldistance Ceilingheight' in CM");
    Serial.println(" for example : '30 500 200' "); 
  


    while (Serial.available()==0) {}


    // read the incoming height:
    Y2 = Serial.parseInt();
    // read the incoming distance:
    X = Serial.parseInt();
    // read the incoming ceiling height:
    Y1 = Serial.parseInt();

    //centimeters to Meters//
    Y0 = Y0 / 100;
    Y1 = Y1 / 100;
    Y2 = Y2 / 100;
    X = X / 100;
    r = r /100;
    Serial.println();
    Serial.print("Bowl Height: ");
    Serial.print(Y2);
    Serial.println(" Meters");

    Serial.print("Bowl distance:");
    Serial.print(X);
    Serial.println(" Meters");

    Serial.print("Ceilingheight:");
    Serial.print(Y1);
    Serial.println(" Meters");
    Serial.println();
    }
}




void Calculation()
{

 if (Tell == false)
  {
    Tell = true;
  
    V0y = sqrt((2) * 9.18 * Y1 - Y0);
    V0x = X / ((sqrt(2 * 9.18 * (Y1 - Y0))) / 9.18 + ((sqrt(-2 * 9.18 * (Y2 - Y1))) / 9.18));
    V0 = sqrt((V0x * V0x) + (V0y * V0y));
    Calculated_RPM = 60 / (2*3.14159265359*r)*V0;


    Serial.print("V0x = ");
    Serial.print(V0x);
    Serial.println(" M/Sec");
    Serial.print("V0y = ");
    Serial.print(V0y);
    Serial.println(" M/Sec");
    Serial.print("V0 = ");
    Serial.print(V0);
    Serial.println(" M/Sec");
    Serial.print("Desired RPM = ");
    Serial.print(Calculated_RPM);
    Serial.println(" RPM");
  }  
}


void Read_Inputs()
{

Safety_switch= digitalRead(Safety_switch_1);
Motor1RPM = analogRead(Input_S1);
Motor2RPM = analogRead(Input_S2);

}

void Motor_Speed_1()        ////////////////////////////////////MOTOR1////////////////////////////////////////////////////
{

Read_Inputs();

int time1d;     //time motor 1 down
int time1u;     //time motor 1 up

    if (Calculated_RPM < Motor1RPM && Safety_switch == HIGH && (time1d + 50) <= millis())                   //Motor 1 slowing down
    {   
        Speed1 = Speed1 - 1;
        analogWrite(Motor_01, Speed1);
        time1d = millis();                                                                                  // timer, otherwise the motor would overshoot its desired speed
    }

    else if (Calculated_RPM > Motor1RPM && Safety_switch == HIGH && (time1u + 50) <= millis())              //motor 1 speeding up
    {   
        Speed1 = Speed1 + 1;
        analogWrite(Motor_01, Speed1);
        time1u = millis();                                                                                  // timer, otherwise the motor would overshoot its desired speed
    }
}


void Motor_Speed_2()        ////////////////////////////////////MOTOR2////////////////////////////////////////////////////
{

Read_Inputs();

int time2d;     //time motor 2 down
int time2u;     //time motor 2 up

    if (Calculated_RPM < Motor2RPM && Safety_switch == HIGH && (time2d + 50) <= millis())                   //Motor 2 slowing down
    {   
        Speed2 = Speed2 - 1;
        analogWrite(Motor_02, Speed2);
        time2d = millis();                                                                                  // timer, otherwise the motor would overshoot its desired speed
    }

    else if (Calculated_RPM > Motor2RPM && Safety_switch == HIGH && (time2u + 50) <= millis())              //motor 2 speeding up
    {   
        Speed2 = Speed2 + 1;
        analogWrite(Motor_02, Speed2);
        time2u = millis();                                                                                  // timer, otherwise the motor would overshoot its desired speed
    }   
}


void Up2speed()
{

Read_Inputs();

int Motor1Up2speed;          // motor 1 has the desired speed?
int Motor2Up2speed;          // motor 2 has the desired speed?


    if (Calculated_RPM + 20 >= Motor1RPM && Calculated_RPM - 20 <= Motor1RPM)                       // Motor 1 on desired RPM
    {
        Motor1Up2speed = 1;
    }
    else
    {
        Motor1Up2speed = 0;
    }


    if (Calculated_RPM + 20 >= Motor2RPM && Calculated_RPM - 20 <= Motor2RPM)                       // Motor 2 on desired RPM
    {
        Motor2Up2speed = 1;
    }
    else
    {
        Motor2Up2speed =0;
    }


    if(Motor1Up2speed == 1 && Motor2Up2speed == 1)
    {
        readytoshoot = true;
    }
}
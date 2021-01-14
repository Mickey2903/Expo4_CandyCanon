#include "Shooter.h"



void Shooter_Init()
{
    pinMode(Safety_switch_1, INPUT);
    pinMode(Input_S1, INPUT);
    pinMode(Input_S2, INPUT);
    pinMode(Motor_01, OUTPUT);
    pinMode(Motor_02, OUTPUT);
    pinMode(MotorDirection_M1_Pin1, OUTPUT);
    pinMode(MotorDirection_M1_Pin2, OUTPUT);
    pinMode(MotorDirection_M2_Pin1, OUTPUT);
    pinMode(MotorDirection_M2_Pin2, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(Input_S1), ENCODER_READER_1, FALLING);
    attachInterrupt(digitalPinToInterrupt(Input_S2), ENCODER_READER_2, FALLING);


    digitalWrite(MotorDirection_M1_Pin1, HIGH);             //Rotating Direction Motor 1
    digitalWrite(MotorDirection_M1_Pin2, LOW);
    digitalWrite(MotorDirection_M2_Pin1, LOW);              //Rotating Direction Motor 2
    digitalWrite(MotorDirection_M2_Pin2, HIGH);
}



void ENCODER_READER_1()
{
  rpmcount1++;

  if (rpmcount1 >= 20) {
    
    rpm1 = (60000/(millis() - timeold1))*rpmcount1;
    Motor1RPM = rpm1 / magnets;
    timeold1 = millis();
    rpmcount1 = 0;
    Serial.println(Motor1RPM);
  }
}


void ENCODER_READER_2()
{
  rpmcount2++;
  
  if (rpmcount2 >= 20) {
    
    rpm2 = (60000/(millis() - timeold2))*rpmcount2;
    Motor2RPM = rpm2 / magnets;
    timeold2 = millis();
    rpmcount2 = 0;
  }
}



void Read_Serial() {

    Serial.println(" Write down 'Bowlheight Bowldistance Maximumheight' in CM");
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
    Serial.print("Begin Height:");
    Serial.print(Y0,3);
    Serial.println(" Meters");

    Serial.print("Maximum Height:");
    Serial.print(Y1,3);
    Serial.println(" Meters");

    Serial.print("End Height: ");
    Serial.print(Y2,3);
    Serial.println(" Meters");

    Serial.print("Distance:");
    Serial.print(X,3);
    Serial.println(" Meters");

    Serial.print("Wheel radius:");
    Serial.print(r,3);
    Serial.println(" Meters");
    Serial.println();
    
}


void Calculation()
{
    V0y = sqrt((2) * 9.81 * (Y1 - Y0));
    V0x = X / ((sqrt(2 * 9.81 * (Y1 - Y0))) / 9.81 + ((sqrt(-2 * 9.81 * (Y2 - Y1))) / 9.81));
    V0 = sqrt((V0x * V0x) + (V0y * V0y));
    Angle = ((atan(V0y/V0x))*180)/(3.14159);
    Calculated_RPM = 60 / (2 * 3.14159265359 * r) * V0;


    Serial.print("V0x = ");
    Serial.print(V0x);
    Serial.println(" M/Sec");
    Serial.print("V0y = ");
    Serial.print(V0y);
    Serial.println(" M/Sec");
    Serial.print("V0 = ");
    Serial.print(V0);
    Serial.println(" M/Sec");
    Serial.println();
    Serial.print("Desired Angle = ");
    Serial.print(Angle);
    Serial.println(" Degree");
    Serial.print("Desired RPM = ");
    Serial.print(Calculated_RPM);
    Serial.println(" RPM");
  
}


void Read_Inputs()
{
Safety_switch= digitalRead(Safety_switch_1);
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
    else
    {
        readytoshoot = false;
    }
}




void SHOOTER()
{

Motor_Speed_1();
Motor_Speed_2();
Up2speed();

}
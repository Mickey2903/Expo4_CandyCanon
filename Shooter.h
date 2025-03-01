#include "Arduino.h"

//////////////////MOTOR SPEED//////////////////////////////////////////////
#define Input_S1 4                //RPM from encoder MOTOR 1                  IN
#define Input_S2 5              //RPM from encoder MOTOR 2                  IN

int Motor1RPM;
int Motor2RPM;

int Writetime = 100;

#define Safety_switch_1 6     //Safety switch for the motors                  IN
int Safety_switch;

#define Motor_01 2               //OUT RPM Motor 1                               OUT
#define Motor_02 3             //OUT RPM Motor 2                               OUT

#define MotorDirection_M1_Pin1 12               //OUT RPM Motor 1                               OUT
#define MotorDirection_M1_Pin2 13               //OUT RPM Motor 1                               OUT

#define MotorDirection_M2_Pin1 14             //OUT RPM Motor 2 
#define MotorDirection_M2_Pin2 15             //OUT RPM Motor 2 

byte Speed1 = 100;            //initial speed of the Motor 1, 0-255
byte Speed2 = 100;            //initial speed of the Motor 2, 0-255

bool readytoshoot;

int Motor1Up2speed;          // motor 1 has the desired speed?
int Motor2Up2speed;          // motor 2 has the desired speed?



int time1d =0;     //time motor 1 down
int time1u =0;     //time motor 1 up

int time2d;     //time motor 2 down
int time2u;     //time motor 2 up


int timeserial =0;

///////////////////////CALCULATIONS & Serial READ////////////////////////////////////

float r = 7;                   // Wheel R in Meters
float X;                        //Bowl distance
float Y0 = 19;         //centerdist 90gr 196mm 180gr 185mm        //begin heigth in CM
float Y1;                       //ceiling height
float Y2;                       //Bowl height

float V0x;
float V0y;
float V0;
float Angle;
int Calculated_RPM;             //Calculated RPM;                               Calculated


bool Ask = false;
bool Tell = false;

///////////////////////////RPM CALCULATOR/////////////////////////////

volatile byte rpmcount1 = 0;
volatile byte rpmcount2 = 0;
unsigned int rpm1 = 0;
unsigned int rpm2= 0;
unsigned long timeold1 = 0;
unsigned long timeold2 = 0;
int magnets = 2;                           ////How many magnets are on the wheel?


void Shooter_Init();                // Initializes the shooting wheels
void ENCODER_READER_1();            // Reading Motor1 Speed
void ENCODER_READER_2();            // Reading
void Read_Serial();
void Calculation();
void Read_Inputs();
void Motor_Speed_1();
void Motor_Speed_2();
void Up2speed();
void SHOOTER();
int Input_S1;               //RPM from encoder MOTOR 1
int Input_S2;               //RPM from encoder MOTOR 2
int Safety_switch_1 = 0;    //Safety switch for the motors

int Motor_01;               //OUT RPM Motor 1
int Motor_02;               //OUT RPM Motor 2


int Calculated_RPM;         //Calculated RPM;




///////////////////////////setup/////////////////////////////////////
    pinMode(Safety_switch_1, INPUT);
    pinMode(Input_S1, INPUT);
    pinMode(Input_S2, INPUT);
    pinMode(Motor_01, OUTPUT);
    pinMode(Motor_02, OUTPUT);



void Shooter()
{




}
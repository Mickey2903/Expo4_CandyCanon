void servo_Init() {
  myServoY1.attach(7);
  myServoY2.attach(8);
  myServoX.attach(9);

  Serial.begin(9600);

}

void homing(double x, double y)
{
  myServoX.write(x);
  Serial.print("X Pos: ");
  Serial.print(x);
  delay(100);

  myServoY1.write(y);
  myServoY2.write(-y);
  Serial.print(" Y Pos: ");
  Serial.println(y);

 

}

void goTo(double x, double y)
{
  myServoX.write(x);
  Serial.print("X Pos: ");
  Serial.print(x);
  delay(100);

  myServoY1.write(y);
  myServoY2.write(-y);
  Serial.print(" Y Pos: ");
  Serial.println(y);
}
void servo_Init() {
  myServoY.attach(6);
  myServoX.attach(7);

  Serial.begin(9600);

}

void homing(double x, double y)
{
  myServoX.write(x);
  Serial.print("X Pos: ");
  Serial.print(x);
  delay(100);

  myServoY.write(y);
  Serial.print(" Y Pos: ");
  Serial.println(y);

}

void goTo(double x, double y)
{
  myServoX.write(x);
  Serial.print("X Pos: ");
  Serial.print(x);
  delay(100);

  myServoY.write(y);
  Serial.print(" Y Pos: ");
  Serial.println(y);
}
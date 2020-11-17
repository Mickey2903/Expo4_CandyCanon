#include <Wire.h>
int x = 0;
void setup() {
  Wire.begin(4);                // join i2c bus with address #8
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  
}

void loop() {
  delay(100);
}

void requestEvent() {
  x++;
  Wire.write(x); // respond with message of 6 bytes
  // as expected by master
}
void receiveEvent(int howMany)
{
  x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

#include <Servo.h>
// Declare the Servo pin
int servoPin = 9;
int servoPin2 = 10;
// Create a servo object
Servo Servo2;
Servo Servo1;
void setup() {
  Servo2.attach(servoPin2);
  Servo1.attach(servoPin);
}
void loop() {
   Servo1.write(180);
  delay(2000);
  Servo2.write(90);
  delay(2000);
  Servo1.write(0);
   Servo2.write(180);
  delay(2000);
   Servo2.write(0);
  delay(2000);
  
}

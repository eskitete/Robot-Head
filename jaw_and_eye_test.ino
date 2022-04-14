  // Include the Servo library
#include <Servo.h>
// Declare the Servo pin
int servoPin = 9;
int servoPin2 = 10;
// Create a servo object
Servo Servo1;
Servo Servol2;
void setup() {
  // We need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  Servol2.attach(servoPin2);
}
void loop() {

  Servo1.write(0);
  delay(2000);
  
  Servol2.write(0);
  delay(2000);

  Servo1.write(90);
  delay(1000);
  // Make servo go to 180 degrees
 
  
  Servol2.write(170);
  delay(2000);
    
  Servo1.write(170);
  delay(2000);  
   


  // Make servo go to 180 degrees


}

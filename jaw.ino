#include <Servo.h>
const int jawpin = 9;
const int eyepin = 10;
Servo eyes;
Servo jaw;
int servojaw;
int servoeye1;
int servoeye0;

char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 4;

void setup() {
  // put your setup code here, to run once:
  jaw.attach(jawpin);  
  eyes.attach(eyepin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveData();
  if(servojaw ==1){jaw.write(0);}else{jaw.write(180);}
  if(servoeye0 == 1 and  servoeye1 == 1){eyes.write(90);}
  if(servoeye0 == 1 and servoeye1 == 0){eyes.write(180);}  
  if(servoeye1 == 1 and servoeye0 == 0){eyes.write(0);}

}


void receiveData() {
   int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
  
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        servojaw = myRevivedString.substring(1, 2).toInt();
        servoeye0 = myRevivedString.substring(2, 3).toInt();
        servoeye1 = myRevivedString.substring(3).toInt();
        //Serial.print(servojaw);
        //Serial.print(" ");
        Serial.print(servoeye0);
        Serial.print(" ");
        Serial.print(servoeye1);       
        myRevivedString = "";
    }
    }
  }
}

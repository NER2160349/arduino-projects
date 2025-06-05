#include <Servo.h>

Servo myServo; //servo object 
int servoDelay = 1000; //This is how long it will wait before sending positioning commands
int servoMax = 180; //max value in degrees that we are allowing our servo to move
int servoMin = 0; //min value in degrees that we are allowing our servo to move 

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  //move the servo to its min position then wait 1 second
  //then move the servo to its max position and wait for one second
  myServo.write(servoMax);
  delay(servoDelay);
  myServo.write(servoMin);
  delay(servoDelay);
}

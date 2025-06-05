#include <Servo.h>

Servo myServo; //servo object 
int servoDelay = 1000; //This is how long it will wait before sending positioning commands
int servoMax = 180; //max value in degrees that we are allowing our servo to move
int servoMaxMid = 135;
int servoMid = 90;
int servoMinMid = 45;
int servoMin = 0; //min value in degrees that we are allowing our servo to move 

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Moving the servo in degrees and waiting one second to perform

    myServo.write(servoMax);
    delay(servoDelay);
    myServo.write(servoMaxMid);
    delay(servoDelay);
    myServo.write(servoMid);
    delay(servoDelay);
    myServo.write(servoMinMid);
    delay(servoDelay);
    myServo.write(servoMin);
    delay(servoDelay);
}

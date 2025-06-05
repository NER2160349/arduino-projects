#include <Servo.h>

Servo myServo; //servo object 
int servoDelay = 1000; //This is how long it will wait before sending positioning commands
int servoMax = 180; //max value in degrees that we are allowing our servo to move
int servoMaxMid = 135;
int servoMid = 90;
int servoMinMid = 45;
int servoMin = 0; //min value in degrees that we are allowing our servo to move 
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //move the servo to its min position then wait 1 second
  //then move the servo to its max position and wait for one second

    digitalWrite(ledPin, HIGH);
    delay(500);
    myServo.write(servoMax);
    digitalWrite(ledPin, LOW);
    delay(servoDelay);

    digitalWrite(ledPin, HIGH);
    delay(500);
    myServo.write(servoMaxMid);
    digitalWrite(ledPin, LOW);
    delay(servoDelay);
   
    digitalWrite(ledPin, HIGH);
    delay(500);
    myServo.write(servoMid);
    digitalWrite(ledPin, LOW);
    delay(servoDelay);
    
    digitalWrite(ledPin, HIGH);
    delay(500);
    myServo.write(servoMinMid);
    digitalWrite(ledPin, LOW);
    delay(servoDelay);
    
    digitalWrite(ledPin, HIGH);
    delay(500);
    myServo.write(servoMin);
    digitalWrite(ledPin, LOW);
    delay(servoDelay);
    
}

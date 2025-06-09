//Include the code library for the sensor
#include "SR04.h"
//Declare pins
int pinTrig = 12;
int pinEcho = 11;
int pinBlue = 10;
int pinGreen = 9;
int pinRed = 6;

//Create sensor object
SR04 sensor = SR04(pinEcho, pinTrig);

//Variable for distance measurments
long distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);// 1 second
  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  if(distance <= 5){
    Serial.println(distance);
    digitalWrite(pinRed, HIGH);
    delay(2000); //maybe change this?
    digitalWrite(pinRed, LOW);
    delay(2000);
  }
  else if(distance >5 && distance <= 10){
    Serial.println(distance);
    digitalWrite(pinBlue, HIGH);
    delay(2000); //maybe change this?
    digitalWrite(pinBlue, LOW);
    delay(2000);
  }
  else if(distance > 10){
    Serial.println(distance);
    digitalWrite(pinGreen, HIGH);
    delay(2000); //maybe change this?
    digitalWrite(pinGreen, LOW);
    delay(2000);
  }
}

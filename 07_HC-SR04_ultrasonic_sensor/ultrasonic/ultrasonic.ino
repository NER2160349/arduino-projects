//Include the code library for the sensor
#include "SR04.h"
//Declare pins
int pinTrig = 12;
int pinEcho = 11;

//Create sensor object
SR04 sensor = SR04(pinEcho, pinTrig);

//Variable for distance measurments
long distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);// 1 second
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  Serial.println(distance);
  delay(1000);
}

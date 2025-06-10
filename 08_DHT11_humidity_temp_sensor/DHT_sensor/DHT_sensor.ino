#include "DHT.h"

//Arduino pin connected to the DHT-11's data pin
#define DHTPIN 2

//Type of DHT sensor
#define DHTTYPE DHT11

//Initialize of DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //data rate of x bits/sec
  Serial.println("Humidity and Temperature"); //send text to monitor

  //start the sensor
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000); //delay 2 sec

  //Read humidity
  float h = dht.readHumidity();

  //Read temperature as Celsius (default)
  float t = dht.readTemperature();

  //Send data to serial monitor for display  
  Serial.println("Humidity: " + String(h) + "% Temperature: " + String(t) + "°C");
  
  
}

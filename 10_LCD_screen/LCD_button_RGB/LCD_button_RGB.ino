//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground *
 * LCD VSS pin to ground *
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */ 

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//initialize buttons and RGB LED
int onButton= 2; // 1 on 
int offButton = 3; // 0 off
int redButton = 4;
int greenButton = 5;
int blueButton = 13;
int redLED = 6;
int greenLED = 15;
int blueLED = 16;
bool isON = true;
bool isOFF = false;
bool printMenu = false;

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(onButton, INPUT_PULLUP); // not pressed, internal pullup resistor
  pinMode(offButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP); 
  //set up for led
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Click \"ON\" :-P");
  Serial.begin(9600);
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  if(digitalRead(onButton) == LOW){
    isON = true;
    isOFF = false;
    if(!printMenu){
      lcd.clear();
      lcd.print("Red-Green-Blue");
      printMenu = true;
    }
  }
  if(digitalRead(offButton) == LOW){
    printMenu = false;
    isOFF = true;
    isON = false;
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    lcd.clear();
    lcd.print("Goodbye");
  }
  
  if(isON){
    //Check which button was pressed and turn on that color
    if(digitalRead(redButton) == LOW){ //Red LED
      Serial.println("Red button pressed");
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      lcd.clear();
      lcd.print("RED");
      digitalWrite(redLED, HIGH);
      delay(4000); // 4 seconds
      
    }else if(digitalRead(greenButton) == LOW){ //Green LED
      Serial.println("Green button pressed");
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      lcd.clear();
      lcd.print("GREEN");
      digitalWrite(greenLED, HIGH);
      delay(4000); // 4 seconds
      
    }else if(digitalRead(blueButton) == LOW){ //Blue LED
      Serial.println("Blue button pressed");
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      lcd.clear();
      lcd.print("BLUE");
      digitalWrite(blueLED, HIGH);
      delay(4000); // 4 seconds
     }
  }
}

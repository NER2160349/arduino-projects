#include "IRremote.h"
#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface
LiquidCrystal lcd(2,3,4,5,6,7);

//Initialize buttons 

//Red LED and button (this is for 1 or true)
int oneLED = 9;
int oneButton = 8;

//Blue LED and button (this is for 0 or false)
int zeroLED = 11;
int zeroButton = 10;

//Green LED and button (this is for AND (∧)
int andLED = 13;
int andButton = 12;

//Yellow LED and button (this is for OR (∨)
int orLED = A2; 
int orButton = A3;

//White LED (Answer is ready)
int outputLED = A0;

bool printMenu = false;


void setup() {
  // put your setup code here, to run once:
  //Setting buttons with internal pullup resistor
  pinMode(oneButton, INPUT_PULLUP);
  pinMode(zeroButton, INPUT_PULLUP);
  pinMode(andButton, INPUT_PULLUP);
  pinMode(orButton, INPUT_PULLUP);

  //Setting LED's
  pinMode(oneLED, OUTPUT);
  pinMode(zeroLED, OUTPUT);
  pinMode(andLED, OUTPUT);
  pinMode(orLED, OUTPUT);
  pinMode(outputLED, OUTPUT);
  
  lcd.begin(16,2);
  lcd.print("Welcome"); //Maybe delete
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // set the cursor to column 0, line 1
  lcd.setCursor(0,1);
  lcd.print("Choose Red(0) or Blue(1)");
  delay(6000); //Three secs delay
  String answer;
  if(digitalRead(oneButton) == LOW && zeroButton == HIGH){ //If 1 was pressed
    answer = "Red"; // Creating the string
    lcd.print("Choose AND(∧) or OR(∨)");
    digitalWrite(oneLED, HIGH); //Turn on LED
    delay(3000);
    if(digitalRead(andButton) == LOW && zeroButton == HIGH){ // If AND was pressed
      answer += "AND";
      lcd.print("Choose Red(0) or Blue(1)"); //Ask again
      digitalWrite(zeroLED, HIGH); //Turn on LED
      delay(3000);
      if(digitalRead(oneButton) == LOW && zeroButton == HIGH){ //If 1 was pressed
        answer += "Red";
        lcd.print("RED AND RED = RED"); //AND logic
        digitalWrite(outputLED, HIGH); //Turn on LED
        delay(3000);
      }
    }
  }
}

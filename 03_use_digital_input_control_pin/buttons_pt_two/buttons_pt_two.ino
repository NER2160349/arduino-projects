int ledPin = 5;
int buttonHigh = 3;
int buttonOffPin = 11;
int buttonMed = 9;
int buttonLow = 6;

int highValue = 255;
int medValue = 110;
int lowValue = 50;
int offValue = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonHigh, INPUT_PULLUP);
  pinMode(buttonMed, INPUT_PULLUP);
  pinMode(buttonLow, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP); 
}

void loop() {
  // put your main code here, to run repeatedly:
   
  if(digitalRead(buttonHigh) == LOW){
    analogWrite(ledPin, highValue); 
  }
  if(digitalRead(buttonMed) == LOW){
    analogWrite(ledPin, medValue);
  }
  if(digitalRead(buttonLow) == LOW){
    analogWrite(ledPin, lowValue);
  }
  if(digitalRead(buttonOffPin) == LOW){
    analogWrite(ledPin, offValue);
  }
  
}

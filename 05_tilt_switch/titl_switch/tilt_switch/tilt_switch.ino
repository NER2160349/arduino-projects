int tiltPin = 10;
int buzzerPin = 9;
int ledPin = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);

  //Make sure the LED and buzzer are turned off
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Monitor the tilt switch
  //If the input goes high, it means the contact has been broken, and
  // the internal pullup resistor is now able to pull the input to HIGH.
  //Notice that it acts as a trigger. Once we see a HIGH signal on the 
  // tilt switch, we activate the LED and the buzzer, but we never set them low again.

  if(digitalRead(tiltPin) == HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
}

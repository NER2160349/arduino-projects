int buzzerPin = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzerPin, HIGH); //Turning the buzzer on
  delay(1); //delay time in between
  digitalWrite(buzzerPin, LOW); //off 
  delay(900); // delay again
}

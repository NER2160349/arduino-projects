int passiveBuzzer = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(passiveBuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 250; i++){
    digitalWrite(passiveBuzzer, HIGH);
    delay(1);
    digitalWrite(passiveBuzzer, LOW);
    delay(1);
  }
  delay(500);

   for(int i = 0; i < 125; i++){
    digitalWrite(passiveBuzzer, HIGH);
    delay(2);
    digitalWrite(passiveBuzzer, LOW);
    delay(2);
  }
}

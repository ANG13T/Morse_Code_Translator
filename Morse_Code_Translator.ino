
const int dashLED = 2;
const int dotLED = 3;
const int buzzerPin = 4;
const int rightButton = 5;
const int centerButton = 6;
const int leftButton = 7;
const int potPin = A0;

int freqValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dotLED, OUTPUT);
  pinMode(dashLED, OUTPUT);
  pinMode(centerButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
  Serial.begin(9600);
}

void loop() {
    freqValue = analogRead(potPin);
//  digitalWrite(dotLED, HIGH);
//  digitalWrite(dashLED, LOW);
//  tone(buzzerPin, 1000);
//  delay(1000);
//  digitalWrite(dotLED, LOW);
//  digitalWrite(dashLED, HIGH);
//  noTone(buzzerPin);
//  delay(1000);
  Serial.print("pot value: ");
  Serial.println(freqValue);
  if(digitalRead(leftButton)){
    digitalWrite(dotLED, HIGH);
  }else{
    digitalWrite(dotLED, LOW);
  }
}

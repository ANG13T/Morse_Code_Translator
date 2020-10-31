const int dotLED = 2;
const int dashLED = 3;
const int buzzerPin = 4;
const int centerButton = 5;
const int rightButton = 6;
const int leftButton = 7;
const int potPin = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(dotLED, OUTPUT);
  pinMode(dashLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(centerButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

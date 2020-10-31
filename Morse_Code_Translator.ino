#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int dashLED = 2;
const int dotLED = 3;
const int buzzerPin = 4;
const int rightButton = 5;
const int centerButton = 6;
const int leftButton = 7;
const int potPin = A0;

int freqValue = 0;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

char codeArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
char topRow[16];

int cursorX = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dotLED, OUTPUT);
  pinMode(dashLED, OUTPUT);
  pinMode(centerButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  intitializeBoard();
  lcd.blink();
}

void loop() {
    freqValue = analogRead(potPin);
    lcd.setCursor(cursorX, 0);
    
//  digitalWrite(dotLED, HIGH);
//  digitalWrite(dashLED, LOW);
//  tone(buzzerPin, 1000);
//  delay(1000);
//  digitalWrite(dotLED, LOW);
//  digitalWrite(dashLED, HIGH);
//  noTone(buzzerPin);
//  delay(1000);

  if(digitalRead(leftButton)){
    moveCursor(-1);
  }

  if(digitalRead(centerButton)){
   changeCharacter();
   
  }
  
  if(digitalRead(rightButton)){
    moveCursor(1);
  }

  delay(50);

}

void moveCursor(int direction){
  if(direction == -1 && cursorX - direction >= 0){ //move left
    cursorX -= 1;
  }

  if(direction == 1 && cursorX + direction < 16){ //move right
    cursorX += 1;
  }
  
}

void changeCharacter(){  
  Serial.print("next char");
  lcd.print(getNextChar(topRow[cursorX]));
}

char getNextChar(char currentChar){
  int result;
  int charIndex = getLetterIndex(currentChar);
   Serial.print(charIndex);
  if(charIndex + 1 < sizeof(codeArray)){
    result = charIndex + 1;
  }else{
    result = 0;
  }

  topRow[cursorX]= codeArray[result];
  lcd.print(codeArray[result]);
}

void intitializeBoard() {
  for (int i = 0; i < sizeof(topRow); i++) {
     lcd.setCursor(i, 0);
     lcd.print("");
  }
  lcd.setCursor(0, 0);
}

int getLetterIndex(char letter) {
  for (int i = 0; i < sizeof(codeArray); i++) {
    if (codeArray[i] == letter) {
      return i;
    }
  }
  return 26;
}

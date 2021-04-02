#include "DigiKeyboard.h"
const int buttonPin = 2;
const int gndpin = 1;
int buttonState = 0;

long pressedTime;
long releasedTime;

int lastState;
int currentState;

const int SHORT_PRESS_TIME = 500; // 500 milliseconds

void setup() {
  lastState = LOW;
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(gndpin, OUTPUT);
  digitalWrite(gndpin, LOW);
  DigiKeyboard.sendKeyStroke(0);
}



void loop() {
  currentState = digitalRead(buttonPin);

  if (lastState == HIGH && currentState == LOW) {
    pressedTime = millis();
    lastState = currentState;
    DigiKeyboard.sendKeyPress(44);
  }
  if (lastState == LOW && currentState == HIGH) {
    releasedTime = millis();
    DigiKeyboard.sendKeyStroke(0);
    lastState = currentState;
  }
  long pressDuration = releasedTime - pressedTime;

  if ( pressDuration < SHORT_PRESS_TIME ) {
    //short
  } else {
    //long
  }
  //  delay(20);
}

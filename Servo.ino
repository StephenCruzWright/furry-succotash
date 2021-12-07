#include <Servo.h>
#define potPin A0
Servo theServo;
int CloseBtnp= 2, RLEDp= 13, ledState= HIGH, buttonState, lastButtonState= LOW;
unsigned long lastDebounceTime= 0, debounceDelay= 50;
void setup() {
  pinMode(CloseBtnp, INPUT);
  pinMode(RLEDp, OUTPUT);
  theServo.attach(9);
  digitalWrite(RLEDp, ledState);
}

void loop() {
  int reading = digitalRead(RLEDp), val= analogRead(potPin);
    val= map(val, 0, 1023, 0, 180);
    theServo.write(val);
    delay(15);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
        digitalWrite(RLEDp, ledState);
      }
    }
  } 
  digitalWrite(RLEDp, ledState);
  lastButtonState = reading;
}

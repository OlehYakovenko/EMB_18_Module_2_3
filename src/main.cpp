#include <Arduino.h>

#define RED_LED_PIN 17
#define BLUE_LED_PIN 15
#define GREEN_LED_PIN 16
#define RED_MILLIS 1000
#define BLUE_MILLIS 500
#define GREEN_MILLIS 200
#define BaudRate 115200

unsigned long previousTimeStempRED = 0;
unsigned long previousTimeStempBLUE = 0;
unsigned long previousTimeStempGREEN = 0;

void setup() {
  Serial.begin(BaudRate);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousTimeStempRED >= RED_MILLIS) {
    previousTimeStempRED = currentMillis;
    digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
  }

  if (currentMillis - previousTimeStempBLUE >= BLUE_MILLIS) {
    previousTimeStempBLUE = currentMillis;
    digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN));
  }

  if (currentMillis - previousTimeStempGREEN >= GREEN_MILLIS) {
    previousTimeStempGREEN = currentMillis;
    digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
  }

}

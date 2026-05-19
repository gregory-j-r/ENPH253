// This code will poll pin 17, which is connected to an external button and also configured as a pulled up input pin
// when the button is depressed the pin is shorted to ground (0V, LOW) and when the button is released the pin is pulled up HIGH (3.3V)
// The value of this pin is read using digitalRead(), and the read value is written to pin 4
// if pin 4 is setup to drive an LED (see LAB 0) then the LED will be on when the button is released and off when it is depressed.
#include <Arduino.h>

#define LED_PIN 4
#define inputButton 17

void setup() {
  pinMode(LED_PIN, OUTPUT); // Sets LED_PIN (in this case defined as pin 4 above) as an output pin
  pinMode(inputButton, INPUT_PULLUP); // Sets inputButton (in this case pin 7) as an internally pulled up input pin
}

void loop() {
  int buttonState = digitalRead(inputButton);
  digitalWrite(LED_PIN, buttonState); // Writes the LED_PIN (pin 4 in this case) HIGH (3.3 volts to the pin which in this case will be powering an LED)
}
//set pin 17 up as Input pullup and ties it to a 
//hardware interrupt on the falling edge
//counts interrupt triggers and prints the 
//counted value to the monitor

#include <Arduino.h>

volatile int count = 0;

void IRAM_ATTR CountISR(){
  count++;
}

void setup() {
  pinMode(17, INPUT_PULLUP);
  attachInterrupt(17, CountISR, FALLING);
  Serial.begin(115200);
}

void loop() {
  Serial.println(count);
  delay(1000);
}
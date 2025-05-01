// a button is connected to the esp32 (at pin 7  in this case) which when depressed shorts it's associated pin to ground.
// the pin is internally pulled up such that when the button is not depressed a digital read of the pin would yield a 1 (or HIGH)
// a falling edge interrupt triggers when the state of the pin switches from HIGH to LOW, incrementing a counter
// the value of the counter is printed to the serial monitor every second

#include <Arduino.h>

#define UpButton 7

// volatile flag makes it so this variable is stored in RAM, which is best practice for variables which will be manipulated in ISR's (interrupt service routines)
volatile int Counter = 0;

// Flagging this IRAM_ATTR makes it so this function is stored in RAM rather than Flash memory, increasing execution speed ammoung other things
// this is usually best practice when dealing with interrupt service routines which we want executing quickly and without issue
void IRAM_ATTR UpCountISR(){
  Counter++;
}

void setup() {
  Serial.begin(115200);
  pinMode(UpButton, INPUT_PULLUP);
  attachInterrupt(UpButton, UpCountISR, FALLING);
}

// print the counter value to the serial monitor every second
void loop() {
  Serial.println(Counter);
  delay(1000);
}
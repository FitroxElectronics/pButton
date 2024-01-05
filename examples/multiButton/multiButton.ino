/*
*/
#include "pButton.h"

// Define pin
const int button1Pin = 2;
const int button2Pin = 3;

// Create a Button object
pButton button1(button1Pin);
pButton button2(button2Pin);

// Define functions for button events
void Click1() {
  Serial.println("Button 1 CLICKED!");
}

void Click2() {
  Serial.println("Button 2 CLICKED!");
}

void setup() {
  Serial.begin(9600);

  // Callback functions
  button1.click(Click1);
  button2.click(Click2);
}

void loop() {
  // Update button state in loop
  button1.update();
  button2.update();

  // Your main code here
}

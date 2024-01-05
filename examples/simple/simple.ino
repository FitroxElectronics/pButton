/*
*/
#include "pButton.h"

// Define button pin
const int buttonPin = 2;

// Create a Button object
pButton button(buttonPin);

// Define functions for button events
void onClick() {
  Serial.println("Button CLICKED!");
}

void onLongClick() {
  Serial.println("Button LONG clicked!");
}

void onDoubleClick() {
  Serial.println("Button DOUBLE clicked!");
}

void onTripleClick() {
  Serial.println("Button TRIPLE clicked!");
}

void setup() {
  Serial.begin(9600);

  // Callback functions to button events
  button.click(onClick);
  button.longClick(onLongClick);
  button.doubleClick(onDoubleClick);
  button.tripleClick(onTripleClick);
}

void loop() {
  // Update button state in loop
  button.update();

  // Your main code here
}

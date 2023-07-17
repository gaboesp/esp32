// Include the necessary libraries
#include <Arduino.h>

// Define the pin connections
const int timerOutputPin = 2;  // Connect the output of IC 555 to this pin
const int ledPin = 13;         // LED connected to pin 13

// Define a flag to track the state
bool timerState = false;

// Function to handle the timer output interrupt
void timerInterrupt()
{
  // Toggle the timer state flag
  timerState = !timerState;
}

void setup()
{
  // Set the pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(timerOutputPin, INPUT_PULLUP);

  // Attach an interrupt to the timer output pin
  attachInterrupt(digitalPinToInterrupt(timerOutputPin), timerInterrupt, CHANGE);
}

void loop()
{
  // Check the timer state
  if (timerState)
  {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  }
  else
  {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }
}
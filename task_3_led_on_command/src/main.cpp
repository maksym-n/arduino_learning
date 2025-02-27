#include <Arduino.h>

const char TURN_ON = '1';
const char TURN_OFF = '0';

int ledState = LOW;
void handleInput(char input);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);   // set digital pin 13 (LED_BUILTIN) as OUTPUT
    digitalWrite(LED_BUILTIN, LOW); // set initial state for digital pin 13 (LED_BUILTIN) as LOW
    Serial.begin(9600);             // initialize serial communication at 9600 bits per second:
}

void loop() {
    if (Serial.available() > 0) {   // check if serial monitor input available
        handleInput(Serial.read()); // read serial monitor input and handle it
    }
}

void handleInput(char input) {
    int newLedState = ledState;

    if (input == TURN_ON) {
        newLedState = HIGH;
    } else if (input == TURN_OFF) {
        newLedState = LOW;
    }

    if (newLedState != ledState) {
        ledState = newLedState;
        digitalWrite(LED_BUILTIN, ledState); // update LED state
    }
}
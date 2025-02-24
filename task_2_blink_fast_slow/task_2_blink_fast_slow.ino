// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int times = 5;
  int fastBlink = 1000; // 1 second
  int slowBlink = 4000; // 4 seconds

  blink(times, fastBlink);
  blink(times, slowBlink);
}

void blink(int times, int period) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(period/2);                  // wait for half period
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(period/2);                  // wait for half period
  }
}
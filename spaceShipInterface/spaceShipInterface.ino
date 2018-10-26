int switchState = 0;
int launched = 0;
int counter = 0;
int ramp = 0;

void setup() {
  // pinMode takes a pin, and argument, can either be INPUT or OUTPUT
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // digitalRead reads the the state of the pin
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // Has hyper drive been initiated?
    if (launched == 1) {
      // Toggle the LED's
      counter = 0;
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(1500); // Wait for a quarter second
      while (counter < 2) {
        digitalWrite(4, LOW);
        delay(150);
        digitalWrite(4, HIGH);
        delay(150);
        counter ++;
      }
      launched = 0;
    }
    // LOW = no power, HIGH = power
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    // HIGH, button is pressed
    counter = 0;
    ramp = 6;

    do {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    } while (digitalRead(2) == HIGH);

    // Engaging hyper drive flash
    while (counter < 5) {
      digitalWrite(5, HIGH);
      delay(50 * ramp); // this is in miliseconds 1000 = 1 second
      digitalWrite(5, LOW);
      delay(50 * ramp);
      counter ++;
      ramp --;
    }

    counter = 0;
    while (counter < 10) {
      digitalWrite(5, HIGH);
      delay(50 * ramp);
      digitalWrite(5, LOW);
      delay(50 * ramp);
      counter ++;
    }

    launched = 1;
  }
}

#include <Wire.h>

const int buzzer = 2;

void setup() {
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);  // initialize the buzzer pin as an output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (0 < Wire.available()) {
    char c = Wire.read(); /* receive byte as a character */
    Serial.print(c);      /* print the character */
    if (c == '0') {

      for (int i = 50; i < 200; i += 5) {
        digitalWrite(buzzer, HIGH);
        delay(1000);  // wait for a variable amount of time
        digitalWrite(buzzer, LOW);
        delay(i);  // wait for twice the amount of time
      }
    }
  }
  Serial.println();
}

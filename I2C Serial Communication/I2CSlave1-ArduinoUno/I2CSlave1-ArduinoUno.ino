#include <Wire.h>
const int irSensorPin = 2;
int irSensorValue;

void setup() {
  Wire.begin(8);                /* join i2c bus with address 8 (Slave 1) */
  Wire.onReceive(receiveEvent); /* register receive event */
  Wire.onRequest(requestEvent); /* register request event */
  Serial.begin(9600);           /* start serial for debug */
}

void loop() {
  delay(100);
  irSensorValue = digitalRead(irSensorPin);

  // Output the sensor value to the Serial Monitor
  Serial.println(irSensorValue);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (0 < Wire.available()) {
    char c = Wire.read(); /* receive byte as a character */
    Serial.print(c);      /* print the character */
  }
  Serial.println(); /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
  if (irSensorValue == 1) {
    Wire.write("1"); /* send string on request */
  } else {
    Wire.write("0"); /* send string on request */
  }
}

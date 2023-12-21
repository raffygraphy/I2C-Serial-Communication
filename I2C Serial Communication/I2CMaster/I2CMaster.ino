#include <Wire.h>

void setup() {
  Serial.begin(9600); /* begin serial for debug */
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {

  char IRvalue;  // Value detected on IR
  // Communication with Slave 1
  Wire.beginTransmission(8);             /* begin with device address 8 (Slave 1) */
  Wire.write("Slave 1 Detect Intruder"); /* sends Slave 1 Detect Intruder string to Slave 1 */
  Wire.endTransmission();                /* stop transmitting to Slave 1 */

  Wire.requestFrom(8, 1); /* request & read data of size 1 from Slave 1 */
  while (Wire.available()) {
    IRvalue = Wire.read();
    Serial.print(IRvalue);
  }
  Serial.println();

  // Communication with Slave 2
  Wire.beginTransmission(9); /* begin with device address 9 (Slave 2) */
  Wire.write(IRvalue);       /* sends the IR Value from Slave 1 to Slave 2 */
  Wire.endTransmission();    /* stop transmitting to Slave 2 */

  delay(100);
}

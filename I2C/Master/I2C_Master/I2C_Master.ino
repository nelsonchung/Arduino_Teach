//Ref: http://coopermaa2nd.blogspot.tw/2011/12/arduino-i2c.html
// master_sender.ino
// Refer to the "slave_receiver" example for use with this
#include <Wire.h>

const int SLAVE_ADDRESS = 0x8A;
char incomingByte = 0;

void setup() {  
  Wire.begin();         // join I2C bus as a Master
  
  Serial.begin(9600);
  Serial.println("Type something to send:");
}

void loop() {
}

void serialEvent()
{
  // read one byte from serial port
  incomingByte = Serial.read();

  // send the received data to slave
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(incomingByte);
  Wire.endTransmission();
}

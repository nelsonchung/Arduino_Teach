/*
 * Ref: http://arduino169.blogspot.tw/2015/07/arduino-i2c-1-i2c-address-i2c.html
 */
#include <Wire.h>
 
#define SERIAL_BAUD 9600 
 
void setup()
{
  Wire.begin();
  
  Serial.begin(SERIAL_BAUD);
  Serial.println("I2C Scanner started");
  Serial.println();
}
  
  
void loop()
{
  uint8_t error, i2cAddress, devCount, unCount;
  
  Serial.println("Scanning...");
  
  devCount = 0;
  unCount = 0;
  //for(i2cAddress = 1; i2cAddress < 127; i2cAddress++ )
  for(i2cAddress = 0x01; i2cAddress < 0x7F; i2cAddress++ )
  {
    Wire.beginTransmission(i2cAddress);
    error = Wire.endTransmission();
  
    if (error == 0)
    {
      Serial.print("I2C device found at 0x");
      if (i2cAddress<16) Serial.print("0");
      Serial.println(i2cAddress,HEX);
      devCount++;
    }
    else if (error==4)
    {
      Serial.print("Unknow error at 0x");
      if (i2cAddress<16) Serial.print("0");
      Serial.println(i2cAddress,HEX);
      unCount++;
    }    
  }
 
  if (devCount + unCount == 0)
    Serial.println("No I2C devices found\n");
  else {
    Serial.println();
    Serial.print(devCount);
    Serial.print(" device(s) found");
    if (unCount > 0) {
      Serial.print(", and unknown error in ");
      Serial.print(unCount);
      Serial.print(" address");
    }
    Serial.println();
  }
  delay(10000);
}

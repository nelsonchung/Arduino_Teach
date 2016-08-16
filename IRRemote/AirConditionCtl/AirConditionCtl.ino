#include <IRremote.h>

unsigned long AirCondition_Close = 0x1D13614F;
unsigned long AirCondition_Open= 0xDE79E6E;
int signal_led = 13;

IRsend irsend; // IRRemote限定使用數位腳位3

void setup()
{
  Serial.begin(115200);
  
  pinMode(signal_led,OUTPUT);
}
void signal_led_flash(int sleeptime){
  digitalWrite(signal_led,HIGH);
  delay(sleeptime);
  digitalWrite(signal_led,LOW);  
  delay(sleeptime);
}

void loop() {
  unsigned long ir_code = 0x0;

  delay(5000);
  
  //Open aircondition
  ir_code = AirCondition_Open;
  irsend.sendNEC(ir_code, 32); // 輸出紅外線訊號
  signal_led_flash(1000);
  
  delay(5000);
  
  //Close aircondition
  ir_code = AirCondition_Close;
  irsend.sendNEC(ir_code, 32); // 輸出紅外線訊號
  signal_led_flash(500);
  signal_led_flash(500);
  
}


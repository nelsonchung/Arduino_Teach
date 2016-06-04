#include <Timer.h>

Timer t13;

void setup() {
  // put your setup code here, to run once:

    pinMode(13, OUTPUT);
    //重複閃滅
    //t13.oscillate(13, 500, HIGH); //控制13, 初始化是HIGH
    //重複閃滅 repeattime 次數
    int repeattime = 10;
    t13.oscillate(13, 500, HIGH, repeattime); //控制13, 初始化是HIGH
}

void loop() {
  // put your main code here, to run repeatedly:
    t13.update();

}

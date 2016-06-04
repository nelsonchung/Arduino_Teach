#include <Timer.h>

Timer t13;

void setup() {
  // put your setup code here, to run once:

    pinMode(13, OUTPUT);
    t13.oscillate(13, 500, HIGH); //控制13, 初始化是HIGH
}

void loop() {
  // put your main code here, to run repeatedly:
    t13.update();

}

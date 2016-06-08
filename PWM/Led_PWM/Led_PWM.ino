#define LED_PWM 8
#define MAX_BRIGHTNESS 255

int brightness = 0;
//int shift_value = 40;
//int delaytime = 4;
int shift_value =30;
int delaytime = 333;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(LED_PWM, brightness);
    brightness = brightness + shift_value;
    if( brightness >= MAX_BRIGHTNESS){
        brightness = brightness - MAX_BRIGHTNESS;
    }
    delay(delaytime);

}

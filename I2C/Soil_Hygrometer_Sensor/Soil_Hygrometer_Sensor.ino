#define DIGITAL_INPUT 12
#define ANALOG_INPUT A0
#define DIGITAL_LED 13
int val_from_digital=0;
int val_from_analog=0;

#include "Led13Flash.h"

Led13Flash led;

typedef struct analog_delaytime{
  int analog;
  int delaytime;
}analog_delaytime;

/*
analog_delaytime analogdelay[ANALOGDELAY_NUM] = { (100, 100),
(200, 200),
(300, 300),
(400, 400),
(500, 500),
(600, 600),
(700, 700),
(800, 800),
(900, 900),
(1000, 1000)
};
*/
analog_delaytime analogdelay[] = { 
    100, 1,
    200, 2,
    300, 3,
    400, 4,
    500, 5,
    600, 6,
    700, 7,
    800, 8,
    900, 9,
    1000, 10,
    1100, 11,
};

void setup() {
  // put your setup code here, to run once:
    pinMode(DIGITAL_INPUT, INPUT);
    pinMode(DIGITAL_LED, OUTPUT);
    Serial.begin(9600);
    led.start();
}

void loop() {
  // put your main code here, to run repeatedly:
    val_from_digital = digitalRead(DIGITAL_INPUT);
    val_from_analog = analogRead(ANALOG_INPUT);
    int index=0;
    for(index=0; index<sizeof(analogdelay)/sizeof(analog_delaytime); index++){
        if( val_from_analog >= analogdelay[index].analog  && val_from_analog < analogdelay[index+1].analog ){
            led.settwinkletime(analogdelay[index].delaytime);
            break;
        }
    }
    Serial.print("Analog value: ");
    Serial.print(val_from_analog);
    Serial.print("\n");
    led.update();
    delay(1000);

}

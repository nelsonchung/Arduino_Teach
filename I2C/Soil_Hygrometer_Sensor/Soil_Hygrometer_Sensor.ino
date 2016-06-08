#define DIGITAL_INPUT 13
#define ANALOG_INPUT A0
int val_from_digital=0;
int val_from_analog=0;

void setup() {
  // put your setup code here, to run once:
    pinMode(DIGITAL_INPUT, INPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    val_from_digital = digitalRead(DIGITAL_INPUT);
    Serial.print("Digital value: ");
    Serial.print(val_from_digital);
    Serial.print("\n");
    delay(1000);
    val_from_analog = analogRead(ANALOG_INPUT);
    Serial.print("Analog value: ");
    Serial.print(val_from_analog);
    Serial.print("\n");
    delay(1000);

}

const int BLUE_LED = 12;
const int GREEN_LED = 8;
const int RED_LED = 13;
const int FAN = 10;
//1.63, 85
//3.86 , 200
//4 , 210
//4.95, 255
const int FAN_LEVEL = 210;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(FAN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BLUE_LED, HIGH);
  delay(1000);
  digitalWrite(BLUE_LED, LOW);
  delay(1000);
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
  analogWrite(FAN, FAN_LEVEL);
  delay(10000);
}

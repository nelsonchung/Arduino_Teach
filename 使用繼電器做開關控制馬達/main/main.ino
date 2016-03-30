const int BLUE_LED = 12;
const int GREEN_LED = 8;
const int RED_LED = 13;
const int MOTOR_ENABLE_PIN = 7;
const int MOTOR_ENABLE_PIN_2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN_2, OUTPUT);
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
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  digitalWrite(MOTOR_ENABLE_PIN_2, HIGH);
  delay(5000);
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_ENABLE_PIN_2, LOW);
  delay(2000);
}

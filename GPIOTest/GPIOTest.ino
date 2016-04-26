#define pin 8
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);           // set pin to input
  Serial.begin(19200);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  digitalWrite(pin, HIGH);
  Serial.print("1\n");
  delay(2000);
  digitalWrite(pin, LOW);
  Serial.print("0\n");

}

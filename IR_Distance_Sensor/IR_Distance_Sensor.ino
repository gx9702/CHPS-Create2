int sensorPin = 0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int distance = 0;

const int numOfReadings = 10; 
int readings[numOfReadings]; 
int arrayIndex = 0;
int total = 0;
int averageDistance = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  //pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
  // prints title with ending line break 
  Serial.println("Program Starting"); 
  analogReference(EXTERNAL); 
  delay(100); 
}

void loop() {
  // read the value from the sensor:
  //The IR distance sensor 0.4-3v/80cm-10 cm / 124.12 - 930.9 / 11.53/cm
  //analogRead 0-3.3V / 0 - 1023 = 310.3 / v
  delay(1000);
  sensorValue = analogRead(sensorPin);

  //Serial.println("sensorValue");
  //Serial.println(sensorValue);
  //if (sensorValue < 81.92)
  //  distance = 10;
  //else if (sensorValue > 614.4)
  //  distance = 80;
  //else
    distance = 80 - (sensorValue - 124.12)/11.53;
 
  //if (distance == 80)
  //  Serial.println("Too far");
  //else if (distance == 10)
  //  Serial.println("Too close");
  //else

  total= total - readings[arrayIndex]; 
  readings[arrayIndex] = distance; 
  total= total + readings[arrayIndex];
  arrayIndex = arrayIndex + 1;
  if (arrayIndex >= numOfReadings) {
  arrayIndex = 0; }
  averageDistance = total / numOfReadings;
    Serial.println("distance");
    Serial.println(distance); 
}

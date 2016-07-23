// only the brown wire 3 is needed for motion control
#include <SoftwareSerial.h>

//int rxPin=3;
//int txPin=4;
//int ddPin=5; //device detect

int rxPin=10;
int txPin=11;
int ddPin=5; //device detect

//int sensorbytes[2]; //array to store encoder counts
//int angle;
//const float pi=3.1415926;
//#define left_encoder (sensorbytes[0])
//#define right_encoder (sensorbytes[1])
SoftwareSerial Roomba(rxPin,txPin);

void setup() {

  Serial.print("hello world\n");
  //pinMode(3, INPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(ledPin, OUTPUT);

  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Roomba.begin(19200);
  Serial.begin(19200);

  //delay(20000);
  // wake up the robot

  /*
    // wake up the robot
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
  */
  /*
  // should set the baud rate to 19200
  digitalWrite(ddPin, HIGH);
  delay(200);
  digitalWrite(ddPin, LOW);
  delay(200);
  digitalWrite(ddPin, HIGH);
  delay(200);
  digitalWrite(ddPin, LOW);
  delay(200);
  digitalWrite(ddPin, HIGH);
  delay(200);
  digitalWrite(ddPin, LOW);
  delay(200);
  digitalWrite(ddPin, HIGH);
  delay(2000);
   */
  Roomba.write(byte(128));  //Start
  delay(50);
  Roomba.write(byte(131));  //Safe mode
  delay(50);
  //Roomba.write(byte(132));  //Full mode
  //updateSensors();

  // Spin slowly
  if (Roomba.available())
  {
    Roomba.write(byte(145));
    Roomba.write(byte(0x00));
    Roomba.write(byte(0x0B));
    Roomba.write(byte(0xFF));
    Roomba.write(byte(0xF5));  
  }
  else
  {
    Serial.print("not available inside the setup");   
  }
  delay(1000);
}

void loop() {

  Serial.print("hello world\n"); 

  //Roomba.write(byte(128));  //Start
  //Roomba.write(byte(131));  //Safe mode
  //Roomba.write(byte(132));  //Full mode
  //Roomba.write(byte(137));
  //Roomba.write(byte(0xFF));
  //Roomba.write(byte(0x38));
  //Roomba.write(byte(0x01));
  //Roomba.write(byte(0xF4)); 
  //Roomba.write(byte(137));
  if (Roomba.available())
  {
  Roomba.write(byte(145));
  Roomba.write(byte(0x00));
  Roomba.write(byte(0x0B));
  Roomba.write(byte(0xFF));
  Roomba.write(byte(0xF5));
  delay(1000);

  Roomba.write(byte(145));
  Roomba.write(byte(0x00));
  Roomba.write(byte(0xC8));
  Roomba.write(byte(0x00));
  Roomba.write(byte(0xC8));
  delay(1000);
  }
  else
  {
    Serial.print("not available inside the loop");  
  }
    //updateSensors();
    // stop if angle is greater than 360 degrees
    //if(abs(angle)>2*pi){
    //  Roomba.write(173);
    //  delay(100);
    //}
}

//void updateSensors() {
  // call for the left and right encoder counts
  //Roomba.write(byte(148));
  //Roomba.write(byte(2));
  //Roomba.write(byte(43));
  //Roomba.write(byte(44));
  //delay(100);

  // load encoder counts into an array
  //int i = 0;
  //while(Roomba.available()) {
  //  int c = Roomba.read();
  //  sensorbytes[i] = c;
  //  i++;
  //}
  //angle=((right_encoder*72*pi/508.8)-(left_encoder*72*pi/508.8))/235;
//}

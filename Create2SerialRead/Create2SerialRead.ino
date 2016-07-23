#include <SPI.h>
// RX is digital pin 10
// (connect to TX of other device - iRobot DB25 pin 2)
// TX is digital pin 11
// (connect to RX of other device - iRobot DB25 pin 1)
//#define rxPin 10
//#define txPin 11
// set up a new software serial port:
//SoftwareSerial softSerial = SoftwareSerial(rxPin, txPin);
void setup() {
delay(2000); // NEEDED!!!! To let the robot initialize

// define pin modes for software tx, rx pins:
//pinMode(rxPin, INPUT);
//pinMode(txPin, OUTPUT);

// set the data rate for the SoftwareSerial port, this is the
// iRobot's default rate of 57600 baud:
 Serial.begin(19200);
Serial.write(128); // This command starts the OI. You must
// always send the Start command before
// sending any other commands to the OI
Serial.write(131); // safe mode
}



void loop() {
char sensorbytes[10]; // variable to hold the returned 10 bytes
// from iRobot Create

Serial.write((byte)142); // get sensor packets
Serial.write((byte)1); // sensor group packet ID 1, size 10
// bytes, contains packets: 7-16
delay(64);
// wipe old sensor data
char i = 0;
while (i < 10) {
sensorbytes[i++] = 0;
}
i = 0;
int c;
while(Serial.available()) {
Serial.print("\n data available: ");
c = Serial.read();
sensorbytes[i++] = c;
};

//int bumpRight = 0;
//int bumpLeft = 0;

int bumpRight = sensorbytes[0] & 0x01;
// if right bumper is triggered sensorbytes[0] is: 00000001
// bitwise AND with 0x01, i.e. 00000001 equals 1
// see: http://arduino.cc/en/Reference/BitwiseAnd
int bumpLeft = sensorbytes[0] & 0x02;
// if left bumper is triggered sensorbytes[0] is: 00000010
// bitwise AND with 0x02, i.e. 00000010 equals 2

// So if the right bumper is triggered bumpRight is 1
// (if not triggered then 0)
// if the left bumper is triggered bumpLeft is 2
// (if not triggered then 0)

Serial.print("\nright: ");
Serial.print(bumpRight);
Serial.print("\n left:");
Serial.println(bumpLeft);

}

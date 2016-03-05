//Phase 2 Color ball following

//Everytime when the Roomba is completely off, the baud rate 
//will change back to factory default. 

//How To change the baud rate?
//When the clean button's light is off,
//Press the clean button long enough untill you hear a decreasing
//tone.  

//wiring
//red 1
// When you flash the program to the Arduino
// Remember to unplag red and green wires
// When you are charing
// unplug Vin. 

#include <SPI.h>  
#include <Pixy.h>

Pixy pixy;


// x from 0 to 300~ define 150 as the middle of the screen
// height 0 to 200~ want to constraint the height above 100
const int numOfReadings = 5; 

int echoPin1 = 2;
int initPin1 = 3;
int echoPin2 = 4;
int initPin2 = 5;

void spin()
{
  Serial.write(145);
  Serial.write(0x00);
  Serial.write(0x0B);
  Serial.write(0xFF);
  Serial.write(0xF5);
}

void moveForward()
{
  Serial.write(145);
  Serial.write(0x00);
  Serial.write(0xC8);
  Serial.write(0x00);
  Serial.write(0xC8);
}

void moveBackward()
{
  Serial.write(145);
  Serial.write(0xFF);
  Serial.write(0x38);
  Serial.write(0xFF);
  Serial.write(0x38);  
}

void moveLeft()
{
  Serial.write(145);
  Serial.write(0x00);
  Serial.write(0x96);
  Serial.write(0xFF);
  Serial.write(0x6A);  
}

void moveRight()
{
  Serial.write(145);
  Serial.write(0xFF);
  Serial.write(0x6A);
  Serial.write(0x00);
  Serial.write(0x96);  
}

void setup(){
  Serial.begin(19200);

  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pixy.init();
  
  Serial.write(128);  // START
  delay(50);
  Serial.write(131);  // SAFE MODE
  delay(50);
  
  spin();
  delay(2000);

  //Serial.println("phase2 starts\n");
};

int test1 = 0;
int test2 = 0;
int delay_flag = 0;

uint16_t blocks;

void loop() 
{
  //test1 = SonarSensor3(initPin1,echoPin1);
  //test2 = SonarSensor2(initPin2,echoPin2);
  
  blocks = pixy.getBlocks();

  if(blocks>0)
  {
    color_follow(blocks);
    //spin();
    //delay_flag = 1;
  }  
  else
  {
    //Serial.println("\nspin\n");
    //spin();
    //delay(500);
  }
  //{
    //if (delay_flag)
    //{
      //delay(2000);
      //delay_flag = 0;
    //}
    //random_walk();
  //}
}

void color_follow(int blocks)
{
      //for (int k = 0; k < blocks; k++)
      //{

        
        if (pixy.blocks[blocks-1].height < 100)
        {
          moveForward();
          //Serial.println("\ngo forward\n");
          //delay(200);
        }
        //else if(pixy.blocks[blocks-1].height > 100)
        //{
          //Serial.println("\ngo backward\n");
          //moveBackward(); 
          //delay(200); 
        //}
        //else
        //{
          //delay(200);  
        //}
        
        if(pixy.blocks[blocks-1].x < 100)
        {
          //Serial.println("\nturn Right\n");
          moveRight();
          //delay(200);
        }
        else if(pixy.blocks[blocks-1].x > 200)
        {
          //Serial.println("\nturn left\n");
          moveLeft(); 
          //delay(200);        
        }
        //else
        //{
          //delay(200);  
        //}
      //}
}

void random_walk()
{
    Serial.println("\nno blocks\n");
    if(test1 < 25 | test2 <25)
    {  
      blocks = pixy.getBlocks();
      if (blocks == 0)
      {
        Serial.println("change trajectory\n");
        Serial.println("\n");
        Serial.println(test2);
        Serial.println("\n");
        moveBackward();
        delay(1000);
        moveRight();
        delay(random(1200,3000)); 
      }
    }
    moveForward();
}

int SonarSensor1(int initPin, int echoPin)
{
  static int readings[numOfReadings];
  static int arrayIndex = 0;
  static int total = 0;

  if (arrayIndex == 0)
  {
    total = 0;
    for (int i = 0; i < numOfReadings; i++) 
      readings[i] = 0;
  }
  
  unsigned long pulseTime = 0;  
  unsigned long distance = 0;

  digitalWrite(initPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(initPin, LOW); 
  
  pulseTime = pulseIn(echoPin, HIGH); 
  distance = pulseTime/58;

  total= total - readings[arrayIndex];
  readings[arrayIndex] = distance; 
  total= total + readings[arrayIndex];
  arrayIndex = arrayIndex + 1;
  
  if (arrayIndex >= numOfReadings) 
  {  
      arrayIndex = 0; 
      return(total / numOfReadings); // average distance
  }
  else
    return(20); // data not available
}
int SonarSensor3(int initPin, int echoPin)
{
 
  unsigned long pulseTime = 0;  
  unsigned long distance = 0;
  
  digitalWrite(initPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(initPin, LOW); 
  
  pulseTime = pulseIn(echoPin, HIGH); 
  distance = pulseTime/58;
  return(distance); // data not available
}

int SonarSensor2(int initPin, int echoPin)
{
 
  unsigned long pulseTime = 0;  
  unsigned long distance = 0;
  
  digitalWrite(initPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(initPin, LOW); 
  
  pulseTime = pulseIn(echoPin, HIGH); 
  distance = pulseTime/58;
  return(distance); // data not available
}

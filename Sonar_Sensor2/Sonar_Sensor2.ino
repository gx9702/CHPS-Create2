//Phase 1 Random Walk

const int numOfReadings = 5; 

int echoPin1 = 2;
int initPin1 = 3;
int echoPin2 = 4;
int initPin2 = 5;

void setup(){
  Serial.begin(19200);

  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.write(128);  // START
  delay(50);
  Serial.write(131);  // SAFE MODE
  delay(50);
  
  spin();
  delay(2000);
};

int test1 = 0;
int test2 = 0;

void loop() 
{
  test1 = SonarSensor3(initPin1,echoPin1);
  test2 = SonarSensor2(initPin2,echoPin2);

  if(test1 < 25 | test2 <25)
  {  
      //Serial.println(test1);
      //Serial.println("\n");
      //Serial.println(test2);
      //Serial.println("\n");
      moveBackward();
      delay(1000);
      //moveBackward();
      //moveBackward();
      //moveRight();
      //moveRight();
      moveRight();
      //delay(2000);
      delay(random(1200,3000)); 
  }
  
  moveForward();
  //Serial.println("move forward\n");
}

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
  //Serial.println("move backward\n");
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

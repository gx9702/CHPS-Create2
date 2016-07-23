void setup() {
Serial.begin(19200);  
Serial.write(128);  // START
delay(50);
Serial.write(131);  // SAFE MODE
delay(50);
//Serial.write(135);  // clean
Serial.write(145);
Serial.write(0x00);
Serial.write(0x0B);
Serial.write(0xFF);
Serial.write(0xF5);
delay(1000);

delay(1000);

//delay(100000);

//Serial.write(173);
}

void loop() {
//if(Serial.available())
//{
  //Serial.print("Hello world!\n");
//}
Serial.write(145);
Serial.write(0x00);
Serial.write(0x0B);
Serial.write(0xFF);
Serial.write(0xF5);

Serial.write(145);
Serial.write(0x00);
Serial.write(0xC8);
Serial.write(0x00);
Serial.write(0xC8);
}

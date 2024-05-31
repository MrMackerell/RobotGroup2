int* readInfrared() {
  static int IRvalue[4]; //Static array to hold the IR sensor values


  //Read analog values from infrared sensors
  IRvalue[0] = digitalRead(IR_1);
  IRvalue[1] = digitalRead(IR_2);
  IRvalue[2] = digitalRead(IR_3);
  IRvalue[3] = digitalRead(IR_4);

  // //Print the read values to the serial monitor 
  // Serial.print("IR_1: ");
  // Serial.println(IRvalue[0]);
  // Serial.print("IR_2: ");
  // Serial.println(IRvalue[1]);
  // Serial.print("IR_3: ");
  // Serial.println(IRvalue[2]);
  // Serial.print("IR_4: ");
  // Serial.println(IRvalue[3]);

  return IRvalue; //Return the array of IR sensor values
}
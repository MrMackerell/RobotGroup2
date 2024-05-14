int readInfrared() {
  static int IRvalues[4]; //Static array to hold the IR sensor values


  //Read analog values from infrared sensors
  int IRvalue[0] = digitalRead(IR_1);
  int IRvalue[1] = digitalRead(IR_2);
  int IRvalue[2] = digitalRead(IR_3);
  int IRvalue[3] = digitalRead(IR_4);

  //Print the read values to the serial monitor 
  Serial.print("IR_1: ");
  Serial.println(IRvalue[0]);
  Serial.print("IR_2: ");
  Serial.println(IRvalue[1]);
  Serial.print("IR_3: ");
  Serial.println(IRvalue[2]);
  Serial.print("IR_4: ");
  Serial.println(IRvalue[3]);

  return IRvlues; //Return the array of IR sensor values
}
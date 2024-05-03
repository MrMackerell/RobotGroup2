//Object created for the colour sensor taking the values from the physical colour sensor
tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

void readColorSensor() {
  //Five samples will be taken
  const int samples = 5;

  long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;//Set the values of the readings to the default

  //Take samples to find an average reading (most accurate form of colour sensor reading)
  for(int i = 0; i < samples; i++) {
    sumRed += tcs.colorRead('r');
    sumGreen += tcs.colorRead('g');
    sumBlue += tcs.colorRead('b');
    sumWhite += tcs.colorRead('c');
  }
  //Find the values read by the colour sensor
  int avgRed = sumRed / samples;
  int avgGreen = sumGreen / samples;
  int avgBlue = sumBlue / samples;
  int avgWhite = sumWhite / samples;


  //Print the values that are read by the colour sensor
  Serial.println("Average Color Sensor Readings: ");
  Serial.print("R = ");
  Serial.println(avgRed);
  Serial.print("G = ");
  Serial.println(avgGreen);
  Serial.print("B = ");
  Serial.println(avgBlue);
  Serial.print("W (clear) = ");
  Serial.println(avgWhite);
}
// Object created for the color sensor taking the values from the physical color sensor
tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

const int samples = 10;  // Number of samples to take for averaging

// Function to capture and average color readings
void captureColorReadings(int& avgRed, int& avgGreen, int& avgBlue, int& avgWhite) {
  long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;
  
  for (int i = 0; i < samples; i++) {
    sumRed += tcs.colorRead('r');
    sumGreen += tcs.colorRead('g');
    sumBlue += tcs.colorRead('b');
    sumWhite += tcs.colorRead('c');
    delay(100); // Short delay between samples
  }

  avgRed = sumRed / samples;
  avgGreen = sumGreen / samples;
  avgBlue = sumBlue / samples;
  avgWhite = sumWhite / samples;
}

void readColorSensor() {
  int avgRed, avgGreen, avgBlue, avgWhite;
  captureColorReadings(avgRed, avgGreen, avgBlue, avgWhite);

  Serial.println("Average Color Sensor Readings: ");
  Serial.print("R = "); Serial.println(avgRed);
  Serial.print("G = "); Serial.println(avgGreen);
  Serial.print("B = "); Serial.println(avgBlue);
  Serial.print("W (clear) = "); Serial.println(avgWhite);

  String detectedColor = "Unknown";

  // Set thresholds based on your calibration values
  if (avgRed > 20 && avgGreen < 10 && avgBlue < 15) {
    detectedColor = "Red";
  } else if (avgRed < 10 && avgGreen > 10 && avgBlue > 10) {
    detectedColor = "Green";
  } else if (avgRed < 10 && avgGreen < 15 && avgBlue > 15) {
    detectedColor = "Blue";
  } else if (avgRed > 35 && avgGreen > 25 && avgBlue < 30) {
    detectedColor = "Yellow";
  }

  Serial.print("Detected Color: "); Serial.println(detectedColor);

  // Set the RGB LED colors based on detected color
  if (detectedColor == "Red") {
    WiFiDrv::analogWrite(25, 0);   // GREEN off
    WiFiDrv::analogWrite(26, 255); // RED on
    WiFiDrv::analogWrite(27, 0);   // BLUE off
  } else if (detectedColor == "Green") {
    WiFiDrv::analogWrite(25, 255); // GREEN on
    WiFiDrv::analogWrite(26, 0);   // RED off
    WiFiDrv::analogWrite(27, 0);   // BLUE off
  } else if (detectedColor == "Blue") {
    WiFiDrv::analogWrite(25, 0);   // GREEN off
    WiFiDrv::analogWrite(26, 0);   // RED off
    WiFiDrv::analogWrite(27, 255); // BLUE on
  } else if (detectedColor == "Yellow") {
    WiFiDrv::analogWrite(25, 255); // GREEN on
    WiFiDrv::analogWrite(26, 255); // RED on
    WiFiDrv::analogWrite(27, 0);   // BLUE off
  } else {
    // Turn off all LEDs if color is unknown
    WiFiDrv::analogWrite(25, 0);   // GREEN off
    WiFiDrv::analogWrite(26, 0);   // RED off
    WiFiDrv::analogWrite(27, 0);   // BLUE off
  }
}
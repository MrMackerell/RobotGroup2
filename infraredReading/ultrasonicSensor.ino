int readUltrasonicSensor() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  
  
  int distance = (duration * 0.034) / 2; //Calculates the distance in cm  

  currentDistance = distance;

  Serial.print("Current Distance: ");
  Serial.println(currentDistance);                                                                                                        
}
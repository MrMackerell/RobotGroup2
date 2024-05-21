void ultrasonicSensor() {
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  
  
  distance = (duration * 0.034) / 2; //Calculates the distance in cm  

  /*Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm.");

  Serial.println();*/

  currentDistance = distance;
}
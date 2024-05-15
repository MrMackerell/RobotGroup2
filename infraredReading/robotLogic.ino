void robotLogic() {
  motorLogic();
}

void motorLogic() {
  int* IRvalues;
  IRvalues = readInfrared();

  if(IRvalues[1] == 1 && IRvalues[2] == 1) {
    motorControl(200, 200); //Move the robot straight forward
    currentState = "Forward";
  } else if(IRvalues[1] == 0 && IRvalues[2] == 1) {
    motorControl(150, 200); //Turns slight left
    currentState = "Left";
  } else if(IRvalues[1] == 1 && IRvalues[2] == 0) {
    motorControl(200, 150); //Turns slight right
    currentState = "Right";
  } else if (IRvalues[0] == 1 && IRvalues[1] == 1 && IRvalues[2] == 1 && IRvalues[3] == 1) {
  // If none of the IR sensors detect a line,continue the last state detected by the center IR sensors
  if (currentState == "Forward") {
    motorControl(200, 200); //Move the robot straight forward
  } else if (currentState == "Left") {
    motorControl(150, 200); //Turn slight left
  } else if (currentState == "Right") {
    motorControl(200, 150); //Turn slight right
  }
  } else if(IRvalues[0] == 0) {
    motorControl(-255, 255); //Turn left
  } else if(IRvalues[3] == 0) {
    motorControl(255, -255); //Turn right
  }

}

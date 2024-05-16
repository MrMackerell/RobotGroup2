bool initialForwardMotion = false;                   //Flag to initiate forward motion at the start of a turn.
const unsigned long initialMotionDuration = 350;     //Duration for initial forward motion in milliseconds.

unsigned long turnStartTime = 0;                     //Time when the turn starts.
const unsigned long initialTurnDuration = 600;       //Duration for initial turn when wall detected before IR sensor activates 
int turnSpeed = 150;

const unsigned long sensorCheckThreshold = 50;       //Threshold in milliseconds to check both sensors.
 
unsigned long firstDetectionTime1 = 0;               //Time of first detection for sensor 1.
unsigned long firstDetectionTime4 = 0;               //Time of first detection for sensor 4.

void robotLogic() {
  motorLogic();
}

void turnLogic() {

}

void motorLogic() {
  int* IRvalues;
  IRvalues = readInfrared();

  if (IRvalues[1] == 0 && IRvalues[2] == 0) {
    motorControl(200, 200);  //Move the robot straight forward
    currentState = "Forward";
  } else if (IRvalues[1] == 0 && IRvalues[2] == 1) {
    motorControl(150, 200);  //Turns slight left
    currentState = "Left";
  } else if (IRvalues[1] == 1 && IRvalues[2] == 0) {
    motorControl(200, 150);  //Turns slight right
    currentState = "Right";
  } else if (IRvalues[0] == 1 && IRvalues[1] == 1 && IRvalues[2] == 1 && IRvalues[3] == 1) {
    // If none of the IR sensors detect a line,continue the last state detected by the center IR sensors
    if (currentState == "Forward") {
      motorControl(200, 200);  //Move the robot straight forward
    } else if (currentState == "Left") {
      motorControl(150, 200);  //Turn slight left
    } else if (currentState == "Right") {
      motorControl(200, 150);         //Turn slight right
    }
  }
}

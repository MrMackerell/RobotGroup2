//PHASE 1:
//Create pin definitions for the Infrared Sensors
#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12
unsigned long irSensorMillis = 0; //Timer to track the last report of the IR sensors

//PHASE 2:
//Include the colour sensor library
#include <tcs3200.h>

//Create pin definitions for the colour sensor using analog pins
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

unsigned long colorSensorMillis = 0; //Timer to track the last report of the color sensors

//PHASE 3:
//Define the motors
#define MOTOR_PIN1 3
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 9

void setup() {
  //PHASE 1:
  //Set the Infrared Sensors as input 
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  Serial.begin(115200);

  //PHASE 3:
  //Set up pinmodes for the motors
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);

}

void loop() {
  //PHASE 1:
  //Get the current run time in milliseconds
  unsigned long currentMillis = millis();

  //Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  //PHASE 2:
  //Read the color sensor
  if(currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }

  //PHASE 4:
  /*Test motor control by creating a routine that moves
  the robot forward for 1 second and then turns 90 degrees right.*/
  motorControl(255, 255); //Go straight forward
  delay(1000);
  motorControl(0, 0); //Stop momentarily
  delay(100);
  motorControl(255, -255) //Turn right
  delay(500);
  motorControl(0, 0); //Stop momentarily
  delay(100);
  
  //You can try and make different shapes using the basic code from Phase 4 :)
  //motorControl(-255, 255); This is to turn left!
  //delay(100);
}

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


void setup() {
  //PHASE 1:
  //Set the Infrared Sensors as input 
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  Serial.begin(11520);

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
}

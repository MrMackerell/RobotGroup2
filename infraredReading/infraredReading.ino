//PHASE 5:
String currentState = "Null";
String oldCurrentState = "Null";

//PHASE 6:
//Turning Logic
String turnDirection = "";
String lastTurnDirection = "";
bool isTurning = false;
bool wallDetected = false;
int currentDistance = 1000;

//PHASE 1:
//Create pin definitions for the Infrared Sensors
#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12
unsigned long irSensorMillis = 0;        //Timer to track the last report of the IR sensors
unsigned long currentMillis;  //Define the currentMillis variable

//PHASE 2:
//Include the colour sensor library
#include <tcs3200.h>

//Create pin definitions for the colour sensor using analog pins
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

unsigned long colorSensorMillis = 0;  //Timer to track the last report of the color sensors
unsigned long ultrasonicMillis = 0;   //Timer to track the last report of the color sensors


//PHASE 3:
//Define the motors
#define MOTOR_PIN1 3
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 9

//PHASE 4:
//Define pins
#define TRIG_PIN 10
#define ECHO_PIN 11

#define LED_R 25
#define LED_G 26
#define LED_B 27

 #include<WiFiNINA.h>

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

  //PHASE 4:
  //Set up pinmodes for the Ultrasonic Sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  //Setup onboard RGB LED pins
  WiFiDrv::pinMode(LED_R, OUTPUT); //define RED LED
  WiFiDrv::pinMode(LED_G, OUTPUT); //define RED LED
  WiFiDrv::pinMode(LED_B, OUTPUT); //define RED LED
}

void loop() {

    currentMillis = millis(); //Reset currentMillis every loop using the millis() function


  //PHASE 1:
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


  if (currentMillis - ultrasonicMillis >= 20) {
    ultrasonicMillis = currentMillis;
    readUltrasonicSensor();
  }

  robotLogic();
}

// //TO READ THE COLOUR SENSOR VALUES FOR NOW!!!!!!
// // Object created for the color sensor taking the values from the physical color sensor
// tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

// const int samples = 10;  // Number of samples to take for averaging

// // Function to capture and average color readings
// void captureColorReadings(int& avgRed, int& avgGreen, int& avgBlue, int& avgWhite) {
//   long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;
  
//   for (int i = 0; i < samples; i++) {
//     sumRed += tcs.colorRead('r');
//     sumGreen += tcs.colorRead('g');
//     sumBlue += tcs.colorRead('b');
//     sumWhite += tcs.colorRead('c');
//     delay(100); // Short delay between samples
//   }

//   avgRed = sumRed / samples;
//   avgGreen = sumGreen / samples;
//   avgBlue = sumBlue / samples;
//   avgWhite = sumWhite / samples;
// }

// void setup() {
//   Serial.begin(9600);
//   // Initialize the color sensor if necessary
// }

// void loop() {
//   int avgRed, avgGreen, avgBlue, avgWhite;

//   // Capture and print readings for a red sample
//   Serial.println("Place the RED sample and press any key...");
//   while (Serial.available() == 0) {} // Wait for user input
//   Serial.read(); // Clear the input buffer
//   captureColorReadings(avgRed, avgGreen, avgBlue, avgWhite);
//   Serial.println("RED Sample Readings:");
//   Serial.print("R = "); Serial.println(avgRed);
//   Serial.print("G = "); Serial.println(avgGreen);
//   Serial.print("B = "); Serial.println(avgBlue);
//   Serial.print("W = "); Serial.println(avgWhite);

//   // Capture and print readings for a green sample
//   Serial.println("Place the GREEN sample and press any key...");
//   while (Serial.available() == 0) {}
//   Serial.read();
//   captureColorReadings(avgRed, avgGreen, avgBlue, avgWhite);
//   Serial.println("GREEN Sample Readings:");
//   Serial.print("R = "); Serial.println(avgRed);
//   Serial.print("G = "); Serial.println(avgGreen);
//   Serial.print("B = "); Serial.println(avgBlue);
//   Serial.print("W = "); Serial.println(avgWhite);

//   // Capture and print readings for a blue sample
//   Serial.println("Place the BLUE sample and press any key...");
//   while (Serial.available() == 0) {}
//   Serial.read();
//   captureColorReadings(avgRed, avgGreen, avgBlue, avgWhite);
//   Serial.println("BLUE Sample Readings:");
//   Serial.print("R = "); Serial.println(avgRed);
//   Serial.print("G = "); Serial.println(avgGreen);
//   Serial.print("B = "); Serial.println(avgBlue);
//   Serial.print("W = "); Serial.println(avgWhite);

//   // Capture and print readings for a yellow sample
//   Serial.println("Place the YELLOW sample and press any key...");
//   while (Serial.available() == 0) {}
//   Serial.read();
//   captureColorReadings(avgRed, avgGreen, avgBlue, avgWhite);
//   Serial.println("YELLOW Sample Readings:");
//   Serial.print("R = "); Serial.println(avgRed);
//   Serial.print("G = "); Serial.println(avgGreen);
//   Serial.print("B = "); Serial.println(avgBlue);
//   Serial.print("W = "); Serial.println(avgWhite);

//   // Add more colors if needed

//   // Delay to allow time for moving samples
//   delay(5000); // 5 seconds delay
// }


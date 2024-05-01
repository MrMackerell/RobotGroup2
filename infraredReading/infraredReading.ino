#define IR_1 4
#define IR_2 7
#define IR_3 10
#define IR_4 11

unsigned long irSensorMillis = 0; //Timer to track the last report of the IR sensors

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Get the current run time in milliseconds
  unsigned long currentMillis = millis();

  //Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }
}

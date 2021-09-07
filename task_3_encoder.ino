#include <myDuino.h>

myDuino robot(1);
bool switch1 = 0;
bool switch2 = 0;
int encoder = 0;
int motorSpeed = 0;
int encRotataions = 0;
double conversion = 25.5/16;
int motorDir = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.doEncoder();
  switch1 = robot.readButton(1);
  switch2 = robot.readButton(3);
  encoder = robot.encoderCount();
  delay(50);
  motorSpeed = abs(encoder) * conversion;
  if (motorSpeed > 255) {
    motorSpeed = 255;
  }
  if (motorSpeed < 0) {
    motorSpeed = 0;
  }
  if (switch1 == 1 && switch2 == 0) {
    motorDir = 1;
    robot.LED(1,1);
  }
  else if (switch1 == 0 && switch2 == 1) {
    motorDir = 2;
    robot.LED(2,1);
  }
  else if ((switch1 == 1 && switch2 == 1) || (switch1 == 0 && switch2 == 0)) {
    motorSpeed = 0;
    robot.LED(1,0);
    robot.LED(2,0);
  }
  robot.moveMotor(1, motorDir, motorSpeed);
  
  Serial.println("Encoder Value: " + String(encoder));
  Serial.println("Motor Speed: " + String(motorSpeed));
  Serial.println("direction: " + String(motorDir));
  
  
}

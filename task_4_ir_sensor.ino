#include <myDuino.h>
myDuino robot(1);
double irsens = 0;
bool valve = 0;
double ttime = 0;
bool check = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  irsens = robot.readIR();
  Serial.println(String(irsens));
  if (irsens <= 372 && irsens >= 249) {
    //robot.digital(1,1);
    //delay(10000);
    while (ttime < 1000 && check == 0) {
      ttime = ttime + 1;
      robot.digital(1,1);
      check = robot.readButton(1);
      Serial.println("Time:" + String(ttime));
    }
    robot.digital(1,0);
  } 
  else {
    robot.digital(1,0);
  }
  ttime = 0;
  check = 0;
  
//  robot.digital(1,0);
//  delay(1000);
//  robot.digital(1,1);
//  delay(1000);
}

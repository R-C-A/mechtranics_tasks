#include <myDuino.h>
myDuino robot(1);

bool btn = 0;
bool prevBtn = 0;
bool light = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn = robot.readButton(1);
  delay(100);
  if (btn == 1 && prevBtn == 0) {
    if (light == 1) {
      light = 0;
    } else {
      light = 1;
    }
  }
  prevBtn = btn;
  robot.LED(1, light);
}

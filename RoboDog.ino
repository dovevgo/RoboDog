/* RoboDog
 by DOVEVGO 
 
 
*/

#include <Servo.h>

Servo frontLeft; // 2
Servo frontRight;// 3
Servo backLeft;  // 4 
Servo backRight; // 5
Servo head; // 6

int pos = 0;    // variable to store the servo position
int speedincrement =3;

int backStartAngle = 145;
int backBlockAngle = 70;
int backCorrectionAngle = -30;

int frontStartAngle = 145;
int frontBlockAngle = 90;
int frontCorrectionAngle = -50;

void walkForward(){

  
  // Front Legs
  for(int i = frontStartAngle; i >= frontBlockAngle; i = i - speedincrement){
    delay(10);
    backLeft.write(i);
    delay(10);
    backRight.write(frontStartAngle-(i-frontBlockAngle - frontCorrectionAngle));
    delay(10);
  }

    // Back Leags
  for(int i = backStartAngle; i >= backBlockAngle ; i = i - speedincrement){
    delay(10);
    frontRight.write(i);
    delay(10);
    frontLeft.write(backStartAngle-(i-backBlockAngle -backCorrectionAngle));
    delay(10);
  }
}

void freeze(){
  frontLeft.write(90);
  frontRight.write(90);
  backLeft.write(90);
  backRight.write(90);
}
  
void setup() {
  frontLeft.attach(2);
  frontRight.attach(3);
  backLeft.attach(4);
  backRight.attach(5);
  head.attach(6);
}

void loop() {
  for (pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
    
  
  walkForward();
  }
  freeze();
  delay(5000);
}

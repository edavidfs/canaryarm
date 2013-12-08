#include <Servo.h>

Servo gripperServo;
boolean isOpen;

void gripperSetup(){
  gripperServo.attach(gripperServoPin);
}

void openGripper(){
  gripperServo.write(openGripperValue);
  isOpen = true;
  
}

void closeGripper(){
  
  gripperServo.write(closeGripperValue);
  isOpen = false;
}

boolean isGripperOpen(){
 return isOpen;
}

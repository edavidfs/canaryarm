#include "Arduino.h"
#include"gripper.h"
    
void GRIPPER::openGripper(){
  _gripperServo.write(180);
  _isOpen = true;
}
  
void GRIPPER::closeGripper(){
  _gripperServo.write(10);
  _isOpen = false;
}

boolean GRIPPER::isOpen(){
  return _isOpen;
}

GRIPPER::GRIPPER(int pinSignalCtrl) : _gripperServo(){
  _pinSignalCtrl = pinSignalCtrl;
  _gripperServo.attach(_pinSignalCtrl);
  this->openGripper();
}

GRIPPER::~GRIPPER(){
  
}

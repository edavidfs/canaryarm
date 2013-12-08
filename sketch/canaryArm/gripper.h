#ifndef GRIPPER_H
#define GRIPPER_H

#include "Arduino.h"
#include <Servo.h>

class GRIPPER{
  public:
 
    GRIPPER(int pinSignalCtrl);
    ~GRIPPER();
    void openGripper();
    void closeGripper();
    boolean isOpen();

  private:
 
    int _pinSignalCtrl;
    Servo _gripperServo;
    boolean _isOpen;
};

#endif



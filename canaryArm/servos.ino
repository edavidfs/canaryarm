
Servo baseServo;
Servo arm1Servo;
Servo arm2Servo;
Servo arm3Servo;
Servo selectedServo;
Servo gripperServo;

boolean isOpen;

void servoSetup(){
  baseServo.attach(baseServoPin);
  arm1Servo.attach(arm1ServoPin,minArm1ServoValue,maxArm1ServoValue);
  arm2Servo.attach(arm2ServoPin,minArm2ServoValue,maxArm2ServoValue);
  arm3Servo.attach(arm3ServoPin,minArm3ServoValue,maxArm3ServoValue);
  gripperServo.attach(gripperServoPin);
  
  baseServo.write (0);
  arm1Servo.write (0);
  arm2Servo.write (0);
  arm3Servo.write (0);
  gripperServo.write(openGripperValue);
}

void moveMotorToAngle(int motor,char movementType,  int angle){
  
  int actualAngle = 0;

  switch (motor){
    case 0:
      selectedServo = baseServo;
      break;
    case 1:
      selectedServo = arm1Servo;
      break;
    case 2:
      selectedServo = arm2Servo;
      break;
    case 3:
      selectedServo = arm3Servo;
      break;
    case 4:
      selectedServo = gripperServo;
      break;
    }
    
   switch (movementType){
     case '+':
       actualAngle = selectedServo.read();
       angle = angle + actualAngle;
       break;
     case '-':
       actualAngle = selectedServo.read();
       angle = angle - actualAngle;
     case 'G':
       break;     
   }
    selectedServo.write(angle);
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


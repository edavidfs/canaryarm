
Servo baseServo;
Servo arm1Servo;
Servo arm2Servo;
Servo arm3Servo;
Servo selectedServo;

void servoSetup(){
  baseServo.attach(baseServoPin);
  arm1Servo.attach(arm1ServoPin);
  arm2Servo.attach(arm2ServoPin);
  arm3Servo.attach(arm3ServoPin);
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

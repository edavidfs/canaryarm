#include <Servo.h>

void setup()
{
  servoSetup();
  Serial.begin(9600); 
  Serial.println("Canary Arm Ready"); 
  
}

void loop(){
  
  receiveCommand();
  
  Serial.print ("Motor Received:");
  Serial.println (motorCommand());
  
  Serial.print ("Angle Received:");
  Serial.println (motorAngle());
  
  moveMotorToAngle(motorCommand(),movementType(), motorAngle());
   
}

void printGripperStatus(){
  Serial.print("The gripper is:");
  if (isGripperOpen() == true){
      Serial.println("open");
  }else{
      Serial.println("close");
  }
}






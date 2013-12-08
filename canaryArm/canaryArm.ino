#include <Servo.h>


int motor;
int angle;
char movement;
void setup()
{
  gripperSetup(); 
  servoSetup();
  Serial.begin(9600); 
  Serial.println("Canary Arm Ready"); 
  
}

void loop(){
  
  receiveCommand();
  
  motor = motorCommand();
  Serial.print ("Motor Received:");
  Serial.println (motor,DEC);
  Serial.print ("\n");
  
  angle = motorAngle();
  Serial.print ("Angle Received:");
  Serial.println (angle);
  Serial.print ("\n");
  
  movement = movementType();
  
  moveMotorToAngle(motor,movement, angle);
  
  openGripper();
  printGripperStatus();
  delay (2000);

  closeGripper();
  printGripperStatus();
  delay (2000);
   
}

void printGripperStatus(){
  Serial.print("The gripper is:");
  if (isGripperOpen() == true){
      Serial.println("open");
  }else{
      Serial.println("close");
  }
}






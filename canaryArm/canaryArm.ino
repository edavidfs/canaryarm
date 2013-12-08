#include <Servo.h>

void setup()
{
  gripperSetup(); 
  Serial.begin(9600); 
  Serial.println("Canary Arm Ready"); 
  
}

void loop(){
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




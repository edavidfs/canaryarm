#include <Servo.h>

void setup()
{
  Serial.begin(9600); 
  Serial.println("Servo Configuration"); 
  servoSetup();
  Serial.println("Canary Arm Ready"); 
}

void loop(){
  
  if (receiveCommand() == true){
    processCommand();
  }else{
    Serial.print("Comando Recibido erroneo");
  }
   
}

void printGripperStatus(){
  Serial.print("The gripper is:");
  if (isGripperOpen() == true){
      Serial.println("open");
  }else{
      Serial.println("close");
  }
}






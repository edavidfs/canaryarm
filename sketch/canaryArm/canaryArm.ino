#include "gripper.h"
#include <Servo.h>

//Servo baseServo;  
//Servo arm1Servo;
//Servo arm2Servo;
//Servo arm3Servo;
//Servo arm4Servo;
GRIPPER gripper(11);

int pos = 0; 
int minPosition = 0;
int maxPosition = 100;
int delayTime = 30;
char selectedServo;

void setup()
{
//  baseServo.attach(5,700,1000);
//  arm1Servo.attach(6,700,1000);
//  arm2Servo.attach(9,700,1000);
//  arm3Servo.attach(10,700,1000); 
 // arm4Servo.attach(11,700,1000); 
  
//  baseServo.write(0);
//  arm1Servo.write(0);
//  arm2Servo.write(0);
//  arm3Servo.write(0);
//  arm4Servo.write(0);
//  gripper.closeGripper();
  Serial.begin(9600); 
  Serial.println("Canary Arm Ready"); 
  
}

void loop(){
  gripper.openGripper();
  printGripperStatus();
  delay (2000);

  gripper.closeGripper();
  printGripperStatus();
  delay (2000);
  
 /* Serial.println("Select motor:");
  Serial.println("0: Base");
  Serial.println("1: Arm 1 Servo");
  Serial.println("2: Arm 2 Servo");
  Serial.println("3: Arm 3 Servo");
  Serial.println("4: Open/Close Gripper");
  
  int userNotSelectMotor = 0;
  while (userNotSelectMotor == 0){
    //Serial.println ("waiting for the user");
    if (Serial.available() > 0) {
      selectedServo = Serial.read();
      if (selectedServo == '0' || selectedServo == '1' || selectedServo == '2' ||selectedServo == '3'){
        Serial.print("Write angle (0-180) for Servo:");
        Serial.println(selectedServo);
        int userNotSelectAngle = 0;
        while (userNotSelectAngle == 0){
          if (Serial.available() > 0) {
            char inputChar [1];
            int i=0;
            while (Serial.available() > 0){
              inputChar[i] = Serial.read();
              delay(100);
              i++;
            }     
            pos = atoi( inputChar);
            switch (selectedServo){
              case '0':
                baseServo.write(pos);
                break;
              case '1':
                arm1Servo.write(pos);
                break;
              case '2':
                arm2Servo.write(pos);
                break;
              case '3':
                arm3Servo.write(pos);
                break;
            }

            Serial.write("New Servo Position:");
            Serial.println(pos);
            userNotSelectAngle = 1;
          }
        }
      }else if (selectedServo == '4'){
        if (gripper.isOpen() == true){
          Serial.println("Closing the gripper ");
          gripper.closeGripper();
        }else{
          Serial.println("Opening the gripper ");          
          gripper.openGripper();
        }
      }
      
      userNotSelectMotor = 1;
      delay(200);
    }
  }  */  
}

void printGripperStatus(){
  Serial.print("The gripper is:");
  if (gripper.isOpen() == true){
      Serial.println("open");
  }else{
      Serial.println("close");
  }

}


#include "configuration.h"

char command[9];

int motor;
int angle;
char movement;

void processCommand(){
  Serial.print("Procesando comando M");
  Serial.println(command[1],HEX);
  switch (command[1]){
    case  0x4D: //"M" Movement command
      Serial.print("Procesando comando M");
      Serial.println(command);
      processMCommand();
      break;
    case 0x41:  // "A" Acceleration Value command
      Serial.print("Procesando comando A");
      Serial.println(command);
      processACommand();
      break;
    }
}

boolean receiveCommand(){

  int i=0;
  boolean commandValid = true;
  Serial.print("\n");
  Serial.println("command?");

  while (Serial.available() < 1);
  command[0] = Serial.read();
  
  if (command[0] == 0x23){
    while (Serial.available() < 1);
    command[1] = Serial.read();   
  
    switch (command[1]){
      case  0x4D: //"M" Movement command
        commandValid = receiveMCommand();
        break;
      case 0x41:  // "A" Acceleration Value command
        commandValid = receiveAccCommand();
        break;
    }
  }
  return commandValid;
}

boolean receiveMCommand(){
  int i = 0;
  boolean commandValid;
  
  while (Serial.available() < 7);
  i=2;
  while (i< 9) {
    command[i] = Serial.read();
    if (i==3 || i == 5){
      if (command[i] != '_' ){
        i=10;
        commandValid = false;
        Serial.println("Se ha recibido un caracter erroneo");
      }else{
        commandValid = true;
      }
    }
    i++;
  }
  return commandValid;
}

boolean receiveAccCommand(){
  int i;
  boolean commandValid;
  
  while (Serial.available() < 5);
  i=2;
  while (i< 7) {
    command[i] = Serial.read();
    if (i==2){
      if (command[i] != '_' ){
        i=10;
        commandValid = false;
        Serial.println("Se ha recibido un caracter erroneo");
      }else{
        commandValid = true;
      }
    }
    i++;
  } 
  return commandValid;
}


// SERVO MOVEMENT COMMANDS

void processMCommand(){
  
    Serial.print ("Motor Received:");
    Serial.println (motorCommand());
  
    Serial.print ("Angle Received:");
    Serial.println (motorAngle());
  
    moveMotorToAngle(servoByNumber(motorCommand()),movementType(), motorAngle());
}

int motorCommand(){ 
  return atoi(&command[2]);
}


char movementType(){
  return command[4];
}


int motorAngle(){
  char angle2[3];
  int i=0; 
  for (i=0 ; i<3 ;i++){
    angle2[i] = command[i+6];
  }
  return atoi(angle2);
}

// ACCELERATION MOVEMENT COMMANDS

double accelerationReceived(){
  char   acc[4];
  int    i=0; 
  double accReceive;
  
  for (i=0 ; i<4 ;i++){
    acc[i] = command[i+3];
  }
  accReceive =  double(atoi(acc));
  if (accReceive>accMax){
    accReceive = accMax;
  }
  return accReceive;
} 

void processACommand(){
  acceleration = accelerationReceived();
  Serial.print ("Acceleration Received:");
  Serial.println (acceleration);
  
  
}




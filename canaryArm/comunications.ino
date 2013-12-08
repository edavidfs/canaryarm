
char command[7];

void receiveCommand(){
  int i=0;
  Serial.print("\n");
  Serial.println("command?");

  while (Serial.available() == 0) {}

  while (Serial.available() > 0) {
    command[i] = Serial.read();
    i++;
    delay(15);
  }
}


int motorCommand(){ 
  return atoi(&command[0]);
}

char movementType(){
  return command[2];
}

int motorAngle(){
  char angle2[3];
  int i=0; 
  for (i=0 ; i<3 ;i++){
    angle2[i] = command[i+4];
  }
  return atoi(angle2);
}

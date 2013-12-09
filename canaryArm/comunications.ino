
char command[7];

int motor;
int angle;
char movement;


void receiveCommand(){
  command[7] = '0_0_000';
  int i=0;
  Serial.print("\n");
  Serial.println("command?");

  while (Serial.available() == 0);

  while (Serial.available() > 0) {
    command[i] = Serial.read();
    i++;
    delay(30);
  }
  Serial.flush();
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

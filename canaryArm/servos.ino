
Servo arm1Servo;
Servo arm2Servo;
Servo arm3Servo;
Servo arm4Servo;
Servo gripperServo;


boolean isOpen;

void servoSetup(){
  arm1Servo.attach(arm1ServoPin,minArm1ServoValue,maxArm1ServoValue);
  arm2Servo.attach(arm2ServoPin,minArm2ServoValue,maxArm2ServoValue);
  arm3Servo.attach(arm3ServoPin,minArm3ServoValue,maxArm3ServoValue);
  arm4Servo.attach(arm4ServoPin,minArm4ServoValue,maxArm4ServoValue);
  gripperServo.attach(gripperServoPin);

  arm1Servo.write(0);
  arm2Servo.write(0);
  arm3Servo.write(0);
  arm4Servo.write(0);
  gripperServo.write(openGripperValue);
}

void moveMotorToAngle(Servo selectedServo,char movementType,  float angleObjective){
  
 // int actualAngle = 0;
  double angleActual = double(selectedServo.read());
  double angleLast;
  double angleDiff;
  double angleInitial;
  int sense;
    
  switch (movementType){
    case '+':
      angleActual = selectedServo.read();
      angleObjective = angleObjective + angleActual;
      break;
    case '-':
      angleActual = selectedServo.read();
      angleObjective = angleObjective - angleActual;
    case 'G':
      break;     
   }
   
   if (angleActual>angleObjective){
     sense = -1;
   }else{ 
     sense = 1;
   }
   Serial.print("Sentido: ");
   Serial.println(sense);
   
   double porcentajeAlObjetivo;
   double initialTime;
   double actualTime;
   double vActual = 0.0;
   double distanciaTotal;
   double distanciaAlObjetivo;
   double vInitial = 0;
   
  
   angleActual = selectedServo.read();
   distanciaTotal = abs(angleActual-angleObjective);
   Serial.print("Distancia a Recorrer: ");
   Serial.println(distanciaTotal);
   
   distanciaAlObjetivo = distanciaTotal;
   Serial.print("Distancia al Objetivo: ");
   Serial.println(distanciaAlObjetivo);
   
   porcentajeAlObjetivo = (distanciaAlObjetivo-distanciaTotal) / distanciaTotal;
   Serial.print("Porcentaje al Objetivo: ");
   Serial.println(porcentajeAlObjetivo);

   Serial.println("");
   Serial.println("Acelerando");
   Serial.println(""); 
   unsigned long iteracion = 0 ;  
   angleInitial = angleActual;
   vInitial = 0;
   initialTime = double(millis())/1000;

   while (porcentajeAlObjetivo < accelerationPercentaje){
     //Serial.println("Acelerando");
     actualTime = (float(millis())/1000)-initialTime;
//     Serial.print("Tiempo Actual: ");
//     Serial.println(actualTime, 4);
     angleLast = angleActual;
     
     vActual = double(acceleration*actualTime);
//     Serial.print("Velocidad Actual Calcualda: ");
//     Serial.println(vActual,4);
     if (vActual > vMax){
       vActual = vMax;
       angleActual  =  angleInitial+sense*vActual*actualTime;
     }else{
//       Serial.print("Velocidad Actual: ");
//       Serial.println(vActual,4);
       angleActual  = angleInitial+ sense*(vInitial*actualTime + (acceleration*actualTime*actualTime)/2);
     }

//     Serial.print("Velocidad Actual Usada: ");
//     Serial.println(vActual,4);
     
//     Serial.print("Moviendose a: ");
//     Serial.println(angleActual);
     selectedServo.write(angleActual);
     
     angleDiff =angleActual-angleLast;
//     Serial.print("Differencia de angiulos : ");
//     Serial.println(angleDiff); 


     distanciaAlObjetivo = abs(angleActual-angleObjective);
//     Serial.print("Distancia al Objetivo: ");
//     Serial.println(distanciaAlObjetivo);   
//     Serial.print("distanciaTotal: ");
//     Serial.println(distanciaTotal);   
     
     porcentajeAlObjetivo = float(distanciaTotal-distanciaAlObjetivo) / float(distanciaTotal);
//     Serial.print("Porcentaje al Objetivo: ");
//     Serial.println(porcentajeAlObjetivo);    
    
    iteracion++; 
   }
   Serial.print("Iteraciones en aceleracion: ");
   Serial.println(iteracion);     
   
   Serial.print("Velocidad Actual: ");
   Serial.println(vActual,4);   
   Serial.println("");
   Serial.println("Velocidad Crucero");
   Serial.println("");   

    iteracion = 0;
   angleInitial = angleActual;
   initialTime = double(millis())/1000;
   while (porcentajeAlObjetivo >= accelerationPercentaje && porcentajeAlObjetivo<(1-accelerationPercentaje)){
   //  Serial.println("Velocidad Crucero");
     actualTime = (double(millis())/1000)-initialTime;
     angleLast = angleActual;
     //Serial.print("Tiempo Actual: ");
     //Serial.println(actualTime);

     angleActual  =  angleInitial+sense*vActual*actualTime;

     selectedServo.write(angleActual);
//     Serial.print("Moviendose a: ");
//     Serial.println(angleActual); 
    
     angleDiff =angleActual-angleLast;
//     Serial.print("Differencia de angiulos : ");
//     Serial.println(angleDiff); 

     distanciaAlObjetivo = abs(angleActual-angleObjective);
     porcentajeAlObjetivo = (distanciaTotal-distanciaAlObjetivo) / distanciaTotal;
     
     //Serial.print("Porcentaje al Objetivo: ");
     //Serial.println(porcentajeAlObjetivo);  
     iteracion++; 
   }
   
   Serial.println("");
   Serial.println("Frenando");
   Serial.println(""); 

   initialTime = double(millis())/1000;
   angleInitial = angleActual;
   vInitial = vActual;
   iteracion = 0;
   while (porcentajeAlObjetivo>=accelerationPercentaje && porcentajeAlObjetivo<1.0){
     //Serial.println("Frenando");
     //Serial.println();
     
     actualTime = (double(millis())/1000)-initialTime;
     angleLast = angleActual;   
//     Serial.print("Tiempo Actual: ");
//     Serial.println(actualTime);
      
      //vActual = sqrt(vInitial*vInitial - 2*acceleration*actualTime);
     vActual = vInitial-acceleration*actualTime;
//     Serial.print("Velocidad Actual: ");
//     Serial.println(vActual,4);
     if (vActual< vMin){
       vActual = vMin;
       angleActual  =  angleObjective;
       
     }else{
        angleActual  = angleInitial+ sense*(vInitial*actualTime - (acceleration*actualTime*actualTime)/2);
     }
     
//     Serial.print("Angulo Inicial: ");
//     Serial.println(angleInitial,4);
//     
//     Serial.print("Velocidad Inicial: ");
//     Serial.println(vInitial,4);
//      
//     Serial.print("Angulo Actual: ");
//     Serial.println(angleActual,4);
//
//     Serial.print("Velocidad Actual 2: ");
//     Serial.println(vActual,4);

     selectedServo.write(angleActual);
//     Serial.print("Moviendose a: ");
//     Serial.println(angleActual,5); 

     angleDiff = angleActual-angleLast;
//     Serial.print("Differencia de angulos : ");
//     Serial.println(angleDiff); 
     
     distanciaAlObjetivo = abs(angleActual-angleObjective);
//     Serial.print("Distancia al Objetivo: ");
//     Serial.println(distanciaAlObjetivo);    

     porcentajeAlObjetivo = (distanciaTotal-distanciaAlObjetivo) / distanciaTotal;
//     Serial.print("Porcentaje al Objetivo: ");
//     Serial.println(porcentajeAlObjetivo,4);  
     iteracion ++;

   }
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

Servo servoByNumber(int motor){
    switch (motor){
    case 1:
      return arm1Servo;
    case 2:
      return arm2Servo;
    case 3:
      return arm3Servo;
    case 4:
      return arm4Servo;
    case 5:
      return gripperServo;
    }

}

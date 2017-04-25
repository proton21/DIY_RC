#include <L293.h>
#define In1 8
#define In2 7
#define En1 6   
#define In3 12
#define In4 13       
#define En2 10
#define pinfrontLights 8
#define pinbackLights  7
#define Tx 3
#define Rx 2

//L293(pinLeft, pinRight, pinLftRgtEn, pinForward, pinBack, pinFwdBakVel);
L293 yellowCar(In1, In2, En1, In3, In4, En2);
char command = 'S';
char prevCommand = 'A';
int velocity = 0;
int velLeftMotor = 0; int velRightMotor = 0;

unsigned long timer0 = 2000;  //Stores the time (in millis since execution started) 
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone

void setup(){
  Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module. 
  pinMode(pinfrontLights, OUTPUT);
  pinMode(pinbackLights, OUTPUT);  
}

void loop(){
  if(Serial.available() > 0){
    timer1 = millis();    
    prevCommand = command;
    command = Serial.read();
    //Change pin mode only if new command is different from previous.    
    if(command!=prevCommand){
      //Serial.println(command);
      switch(command){
      case 'F':  
        yellowCar.forward_2W(En1,En2);
        break;
      case 'B':  
        yellowCar.back_2W(En1, En2);
        break;
      case 'L':  
        yellowCar.rotateLeft_2W(velLeftMotor, velRightMotor);
        break;
      case 'R':
        yellowCar.rotateRight_2W(velLeftMotor, velRightMotor);  
        break;
      case 'S':  
        yellowCar.stopped_2W();
        break; 
      case 'I':   
        yellowCar.forwardRight_4W(velocity);
        break; 
      case 'J':    
        yellowCar.backRight_4W(velocity);
        break;        
      case 'G':    
        yellowCar.forwardLeft_4W(velocity);
        break; 
      case 'H':  
        yellowCar.backLeft_4W(velocity);
        break;
      case 'W':  //Font ON 
        digitalWrite(pinfrontLights, HIGH);
        break;
      case 'w':  //Font OFF
        digitalWrite(pinfrontLights, LOW);
        break;
      case 'U':  //Back ON 
        digitalWrite(pinbackLights, HIGH);
        break;
      case 'u':  //Back OFF 
        digitalWrite(pinbackLights, LOW);
        break;  
      case 'D':  //Everything OFF 
        digitalWrite(pinfrontLights, LOW);
        digitalWrite(pinbackLights, LOW);
        yellowCar.stopped_2W();
        break;         
      default:  //Get velocity
        if(command=='q'){
          velocity = 255;  //Full velocity
          velLeftMotor = 255; velRightMotor = 255;
          yellowCar.setSpeeds_2W(velLeftMotor, velRightMotor);
        }
        else{
          //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
          if((command >= 48) && (command <= 57)){ 
            //Subtracting 48 changes the range from 48-57 to 0-9.
            //Multiplying by 25 changes the range from 0-9 to 0-225.
            velocity = (command - 48)*25;         
            velLeftMotor = (command - 48)*25;         
            velRightMotor =(command - 48)*25;         
            yellowCar.setSpeeds_2W(velLeftMotor,velRightMotor);
          }  
        }
      }
    }
  }
  else{
    timer0 = millis();  //Get the current time (millis since execution started).
    //Check if it has been 500ms since we received last command.
    if((timer0 - timer1)>500){  
      //More tan 500ms have passed since last command received, car is out of range.
      //Therefore stop the car and turn lights off.
      digitalWrite(pinfrontLights, LOW);
      digitalWrite(pinbackLights, LOW);
      yellowCar.stopped_2W();
    }
  }
}

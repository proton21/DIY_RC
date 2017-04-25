/* H-bridge 회로테스트 
두개의 디지탈입력으로 방향을 제어하고 두개의 
PWM출력으로 모터의 속력을 제어한다. */

//boolean reverse;
//#include <SoftwareSerial.h>

int En1 = 11;
int In1 = 12; int In2 = 13; //모터뱡향제어, 0 or 1 디지탈출력 
                        //숫자는 UNO의 IDE넘버
int In4 = 10; int In3 = 11; // PWM출력 ,숫자는 UNO IDE넘버 

void setup() {

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  // int potpin = 0;
  //Serial.begin(9600);
}

void loop() {
  
 digitalWrite(A, HIGH); digitalWrite(B, LOW);
for(int sp=0 ; sp >= 0 ; sp++ ){
  setMotor(D, sp); 
  if (sp =255) break;
}
delay(500); // TR 데드타임을 준다. 

 digitalWrite(A, LOW); digitalWrite(B, HIGH);

 for(int sp = 255 ; sp <=255 ; sp--) {
  setMotor(C , sp);
  if(sp = 0) break;
  
 }
  delay(500);
 
 
 

    
  
}


void setMotor(int pin ,int sp) {
  analogWrite(pin, sp);
 /* 
  if (reverse != !reverse) {
    delay(1000);
  }
*/
  

}




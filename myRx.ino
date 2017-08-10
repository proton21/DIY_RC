
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int joystick[3];
RF24 radio(7, 8);
//const uint64_t pipe = OxE8E8F0F0E1LL;
byte addresses[][6] = {"1Node"};

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600);
  Serial.begin(115200);
  radio.begin();
  //radio.openReadingPipe(1,pipe);
  radio.setChannel(108);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(1, addresses[0]);
  radio.startListening();
  pinMode(5, OUTPUT);

}

void loop() {
  if (radio.available()) {
    // put your main code here, to run repeatedly:
    while (radio.available()) {

      radio.read(&joystick, sizeof(joystick));

    }


    Serial.println(joystick[3]); 
  
  char a = map(joystick[0], 0, 1023, 0, 255);
  char g = map(joystick[1], 0, 1023, 0, 255);
  digitalWrite(5, joystick[2]);

  analogWrite(6, a);
  analogWrite(9, g);
  
   } //END Radio.available

   
  delay(50);

} //--(end main loop)---


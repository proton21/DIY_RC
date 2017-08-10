#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int joystick[3];
RF24 radio(7, 8);

byte addresses[][6] = {"1Node"}; //Create address for 1 pipe.

void setup() {

  Serial.begin(115200);
  radio.begin();
  radio.setChannel(108);// Above most Wifi Channels
  radio.setPALevel(RF24_PA_MIN);
  //radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(addresses[0]);
  pinMode(2, INPUT);

}

void loop() {
  joystick[0] = analogRead(A0);
  joystick[1] = analogRead(A1);
  joystick[2] = analogRead(2);

  Serial.println(joystick[3]);
  Serial.println(digitalRead(2));
  radio.write(&joystick, sizeof(joystick));
  
  delay(50);

}




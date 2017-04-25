#include "Arduino.h"
#include "L293.h"
L293::L293(int pinMotor_A_dir0, int pinMotor_A_dir1, int pinMotor_A_speed, int pinMotor_B_dir0, int pinMotor_B_dir1, int pinMotor_B_speed)
{
	pinMode(pinMotor_A_dir0, OUTPUT);
	_pinMotor_A_dir0 = pinMotor_A_dir0; 
	pinMode(pinMotor_A_dir1, OUTPUT);
	_pinMotor_A_dir1 = pinMotor_A_dir1; 
	pinMode(pinMotor_A_speed, OUTPUT);
	_pinMotor_A_speed = pinMotor_A_speed; 
	pinMode(pinMotor_B_dir0, OUTPUT);
	_pinMotor_B_dir0 = pinMotor_B_dir0; 
	pinMode(pinMotor_B_dir1, OUTPUT);
	_pinMotor_B_dir1 = pinMotor_B_dir1; 
	pinMode(pinMotor_B_speed, OUTPUT);
	_pinMotor_B_speed = pinMotor_B_speed; 
}

L293::L293(int pinMotor_A_dir0, int pinMotor_A_dir1, int pinMotor_A_speed)
{
	pinMode(pinMotor_A_dir0, OUTPUT);
	_pinMotor_A_dir0 = pinMotor_A_dir0; 
	pinMode(pinMotor_A_dir1, OUTPUT);
	_pinMotor_A_dir1 = pinMotor_A_dir1; 
	pinMode(pinMotor_A_speed, OUTPUT);
	_pinMotor_A_speed = pinMotor_A_speed;  
}

void L293::forward_1W(int velSingleMotor){
	_velSingleMotor = velSingleMotor;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	analogWrite(_pinMotor_A_speed,_velSingleMotor);
}

void L293::back_1W(int velSingleMotor){
	_velSingleMotor = velSingleMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	analogWrite(_pinMotor_A_speed,_velSingleMotor);
}

void L293::stopped_1W(){
	_velSingleMotor = 0;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,LOW);
	analogWrite(_pinMotor_A_speed,_velSingleMotor);
}

void L293::setSpeed_1W(int velSingleMotor){
	_velSingleMotor = velSingleMotor;
	analogWrite(_pinMotor_A_speed,_velSingleMotor);
}

void L293::forward_2W(int velLeftMotor, int velRightMotor)
{
	_velLeftMotor = velLeftMotor;
	_velRightMotor = velRightMotor;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	digitalWrite(_pinMotor_B_dir0,HIGH);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::back_2W(int velLeftMotor, int velRightMotor)
{
	_velLeftMotor = velLeftMotor;
	_velRightMotor = velRightMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,HIGH);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::rotateLeft_2W(int velLeftMotor, int velRightMotor)
{
	_velLeftMotor = velLeftMotor;
	_velRightMotor = velRightMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	digitalWrite(_pinMotor_B_dir0,HIGH);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::rotateRight_2W(int velLeftMotor, int velRightMotor)
{
	_velLeftMotor = velLeftMotor;
	_velRightMotor = velRightMotor;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,HIGH);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::stopped_2W()
{
	_velLeftMotor = 0;
	_velRightMotor = 0;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,LOW);
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::setSpeeds_2W(int velLeftMotor, int velRightMotor)
{
	_velLeftMotor = velLeftMotor;
	_velRightMotor = velRightMotor;
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::setSpeedLeft_2W(int velLeftMotor)
{
	_velLeftMotor = velLeftMotor;
	analogWrite(_pinMotor_A_speed,_velLeftMotor);
}

void L293::setSpeedRight_2W(int velRightMotor)
{
	_velRightMotor = velRightMotor;
	analogWrite(_pinMotor_B_speed,_velRightMotor);
}

void L293::forward_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,LOW);
	digitalWrite(_pinMotor_B_dir0,HIGH);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::back_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,LOW);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,HIGH);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::left_4W()
{
	_velBackMotor = 0;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::right_4W()
{
	_velBackMotor = 0;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::forwardLeft_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,HIGH);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::forwardRight_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,HIGH);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::backLeft_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,HIGH);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,HIGH);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::backRight_4W(int velBackMotor)
{
	_velBackMotor = velBackMotor;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,HIGH);
	digitalWrite(_pinMotor_A_speed,HIGH);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,HIGH);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::stopped_4W()
{
	_velBackMotor = 0;
	digitalWrite(_pinMotor_A_dir0,LOW);
	digitalWrite(_pinMotor_A_dir1,LOW);
	digitalWrite(_pinMotor_A_speed,LOW);
	digitalWrite(_pinMotor_B_dir0,LOW);
	digitalWrite(_pinMotor_B_dir1,LOW);
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}

void L293::setSpeed_4W(int velBackMotor){
	_velBackMotor = velBackMotor;
	analogWrite(_pinMotor_B_speed,_velBackMotor);
}
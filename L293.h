#ifndef L293_h
#define L293_h

#include "Arduino.h"

class L293
{
	public:
		L293(int pinMotor_A_dir0, int pinMotor_A_dir1, int pinMotor_A_speed, int pinMotor_B_dir0, int pinMotor_B_dir1, int pinMotor_B_speed);
		L293(int pinMotor_A_dir0, int pinMotor_A_dir1, int pinMotor_A_speed);

		void forward_1W(int velSingleMotor);
		void back_1W(int velSingleMotor);
		void stopped_1W();
		void setSpeed_1W(int velSingleMotor);

		void forward_2W(int velLeftMotor, int velRightMotor);
		void back_2W(int velLeftMotor, int velRightMotor);
		void rotateLeft_2W(int velLeftMotor, int velRightMotor);
		void rotateRight_2W(int velLeftMotor, int velRightMotor);
		void stopped_2W();
		void setSpeeds_2W(int velLeftMotor, int velRightMotor);
		void setSpeedLeft_2W(int velLeftMotor);
		void setSpeedRight_2W(int velRightMotor);

		void forward_4W(int velBackMotor);
		void back_4W(int velBackMotor);
		void left_4W();
		void right_4W();
		void forwardLeft_4W(int velBackMotor);
		void forwardRight_4W(int velBackMotor);
		void backLeft_4W(int velBackMotor);
		void backRight_4W(int velBackMotor);
		void stopped_4W();
		void setSpeed_4W(int velBackMotor);
	private:
		int _pinMotor_A_dir0;
		int _pinMotor_A_dir1; 
		int _pinMotor_A_speed; 
		int _pinMotor_B_dir0; 
		int _pinMotor_B_dir1; 
		int _pinMotor_B_speed;
		int _velLeftMotor;
		int _velRightMotor;
		int _velBackMotor;
		int _velSingleMotor;
};

#endif
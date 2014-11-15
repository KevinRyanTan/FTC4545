float x1 = 0;
float y1 = 0;
float x2 = 0;
float joy2y1 = 0;
float joy2y2 = 0;
float num = 0.00;
float FL = 0.00;
float BL = 0.00;
float FR = 0.00;
float BR = 0.00;
int y2 = 0;

#include "JoystickDriver.c"
#include "normalize.h"

void initializeRobot(){
	return;
} // end of initialization

task moveLift()
{
	wait1Msec(1000);
	while(true){
		int num = joystick.joy2_y2;
		if(num > 10)
		{
			servo[servoLeftBridge] = ServoValue[servoLeftBridge] + num / 8;
			servo[servoRightBridge] = ServoValue[servoRightBridge] - num / 8;
			wait1Msec(100);
		}
		else if(num < -10)
		{
			servo[servoLeftBridge] = ServoValue[servoLeftBridge] + num / 8;
			servo[servoRightBridge] = ServoValue[servoRightBridge] - num / 8;
			wait1Msec(100);
		}
	}
}

task moveGrabber()
{
	if(joy2Btn(7))
	{
		servo[servoRearGrabber] = ServoValue[servoRearGrabber] + 10;
		wait1Msec(250);
	}
	else if(joy2Btn(8))
	{
		servo[servoRearGrabber] = ServoValue[servoRearGrabber] - 10;
		wait1Msec(250);
	}

}


task HoloDrive()
{
	servo[servoLeftBridge] = 0;
	servo[servoRightBridge] = 255;
	startTask(moveLift);
	startTask(moveGrabber);
	//nMotorEncoder[motorLeftPulley] = 100;
	while(true)
	{
		getJoystickSettings(joystick);
		x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;
		y2 = joystick.joy1_y2;
		joy2y1 = joystick.joy2_y1;
		joy2y2 = joystick.joy2_y2;

		x1 = x1 / 1.28;
		y1 = y1 / 1.28;
		x2 = x2 / 1.28;
		y2 = y2 / 1.28;
		joy2y1 = joy2y1 / 1.28;
		joy2y2 = joy2y2 / 1.28;

		FL = y1 + x1 + x2;
		BL = y1 - x1 + x2;
		FR = y1 - x1 - x2;
		BR = y1 + x1 - x2;

		normalize();

		//All Motors at 3/5 speed
		FL = FL * 0.60;
		BL = BL * 0.60;
		FR = FR * 0.60;
		BR = BR * 0.60;

		//if(joy1Btn(8))
		//{
		//	FL = FL * 0.50;
		//	BL = BL * 0.50;
		//	FR = FR * 0.50;
		//	BR = BR * 0.50;
		//}

		//Run the motors
		if((abs(x2) >= 10) && (joy1Btn(3)))
		{
			motor[motorFL] = x2 / 5;
			motor[motorBL] = x2 / 5;
			motor[motorFR] = x2 / 5;
			motor[motorBR] = x2 / 5;
		}
		else if((abs(x2) >= 10) && (joy1Btn(2)))
		{
			motor[motorFL] = x2 / 3;
			motor[motorBL] = x2 / 3;
			motor[motorFR] = x2 / 3;
			motor[motorBR] = x2 / 3;
		}
		else if(abs(x2) >= 10)
		{
			motor[motorFL] = x2;
			motor[motorBL] = x2;
			motor[motorFR] = x2;
			motor[motorBR] = x2;
		}
		else if((abs(x1) >= 10 || abs(y1) >= 10) && joy1Btn(2))
		{
			motor[motorFL] = FL / 2;
			motor[motorBL] = BL / 2;
			motor[motorFR] = -FR / 2;
			motor[motorBR] = -BR / 2;
		}
		else if((abs(x1) >= 10 || abs(y1) >= 10) && joy1Btn(3))
		{
			motor[motorFL] = FL / 3;
			motor[motorBL] = BL / 3;
			motor[motorFR] = -FR / 3;
			motor[motorBR] = -BR / 3;
		}
		else if(abs(x1) >= 10 || abs(y1) >= 10)
		{
			motor[motorFL] = FL;
			motor[motorBL] = BL;
			motor[motorFR] = -FR;
			motor[motorBR] = -BR;
		}
		else
		{
			motor[motorFL] = 0;
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
		}
		if(joy1Btn(7))
			motor[motorManipulator] = 70;
		else if(joy1Btn(8))
			motor[motorManipulator] = -70;
		else
			motor[motorManipulator] = 0;
		//Move Lift
		if(joy2y1 >= 10)
		{
			motor[motorLeftPulley] = joy2y1 / 2;
			motor[motorRightPulley] = joy2y1 / 2;
		}
		else if(joy2y1 <= -10) //&& nMotorEncoder[motorLeftPulley] > 50)
		{
			motor[motorLeftPulley] = joy2y1 / 12;
			motor[motorRightPulley] = joy2y1 / 12;
		}
		else
		{
			motor[motorLeftPulley] = 0;
			motor[motorRightPulley] = 0;
		}
		wait1Msec(7);
	}
}


task main()
{
	initializeRobot();
	waitForStart();
	startTask(HoloDrive);
	while(true){wait1Msec(1);}
} // End of task main

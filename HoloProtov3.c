#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTGYRO,         sensorAnalogInactive)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorRightPulley, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorManipulator, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorNull,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorLeftPulley, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C1_1,    servoRearGrabberR,    tServoStandard)
#pragma config(Servo,  srvo_S4_C1_2,    servoLeftBridge,      tServoStandard)
#pragma config(Servo,  srvo_S4_C1_3,    servoRightBridge,     tServoStandard)
#pragma config(Servo,  srvo_S4_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_6,    servoRearGrabberL,    tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
	float diff = 225;
	while(true)
	{
		float num = joystick.joy2_y2;
		num = num / 16;
		if(num > 10)
		{
			if(diff < 230 && diff > 150)
				diff = diff - num;
		}
		else if(num < -10)
		{
			if(diff < 230 && diff > 150)
				diff = diff + num;
		}
		if(diff <= 150)
			diff = 151;
		else if(diff >= 230)
			diff = 229;
		servo[servoLeftBridge] = diff;
		servo[servoRightBridge] = 255 - diff;
		wait1Msec(150);
	}
}

task moveGrabber()
{
	wait1Msec(1000);
	bool grabChoice = true;
	float dif = 127;
	if(grabChoice)
	{
		while(true)
		{
			if(joy2Btn(7))
				dif = dif - 10;
			else if(joy2Btn(8))
				dif = dif + 10;
			servo[servoRearGrabberR] = dif;
			servo[servoRearGrabberL] = 255 - dif;
			wait1Msec(50);
		}
	}
	else
	{
		while(true){
			if(joy2Btn(7))
			{
				servo[servoRearGrabberR] = 0;
				servo[servoRearGrabberL] = 255;
			}
			else if(joy2Btn(8))
			{
				servo[servoRearGrabberR] = 127;
				servo[servoRearGrabberL] = 127;
			}
		}
	}

}


task HoloDrive()
{
	startTask(moveLift);
	startTask(moveGrabber);
	nMotorEncoder[motorLeftPulley] = 100;
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
			motor[motorLeftPulley] = joy2y1;
			motor[motorRightPulley] = joy2y1;
		}
		else if(joy2y1 <= -10) //&& nMotorEncoder[motorLeftPulley] > 50)
		{
			motor[motorLeftPulley] = joy2y1;
			motor[motorRightPulley] = joy2y1;
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

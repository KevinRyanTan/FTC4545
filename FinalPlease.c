#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     BR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     FR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     FL,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     BL,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
void initializeRobot(){
	return;
} // end of initialization

task drive()
{
	int FL = 0;
	int FR = 0;
	int BL = 0;
	int BR = 0;

	int threshold = 15;
	int y1 = 0;
	int x1 = 0;
	int x2 = 0;

	while (true){
		getJoystickSettings(joystick);
		y1 = (short)joystick.joy1_y1;
		x1 = (short)joystick.joy1_x1;
		x2 = (short)joystick.joy1_x2;

		motor[FR] = y1 - x2 - x1;
		motor[BR] =  y1 - x2 + x1;
		motor[FL] = y1 + x2 + x1;
		motor[BL] =  y1 + x2 - x1;

	/*	if (motor[FR] < 100)
		{
			motor[FR] = y1;
		} // End of if
		else
		{
			motor[FR] = 100;
		} // End of else
		if (motor[FR] > -100)
		{
			motor[FR] = y1;
		} // End of if
		else
		{
			motor[FR] = -100;
		} // End of else

		//******************8

		if (motor[FL] < 100)
		{
			motor[FL] = y1;
		} // End of if
		else
		{
			motor[FL] = 100;
		} // End of else
		if (motor[FL] > -100)
		{
			motor[FL] = y1;
		} // End of if
		else
		{
			motor[FR] = -100;
		} // End of else

		//******************8

		if (motor[BR] < 100)
		{
			motor[BR] = y1;
		} // End of if
		else
		{
			motor[BR] = 100;
		} // End of else
		if (motor[FL] > -100)
		{
			motor[BR] = y1;
		} // End of if
		else
		{
			motor[BR] = -100;
		} // End of else

		//******************8

		if (motor[BL] < 100)
		{
			motor[BL] = y1;
		} // End of if
		else
		{
			motor[BL] = 100;
		} // End of else
		if (motor[FL] > -100)
		{
			motor[BL] = y1;
		} // End of if
		else
		{
			motor[BL] = -100;
		} // End of else
		*/
		if (abs(joystick.joy1_y1) > 10 || abs(joystick.joy1_y2) > 10) {
			motor[FL] = joystick.joy1_y1 / 1.28;
			motor[BL] = joystick.joy1_y1 / 1.28;
			motor[FR] = joystick.joy1_y2 / 1.28;
			motor[BR] = joystick.joy1_y2 / 1.28;
		}

		else {
			motor[FL] = 0;
			motor[BL] = 0;
			motor[FR] = 0;
			motor[BR] = 0;
		}
		wait1Msec(7);

	} // End of while true
} // End of task drive

task main()
{
	initializeRobot();
	waitForStart();
	startTask(drive);
	while(true)
	{
		wait1Msec(5);
	} // End of while true
} // End of task main

#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     FR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     FL,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     BR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     BL,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

void initializeRobot(){
	return;
}

task FancyDrive()
{
	// Forever loop
	while(true){
		int y1 = 0;
		int x1 = 0;
		int threshold = 15;
		//Create "deadzone" for y1
		if(abs(joystick.joy1_y1) > threshold)
		{
			y1 = joystick.joy1_y1;
		} // End of if statement
		else
		{
			y1 = 0;
		} // End of else statement
		//Create "deadzone" for x1
		if(abs(joystick.joy1_x1) > threshold)
		{
			x1 = joystick.joy1_x1;
		} // End of if statement
		else
		{
			x1 = 0;
		} // End of else statement
		if(joy1Btn(7))
		{
			motor[FL] = -100;
			motor[FR] = -100;
			motor[BL] = -100;
			motor[BR] = -100;
		} // End of else if statement
		else if(joy1Btn(8))
		{
			motor[FL] = 100;
			motor[FR] = 100;
			motor[BL] = 100;
			motor[BR] = 100;
		} // End of else if statement
		else
		{
			motor[FR] = y1 + x1;
			motor[BR] =  y1 - x1;
			motor[FL] = y1 - x1;
			motor[BL] =  y1 + x1;
		}
		wait1Msec(7);
	}
}
task main()
{
	initializeRobot();

	waitForStart();
	startTask(FancyDrive);
}

#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     FL,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     FR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     BL,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     BR,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

void initializeRobot(){
	return;
}

task HoloDrive()
{
	while(true){
		short y1 = joystick.joy1_y1;
		short x1 = joystick.joy1_x1;
		// Forward movement and Backward movement
		if(x1 > 5 && y1 > 5)
		{
			motor[FL] = (((2.222) * atan(abs(y1/x1)) - 100));
			motor[FR] = (100);
			motor[BL] = (((-2.222) * atan(abs(y1/x1)) + 100));
			motor[BR] = (-100);
		} // End of if statement

		// Right movement and Left movement
		else if(x1 < -5 && y1 > 5)
		{
			motor[FL] = (100);
			motor[FR] = (((2.222) * atan(abs(y1/x1)) - 100));
			motor[BL] = (-100);
			motor[BR] = (((-2.222) * atan(abs(y1/x1)) + 100));
		} // End of else if statement
		else if(x1 < -5 && y1 < -5)
		{
			motor[FL] = (((-2.222) * atan(abs(y1/x1)) - 100));
			motor[FR] = (-100);
			motor[BL] = (((2.222) * atan(abs(y1/x1)) + 100));
			motor[BR] = (100);
		} // End of else if statement
		else if(x1 > 5 && y1 < -5)
		{
			motor[FL] = (-100);
			motor[FR] = (((-2.222) * atan(abs(y1/x1)) + 100));
			motor[BL] = (100);
			motor[BR] = (((2.222) * atan(abs(y1/x1)) - 100));
		} // End of else if statement
		else if(joy1Btn(7))
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
		else {
			motor[FL] = (0);
			motor[FR] = (0);
			motor[BL] = (0);
			motor[BR] = (0);
		} // End of else statement
	} // End of while(true)
} // End of task HoloDrive{}

task main()
{
	initializeRobot();
	waitForStart();
	startTask(HoloDrive);
}

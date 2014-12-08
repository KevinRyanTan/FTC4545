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

#include "JoystickDriver.c"

task main()
{

	while(true){
	//left is down
	if(nNxtButtonPressed == 1)
	{
		motor[motorRightPulley] = -100;
		motor[motorLeftPulley] = -100;
		wait1Msec(50);
	}
	if(nNxtButtonPressed == 2)
	{
		motor[motorRightPulley] = 100;
		motor[motorLeftPulley] = 100;
		wait1Msec(50);
	}
	else
	{
		motor[motorRightPulley] = 0;
		motor[motorLeftPulley] = 0;
	}
}

}

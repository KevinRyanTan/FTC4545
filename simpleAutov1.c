#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTGYRO,         sensorAnalogInactive)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorNull,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeftPulley, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorBL,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorBR,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorFR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorRightPulley, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorManipulator, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C1_1,    servoRightBridge,     tServoStandard)
#pragma config(Servo,  srvo_S4_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_6,    servoLeftBridge,      tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool FLdone = false;
bool BLdone = false;
bool FRdone = false;
bool BRdone = false;
int _dirAC = 0;
int _dirDC = 0;

#include "reset.h"
#include "moveRobotRearW.h"
#include "setServos.h"
#include "drivers\hitechnic-sensormux.h"
#include "drivers\hitechnic-irseeker-v2.h"
#include "drivers\hitechnic-gyro.h"
#include "gyroTurn.h"
#include "lift.h"

task main()
{
	//Only kickstand
	moveRobotR(20,-85,0.01,2.2);
	doneReset();
	resetEncoders();
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorBR]) < abs(2.2 * 1120))
		{
			motor[motorFL] = -85;
			motor[motorBR] = -85;
			motor[motorFR] = 20;
			motor[motorBL] = 20;
		}
		else
		{
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			BLdone = true;
			FRdone = true;
			FLdone = true;
			BRdone = true;
		}
	}
	stopMotors();
	doneReset();
	moveRobotRotate(45,-45,0.1,0.1);
	moveRobotR(-60,-60,3.3,3.3);
	_dirDC = HTIRS2readDCDir(HTIRS2);
	_dirAC = HTIRS2readACDir(HTIRS2);
	wait1Msec(1000);
	if(_dirDC > 1) 			//IR NOT in range = preset 1
	{
		moveRobotR(60,60,2.4,2.4);
		moveRobotRotate(45,-45,0.75,0.75);
		moveRobotR(70,70,2.5,2.5);
		while(true){wait1Msec(5);}
	}
	else 															//IR IS in range (preset 1 = true)
	{
		moveRobotR(45,45,1,1); 		//Knock over preset 1 kickstand
		moveRobotR(-20,85,0.01,5.8);
		moveRobotRotate(-45,45,2,2);
	}
	//Read DC and AC on IR sensor
	_dirDC = HTIRS2readDCDir(HTIRS2);
	_dirAC = HTIRS2readACDir(HTIRS2);
	if(_dirDC > 1) 			//IR in range = preset 2
	{
		moveRobotRotate(45,-45,0.35,0.35);
		moveRobotR(70,70,2.5,2.5);
		while(true){wait1Msec(5);}      //Wait until end of program
	}
	else 															//IR not in range = preset 3
	{
		moveRobotR(45,45,1,1); 		//Knock over preset 3 kickstand
		moveRobotRotate(30,-30,1,1);
		moveRobotR(70,70,2.5,2.5);
		while(true){wait1Msec(5);}      //Wait until end of program
	}

	//Initializes Servos to initial values
	//initializeServos();
	////Lifts the lift slightly off of the ground
	//initializeLift();
	//////Moves the servos slightly forward to make sure the ablls dont roll out
	//setServos(127);
	//wait1Msec(1000);
	//////Moves the robot near the medium tube
	//moveRobotR(20,-60,0.1,2.4);
	//wait1Msec(500);
	//moveRobotRotate(16,-16,0.15,0.15);
	//wait1Msec(500);
	//moveRobotR(-30,-30,3.6,3.6);
	////moveRobotR(30,30,3.6,3.6);
	////90 degree turn left
	////gyroTurn(true, 70, 90.0); 						//With gyro
	////moveRobotRotate(-45,45,1.2,1.2);	//Or without gyro
	//stopMotors();
	//////Raise lift to small (not medium) size goal
	//lift30();
	//////Slight adjustments before dropping
	////motor[motorFL] = 30;
	////motor[motorBL] = 30;
	////motor[motorFR] = -30;
	////motor[motorBR] = -30;
	////wait1Msec(50);
	////stopMotors();
	////wait1Msec(300);
	////drop30();
	////undrop30();
	////wait1Msec(2000);
	//////Lower the basket to initial level
	////lower30();
	//////Moves to spot to "see" if IR is in range
	//////gyroTurn(true,70,90);
	////moveRobotR(45,45,3.5,3.5);
	//////Read DC and AC on IR sensor
	////_dirDC = HTIRS2readDCDir(HTIRS2);
	////_dirAC = HTIRS2readACDir(HTIRS2);
	////if(_dirDC > 1 || _dirAC > 1) 			//IR NOT in range = preset 1
	////{
	////	moveRobotR(-60,0,2.4,0);
	////	moveRobotR(70,70,5,5);
	////}
	////else 															//IR IS in range (preset 1 = true)
	////{
	////	moveRobotR(45,45,0.75,0.75); 		//Knock over preset 1 kickstand
	////	while(true){wait1Msec(5);}      //Wait till end of program
	////}
	//////Read DC and AC on IR sensor
	////_dirDC = HTIRS2readDCDir(HTIRS2);
	////_dirAC = HTIRS2readACDir(HTIRS2);
	////if(_dirDC > 1 || _dirAC > 1) 			//IR in range = preset 2
	////{
	////	moveRobotR(-45,-45,2,2); 				//Knock over preset 2 kickstand
	////	moveRobotRotate(30,-30,0.5,0.5);
	////	moveRobotR(70,70,5,5);
	////	while(true){wait1Msec(5);}      //Wait until end of program
	////}
	////else 															//IR not in range = preset 3
	////{
	////	moveRobotR(-45,-45,1,1); 		//Knock over preset 3 kickstand
	////	moveRobotRotate(30,-30,1,1);
	////	moveRobotR(70,70,5,5);
	////	while(true){wait1Msec(5);}      //Wait until end of program
	////}
	////stopMotors();
	while(true){wait1Msec(100);}
}

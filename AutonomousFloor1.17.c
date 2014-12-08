#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S2,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S3,     HTGYRO,         sensorAnalog)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFR,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, openLoop, reversed)
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

bool ramp = true;
bool FLdone = false;
bool BLdone = false;
bool FRdone = false;
bool BRdone = false;
int _dirAC = 0;
int _dirDC = 0;
int irTotal = 0;
int dcS1, dcS2, dcS3, dcS4, dcS5, acS1, acS2, acS3, acS4, acS5 = 0;
int heading = 0;

#include "reset.h"
#include "JoystickDriver.c"
#include "autonomousChooserNew.h"
#include "moveRobotRearW.h"
#include "setServos.h"
#include "drivers\hitechnic-sensormux.h"
#include "drivers\hitechnic-irseeker-v2.h"
#include "drivers\hitechnic-gyro.h"
#include "gyroTurn.h"
#include "lift.h"
#include "readIR.h"

void initializeRobot()
{

}

task main()
{
	initializeRobot();
	disableDiagnosticsDisplay();
	//waitForStart();
	ramp = false;
	heading = 180;
	initializeServos(); //Initializes Servos to initial values
	initializeLift(); //Lifts the lift slightly off of the ground
	setServos(50); //Moves the servos slightly forward to make sure the ablls dont roll out
	wait1Msec(1000);
	moveRobotBL(30,0.75); //Move forward for better readings
	irTotal = readIR(); //Read the IR value
	_dirAC = HTIRS2readACDir(HTIRS2);
	if(_dirAC == 5) //If preset 3
	{
		moveRobotBL(30,1); //Move forward more
		gyroTurn(30,90); //Turn Right 90 degrees
		gyroTurn(30,90); //Turn Right 90 degrees
		liftCenter(); //Raise the lift to the center goal
		moveRobotBL(-30,0.5); //Back up to center goal
		dumpCenter(); //Dump the balls in the center goal
		moveRobotBL(30,0.5); //Move back forwards
		lowerCenter(); //Lower the lift to the floor
		gyroTurn(30,-90); //Turn 90 degrees to the left
		moveRobotBL(30,1); //Move forwards
		gyroTurn(30,-90); //Turn 90 degrees to the left
		hitKickstand(); //Run into the kickstand
	}
	else if(_dirAC > 1) //If preset 2
	{
		gyroTurn(30,-45); //Turn Left 45 degrees
		moveRobotBL(30,1.5); //Move forward
		gyroTurn(30,-90); //Turn Left 90 degrees
		moveRobotBL(-30,1); //Move back
		liftCenter(); //Raise the lift to the center goal
		moveRobotBL(-20,0.5); //Back up to the center goal
		dumpCenter(); //Dump the balls in the center goal
		moveRobotBL(20,0.5); //Move away from the center goal
		lowerCenter(); //Lower the lift
		gyroTurn(30,-90); //Turn Left 90 Degrees
		moveRobotBL(30,1); //Move forward
		gyroTurn(30,-90); //Turn Left 90 degrees
		hitKickstand(); //Run into the kickstand
	}
	else //If preset 1
	{
		gyroTurn(30,-45); //Turn Left 45 Degrees
		moveRobotBL(30,1.5); //Move forward
		gyroTurn(30,-45); //Turn Left 45 Degrees
		moveRobotBL(-30,1.5); //Back up to the center goal
		liftCenter(); //Raise the lift to the center goal
		moveRobotBL(-20,0.5); //Back up to the center goal
		dumpCenter(); //Dump the balls in the center goal
		moveRobotBL(20,0.5); //Move away form the center goal
		lowerCenter(); //Lower the lift
		gyroTurn(30,-90); //Turn Left 90 Degrees
		moveRobotBL(30,1); //Move forward
		gyroTurn(30,-90); //Turn Left 90 degrees
		hitKickstand();
	}
	while(true){wait1Msec(100);}
}

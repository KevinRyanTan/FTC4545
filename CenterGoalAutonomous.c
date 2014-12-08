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
	waitForStart();
	initializeServos(); //Initializes Servos to initial values
	initializeLift(); // Lifts the lift slightly off the ground		
	setServos(50); //Moves the servos slightly forward to make sure the ablls dont roll out
	wait1Msec(1000);
	moveRobotBR(30,1); //Move forward for better readings
	irTotal = readIR(); //Read the IR value
	_dirAC = HTIRS2readACDir(HTIRS2);
	heading = 0;
	wait1Msec(1000);
	moveRobotBR(30,1); //Move robot forward for better IR readings
	if(_dirAC == 5) //If preset 3
	{
		moveRobotBR(30,0.75); //Move forward
		gyroTurn(true,30,180); //Rotate 180 degrees
		liftCenter(); //Lift to the center
		moveRobotBR(-30,0.75); //Move back to adjust
		dumpCenter(); //Dump the balls into the goal, and return the servos to a position so that the lift can be lowered
		lowerCenter(); //Lower the lift
		gyroTurn(false,30,90); //Turn to the right 90 degrees
		moveRobotBR(30,1); //Move forward
		gyroTurn(true,30,90); //Turn to the left 90 degrees
		moveRobotBR(60,4); //Run into kickstand
	}
	else if(_dirAC > 1) //If preset 2
	{
		moveRobotBR(30,0.75); //Move forward
		gyroTurn(true,30,45); //Turn 45 degrees to the left
		moveRobotBR(30,0.75); //Move the robot forward
		gyroTurn(false,30,45); //Turn 45 degrees to the right (should be facing center goal)
		gyroTurn(false,30,180); //Rotate 180 degrees so you can place ball in center goal
		moveRobotBR(-30,1); //Move back a bit
		liftCenter(); //Raise the lift
		moveRobotBR(-30,0.75); //Move drawbridge over the center goal
		dumpCenter(); //Dump the balls
		lowerCenter(); //Lower the lift
		gyroTurn(false,30,90); //Turn to the right 90 degrees
		moveRobotBR(30,1); //Move forward
		gyroTurn(true,30,90); //Turn to the left 90 degrees
		moveRobotBR(60,4); //Run into kickstand
	}
	else //If preset 1
	{
		gyroTurn(true,30,45); //Turn to the left 45 degrees
		moveRobotBR(30,2.5); //Go forward
		gyroTurn(true,30,45); //Turn to the left 45 degrees
		moveRobotBR(-30,1.5); //Move backwards to get closer to center goal
		liftCenter(); //Raise the lift
		moveRobotBR(-30,0.75); //Adjust back to the center goal
		dumpCenter(); //Dump the balls
		lowerCenter(); //Lower the lift
		gyroTurn(false,30,90); //Turn to the right 90 degrees
		moveRobotBR(30,1); //Move forward
		gyroTurn(true,30,90); //Turn to the left 90 degrees
		moveRobotBR(60,4); //Run into kickstand
	}
	while(true){wait1Msec(500);}
}

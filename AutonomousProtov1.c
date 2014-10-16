#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTGYRO,         sensorAnalogInactive)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     Sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorNull,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorManipulator, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorFR,       tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Initializes all global variables
int _dirDC = 0;
int _dirAC = 0;
int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
int acS1, acS2, acS3, acS4, acS5 = 0;
int irNear = 0;
int irFar = 0;
int irDist = 0;
int irTotal = 0;
int preset = 0;
int num = 0;
int ramp = 0;
int red = 0;
int blue = 0;
int irMax = 0;
float ultsonar = 0.0;
int irTotalOld = 0;
int alignDir = 20;
int final = 0;
int count = 1;
char optionRamp1 = 'a';
char optionFloor1 = 'a';
char optionRamp2 = 'a';
char optionFloor2 = 'a';
char optionRamp3 = 'a';
char optionFloor3 = 'a';
bool FLdone = false;
bool BLdone = false;
bool FRdone = false;
bool BRdone = false;

//Includes header files

//Resets motors, encoders and doneReset
#include "reset.h"
//Moves robot
#include "moveRobot.h"
//AUTONOMOUS CHOOSER!!!
#include "autonomousChooser.h"
//Includes ability to use joysticks(not sure if necessary)
#include "JoystickDriver.c"
//General drivers for Xander's sensors
#include "drivers\hitechnic-sensormux.h"
//Drivers for IR seeker
#include "drivers\hitechnic-irseeker-v2.h"
//Drivers for Gyro Sensor
#include "drivers\hitechnic-gyro.h"
//Button for debugging, stops autonomous immediately when back right bumper is pressed
#include "emergency.h"
//Drops baseball or golf ball into center goal when already aligned
#include "liftCenter.h"
//When aligned with center goal, moves robot forward into position
#include "moveSonar.h"
//In floorOneA, aligns robot with the center goal
#include "floorThreeAMethods.h"
//Calibrates and finds starting position of the center goal
#include "startPos.h"
//File for running autonomous in case of center goal in position 3
#include "presetOne.h"
//File for running autonomous in case of center goal in position 2
#include "presetTwo.h"
//File for running autonomous in case of center goal in position 1
#include "presetThree.h"
//Sets the mode of the IRSeeker DC input
tHTIRS2DSPMode _mode = DSP_1200;

void initializeRobot()
{
	return;
} // end of initialization

//This is where the program is changed during the competition
//We will have many different files with different parts of this commented
//It will automatically run the correct program
void autoType()
{
	//Starting on blue ramp
	//blue = 1;
	//ramp = 1;

	//Starting on blue floor
	blue = 1;
	ramp = 0;

	//Starting on red ramp
	//red = 1;
	//ramp = 1;

	//Starting on red floor
	//red = 1;
	//ramp = 0;

	//Redundancy to prevent freak errors in the program
	if(blue == 1)
		red = 0;
	if(red == 1)
		blue = 0;
}



task main()
{
	initializeRobot();          //Initialize robot
	StartTask(autonomousChooser);
	waitForStart();             //Importante!
	StopTask(autonomousChooser);
	startTask(emergency);       //Starts emergency task in case quick stop is needed
	autoType();                 //Manual preset input
	startPos();                 //Finds initial readings
	if(preset == 1)             //If the preset is determined to be 1
		presetOne();              //Then run the presetOne
	else if(preset == 2)        //If the preset is determined to be 2
		presetTwo();              //Then run the presetTwo
	else if(preset == 3)        //If the preset is determined to be 3
		presetThree();            //Then run the presetThree
	while(true){wait1Msec(10);} //Infinite loop until the end of autonomous period
}

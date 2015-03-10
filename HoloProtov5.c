#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S3,     HTGYRO,         sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorLeftPulleyT, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorManipulator, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorBL,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorFR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorRightPulley, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorBR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_2,     motorRightPulleyT, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S4_C1_1,    servoLeftBridge,      tServoStandard)
#pragma config(Servo,  srvo_S4_C1_2,    servoRightBridge,     tServoStandard)
#pragma config(Servo,  srvo_S4_C1_3,    servoRearGrabberR,    tServoStandard)
#pragma config(Servo,  srvo_S4_C1_4,    servoManipRight,      tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C1_5,    servoRearGrabberL,    tServoStandard)
#pragma config(Servo,  srvo_S4_C1_6,    servoManipLeft,       tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Establishing global variables
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
bool FLdone = false;
bool BLdone = false;
bool FRdone = false;
bool BRdone = false;
int y2 = 0;
int liftServoPos = 0;
bool autoLiftRunning = false;
bool stabilizing = false;
bool forceStopped = false;
int stabilizingVal = 0;
//int liftStick = 0;

#include "JoystickDriver.c"
#include "normalize.h"
#include "setServos.h"
#include "reset.h"
#include "lift.h"

void initializeRobot()
{
	nMotorEncoder[motorLeftPulleyT] = 1000;
	return;
} // end of initialization

void drop() //
{
	autoLiftRunning = true;
	if(autoLiftRunning)
	{
		motor[motorRightPulley] = 30;
		motor[motorRightPulleyT] = 30;
		//motor[motorLeftPulley] = 30;
		motor[motorLeftPulleyT] = 30;
		liftServoPos = 25;
		//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
		wait1Msec(15);
		while(autoLiftRunning && liftServoPos < 140)
		{
			liftServoPos += 5;
			/*servo[servoRightBridge] = liftServoPos;
			servo[servoLeftBridge] = 240 - liftServoPos;*/
			//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
			wait1Msec(75);
		}
	}
	int count = 0;
	while(autoLiftRunning && count < 40)
	{
		count++;
		wait1Msec(49);
	}
	while(autoLiftRunning && liftServoPos > 0)
	{
		liftServoPos -= 5;
		/*servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;*/
		//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
		wait1Msec(25);
	}
}

task isAutoLiftRunning() //Checks if autoLift is interrupted. Also controls lift servo movement
{
	while(true)
	{
		nxtDisplayCenteredBigTextLine(5,"%d",nMotorEncoder[motorLeftPulleyT]);
		if(liftServoPos > 140)
			liftServoPos = 140;
		else if(liftServoPos < 0)
			liftServoPos = 0;
		servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;
		if(abs(joy2y1) > 10 || joy2Btn(6) || joy2Btn(8))
		{
			forceStopped = true;
			autoLiftRunning = false;
		}
		wait1Msec(25);
	}
}

void autoLift(int autoLiftDist) //Method for automatically moving the lift up and down with possible driver interruptions
{
	bool finishedAll = false;
	autoLiftRunning = true;
	int time = autoLiftDist;
	int startVal = nMotorEncoder[motorLeftPulleyT];
	liftServoPos = 25;
	int temp = startVal + autoLiftDist;
	//int change = 0;
	clearTimer(T3);
	if(autoLiftRunning)
	{
		while(autoLiftRunning && nMotorEncoder[motorLeftPulleyT] < temp && time1(T3) < time)
		{
			motor[motorRightPulley] = 100;
			motor[motorRightPulleyT] = 100;
			//motor[motorLeftPulley] = 100;
			motor[motorLeftPulleyT] = 100;
			//startVal
			wait1Msec(20);
			writeDebugStreamLine("%d",nMotorEncoder[motorLeftPulleyT]);
		}
	}
	startTask(liftStabilizing);
	if(autoLiftRunning)
	{
		liftServoPos = 25;
		//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
		wait1Msec(15);
		while(autoLiftRunning && liftServoPos < 125)
		{
			liftServoPos += 5;
			/*servo[servoRightBridge] = liftServoPos;
			servo[servoLeftBridge] = 240 - liftServoPos;*/
			//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
			wait1Msec(50);
		}
	}
	int count = 0;
	while(autoLiftRunning && count < 40)
	{
		count++;
		wait1Msec(49);
	}
	while(autoLiftRunning && liftServoPos > 0)
	{
		liftServoPos -= 5;
		/*servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;*/
		//nxtDisplayCenteredBigTextLine(5,"%d",liftServoPos);
		wait1Msec(25);
	}
	stopTask(liftStabilizing);
	clearTimer(T3);
	while(autoLiftRunning && nMotorEncoder[motorLeftPulleyT] > startVal + 1000 && time1(T3) < time)
	{
		motor[motorRightPulley] = -100;
		motor[motorRightPulleyT] = -100;
		//motor[motorLeftPulley] = -100;
		motor[motorLeftPulleyT] = -100;
		wait1Msec(20);
	}
	if(autoLiftRunning)
		finishedAll = true;
	if(forceStopped || finishedAll)
	{
		motor[motorRightPulley] = 0;
		motor[motorRightPulleyT] = 0;
		//motor[motorLeftPulley] = 0;
		motor[motorLeftPulleyT] = 0;
	}
	wait1Msec(20);
	autoLiftRunning = false;
}

task moveLift() //Method that moves the lift up and down, as well as moving the lift servos
{
	while(true)
	{
		//Debugging code
		if(liftServoPos > 140) //Makes sure liftServoPos doesn't go above 140
			liftServoPos = 140;
		if(liftServoPos < 0) //Makes sure liftServPos doesn't go below 0
			liftServoPos = 0;
		if(abs(joy2y1) > 10) //If the liftStick is being used
		{
			stabilizing = false;
			motor[motorRightPulley] = joy2y1;
			motor[motorRightPulleyT] = joy2y1;
			//motor[motorLeftPulley] = joy2y1;
			motor[motorLeftPulleyT] = joy2y1;
			wait1Msec(35);
		}
		if(joy2Btn(6)) //Moves the lift servos down if Joy2 Top Right Trigger is pressed
		{
			stabilizing = false;
			liftServoPos -= 4;
			wait1Msec(8);
		}
		else if(joy2Btn(8)) //Moves the lift servos up if Joy2 Bottom Right Trigger is pressed
		{
			stabilizing = false;
			liftServoPos += 3;
			wait1Msec(8);
		}
		else if(joy2Btn(1)) //If the "X" button is pressed(joy2Btn1), run autoLift for the medium goal
		{
			stabilizing = false;
			autoLift(2800);
			wait1Msec(5);
		}
		else if(joy2Btn(2))
		{
			stabilizing = false;
			drop();
			wait1Msec(5);
		}
		else if(joy2Btn(3)) //If the "B" button is pressed(joy2Btn3), run autoLift for the tall goal
		{
			stabilizing = false;
			autoLift(4000);
			wait1Msec(5);
		}
		else if(joy2Btn(4)) //If the "Y" button is pressed(joy2Btn3), run autoLift for the center goal
		{
			stabilizing = false;
			autoLift(4500);
			wait1Msec(5);
		}
		else if(abs(joy2y1) < 10) //Auto lift is not running and no buttons are being pressed
		{
			motor[motorRightPulley] = 0;
			motor[motorRightPulleyT] = 0;
			//motor[motorLeftPulley] = 0;
			motor[motorLeftPulleyT] = 0;
			if(!stabilizing)
			{
				stabilizingVal = abs(nMotorEncoder[motorLeftPulleyT]);
				clearTimer(T4);
			}
			stabilizing = true;
			if(time1(T4) < 5000 && abs(nMotorEncoder[motorLeftPulleyT]) > 1500)
			{
				int change = stabilizingVal - abs(nMotorEncoder[motorLeftPulleyT]);
				if(change > 100)
				{
					motor[motorRightPulley] = 30;
					motor[motorRightPulleyT] = 30;
					//motor[motorLeftPulley] = 30;
					motor[motorLeftPulleyT] = 30;
				}
				else
				{
					motor[motorRightPulley] = 0;
					motor[motorRightPulleyT] = 0;
					//motor[motorLeftPulley] = 0;
					motor[motorLeftPulleyT] = 0;
				}
			}
			else
			{
				motor[motorRightPulley] = 0;
				motor[motorRightPulleyT] = 0;
				//motor[motorLeftPulley] = 0;
				motor[motorLeftPulleyT] = 0;
			}
			wait1Msec(20);
		}
		wait1Msec(15);
	}
	while(true){wait1Msec(20);}
}

task moveGrabber() //Moves the rear grabbers on the robot
{
	bool grabChoice = false; //True for
	if(grabChoice)
	{
		int dif = 127;
		while(true)
		{
			if(joy1Btn(6))
				dif+=10;
			if(joy1Btn(8))
				dif-=10;
			if(dif < 0)
				dif = 0;
			if(dif > 270)
				dif = 270;
			servo[servoRearGrabberR] = dif - 15;
			servo[servoRearGrabberL] = 255 - dif;
			//nxtDisplayCenteredBigTextLine(2,"%d",dif);
			wait1Msec(50);
		}
	}
	else
	{
		releaseGoal();
		while(true)
		{
			if(joy1Btn(6))
				grabGoal();
			if(joy1Btn(8))
				releaseGoal();
			///if(joy1Btn(7));
			  //tightenGoal();
			wait1Msec(50);
		}
	}
}

task HoloDrive() //Main taks for moving the robot
{
	getJoystickSettings(joystick);
	startTask(isAutoLiftRunning,10);
	startTask(moveLift); //Starts the task for moving the lift servos
	startTask(moveGrabber); //Start the task for moving the rear grabbers
	while(true)
	{
		writeDebugStreamLine("%d",nMotorEncoder[motorLeftPulleyT]);
		//Takes input from the joystick and sets variables to them
		getJoystickSettings(joystick);
		x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;
		y2 = joystick.joy1_y2;
		joy2y1 = joystick.joy2_y1;
		joy2y2 = joystick.joy2_y2;

		//Scales all the values to the 0-100 range of motor controllers
		x1 = x1 / 1.28;
		y1 = y1 / 1.28;
		x2 = x2 / 1.28;
		y2 = y2 / 1.28;
		joy2y1 = joy2y1 / 1.28;
		joy2y2 = joy2y2 / 1.28;

		//Formula for determining the wheel speeds based on the joystick position.
		FL = y1 + x1 + x2;
		BL = y1 - x1 + x2;
		FR = y1 - x1 - x2;
		BR = y1 + x1 - x2;

		normalize(); //Use normalize function to compensate for wheel values above 100 or below -100

		//Scaling motor values
		if(abs(x1) > 10 && abs(y1) > 10) //If the robot is strafing, run the wheels at full speed
		{
			FL = FL;
			BL = BL;
			FR = FR;
			BR = BR;
		}
		else if(joy1Btn(5)) //If the driver is pressing the speed up button, run at full speed
		{
			FL = FL;
			BL = BL;
			FR = FR;
			BR = BR;
		}
		else //Otherwise, run at 60% speed
		{
			FL = FL * 0.60;
			BL = BL * 0.60;
			FR = FR * 0.60;
			BR = BR * 0.60;
		}

		//Run the motors
		//This section checks
		if((abs(x2) >= 10) && (joy1Btn(3))) //Slow down button 1
		{
			motor[motorFL] = x2 / 5;
			motor[motorBL] = x2 / 5;
			motor[motorFR] = -x2 / 5;
			motor[motorBR] = -x2 / 5;
		}
		else if((abs(x2) >= 10) && (joy1Btn(2))) //Slower down button 2
		{
			motor[motorFL] = x2 / 3;
			motor[motorBL] = x2 / 3;
			motor[motorFR] = -x2 / 3;
			motor[motorBR] = -x2 / 3;
		}
		else if(abs(x2) >= 10) //Regular running speed
		{
			motor[motorFL] = x2;
			motor[motorBL] = x2;
			motor[motorFR] = -x2;
			motor[motorBR] = -x2;
		}
		else if((abs(x1) >= 10 || abs(y1) >= 10) && joy1Btn(2))
		{
			motor[motorFL] = FL / 2;
			motor[motorBL] = BL / 2;
			motor[motorFR] = FR / 2;
			motor[motorBR] = BR / 2;
		}
		else if((abs(x1) >= 10 || abs(y1) >= 10) && joy1Btn(3))
		{
			motor[motorFL] = FL / 3;
			motor[motorBL] = BL / 3;
			motor[motorFR] = FR / 3;
			motor[motorBR] = BR / 3;
		}
		else if(abs(x1) >= 10 || abs(y1) >= 10)
		{
			motor[motorFL] = FL;
			motor[motorBL] = BL;
			motor[motorFR] = FR;
			motor[motorBR] = BR;
		}
		else
		{
			motor[motorFL] = 0;
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
		}
		//Spins manipulator
		if(joy1Btn(5))
		{
			motor[motorManipulator] = 100;
		}
		else if(joy1Btn(7))
		{
			motor[motorManipulator] = -100;
		}
		else
		{
			motor[motorManipulator] = 0;
		}
		wait1Msec(5);
	}
}

task main()
{
	//initializeRobot();
	waitForStart();
	getJoystickSettings(joystick);
	//startTask(moveGrabber);
	//startTask(raiseLift);
	releaseGoal();
	startTask(HoloDrive);
	while(true){wait1Msec(5);}
} // End of task main

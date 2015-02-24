void grabGoalMoving() //Grab onto the rolling goal
{
	servo[servoRearGrabberR] = 180; //Grab onto the rolling goal
	servo[servoRearGrabberL] = 75;
}

void moveRobotR(float BLspeed, float BRspeed, float BLrot, float BRrot)
{
	doneReset();
	resetEncoders();
	float FLspeed = BRspeed;
	float FRspeed = BLspeed;
	float FRrot = BLrot;
	float FLrot = BRrot;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(BLrot * 1120))
		{
			motor[motorFR] = FRspeed;
			motor[motorBL] = BLspeed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			BLdone = true;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(BRrot * 1120))
		{
			motor[motorFL] = FLspeed;
			motor[motorBR] = BRspeed;
		}
		else
		{
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			FLdone = true;
			BRdone = true;
		}
	}
	stopMotors();
	doneReset();
}

void moveRobotBRamp(float speed, float rot)
{
	doneReset();
	resetEncoders();
	while(!BLdone)
	{
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 1120))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
	}
	stopMotors();
	doneReset();
}

void moveRobotBLGrabLate(float speed, float rot)
{
	doneReset();
	resetEncoders();
	int grabPoint = rot * 1120;
	grabPoint -= 400;
	bool grabbed = false;
	clearTimer(t2);
	while(!BLdone && time1(T2) < 3000)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) > abs(grabPoint))
		{
			grabbed = true;
			grabGoalMoving();
		}
	}
	if(!grabbed)
		grabGoalMoving();
	stopMotors();
	doneReset();
}

void moveRobotBLGrab(float speed, float rot)
{
	doneReset();
	resetEncoders();
	int grabPoint = rot * 1120;
	grabPoint -= 1000;
	bool grabbed = false;
	clearTimer(t2);
	while(!BLdone && time1(T2) < 3000)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) > abs(grabPoint))
		{
			grabbed = true;
			grabGoalMoving();
		}
	}
	if(!grabbed)
		grabGoalMoving();
	stopMotors();
	doneReset();
}

void moveRobotBLGrabLong(float speed, float rot)
{
	doneReset();
	resetEncoders();
	int grabPoint = rot * 1120;
	grabPoint -= 1000;
	bool grabbed = false;
	clearTimer(t2);
	while(!BLdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) > abs(grabPoint))
		{
			grabbed = true;
			grabGoalMoving();
		}
	}
	grabGoalMoving();
	stopMotors();
	doneReset();
}

void moveRobotBLRamp(float speed, float rot)
{
	doneReset();
	resetEncoders();
	while(!BLdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) > abs(rot * 1000))
		{
				servo[servoRearGrabberR] = 180; //Moves the servos slightly forward to make sure the ablls dont roll out
			servo[servoRearGrabberL] = 60;
		}
	}
	stopMotors();
	doneReset();
}

void moveRobotBR(float speed, float rot)
{
	doneReset();
	resetEncoders();
	while(!BLdone)
	{
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 840))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else if(abs(nMotorEncoder[motorBR]) < abs(rot * 1120))
		{
			motor[motorFR] = speed / 2;
			motor[motorBR] = speed / 2;
			motor[motorFL] = speed / 2;
			motor[motorBL] = speed / 2;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
	}
	stopMotors();
	doneReset();
	wait1Msec(500);
}

void moveRobotRotate(float BLspeed, float BRspeed, float BLrot, float BRrot)
{
	doneReset();
	resetEncoders();
	float FLspeed = BLspeed;
	float FRspeed = BRspeed;
	float FRrot = BRrot;
	float FLrot = BLrot;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(BLrot * 1120))
		{
			motor[motorFL] = FLspeed;
			motor[motorBL] = BLspeed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFL] = 0;
			BLdone = true;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(BRrot * 1120))
		{
			motor[motorFR] = FRspeed;
			motor[motorBR] = BRspeed;
		}
		else
		{
			motor[motorBR] = 0;
			motor[motorFR] = 0;
			FRdone = true;
			BRdone = true;
		}
	}
	stopMotors();
	doneReset();
}

void moveRobotBL(float speed, float rot)
{
	doneReset();
	resetEncoders();
	while(!BLdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 840))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorFR] = speed / 2;
			motor[motorBR] = speed / 2;
			motor[motorFL] = speed / 2;
			motor[motorBL] = speed / 2;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
	}
	stopMotors();
	doneReset();
	wait1Msec(500);
}

task liftStabilizingAndMoving()
{
	int blargl = abs(nMotorEncoder[motorRightPulley]);
	while(true)
	{
		int blargl2 = blargl - abs(nMotorEncoder[motorRightPulley]);
		if(blargl2 > 100)
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
		wait1Msec(100);
		nxtDisplayCenteredBigTextLine(2,"Stabilizing");
	}
}

void moveRobotLift(float speed, float rot, int height)
{
	doneReset();
	resetEncoders();
	bool liftDone = false;
	bool liftUpDone = false;
	bool liftRunning = false;
	bool dumpBalls1 = false;
	bool dumpBalls2 = false;
	bool dumpBalls3 = false;
	bool justDoneDumping = false;
	int liftServoPos = 25;
	clearTimer(T1);
	while(!BLdone || !liftDone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 840))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else if(abs(nMotorEncoder[motorBL]) < abs(rot * 1000))
		{
			motor[motorFR] = speed / 2;
			motor[motorBR] = speed / 2;
			motor[motorFL] = speed / 2;
			motor[motorBL] = speed / 2;
		}
		else if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			if(speed > 0)
				speed = 15;
			else
				speed = -15;
			motor[motorFR] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
			motor[motorBL] = speed;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BLdone = true;
		}
		if(!liftUpDone)
		{
			liftRunning = true;
			motor[motorRightPulley] = 100;
			motor[motorRightPulleyT] = 100;
			//motor[motorLeftPulley] = 100;
			motor[motorLeftPulleyT] = 100;
			wait1Msec(20);
			if(abs(nMotorEncoder(motorRightPulley)) > height)
				liftUpDone = true;
		}
		else if(!dumpBalls1)
		{
			justDoneDumping = true;
			if(liftRunning)
			{
				liftRunning = false;
				startTask(liftStabilizingAndMoving);
			}
			liftServoPos += 5;
			if(liftServoPos > 125)
				dumpBalls1 = true;
			servo[servoRightBridge] = liftServoPos;
			servo[servoLeftBridge] = 240 - liftServoPos;
			wait1Msec(75);
		}
		else if(!dumpBalls2)
		{
			if(justDoneDumping)
			{
				justDoneDumping = false;
				clearTimer(T1);
			}
			if(time1(T1) > 2000)
				dumpBalls2 = true;
		}
		else if(!dumpBalls3)
		{
			justDoneDumping = true;
			liftServoPos -= 5;
			if(liftServoPos <= 0)
			{
				liftServoPos = 0;
				dumpBalls3 = true;
			}
			servo[servoRightBridge] = liftServoPos;
			servo[servoLeftBridge] = 240 - liftServoPos;
			wait1Msec(25);
		}
		else if(!liftDone)
		{
			if(justDoneDumping)
			{
				justDoneDumping = false;
				stopTask(liftStabilizingAndMoving);
			}
			motor[motorRightPulley] = -100;
			motor[motorRightPulleyT] = -100;
			//motor[motorLeftPulley] = -100;
			motor[motorLeftPulleyT] = -100;
			wait1Msec(20);
			if(abs(nMotorEncoder(motorRightPulley)) < 1000)
				liftDone = true;
		}
		else
		{
			stopTask(liftStabilizingAndMoving);
			motor[motorRightPulley] = 0;
			motor[motorRightPulleyT] = 0;
			//motor[motorLeftPulley] = 0;
			motor[motorLeftPulleyT] = 0;
			liftDone = true;
			wait1Msec(20);
		}
	}
	motor[motorRightPulley] = 0;
	motor[motorRightPulleyT] = 0;
	//motor[motorLeftPulley] = 0;
	motor[motorLeftPulleyT] = 0;
	stopMotors();
	doneReset();
	wait1Msec(500);
}

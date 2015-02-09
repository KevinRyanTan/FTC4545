task liftStabilizing()
{
	int stabilizingVal = abs(nMotorEncoder[motorRightPulley]);
	while(true)
	{
		int change = stabilizingVal - abs(nMotorEncoder[motorRightPulley]);
		if(change > 100)
		{
			motor[motorRightPulley] = 30;
			motor[motorRightPulleyT] = 30;
			motor[motorLeftPulley] = 30;
			motor[motorLeftPulleyT] = 30;
		}
		else
		{
			motor[motorRightPulley] = 0;
			motor[motorRightPulleyT] = 0;
			motor[motorLeftPulley] = 0;
			motor[motorLeftPulleyT] = 0;
		}
	}
}

void autonomousLift(int height)
{
	nMotorEncoder[motorRightPulley] = 0;
	servo[servoRightBridge] = 25;
	servo[servoLeftBridge] = 255 - 25;
	clearTimer(T1);
	while(abs(nMotorEncoder(motorRightPulley)) < height && time1[T1] < 5000)
	{
		motor[motorRightPulley] = 100;
		motor[motorRightPulleyT] = 100;
		motor[motorLeftPulley] = 100;
		motor[motorLeftPulleyT] = 100;
		wait1Msec(20);
	}
	bool liftRunning = true;
	startTask(liftStabilizing);
	int liftServoPos = 25;
	while(liftServoPos < 125)
	{
		liftServoPos += 5;
		servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;
		wait1Msec(75);
	}
	wait1Msec(2000);
	while(liftServoPos > 0)
	{
		liftServoPos -= 5;
		servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;
		wait1Msec(25);
	}
	stopTask(liftStabilizing);
	wait1Msec(250);
	clearTimer(T1);
	while(abs(nMotorEncoder(motorRightPulley)) > 1000 && time1[t1] < 5000)
	{
		motor[motorRightPulley] = -100;
		motor[motorRightPulleyT] = -100;
		motor[motorLeftPulley] = -100;
		motor[motorLeftPulleyT] = -100;
		wait1Msec(20);
	}
	motor[motorRightPulley] = 0;
	motor[motorRightPulleyT] = 0;
	motor[motorLeftPulley] = 0;
	motor[motorLeftPulleyT] = 0;
	wait1Msec(500);
}

void autonomousLiftAgain(int height)
{
	nMotorEncoder[motorRightPulley] = 1000;
	servo[servoRightBridge] = 25;
	servo[servoLeftBridge] = 255 - 25;
	clearTimer(T1);
	while(abs(nMotorEncoder(motorRightPulley)) < height && time1[T1] < 5000)
	{
		motor[motorRightPulley] = 100;
		motor[motorRightPulleyT] = 100;
		motor[motorLeftPulley] = 100;
		motor[motorLeftPulleyT] = 100;
		wait1Msec(20);
	}
	bool liftRunning = true;
	startTask(liftStabilizing);
	int liftServoPos = 25;
	while(liftServoPos < 125)
	{
		liftServoPos += 5;
		servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;
		wait1Msec(75);
	}
	wait1Msec(2000);
	while(liftServoPos > 0)
	{
		liftServoPos -= 5;
		servo[servoRightBridge] = liftServoPos;
		servo[servoLeftBridge] = 240 - liftServoPos;
		wait1Msec(25);
	}
	stopTask(liftStabilizing);
	wait1Msec(250);
	clearTimer(T1);
	while(abs(nMotorEncoder(motorRightPulley)) > 1000 && time1[t1] < 5000)
	{
		motor[motorRightPulley] = -100;
		motor[motorRightPulleyT] = -100;
		motor[motorLeftPulley] = -100;
		motor[motorLeftPulleyT] = -100;
		wait1Msec(20);
	}
	motor[motorRightPulley] = 0;
	motor[motorRightPulleyT] = 0;
	motor[motorLeftPulley] = 0;
	motor[motorLeftPulleyT] = 0;
	wait1Msec(500);
}

void liftCenter()
{
	autonomousLift(7000);
}

void lift90()
{
	autonomousLift(5450);
}

void lift60()
{
	autonomousLift(3500);
}

void lift30()
{
	autonomousLift(1000);
}

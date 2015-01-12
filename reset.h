void initializeServos()
{
	servo[servoLeftBridge] = 240;
	servo[servoRightBridge] = 0;
}

void initializeLift()
{
	motor[motorLeftPulley] = 60;
	motor[motorRightPulley] = 60;
	wait1Msec(400);
	motor[motorLeftPulley] = 0;
	motor[motorRightPulley] = 0;
}

void doneReset()
{
	FLdone = false;
	BLdone = false;
	FRdone = false;
	BRdone = false;
}

void stopMotors()
{
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	motor[motorLeftPulley] = 0;
	motor[motorRightPulley] = 0;
}

void resetEncoders()
{
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorBR] = 0;
}

void clearScreen()
{
	nxtDisplayCenteredTextLine(1, "");
	nxtDisplayCenteredTextLine(2, "");
	nxtDisplayCenteredTextLine(3, "");
	nxtDisplayCenteredTextLine(4, "");
	nxtDisplayCenteredTextLine(5, "");
	nxtDisplayCenteredTextLine(6, "");
	nxtDisplayCenteredTextLine(7, "");
	nxtDisplayCenteredTextLine(8, "");
	nxtDisplayCenteredTextLine(9, "");
	nxtDisplayCenteredTextLine(10, "");
}

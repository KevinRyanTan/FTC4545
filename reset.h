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

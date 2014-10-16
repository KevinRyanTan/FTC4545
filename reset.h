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
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
}

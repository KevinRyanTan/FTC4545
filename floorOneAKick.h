void floorOneAKickForwardFL()
{
	nMotorEncoder[motorFL] = 0;
	while(nMotorEncoder[motorFL] < 560)
	{
		motor[motorFL] = 60;
	}
	motor[motorFL] = 0;
	bool FLdone = false;
}

void floorOneAKickForwardBL()
{
	nMotorEncoder[motorBL] = 0;
	while(nMotorEncoder[motorBL] < 560)
	{
		motor[motorBL] = 60;
	}
	motor[motorBL] = 0;
	BLdone = false;
}

void floorOneAKickForwardFR()
{
	nMotorEncoder[motorFR] = 0;
	while(nMotorEncoder[motorFR] < 560)
	{
		motor[motorFR] = 60;
	}
	motor[motorFR] = 0;
	BLdone = false;
}

void floorOneAKickForwardBR()
{
	nMotorEncoder[motorBR] = 0;
	while(nMotorEncoder[motorBR] < 560)
	{
		motor[motorBR] = 60;
	}
	motor[motorBR] = 0;
	BRdone = false;
}

void floorOneAKickBackwardFL()
{
	nMotorEncoder[motorFL] = 0;
	while(nMotorEncoder[motorFL] > 560)
	{
		motor[motorFL] = -60;
	}
	motor[motorFL] = 0;
	FLdone = false;
}

void floorOneAKickBackwardBL()
{

}

void floorOneAKickBackwardFR()
{

}

void floorOneAKickBackwardBR()
{

}

void moveRobot(int FLspeed, int BLspeed, int FRspeed, int BRspeed, int FLrot, int BLrot, int FRrot, int BRrot)
{
	doneReset();
	resetEncoders();
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorFL]) < abs(FLrot * 1440))
			motor[motorFL] = FLspeed;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < abs(BLrot * 1440))
			motor[motorBL] = BLspeed;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < abs(FRrot * 1440))
			motor[motorFR] = FRspeed;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(BRrot * 1440))
			motor[motorBR] = BRspeed;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
		//nxtDisplayCenteredTextLine(1, nMotorEncoder[motorFL]);

	}
	stopMotors();
	doneReset();
}

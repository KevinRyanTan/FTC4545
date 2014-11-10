void moveRobotR(float BLspeed, float BRspeed, float BLrot, float BRrot)
{
	doneReset();
	resetEncoders();
	float FLspeed = BRspeed;
	float FRspeed = BLspeed;
	float FRrot = BLrot;
	float FLrot = BRrot;
	bool FLdone = false;
	bool BLdone = false;
	bool FRdone = false;
	bool BRdone = false;
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

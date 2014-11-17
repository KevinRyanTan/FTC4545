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
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 350))
		{
			motor[motorFR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;
			motor[motorFL] = speed;
		}
		else if(abs(nMotorEncoder[motorBR]) < abs(rot * 700))
		{
			motor[motorFR] = speed / 3;
			motor[motorBR] = speed / 3;
			motor[motorFL] = speed / 3;
			motor[motorBL] = speed / 3;
		}
		else if(abs(nMotorEncoder[motorBR]) < abs(rot * 1120))
		{
			motor[motorFR] = speed / 5;
			motor[motorBR] = speed / 5;
			motor[motorFL] = speed / 5;
			motor[motorBL] = speed / 5;
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

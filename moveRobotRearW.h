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

void moveRobotBLGrab(float speed, float rot)
{
	doneReset();
	resetEncoders();
	int grabPoint = rot * 1120;
	grabPoint -= 1000;
	clearTimer(t2);
	while(!BLdone && time1(T2) < 5000)
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
			grabGoal();
		}
	}
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

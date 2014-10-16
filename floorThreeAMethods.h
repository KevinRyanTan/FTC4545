void floorThreeAAlignMover(int FLrot, int BLrot, int FRrot, int BRrot)
{
	doneReset();
	nMotorEncoder[motorFL] = 0;
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorFR] = 0;
	nMotorEncoder[motorBR] = 0;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorFL]) < abs(FLrot))
			motor[motorFL] = alignDir * -3;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < abs(BLrot))
			motor[motorBL] = alignDir * 3;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < abs(FRrot))
			motor[motorFR] = alignDir * 3;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(BRrot))
			motor[motorBR] = alignDir * -3;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
	}
	doneReset();
}


void floorThreeAAlign()
{
	irTotal = 0;
	for(int i = 0; i <= 25; i++)
	{
		_dirDC = HTIRS2readDCDir(HTIRS2);
		_dirAC = HTIRS2readACDir(HTIRS2);
		if(!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
			wait1Msec(0);
		if(!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4))
			wait1Msec(0);
		irTotal = irTotal + acS3 + dcS3;
		wait1Msec(5);
	}
	irMax = irTotal;
	moveRobot(-50,50,50,-50,2,2,2,2);//motor[motorFL] = -50;, motor[motorBL] = 50;, //motor[motorFR] = 50 //motor[motorBR] = -50
	while(final == 0)
	{
		doneReset();
		floorThreeAAlignMover(2,2,2,2);
		while(FLdone && BLdone && FRdone && BRdone)
		{
			wait1Msec(10);
		}// == 1 && BR
		wait1Msec(200);
		stopMotors();
		doneReset();
		irTotal = 0;
		for(int i = 0; i <= 25; i++)
		{
			_dirDC = HTIRS2readDCDir(HTIRS2);
			_dirAC = HTIRS2readACDir(HTIRS2);
			if(!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
				wait1Msec(0);
			if(!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4))
				wait1Msec(0);
			irTotal = irTotal + acS3 + dcS3;
			wait1Msec(5);
			//string output =  irTotal + "";
		}
		//writeDebugStreamLine("int x is %d", irTotal);
		//int temp = irTotal + 100;
		if(irMax > irTotal)
		{
			alignDir = alignDir * -1;
			count = count + 1;
		}
		else if(irMax < irTotal && count > 3)
		{
			final = 1;
		}
		else if(irTotalOld < irTotal)
		{
			irMax = irTotal;
			alignDir = alignDir;
		}
		else
		{
			alignDir = alignDir;
		}
	}
	moveSonar(20.0,60);
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	liftCenter();
}

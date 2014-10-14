void floorOneAAlignMover()
{
	doneReset();
	nMotorEncoder[motorFL] = 0;
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorFR] = 0;
	nMotorEncoder[motorBR] = 0;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorFL]) < 560)
			motor[motorFL] = alignDir * -3;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < 560)
			motor[motorBL] = alignDir * 3;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < 560)
			motor[motorFR] = alignDir * 3;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < 560)
			motor[motorBR] = alignDir * -3;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
	}
	doneReset();
}


void floorOneAAlign()
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
	floorOneAStrafe();//motor[motorFL] = -50;, motor[motorBL] = 50;, //motor[motorFR] = 50 //motor[motorBR] = -50
	while(final == 0)
	{
		doneReset();
		floorOneAAlignMover();
		while(FLdone && BLdone && FRdone && BRdone)
		{
			wait1Msec(10);
		}// == 1 && BR
		wait1Msec(200);
		motor[motorFL] = 0;
		motor[motorBL] = 0;
		motor[motorFR] = 0;
		motor[motorBR] = 0;
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
	while(ultsonar >= 20.0)
	{
		wait1Msec(5);
		motor[motorFL] = 20;
		motor[motorBL] = 20;
		motor[motorFR] = 20;
		motor[motorBR] = 20;
		wait1Msec(10);
		motor[motorFL] = 0;
		motor[motorBL] = 0;
		motor[motorFR] = 0;
		motor[motorBR] = 0;
		wait1Msec(50);
		ultsonar = SensorValue[Sonar];
	}
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	liftCenter();
}

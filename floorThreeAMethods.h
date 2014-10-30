void floorThreeAAlignMover(int rot)
{
	doneReset();
	resetEncoders();
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorFL]) < abs(rot * 280))
			motor[motorFL] = alignDir * -2;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 280))
			motor[motorBL] = alignDir * 2;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < abs(rot * 280))
			motor[motorFR] = alignDir * 2;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 280))
			motor[motorBR] = alignDir * -2;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
	}
	doneReset();
	stopMotors();
}


void floorThreeAAlign()
{
	alignDir = 20.0;
	float alignRot = 4;
	irMax = irTotal;
	//moveRobot(-50,50,50,-50,2,2,2,2);//motor[motorFL] = -50;, motor[motorBL] = 50;, //motor[motorFR] = 50 //motor[motorBR] = -50
	while(final == 0)
	{
		floorThreeAAlignMover(alignRot);
		stopMotors();
		wait1Msec(200);
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
		clearTimer(T2);
		if(time1[T2] > 10000)
			final = 1;
		else if(irMax > irTotal)
		{
			float temp5 = irMax - irTotal;
			temp5 = temp5 / 25;
			if(alignDir > 0)
				alignDir = temp5 * -1;
			else
				alignDir = temp5;
			count = count + 1;
			alignRot = alignRot * 0.5;
		}
		else if(irMax < irTotal && count > 2)
			final = 1;
		else if(irMax < irTotal)
		{
			irMax = irTotal;
			alignDir = alignDir;
		}
		else
			alignDir = alignDir;
	}
	moveSonar(20.0,60);
	stopMotors();
	liftCenter();
}

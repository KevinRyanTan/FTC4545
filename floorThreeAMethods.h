void floorThreeAAlignMover(float alignDir, int rot)
{
	doneReset();
	resetEncoders();
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorBL] = alignDir * 2;
			motor[motorFR] = alignDir * 2;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			BLdone = true;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 1120))
		{
			motor[motorBR] = alignDir * -2;
			motor[motorFL] = alignDir * -2;
		}
		else
		{
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BRdone = true;
			FLdone = true;
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
		//floorThreeAAlignMover(alignRot);
		stopMotors();
		wait1Msec(200);
		irTotal = 0;
		irTotal = readIR();
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
			int count = count + 1;
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
	stopMotors();
}

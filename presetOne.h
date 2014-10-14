void one()
{
	irDist = 0;
	irNear = 0;
	irMax = 0;
	if(blue == 1 && ramp == 1)
	{
		//run down the ramp, run through kickstand
	}
	else if(blue == 1 && ramp == 0 && option == 'a')
	{
		floorOneAKickForward();
		doneReset();
		wait1Msec(1000);
		floorOneAKickBackward();
		doneReset();
		int count = 0;
		count = count + 1;
		irTotal = 0;
		motor[motorFL] = 0;
		motor[motorBL] = 0;
		motor[motorFR] = 0;
		motor[motorBR] = 0;
		for(int i = 0; i <= 25; i++)
		{
			_dirDC = HTIRS2readDCDir(HTIRS2);
			_dirAC = HTIRS2readACDir(HTIRS2);
			if(!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
				wait1Msec(0);
			if(!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4))
				wait1Msec(0);
			irTotal = irTotal + acS3 + dcS4;
			wait1Msec(5);
		}
		ultsonar = SensorValue[Sonar];
		floorOneAAlign();
	}
	else if(blue == 1 && ramp == 0 && option == 2)
	{
		while(ultsonar >= 20.0)
		{
			doneReset();
			wait1Msec(5);
			moveSonar();
			while(FLdone && BLdone && FRdone && BRdone){wait1Msec(5);}
			wait1Msec(10);
			motor[motorFL] = 0;
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			ultsonar = SensorValue[Sonar];
			wait1Msec(50);
		}
		liftCenter();
		doneReset();
		floorOneBMove();

	}
}

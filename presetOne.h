void one()
{
	irDist = 0;
	irNear = 0;
	irMax = 0;
	if(blue == 1 && ramp == 1 && option == 'a')
	{
		//run down the ramp, run through kickstand
	}
	//Utilizes sensors
	//Starts on the right side of the box
	//1. Moves forwards and knocks over kickstand
	//2. Knocks over kickstand
	//3. Moves back to the box
	//4. Aligns with center goal using IR
	//5. Moves forward using Sonar
	//6. Drops ball in center goal
	//7. Ends program
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
			irTotal = irTotal + acS3 + dcS3;
			wait1Msec(5);
		}
		ultsonar = SensorValue[Sonar];
		floorOneAAlign();
	}
	//Relies on driver positioning
	//Starts across from center goal
	//1. Moves forwards
	//2. Lifts ball to goal
	//3. Moves left
	//4. Runs over kickstand
	//5. Ends program
	else if(blue == 1 && ramp == 0 && option == 2)
	{
		//1. Moves forwards
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
		//2. Lifts ball to goal
		liftCenter();
		doneReset();
		//3. Moves left and 4. Runs over kickstand
		floorOneBMove();
	}
}

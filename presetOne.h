void one()
{
	irDist = 0;
	irNear = 0;
	irMax = 0;
	if(blue == 1 && ramp == 1 && option == 'a')
	{
		//run down the ramp, run through kickstand
	}
	//Difficulty: 5 - MEDIUM
	//Utilizes sensors
	//Starts on the right side of the box
	//Baseball in lift, golf ball in basket
	//1. Moves forwards and knocks over kickstand
	//2. Moves back to the box
	//3. Aligns with center goal using IR
	//4. Moves forward using Sonar
	//5. Drops baseball in center goal
	//6. Ends program
	else if(blue == 1 && ramp == 0 && option == 'a')
	{ //1. Moves forwards and knocks over kickstand
		floorOneAKickForward();
		doneReset();
		wait1Msec(1000);
		//2. Moves back to the box
		floorOneAKickBackward();
		doneReset();
		int count = 0;
		count = count + 1;
		irTotal = 0;
		motor[motorFL] = 0;
		motor[motorBL] = 0;
		motor[motorFR] = 0;
		motor[motorBR] = 0;
		//3. Aligns with the center goal using IR
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
		//4. Moves forward using Sonar and 5. Drops ball in center goal
		floorOneAAlign();
		//6. Ends program
	}
	//Difficulty: 1 - EXTREMELY EASY
	//Relies on driver positioning
	//Starts across from center goal
	//Baseball in lift, golf ball in basket
	//1. Moves forwards using Sonar
	//2. Lifts ball to goal
	//3. Moves right
	//4. Runs over kickstand
	//5. Ends program
	else if(blue == 1 && ramp == 0 && option == 'c')
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
		//5. Ends program
	}
	//Difficulty: 9 - IMPOSSIBRU
	//Relies on driver positioning
	//Starts on left side of box
	//Baseball in basket, golf ball in lift
	//1. Moves forward-right
	//2. Moves forward
	//3. Turn 180 degrees
	//4. Latches onto rolling goal
	//5. Lifts golf ball into 45 inch rolling goal
	//6. Loads baseball into lift
	//7. Drags rolling goal to parking zone
	//8. Drops off parking zone
	//9. Aligns with IR beacon
	//10. Moves forward with the Sonar
	//11. Lifts baseball to center goal
	else if(blue == 1 && ramp == 0 && option == 'c')
	{
		floorOneCMove();
	}

}

void presetThree()
{
	//Resets some key values
	irDist = 0;
	irNear = 0;
	irMax = 0;
	//Option A of Starting position 3, Ramp
	//Difficulty: 7 - Oh boy
	//Relies on driver positioning
	//Starts on middle of ramp
	//Baseball second, golf ball first
	//1. Go and latch onto
	if(blue == 1 && ramp == 1 && option3 == 'a')
	{

	}
	//Option B of starting position 3, Ramp
	//Difficulty: 4 - Medium
	//Relies on sensors
	//Starts on middle of ramp
	//Baseball first, golf ball second
	//1.
	//2.
	//3.
	//4.
	else if(blue == 1 && ramp == 1 && option3 == 'b')
	{

	}
	//Option C of starting position 3, Ramp
	//Difficulty:
	//
	else if(blue == 1 && ramp == 1 && option3 == 'c')
	{

	}
	//Difficulty: 5 - MEDIUM
	//Utilizes sensors
	//Starts on the right side of the box
	//Baseball first, golf ball second
	//1. Finds initial IR reading
	//2. Aligns with center goal using IR
	//3. Drops baseball in center goal
	//4. Moves to the right
	//5. Runs into kickstand
	//6. Moves towards rolling goals
	//7. Ends program
	if(blue == 1 && ramp == 0 && option3 == 'a')
	{ //1. Finds initial IR reading
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
		//2. Aligns with center goal and 3. Drops baseball in center goal
		floorThreeAAlign();
		//4. Moves to the right
		moveRobot(60, -60, -60, 60, 2, 2, 2, 2);
		wait1Msec(1000);
		//5. Runs into the kickstand
		moveRobot(60, -60, -60, 60, 1, 1, 1, 1);
		//6. Moves towards rolling goals
		moveRobot(60, -60, -60, 60, 2, 2, 2, 2);
		doneReset();
		irTotal = 0;
		//7. Ends program
		stopMotors();
	}
	//Difficulty: 1 - EXTREMELY EASY
	//Relies on driver positioning
	//Starts across from center goal
	//Baseball first, golf ball second
	//1. Moves forwards using Sonar
	//2. Lifts ball to goal
	//3. Moves right
	//4. Runs over kickstand
	//5. Ends program
	else if(blue == 1 && ramp == 0 && option3 == 'b')
	{
		//1. Moves forwards
		moveSonar(20.0,60);
		//2. Lifts ball to goal
		liftCenter();
		doneReset();
		//3. Moves left and 4. Runs over kickstand
		moveRobot(0,0,0,0,0,0,0,0);
		//5. Ends program
	}
	//Difficulty: 9 - IMPOSSIBRU
	//Relies on driver positioning
	//Starts on left side of box
	//Baseball second, golf ball first
	//1. Moves forward-right
	//2. Moves forward
	//3. Turn 180 degrees
	//4. Latches onto rolling goal
	//5. Lifts golf ball into 45 inch rolling goal
	//6. Drags rolling goal to parking zone
	//7. Drops off rolling goal in parking zone
	//8. Aligns with IR beacon
	//9. Moves forward with the Sonar
	//10. Lifts baseball to center goal
	else if(blue == 1 && ramp == 0 && option3 == 'c')
	{
		//1. Moves forward-right and 2. Moves forward and 3. Turn 180 degrees
		moveRobot(0,0,0,0,0,0,0,0);
		moveRobot(0,0,0,0,0,0,0,0);
		moveRobot(0,0,0,0,0,0,0,0);
		//4. Latches onto rolling goal and 5. Lifts golf ball into 45 inch rolling goal
		floorThreeCLift(); // ???
		//6. Drags rolling goal to parking and 7. Drops off rolling goal in parking zone
		moveRobot(0,0,0,0,0,0,0,0);
		//8. Aligns with IR beacon
	}

}

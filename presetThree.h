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
	if(blue == 1 && ramp == 1 && optionRamp3 == 'a')
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
	else if(blue == 1 && ramp == 1 && optionRamp3 == 'b')
	{

	}
	//Option C of starting position 3, Ramp
	//Difficulty:
	//
	else if(blue == 1 && ramp == 1 && optionRamp3== 'c')
	{

	}
	//Difficulty: 5 - MEDIUM
	//Utilizes sensors
	//Starts on the right side of the box
	//Baseball first, golf ball second
	//1. Moves forwards and knocks over kickstand
	//2. Moves back to the box
	//3. Aligns with center goal using IR
	//4. Moves forward using Sonar
	//5. Drops baseball in center goal
	//6. Ends program
	if(blue == 1 && ramp == 0 && optionFloor3 == 'a')
	{ //1. Moves forwards and knocks over kickstand
		moveRobot(60, 60, 60, 60, 2, 2, 2,2);
		doneReset();
		wait1Msec(1000);
		//2. Moves back to the box
		moveRobot(60, 60, 60, 60, 2, 2, 2 ,2);
		doneReset();
		int count = 0;
		count = count + 1;
		irTotal = 0; //Resets irTotal for aligning
		stopMotors();
		//3. Aligns with the center goal using IR
		readIR();
		irTotal = irTotal + acS3 + dcS3;
		ultsonar = SensorValue[Sonar];
		//4. Moves forward using Sonar and 5. Drops ball in center goal
		floorThreeAAlign();
		//6. Ends program
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
	else if(blue == 1 && ramp == 0 && optionFloor3 == 'b')
	{
		//1. Moves forwards
		moveSonar(20.0,60);
		//2. Lifts ball to goal
		liftCenter();
		doneReset();
		//3. Moves left
		robotMover(0,0,0,0,0,0,0,0);
		//4. Runs over kickstand
		robotMover(0,0,0,0,0,0,0,0);
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
	else if(blue == 1 && ramp == 0 && optionFloor3 == 'c')
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

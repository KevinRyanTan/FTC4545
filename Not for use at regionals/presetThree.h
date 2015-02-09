void presetThreeFloorA()
{
	clearTimer(T1);
	//1. Finds initial IR reading
	irTotal = readIR();
	//2. Aligns with center goal
	floorThreeAAlign();
	moveRobotR(45, 45, 1, 1);
	//3. Drops baseball in center goal
	liftCenter();
	//4. Moves to the right
	moveRobotR(-45, 45, 2, 2);
	wait1Msec(1000);
	//Wait until 20 seconds has passed
	while(time1[T1] < 20000){wait1Msec(5);}
	//5. Runs into the kickstand
	moveRobotR(45, 45, 1, 1);
	wait1Msec(1000);
	//6. Moves towards rolling goals
	moveRobotR(-45, 60, 2, 2.66);
	//7. Ends program
	stopMotors();
}

void presetThreeFloorB()
{
	//1. Moves forwards
		//moveSonar(20.0,60);
		moveRobotR(45,45,2,2);
		//2. Lifts ball to goal
		liftCenter();
		//3. Moves right
		moveRobotR(45,45,2,2);
		//4. Runs over kickstand
		moveRobotR(50,50,2,2);
		//5. Ends program
		stopMotors();
}

void presetThree()
{
	irDist = 0;
	irNear = 0;
	irMax = 0;
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
	{
		presetThreeFloorA();
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
		presetThreeFloorB();
	}
}

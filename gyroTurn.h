void gyroTurn(int speed, int goal)
{
	float divisor = 1;
	if(goal < 0)
		speed *= -1;
	//Establishing divisor values
	/*if(goal > 0)
	{
		if(abs(goal) == 90)
			divisor = 2;
		else if(abs(goal) == 45)
			divisor = 2;
		else if(abs(goal) == 15)
			divisor = 2;
	}
	else
	{
		speed = speed * -1;
		if(abs(goal) == 90)
			divisor = 0.75;
		else if(abs(goal) == 45)
			divisor = 0.75;
		else if(abs(goal) == 15)
			divisor = 0.75;
	}*/
	clearScreen();
	int rotPos = 0;
	int num = 0;
	float rotVel = 0;
	float position = 0;
	wait1Msec(250);
	while(abs(position) < abs(goal))
	{
		//clearTimer(T3);
		position += HTGYROreadRot(HTGYRO) * (float)(20 / 1000.0);
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = -speed;
		motor[motorBR] = -speed;
		/*wait1Msec(100);
		num = time1(T3) / 1000;
		rotPos = HTGYROreadCal(HTGYRO);
		rotVel = HTGYROreadRot(HTGYRO);
		if(abs(rotVel) > 10)
		{
			rotVel = rotVel * divisor;
			position = position + rotVel / (1000 / time1(T3));
		}*/
		displayTextLine(2, "%4fi", position);
		displayTextLine(3, "%5i", HTGYROreadRot(HTGYRO));
		wait1Msec(20);
	}
	//int new1 = abs(goal) - 5;
	//int new2 = abs(goal) + 5
	//if(abs(position) > new1 && abs(position) < abs(new2))

	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	wait1Msec(500);
}

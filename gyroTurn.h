void gyroTurn(bool left, int speed, int goal)
{
	float divisor = 0;
	//Establishing divisor values
	//4.5???
	if(goal == 90)
		divisor = 1.35;
	else if(goal == 45)
		divisor = 3.2;
	else
		divisor = 1;
	clearScreen();
	int rotPos = 0;
	int num = 0;
	float rotVel = 0;
	int position = 0;
	if(left)
		speed = speed * -1;
	while(abs(position) < abs(goal))
	{
		clearTimer(T3);
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = -speed;
		motor[motorBR] = -speed;
		wait1Msec(100);
		num = time1(T3) / 1000;
		rotPos = HTGYROreadCal(HTGYRO);
		rotVel = HTGYROreadRot(HTGYRO);
		if(abs(rotVel) > 10)
		{
			rotVel = rotVel * divisor;
			position = position + rotVel / (1000 / time1(T3));
		}
		nxtDisplayCenteredTextLine(2, "position: %d", position);
	}
	//int new1 = abs(goal) - 5;
	//int new2 = abs(goal) + 5
	//if(abs(position) > new1 && abs(position) < abs(new2))

	stopMotors();
	wait1Msec(500);
}

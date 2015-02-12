void gyroTurn(int speed, int goal)
{
	float divisor = 1;
	if(goal < 0)
		speed *= -1;
	clearScreen();
	int rotPos = 0;
	float rotVel = 0;
	float position = 0;
	wait1Msec(250);
	while(abs(position) < abs(goal))
	{
		position += HTGYROreadRot(HTGYRO) * (float)(20 / 1000.0);
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = -speed;
		motor[motorBR] = -speed;
		wait1Msec(20);
	}
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	wait1Msec(500);
}

void gyroTurn(bool left, int speed, int goal)
{
	int rotPos = 0;
	int num = 0;
	int rotVel = 0;
	int position = 0;
	if(left)
		speed = speed * -1;
	rotPos = HTGYROstartCal(HTGYRO);
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
		position = position + (rotVel * num);
	}
	stopMotors();
}

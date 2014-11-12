void gyroTurn(bool left, int speed, float goal)
{
	int rotPos = 0;
	int num = 0;
	int rotVel = 0;
	if(left)
	{
		speed = speed * -1;
	}
	HTGYROstartCal(HTGYRO);
	while(position < goal)
	{
		HTGYROstartCal(HTGYRO);
		clearTimer(T3);
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = -speed;
		motor[motorBR] = -speed;
		wait1Msec(100);
		num = time1(T3) / 1000;
		rotVel = HTGYROreadRot(HTGYRO);
		position = position + (rotVel * num);
	}
	stopMotors();
	//int position = 0;
	//float rotPos = 0.0;
	//float rotVel = 0.0;
	//bool done;
	//if(left)
	//{
	//	speed = speed * -1;
	//}
	//	while(!done)
	//	{
	//		motor[motorFL] = speed;
	//		motor[motorBL] = speed;
	//		motor[motorFR] = -speed;
	//		motor[motorBR] = -speed;
	//		rotPos = HTGYROreadCal(HTGYRO);
	//		rotVel = HTGYROreadRot(HTGYRO);
	//		position = position + (rotVel  * .1);
	//		if((position < goal + 5) && (position < goal + 5))
	//			done = true;
	//		wait1Msec(100);
	//	}
	//	stopMotors();
	//	done = false;
	//	while(!done)
	//	{
	//		while(position > goal)
	//		{
	//			clearTimer(T3);
	//			motor[motorFL] = speed / -2;
	//			motor[motorBL] = speed / -2;
	//			motor[motorFR] = speed / 2;
	//			motor[motorBR] = speed / 2;
	//			rotPos = HTGYROreadCal(HTGYRO);
	//			rotVel = HTGYROreadRot(HTGYRO);
	//			rotVel = rotVel / time1[T3];
	//			rotVel = rotVel * 1000;
	//			position = position + rotVel;
	//		}
	//		stopMotors();
	//		while(position < goal)
	//		{
	//			motor[motorFL] = speed / 2;
	//			motor[motorBL] = speed / 2;
	//			motor[motorFR] =  speed / -2;
	//			motor[motorBR] = speed / -2;
	//			rotPos = HTGYROreadCal(HTGYRO);
	//			rotVel = HTGYROreadRot(HTGYRO);
	//			position = position + (rotVel  * .1);
	//		}
	//		stopMotors();
	//		if((position < goal + 0.5) && (position < goal + 0.5))
	//			done = true;
	//}
}

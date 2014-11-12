void liftCenter()
{
	playSound(soundBeepBeep);
	//play sound
	wait1Msec(5000);
}

void lift90()
{
	motor[motorLeftPulley] = 20;
	motor[motorRightPulley] = 20;
	wait1Msec(400);
	setServos(100);
	wait1Msec(300);
	stopMotors();
}

void lift60()
{
	motor[motorLeftPulley] = 20;
	motor[motorRightPulley] = 20;
	wait1Msec(400);
	setServos(100);
	wait1Msec(300);
	stopMotors();
}

void lift30()
{
	motor[motorLeftPulley] = 20;
	motor[motorRightPulley] = 20;
	wait1Msec(400);
	setServos(100);
	wait1Msec(300);
	stopMotors();
}

void lowerCenter()
{
	motor[motorLeftPulley] = -20;
	motor[motorRightPulley] = -20;
	wait1Msec(400);
	setServos(200);
	wait1Msec(200);
	stopMotors();
}

void lower90()
{
	motor[motorLeftPulley] = -20;
	motor[motorRightPulley] = -20;
	wait1Msec(400);
	setServos(200);
	wait1Msec(200);
	stopMotors();
}

void lower60()
{
	motor[motorLeftPulley] = -20;
	motor[motorRightPulley] = -20;
	wait1Msec(400);
	setServos(200);
	wait1Msec(200);
	stopMotors();
}

void lower30()
{
	motor[motorLeftPulley] = -20;
	motor[motorRightPulley] = -20;
	wait1Msec(400);
	setServos(200);
	wait1Msec(200);
	stopMotors();
}

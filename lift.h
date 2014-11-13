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
	nMotorEncoder[motorLeftPulley] = 0;
	nMotorEncoder[motorRightPulley] = 0;
	while(abs(nMotorEncoder[motorLeftPulley]) < 1300)
	{
		motor[motorLeftPulley] = 60;
		motor[motorRightPulley] = 60;
	}
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

void drop30()
{
	servo[servoLeftBridge] = 255;
	servo[servoRightBridge] = 0;
}

void undrop30()
{
	servo[servoLeftBridge] = 100;
	servo[servoRightBridge] = 155;
}

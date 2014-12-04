void liftCenter()
{
	nMotorEncoder[motorRightPulley] = 0;
	while(abs(nMotorEncoder[motorRightPulley]) < 4670)
	{
		motor[motorRightPulley] = 20;
		motor[motorLeftPulley] = 20;
	}
	motor[motorRightPulley] = 0;
	motor[motorLeftPulley] = 0;
	wait1Msec(500);
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
	motor[motorLeftPulley] = 100;
	motor[motorRightPulley] = 100;
	wait1Msec(1000);
	setServos(0);
	wait1Msec(750);
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
	wait1Msec(500);
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
	motor[motorLeftPulley] = -100;
	motor[motorRightPulley] = -100;
	wait1Msec(1000);
	setServos(200);
	wait1Msec(750);
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

void dumpCenter()
{
	servo[servoLeftBridge] = 255;
	servo[servoRightBridge] = 0;
	wait1Msec(500);
	servo[servoLeftBridge] = 0;
	servo[servoRightBridge] = 255;
	wait1Msec(500);
}

void dump30()
{
	servo[servoLeftBridge] = 255;
	servo[servoRightBridge] = 0;
}

void dump60()
{
	servo[servoLeftBridge] = 100;
	servo[servoRightBridge] = 155;
}

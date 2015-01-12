void liftCenter()
{
	nMotorEncoder[motorRightPulley] = 0;
	clearTimer(T1);
	while(abs(nMotorEncoder(motorRightPulley)) < 9500 && time1[T1] < 7500)
	{
		motor[motorRightPulley] = 100;
		motor[motorLeftPulley] = 100;
	}
	motor[motorRightPulley] = 30;
	motor[motorLeftPulley] = 30;
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
	wait1Msec(3000);
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
	nMotorEncoder[motorRightPulley] = 0;
	while(abs(nMotorEncoder[motorRightPulley]) < 8500)
	{
		motor[motorRightPulley] = -100;
		motor[motorLeftPulley] = -100;
	}
	motor[motorRightPulley] = 0;
	motor[motorLeftPulley] = 0;
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
	wait1Msec(3200);
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
	servo[servoLeftBridge] = 240;
	servo[servoRightBridge] = 0;
	wait1Msec(750);
	servo[servoLeftBridge] = 170;
	servo[servoRightBridge] = 70;
	wait1Msec(750);
	servo[servoLeftBridge] = 100;
	servo[servoRightBridge] = 140;
	wait1Msec(2500);
	servo[servoLeftBridge] = 170;
	servo[servoRightBridge] = 70;
	wait1Msec(750);
	servo[servoLeftBridge] = 240;
	servo[servoRightBridge] = 0;
	wait1Msec(1000);
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

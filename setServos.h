void setServos(int diff)
{
	servo[servoRightBridge] = 240 - diff;
	servo[servoLeftBridge] = diff;
}

void setMotors(int speed)
{
	motor[motorFL] = speed;
	motor[motorBL] = speed;
	motor[motorFR] = speed;
	motor[motorBR] = speed;
}

void hitKickstand()
{
	setMotors(60);
	wait1Msec(1000);
	setMotors(0);
}

void grabGoal(int diff) //Grab onto the rolling goal
{
	servo[servoRearGrabberR] = 240; //Grab onto the rolling goal
	servo[servoRearGrabberL] = 0;
}

void releaseGoal(int diff) //Release rolling goal
{
	servo[servoRearGrabberR] = 0;
	servo[servoRearGrabberL] = 240;
}
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

void grabGoal() //Grab onto the rolling goal
{
	servo[servoRearGrabberR] = 210; //Grab onto the rolling goal
	servo[servoRearGrabberL] = 45;
}

void releaseGoal() //Release rolling goal
{
	servo[servoRearGrabberR] = 75;
	servo[servoRearGrabberL] = 180;
}

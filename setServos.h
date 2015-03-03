void setServos(int diff)
{
	servo[servoRearGrabberR] = 240 - diff;
	servo[servoRearGrabberL] = diff;
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
	servo[servoRearGrabberR] = 235; //Grab onto the rolling goal
	servo[servoRearGrabberL] = 20;
}

void releaseGoal() //Release rolling goal
{
	servo[servoRearGrabberR] = 128;
	servo[servoRearGrabberL] = 127;
}

void tightenGoal()
{
	servo[servoRearGrabberR] = 255;
	servo[servoRearGrabberL] = 0;
}

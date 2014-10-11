task moveSonarFL()
{
	nMotorEncoder[motorFL] = 0;
	while(nMotorEncoder[motorFL] < 100)
	{
		motor[motorFL] = 40;
	}
	motor[motorFL] = 0;
	FLdone = false;
	stopTask(moveSonarFL);
}

task moveSonarBL()
{
	nMotorEncoder[motorBL] = 0;
	while(nMotorEncoder[motorBL] < 100)
	{
		motor[motorBL] = 40;
	}
	motor[motorBL] = 0;
	BLdone = false;
	stopTask(moveSonarBL);
}

task moveSonarFR()
{
	nMotorEncoder[motorFR] = 0;
	while(nMotorEncoder[motorFR] < 560)
	{
		motor[motorFR] = 60;
	}
	motor[motorFR] = 0;
	FRdone = false;
	stopTask(moveSonarFR);
}

task moveSonarBR()
{
	nMotorEncoder[motorBR] = 0;
	while(nMotorEncoder[motorBR] < 560)
	{
		motor[motorBR] = 60;
	}
	motor[motorBR] = 0;
	BRdone = false;
	stopTask(moveSonarBR);
}

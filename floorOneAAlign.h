void floorOneAAlign()
{
	doneReset();
	nMotorEncoder[motorFL] = 0;
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorFR] = 0;
	nMotorEncoder[motorBR] = 0;
	while(!FLdone && !BLdone && !FRdone && !BRdone)
	{
		if(abs(nMotorEncoder[motorFL]) < 560)
			motor[motorFL] = 60;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < 560)
			motor[motorBL] = 60;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < 560)
			motor[motorFR] = 60;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorB]) < 560)
			motor[motorBR] = 0;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
	}
	doneReset();
}

//Align the Front Left motor
task floorOneAAlignFL()
{
	nMotorEncoder[motorFL] = 0;
	while((abs(nMotorEncoder[motorFL])) < (abs(560 / count)))
		motor[motorFL] = alignDir * 3;
	motor[motorFL] = 0;
	FLdone = false;
	stopTask(floorOneAAlignFL);
}

//Align the Back Left motor
task floorOneAAlignBL()
{
	nMotorEncoder[motorBL] = 0;
	while((abs(nMotorEncoder[motorBL])) > (abs(560 / count)))
	{
		motor[motorBL] = alignDir * -3;
	}
	motor[motorBL] = 0;
	BLdone = false;
	stopTask(floorOneAAlignBL);
}

//Align the Front Right motor
task floorOneAAlignFR()
{
	nMotorEncoder[motorFR] = 0;
	while((abs(nMotorEncoder[motorFR])) > (abs(560 / count)))
	{
		motor[motorFR] = alignDir * -3;
	}
	motor[motorFR] = 0;
	FRdone = false;
	stopTask(floorOneAAlignFR);
}

//Align the Back Right motor
task floorOneAAlignBR()
{
	nMotorEncoder[motorBR] = 0;
	while((abs(nMotorEncoder[motorBR])) < (abs(560 / count)))
	{
		motor[motorBR] = alignDir * 3;
	}
	motor[motorBR] = 0;
	BRdone = false;
	stopTask(floorOneAAlignBR);
}

void moveSonar(float sonarDist, int speed)
{
	doneReset();
	resetEncoders();
	while(ultsonar >= 20.0)
	{
		if(abs(nMotorEncoder[motorFL]) < 560)
			motor[motorFL] = speed;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < 560)
			motor[motorBL] = speed;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < 560)
			motor[motorFR] = speed;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < 560)
			motor[motorBR] = speed;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
		ultSonar
	}
	doneReset();
}

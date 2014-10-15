void floorOneCMove()
{
	doneReset();
	nMotorEncoder[motorFL] = 0;
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorFR] = 0;
	nMotorEncoder[motorBR] = 0;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{

		if(abs(nMotorEncoder[motorFL]) < 840)
			motor[motorFL] = 80;
		else
		{
			motor[motorFL] = 0;
			FLdone = true;
		}
		if(abs(nMotorEncoder[motorBL]) < 280)
			motor[motorBL] = -40;
		else
		{
			motor[motorBL] = 0;
			BLdone = true;
		}
		if(abs(nMotorEncoder[motorFR]) < 280)
			motor[motorFR] = -40;
		else
		{
			motor[motorFR] = 0;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorB]) < 840)
			motor[motorBR] = 80;
		else
		{
			motor[motorBR] = 0;
			BRdone = true;
		}
	}
doneReset();
}

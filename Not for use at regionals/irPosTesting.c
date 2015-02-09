void irPosTesting()
{
	int alignDir = 40;
	bool FLdone = false;
	bool BLdone = false;
	bool FRdone = false;
	bool BRdone = false;
	nMotorEncoder[motorFL] = 0;
	nMotorEncoder[motorBL] = 0;
	nMotorEncoder[motorFR] = 0;
	nMotorEncoder[motorBR] = 0;
	while(!FLdone || !BLdone || !FRdone || !BRdone)
	{
		if(abs(nMotorEncoder[motorBL]) < abs(rot * 1120))
		{
			motor[motorBL] = alignDir * 2;
			motor[motorFR] = alignDir * 2;
		}
		else
		{
			motor[motorBL] = 0;
			motor[motorFR] = 0;
			BLdone = true;
			FRdone = true;
		}
		if(abs(nMotorEncoder[motorBR]) < abs(rot * 1120))
		{
			motor[motorBR] = alignDir * -2;
			motor[motorFL] = alignDir * -2;
		}
		else
		{
			motor[motorBR] = 0;
			motor[motorFL] = 0;
			BRdone = true;
			FLdone = true;
		}
	}
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	_dirDC = HTIRS2readDCDir(HTIRS2);
	_dirAC = HTIRS2readACDir(HTIRS2);
	//In the case of Preset 3
	if(_dirDC == 5)
	{
		motor[motorFL] = 50;
		motor[motorBL] = 50;
		motor[motorFR] = 50;
		motor[motorBR] = 50;
		wait1MSec(500);
		while(true)
		{
			motor[motorFL] = 50;
			motor[motorBL] = 50;
			motor[motorFR] = 50;
			motor[motorBR] = 50;
			wait1Msec(500);
			motor[motorFL] = -50;
			motor[motorBL] = -50;
			motor[motorFR] = -50;
			motor[motorBR] = -50;
			wait1Msec(500);
		}
	}
	//In the case of Preset 1
	else if(_dirDC == 0)
	{
		motor[motorFL] = -45;
		motor[motorBL] = 75;
		motor[motorFR] = 75;
		motor[motorBR] = -45;
		wait1Msec(750);
		motor[motorFL]  = 50;
		motor[motorBL] = 50;
		motor[motorFR] = -50;
		motor[motorBR] = -50;
		wait1Msec(50000);
	}
	//In the case of Preset 2
	else
	{
		while(true)
		{
			wait1Msec(50);
		}
	}
}

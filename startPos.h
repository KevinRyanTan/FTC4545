void startPos()
{
	_dirDC = HTIRS2readDCDir(HTIRS2);
	_dirAC = HTIRS2readACDir(HTIRS2);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5);
	irFar = acS3;
	irNear = dcS3;
	if(irNear >= 30 && irNear <= 60)
	{
		if(irNear <= 60 && irNear >= 55)
			irDist = 15;
		else if(irNear <= 55 && irNear >= 37)
			irDist = 20;
		else if(irNear <= 37 && irNear >= 30)
			irDist = 25;
	}
	else
	{
		if(irFar <= 200 && irFar >= 190)
			irDist = 15;
		else if(irFar <= 190 && irFar >= 188)
			irDist = 20;
		else if(irFar <= 188 && irFar >= 183)
			irDist = 30;
		else if(irFar <= 183 && irFar >= 172)
			irDist = 35;
		else if(irFar <= 172 && irFar >= 145)
			irDist = 40;
		else if(irFar <= 145 && irFar >= 137)
			irDist = 45;
		else if(irFar <= 137 && irFar >= 131)
			irDist = 50;
		else if(irFar <= 131 && irFar >= 120)
			irDist = 55;
		else if(irFar <= 120 && irFar >= 109)
			irDist = 60;
		else if(irFar <= 109 && irFar >= 100)
			irDist = 65;
		else if(irFar <= 100 && irFar >= 92)
			irDist = 70;
		else if(irFar <= 92 && irFar >= 90)
			irDist = 75;
		else if(irFar <= 90 && irFar >= 88)
			irDist = 80;
		else if(irFar <= 88 && irFar >= 85)
			irDist = 85;
		else if(irFar <= 85 && irFar >= 75)
			irDist = 90;
		else if(irFar <= 75 && irFar >= 67)
			irDist = 100;
		else if(irFar <= 67 && irFar >= 62)
			irDist = 105;
		else if(irFar <= 62 && irFar >= 56)
			irDist = 110;
		else
			irDist = -10;
	}
	if(ramp == 0)
	{
	if((_dirAC >= 4 && _dirAC <= 6 && _dirDC >= 4 && _dirDC <= 6))
	{
		preset = 1;
		num = 1;
	}
	else if(_dirAC == 0 && _dirDC == 0)
	{
		preset = 3;
		num = 1;
	}
	else
		preset = 2;
	}
	else
	{
		//dete


	}
}

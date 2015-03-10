int readIR()
{
	int num = 0;
	_dirDC = HTIRS2readDCDir(HTIRS2);
	_dirAC = HTIRS2readACDir(HTIRS2);
	HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
	HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4);
	return num;
}


int readIRNew(string output)
{
	float total = 0;
	float avg = 0;
	if(output == "acS2")
	{
		for(int i = 1; i < 6; i++)
		{
			_dirDC = HTIRS2readDCDir(HTIRS2);
			_dirAC = HTIRS2readACDir(HTIRS2);
			HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
			HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4);
			total += acS2;
			avg = total / i;
			wait1Msec(15);
		}
	}
	else if(output == "acS3")
	{
		for(int i = 1; i < 6; i++)
		{
			_dirDC = HTIRS2readDCDir(HTIRS2);
			_dirAC = HTIRS2readACDir(HTIRS2);
		HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
		HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4);
		total += acS3;
			avg = total / i;
			wait1Msec(15);
		}
	}
	else if(output == "acS4")
	{
		for(int i = 1; i < 6; i++)
		{
			_dirDC = HTIRS2readDCDir(HTIRS2);
			_dirAC = HTIRS2readACDir(HTIRS2);
		HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
		HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4);
		total += acS4;
			avg = total / i;
			wait1Msec(15);
		}
	}
	else if(output == "acSector")
	{
		for(int i = 1; i < 6; i++)
		{
			_dirAC = HTIRS2readACDIR(HTIRS2);
			total += _dirAC;
			avg = total / i;
			wait1Msec(15);
		}
	}
	return avg;
}

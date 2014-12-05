int readIR()
{
	int num = 0;
		_dirDC = HTIRS2readDCDir(HTIRS2);
		_dirAC = HTIRS2readACDir(HTIRS2);
		HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5);
		HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4);
	return num;
}

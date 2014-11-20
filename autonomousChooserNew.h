task autonomousChooserSimple()
{
	clearScreen();
	bool chooserDone = false;
	int ramp = -1;
	string display = "Ramp";
	int optionChoice = 0;
	clearScreen();
	while(!chooserDone)
	{
		nxtDisplayCenteredBigTextLine(4, Display);
		if(nNxtButtonPressed == 1)
		{
			optionChoice++;
			wait1Msec(500);
		}
		else if(nNxtButtonPressed == 2)
		{
			optionChoice--;
			wait1Msec(500);
		}
		else if(nNxtButtonPressed == 3)
			chooserDone = true;
		if(optionChoice > 1)
			optionChoice = 0;
		else if(optionChoice < 0)
			optionChoice = 1;
		if(optionChoice == 0)
			Display = "Ramp";
		else if(optionChoice == 1)
			Display = "Floor";
		}
		clearScreen();
		nxtDisplayCenteredTextLine(1, "Your final option is:");
		nxtDisplayCenteredBigTextLine(5, Display);
		if(optionChoice == 0)
			ramp = true;
		else if(optionChoice == 1)
			ramp = false;
		while(true){wait1Msec(100);}
}

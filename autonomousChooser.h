task autonomousChooser()
{
	bool chooserDone = false;
	string Display = "Floor";
	string Display1 = "yolo";
	string Display2 = "yolo";
	string Display3 = "yolo";
	int optionChoice = 1;
	bool Ramp = false;
	int RampOrFloor = 1;
	while(!chooserDone)
	{
		nxtDisplayCenteredTextLine(2, "Current Selected Option");
		nxtDisplayCenteredTextLine(3, Display);
		if(nNxtButtonPressed == 1)
		{
			RampOrFloor = RampOrFloor * -1;
			if(RampOrFloor > 0)
			{
				Display = "Ramp";
				Ramp = true;
				wait1Msec(500);
			}
			else
			{
				Display = "Floor";
				Ramp = false;
				wait1Msec(500);
			}
		}
		if(nNxtButtonPressed == 2)
		{
			RampOrFloor = RampOrFloor * -1;
			if(RampOrFloor > 0)
			{
				Display = "Ramp";
				Ramp = true;
				wait1Msec(500);
			}
			else
			{
				Display = "Floor";
				Ramp = false;
				wait1Msec(500);
			}
		}
		if(nNxtButtonPressed == 3)
		{
			chooserDone = true;
			wait1Msec(500);
		}
	}
	clearScreen();
	if(Ramp)
	{
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display1 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset One,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display1);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display1 = "Option A";
					optionRamp1 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display1 = "Option B";
					optionRamp1 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display1 = "Option C";
					optionRamp1 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display1 = "Option A";
					optionRamp1 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display1 = "Option B";
					optionRamp1 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display1 = "Option C";
					optionRamp1 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display2 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset Two,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display2);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display2 = "Option A";
					optionRamp2 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display2 = "Option B";
					optionRamp2 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display2 = "Option C";
					optionRamp2 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display2 = "Option A";
					optionRamp2 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display2 = "Option B";
					optionRamp2 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display2 = "Option C";
					optionRamp2 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display3 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset Three,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display3);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display3 = "Option A";
					optionRamp3 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display3 = "Option B";
					optionRamp3 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display3 = "Option C";
					optionRamp3 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display3 = "Option A";
					optionRamp3 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display3 = "Option B";
					optionRamp3 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display3 = "Option C";
					optionRamp3 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
	}
	else
	{
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display1 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset One,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display1);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display1 = "Option A";
					optionRamp1 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display1 = "Option B";
					optionRamp1 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display1 = "Option C";
					optionRamp1 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display1 = "Option A";
					optionRamp1 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display1 = "Option B";
					optionRamp1 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display1 = "Option C";
					optionRamp1 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display2 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset Two,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display2);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display2 = "Option A";
					optionRamp2 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display2 = "Option B";
					optionRamp2 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display2 = "Option C";
					optionRamp2 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display2 = "Option A";
					optionRamp2 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display2 = "Option B";
					optionRamp2 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display2 = "Option C";
					optionRamp2 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
		clearScreen();
		wait1Msec(1000);
		chooserDone = false;
		Display3 = "Option A";
		optionChoice = 1;
		while(!chooserDone)
		{
			nxtDisplayCenteredTextLine(2, "If the center goal");
			nxtDisplayCenteredTextLine(3, "is Preset Three,");
			nxtDisplayCenteredTextLine(4, "the Option is:");
			nxtDisplayCenteredTextLine(5, Display3);
			if(nNxtButtonPressed == 1)
			{
				optionChoice++;
				if(optionChoice == 4)
					optionChoice = 1;
				if(optionChoice == 1)
				{
					Display3 = "Option A";
					optionRamp3 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display3 = "Option B";
					optionRamp3 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display3 = "Option C";
					optionRamp3 = 'c';
				}
				wait1MSec(500);
			}
			if(nNxtButtonPressed == 2)
			{
				optionChoice--;
				if(optionChoice == 0)
					optionChoice = 3;
				if(optionChoice == 1)
				{
					Display3 = "Option A";
					optionRamp3 = 'a';
				}
				else if(optionChoice == 2)
				{
					Display3 = "Option B";
					optionRamp3 = 'b';
				}
				else if(optionChoice == 3)
				{
					Display3 = "Option C";
					optionRamp3 = 'c';
				}
				wait1Msec(500);
			}
			if(nNxtButtonPressed == 3)
			{
				chooserDone = true;
			}
		}
	}
	if(Ramp)
		Display = "Ramp";
	else
		Display = "Floor";
	clearScreen();
	nxtDisplayCenteredTextLine(0, "Final selection");
	nxtDisplayCenteredTextLine(1, Display);
	nxtDisplayCenteredTextLine(2, "Preset One:");
	nxtDisplayCenteredTextLine(3, Display1);
	nxtDisplayCenteredTextLine(4, "Preset Two");
	nxtDisplayCenteredTextLine(5, Display2);
	nxtDisplayCenteredTextLine(6, "Preset Three");
	nxtDisplayCenteredTextLine(7, Display3);
}

void normalize()
{
	if(abs(FL) >= abs(BL) && abs(FL) >= abs(FR) && abs(FL) >= abs(BR) && abs(FL) > 100)
		{
			num = abs(FL / 100);
			FL = FL / num;
			BL = BL / num;
			FR = FR / num;
			BR = BR / num;
		} // end of if
		if(abs(BL) >= abs(FL) && abs(BL) >= abs(FR) && abs(BL) >= abs(BR) && abs(BL) > 100)
		{
			num = abs(BL / 100);
			FL = FL / num;
			BL = BL / num;
			FR = FR / num;
			BR = BR / num;
		} // end of if
		if(abs(FR) >= abs(FL) && abs(FR) >= abs(BL) && abs(FR) >= abs(BR) && abs(FR) > 100)
		{
			num = abs(FR / 100);
			FL = FL / num;
			BL = BL / num;
			FR = FR / num;
			BR = BR / num;
		} // end of if
		if(abs(BR) >= abs(FL) && abs(BR) >= abs(BL) && abs(BR) >= abs(FR) && abs(BR) > 100)
		{
			num = abs(BR / 100);
			FL = FL / num;
			BL = BL / num;
			FR = FR / num;
			BR = BR / num;
		} // end of if
}

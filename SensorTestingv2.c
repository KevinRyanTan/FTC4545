#pragma config(Sensor, S2,     HTGYRO,              sensorAnalogInactive)
#pragma config(Sensor, S1,     HTIRS2,              sensorI2CCustom)
#pragma config(Sensor, S4,     Sonar,          sensorSONAR)
/*#pragma config(Motor,  mtr_S1_C1_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBL,       tmotorTetrix, openLoop)
//!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

//#include "drivers\JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "drivers\hitechnic-sensormux.h"
#include "drivers\hitechnic-irseeker-v2.h"
#include "drivers\hitechnic-gyro.h"

void initializeRobot()
{
	return;
}

task gyrosense()
{
	wait1Msec(500);
	float position = 0;
	eraseDisplay();
	time1[T1] = 0;
	while(true) {
		if (time1[T1] > 1000)
		{
			//eraseDisplay();
			//nxtDisplayTextLine(1, "Resetting");
			//nxtDisplayTextLine(1, "offset");
			wait1Msec(500);

			// Start the calibration and display the offset
			nxtDisplayTextLine(5, "Offset: %f", HTGYROstartCal(HTGYRO));
			position = 0;
			PlaySound(soundBlip);
			while(bSoundActive) EndTimeSlice();
			time1[T1] = 0;
		}

		while(nNxtButtonPressed != kEnterButton) {
			//eraseDisplay();
			//nxtDisplayTextLine(1, "Reading");
			float offset = HTGYROreadCal(HTGYRO);
			float rotVel = HTGYROreadRot(HTGYRO);
			nxtDisplayTextLine(5, "Offset: %4f", offset);
			nxtDisplayTextLine(4, "Gyro: %4f", rotVel);

			position = position + (rotVel  * .1);
			nxtDisplayTextLine(6, "Pos: %4f", position);
			wait1Msec(100);
		}
	}
}

task ultsense (){
	float ultsonar = 0;
	ultsonar = SensorValue[Sonar];
	nxtDisplayTextLine(1, "Sonar reading");
	nxtDisplayTextLine(2, "%2.2f", ultsonar);
}


task irsense(){
	while(true){
		tHTIRS2DSPMode _mode = DSP_1200;
		int _dirDC = 0;
		int _dirAC = 0;
		int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
		int acS1, acS2, acS3, acS4, acS5 = 0;

		_dirDC = HTIRS2readDCDir(HTIRS2);
		_dirAC = HTIRS2readACDir(HTIRS2);
		if(!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5))
			wait1Msec(5);
		if(!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS4))
			wait1Msec(5);

		nxtDisplayTextLine(3, "%d %d", acS3, dcS3);
	}
}

task main()
{
	initializeRobot();
	//waitForStart();
	startTask(irsense);
	//while(true)
	//{
	//startTask(ultsense);
	//startTask(gyrosense);
	while(true)
	{
		wait1Msec(100);
	}
	//}
}

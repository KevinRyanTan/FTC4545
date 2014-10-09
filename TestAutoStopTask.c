#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTGYRO,         sensorAnalogInactive)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     Sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motorBR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorFR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorManipulator, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)

void initializeRobot()
{
return;
}

task moveBlueOneFL()
{
	motor[motorFL] = 100;
	wait1Msec(5000);
	stopTask(moveBlueOneFL);
	motor[motorBR] = -100;
	wait1Msec(5000);
}

task main()
{
initializeRobot();
startTask(moveBlueOneFL);
while(true){}
}

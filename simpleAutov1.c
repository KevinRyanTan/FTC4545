#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTGYRO,         sensorAnalogInactive)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorNull,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeftPulley, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorRightPulley, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorManipulator, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C1_1,    servoRightBridge,     tServoStandard)
#pragma config(Servo,  srvo_S4_C1_6,    servoLeftBridge,           tServoStandard)

#include "moveRobotRearW.h"
#include "irPosTesting.h"
#include "floorThreeAMethods.h"

task(main)
{
	//Place robot on right side of parking zone
	//Move robot back and forth for Preset 3
	//Move front left and then spin for preset 2
	//Spin in place for preset 1
	irPosTesting();
	//This is the actual autonomous for Preset 3 only

	
}

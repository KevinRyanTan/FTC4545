void moveSonar(float sonarDist, int speed)
{
	doneReset();
	resetEncoders();
	while(ultsonar >= sonarDist)
	{
		resetEncoders();
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = speed;
		motor[motorBR] = speed;
		ultsonar = SensorValue[Sonar];
	}
	doneReset();
}

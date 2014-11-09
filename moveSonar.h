void moveSonar(float sonarDist, int speed)
{
	//ultsonar = SensorValue[Sonar];
	while(ultsonar >= sonarDist)
	{
		motor[motorFL] = speed;
		motor[motorBL] = speed;
		motor[motorFR] = speed;
		motor[motorBR] = speed;
		//ultsonar = SensorValue[Sonar];
	}
}

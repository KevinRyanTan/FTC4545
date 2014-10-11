//Stops the program if the back right bumper is pressed. For testing
void StopAll()
{
	stopAllTasks();
	motor[motorFL] = 0;
	motor[motorBL] = 0;
	motor[motorFR] = 0;
	motor[motorBR] = 0;
	while(true)
		wait1Msec(30000);
}

//Stops the program if the back right bumper is pressed
task emergency()
{
	while(!joy1Btn(8)){}
	StopAll();

}

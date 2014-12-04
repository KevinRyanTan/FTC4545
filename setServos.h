void setServos(int diff)
{
	servo[servoRightBridge] = 240 - diff;
	servo[servoLeftBridge] = diff;
}

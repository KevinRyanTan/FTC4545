void setServos(int diff)
{
	servo[servoRightBridge] = 255 - diff;
	servo[servoLeftBridge] = diff;
}

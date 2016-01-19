#include "OI.h"

OI::OI()
{
	leftStick = new Joystick(0);
	rightStick = new Joystick(1);
}

float OI::getRightStick(){
	return rightStick->GetY();
}

float OI::getLeftStick(){
	return leftStick->GetY();
}

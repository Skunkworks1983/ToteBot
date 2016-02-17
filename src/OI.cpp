#include "OI.h"

OI::OI() {
#if USING_GAMEPAD
	gamepad = new Joystick(0);
#else
	leftStick = new Joystick(0);
	rightStick = new Joystick(1);
#endif
}

float OI::getRightStick() {
#if USING_GAMEPAD
	return -gamepad->GetY();
#else
	return rightStick->GetY();
#endif
}

float OI::getLeftStick() {
#if USING_GAMEPAD
	return gamepad->GetAxis(Joystick::AxisType::kThrottleAxis);
#else
	return leftStick->GetY();
#endif
}

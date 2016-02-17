#ifndef OI_H
#define OI_H

#include "WPILib.h"
#define USING_GAMEPAD 1

class OI
{
private:
#if USING_GAMEPAD
	Joystick *gamepad;
#else
	Joystick *leftStick, *rightStick;
#endif
public:
	OI();
	float getLeftStick();
	float getRightStick();
};

#endif

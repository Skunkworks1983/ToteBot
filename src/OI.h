#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *leftStick, *rightStick;
public:
	OI();
	float getLeftStick();
	float getRightStick();
};

#endif

#ifndef DRIVE_BASE_H
#define DRIVE_BASE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Sensors/SkunkEncoder.h>

class DriveBase: public Subsystem
{
private:
	CANTalon *frontLeft, *frontRight, *backLeft, *backRight;
	SkunkEncoder *encFrontLeft, *encFrontRight, *encBackLeft, *encBackRight;
public:
	DriveBase();
	void InitDefaultCommand();
	void setSpeeds(float left, float right);
};

#endif

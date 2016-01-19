#include <CANTalon.h>
#include <Commands/TankDrive.h>
#include <RobotMap.h>
#include <Subsystems/DriveBase.h>

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	frontLeft = new CANTalon(FRONT_LEFT_MOTOR_CHANNEL);
	frontRight = new CANTalon(FRONT_RIGHT_MOTOR_CHANNEL);
	backLeft = new CANTalon(BACK_LEFT_MOTOR_CHANNEL);
	backRight = new CANTalon(BACK_RIGHT_MOTOR_CHANNEL);

	encFrontLeft = new SkunkEncoder(ENCODER_FRONT_LEFT_PORTS);
	encFrontLeft = new SkunkEncoder(ENCODER_FRONT_RIGHT_PORTS);
	encFrontLeft = new SkunkEncoder(ENCODER_BACK_LEFT_PORTS);
	encFrontLeft = new SkunkEncoder(ENCODER_BACK_RIGHT_PORTS);
}

void DriveBase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}


void DriveBase::setSpeeds(float left, float right){
	frontLeft->Set(left);
	frontRight->Set(right);
	backLeft->Set(left);
	backRight->Set(right);
}

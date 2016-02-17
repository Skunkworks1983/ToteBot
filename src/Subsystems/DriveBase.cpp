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

	frontLeft->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	frontRight->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	backLeft->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	backRight->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	/*
	encFrontLeft = new SkunkEncoder(ENCODER_FRONT_LEFT_PORTS, "encFrontLeft");
	encFrontRight = new SkunkEncoder(ENCODER_FRONT_RIGHT_PORTS, "encFrontRight");
	encBackLeft = new SkunkEncoder(ENCODER_BACK_LEFT_PORTS, "encBackLeft");
	encBackRight = new SkunkEncoder(ENCODER_BACK_RIGHT_PORTS, "encBackRight");
	*/
}

void DriveBase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}

int DriveBase::getEncoderTicks(EncoderLoc loc){
	switch(loc){
	case FRONT_LEFT:
		return encFrontLeft->GetPosition();
	case FRONT_RIGHT:
		return encFrontRight->GetPosition();
	case BACK_LEFT:
		return encBackLeft->GetPosition();
	case BACK_RIGHT:
		return encBackRight->GetPosition();
	}
	return 0;	//just to remove the warning
}

void DriveBase::setSpeeds(float left, float right){
	SmartDashboard::PutNumber("right front", right);

	frontLeft->Set(left);
	frontRight->Set(right);
	backLeft->Set(left);
	backRight->Set(right);
}

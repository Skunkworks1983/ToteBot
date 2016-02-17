#include <CommandBase.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <RobotBase.h>
#include <Subsystems/DriveBase.h>
#include <cstdio>


class Robot: public IterativeRobot {
private:
	int counter = 0;
public:

	void RobotInit() {
		CommandBase::init();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() {
		printf("DisabledInit Called\n");
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() {
		Scheduler::GetInstance()->RemoveAll();
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		Scheduler::GetInstance()->RemoveAll();
	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		if(counter++ > 10){
			printf("EncoderFrontLeft: %d\n", CommandBase::drivebase->getEncoderTicks(DriveBase::EncoderLoc::FRONT_LEFT));
			printf("EncoderFrontRight: %d\n", CommandBase::drivebase->getEncoderTicks(DriveBase::EncoderLoc::FRONT_RIGHT));
			printf("EncoderBackLeft: %d\n", CommandBase::drivebase->getEncoderTicks(DriveBase::EncoderLoc::BACK_LEFT));
			printf("EncoderBackRight: %d\n", CommandBase::drivebase->getEncoderTicks(DriveBase::EncoderLoc::BACK_RIGHT));
			counter = 0;
		}
	}

	void TestPeriodic() {
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <Commands/Scheduler.h>
#include <Commands/Subsystem.h>
#include <SmartDashboard/SmartDashboard.h>

OI Robot::oi_;
std::unordered_map<Robot::SubsystemType, InputSubsystem*,
				   std::hash<unsigned int>> Robot::components_;

void Robot::RobotInit()
{
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	m_autonomousCommand = m_chooser.GetSelected();

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

InputSubsystem* Robot::getSubsystem(Robot::SubsystemType subsystem)
{
	return components_[subsystem];
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)

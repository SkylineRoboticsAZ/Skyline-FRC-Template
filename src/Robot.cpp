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

OI Robot::m_oi;
std::unordered_map<unsigned int, frc::Subsystem*> Robot::components_;

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

frc::Subsystem* Robot::getComponent(Robot::Component component)
{
	return components_[component];
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)

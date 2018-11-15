/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <Commands/Subsystem.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include <unordered_map>

#include "OI.h"

class Robot : public frc::TimedRobot
{
public:
	enum Component : unsigned int
	{
		DriveTrain
	};

	static OI m_oi;
	static frc::Subsystem* getComponent(Component component);

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	static std::unordered_map<unsigned int, frc::Subsystem*> components_;

	frc::Command* m_autonomousCommand = nullptr;
	frc::SendableChooser<frc::Command*> m_chooser;
};

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

#include "OperatorInterface/OI.h"
#include "Extensions/InputSubsystem.h"

class OI;

class Robot : public frc::TimedRobot
{
public:
	enum SubsystemType : unsigned int
	{
		DriveTrain
	};

	static OI oi_;
	static InputSubsystem* getSubsystem(Robot::SubsystemType subsystem);

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	static std::unordered_map<Robot::SubsystemType, InputSubsystem*,
							  std::hash<unsigned int>> components_;

	frc::Command* m_autonomousCommand = nullptr;
	frc::SendableChooser<frc::Command*> m_chooser;
};

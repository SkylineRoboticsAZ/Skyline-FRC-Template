/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() : primaryJoystick_(1)
{
	//DriveTrain Configuration
	InputSubsystem *driveTrain = Robot::getSubsystem(Robot::DriveTrain);
	driveTrain->bindInput(0, primaryJoystick_.getOutput(JoystickOutput::XAxis));

	bindControl(Robot::getSubsystem(Robot::DriveTrain),
			    Robot::DriveTrain,
				primaryJoystick_.getOutput(JoystickOutput::XAxis));
}

void OI::bindControl(InputSubsystem *subsystem,
				     unsigned int input,
			         std::shared_ptr<OutputDevice> output)
{
	subsystem->bindInput(input, output);
}

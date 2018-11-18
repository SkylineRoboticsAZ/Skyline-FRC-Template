/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Robot.h"
#include "Interfaces/OutputDevice.h"
#include "Extensions/InputSubsystem.h"
#include "OIJoystick.h"

#include <memory>

class OI {
public:
	OI();

	void bindControl(InputSubsystem *subsystem,
				     unsigned int input,
			         std::shared_ptr<OutputDevice> output);

private:
	OIJoystick primaryJoystick_;
};

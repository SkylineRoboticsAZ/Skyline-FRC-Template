/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Robot.h"
#include "Interfaces/OutputDevice.h"

#include <unordered_map>
#include <memory>
#include <Joystick.h>

class OI {
public:
	enum Input : unsigned int
	{
		Input1, Input2
	};

	OI();

	void setInput(Input input, std::shared_ptr<OutputDevice> output);
	std::shared_ptr<OutputDevice> getInput(Input input);

	double readInput(Input input) const;

private:
	std::unordered_map<Input, std::shared_ptr<OutputDevice>,
	                   std::hash<unsigned int>> controls_;

	frc::Joystick primaryJoystick_;
};

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <iostream>

OI::OI() : primaryJoystick_(1)
{

}

void OI::setInput(Input input, std::shared_ptr<OutputDevice> output)
{
	controls_[input] = output;
}

std::shared_ptr<OutputDevice> OI::getInput(Input input)
{
	return controls_[input];
}

double OI::readInput(Input input) const
{
	try {
		return controls_.at(input)->getOutput();
	} catch (...) {
		std::cerr << "Error while reading input " << input <<
				" returning default value of 0" << std::endl;
		return 0;
	}
}

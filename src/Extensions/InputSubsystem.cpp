/*
 * InputSubsystem.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: Ian
 */

#include "InputSubsystem.h"

InputSubsystem::InputSubsystem(const llvm::Twine &name) : frc::Subsystem(name)
{
}

void InputSubsystem::bindInput(unsigned int input, std::shared_ptr<OutputDevice> output)
{
	controls_[input] = output;
}

double InputSubsystem::readInput(unsigned int input) const
{
	try {
		const std::shared_ptr<OutputDevice> output = controls_.at(input);

		if (output.get() != nullptr)
			return output->getOutput();
	} catch (std::out_of_range &exception) {}

	throw InputNotBound(this, input);
}

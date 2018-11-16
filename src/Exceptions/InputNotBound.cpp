/*
 * InputNotBound.cpp
 *
 *  Created on: Nov 15, 2018
 *      Author: Ian
 */

#include <Exceptions/InputNotBound.h>

InputNotBound::InputNotBound(const frc::Subsystem* subsystem, unsigned int input) :
subsystem_(subsystem), input_(input)
{
}

std::string InputNotBound::message() const
{
	std::stringstream stream;
	stream << "Input #" << input_ << "in subsystem " <<
			subsystem_->GetName() << " has no associated output!";
	return stream.str();
}

const frc::Subsystem* InputNotBound::subsystem() const
{
	return subsystem_;
}

unsigned int InputNotBound::input() const
{
	return input_;
}

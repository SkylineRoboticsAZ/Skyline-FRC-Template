/*
 * InputNotBound.h
 *
 *  Created on: Nov 15, 2018
 *      Author: Ian
 */

#pragma once

#include <Commands/Subsystem.h>

#include <Exception>
#include <sstream>
#include <String>

class InputNotBound
{
public:
	InputNotBound(const frc::Subsystem* subsystem, unsigned int input);

	std::string message() const;
	const frc::Subsystem* subsystem() const;
	unsigned int input() const;

private:
	const frc::Subsystem* subsystem_;
	unsigned int input_;
};

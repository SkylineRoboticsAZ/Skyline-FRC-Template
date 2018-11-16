/*
 * InputSubsystem.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Ian
 */

#pragma once

#include <memory>
#include <unordered_map>
#include <Commands/Subsystem.h>

#include "Interfaces/OutputDevice.h"
#include "Exceptions/InputNotBound.h"

class InputSubsystem : public frc::Subsystem
{
public:
	InputSubsystem(const llvm::Twine &name);

	void bindInput(unsigned int input, std::shared_ptr<OutputDevice> output);
	double readInput(unsigned int input) const;

private:
	std::unordered_map<unsigned int, std::shared_ptr<OutputDevice>> controls_;
};

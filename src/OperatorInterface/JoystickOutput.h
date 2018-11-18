/*
 * JoystickOutput.h
 *
 *  Created on: Nov 16, 2018
 *      Author: Ian
 */

#pragma once

#include <Joystick.h>
#include <memory>

#include "Interfaces/OutputDevice.h"

class JoystickOutput : public OutputDevice {
public:
	enum Control : unsigned int
	{
		XAxis
	};

	static std::shared_ptr<JoystickOutput> create(frc::Joystick *joystick, Control control);

	JoystickOutput(frc::Joystick *joystick, Control control);

	double getOutput() const;

private:
	frc::Joystick *joystick_;
	Control control_;
};


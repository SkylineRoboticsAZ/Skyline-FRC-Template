/*
 * OIJoystick.h
 *
 *  Created on: Nov 16, 2018
 *      Author: Ian
 */

#pragma once

#include <Joystick.h>

#include "OperatorInterface/JoystickOutput.h"

class OIJoystick {
public:
	OIJoystick(int port);

	std::shared_ptr<JoystickOutput> getOutput(JoystickOutput::Control control);

private:
	frc::Joystick joystick_;
};


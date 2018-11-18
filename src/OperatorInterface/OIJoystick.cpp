/*
 * OIJoystick.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Ian
 */

#include <OperatorInterface/OIJoystick.h>

OIJoystick::OIJoystick(int port) : joystick_(port)
{
}

std::shared_ptr<JoystickOutput> OIJoystick::getOutput(JoystickOutput::Control control)
{
	return JoystickOutput::create(&joystick_, control);
}

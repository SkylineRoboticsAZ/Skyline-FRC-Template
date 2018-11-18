/*
 * JoystickOutput.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Ian
 */

#include <OperatorInterface/JoystickOutput.h>

std::shared_ptr<JoystickOutput> JoystickOutput::create(frc::Joystick *joystick, Control control)
{
	return std::make_shared<JoystickOutput>(joystick, control);
}

JoystickOutput::JoystickOutput(frc::Joystick *joystick, Control control) :
joystick_(joystick), control_(control)
{}

//TO-DO Insert code that converts a friendly enum name into wpilib joystick calls
double getOutput() const
{

}

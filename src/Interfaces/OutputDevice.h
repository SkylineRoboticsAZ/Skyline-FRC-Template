/*
 * OutputDevice.h
 *
 *  Created on: Nov 15, 2018
 *      Author: Ian
 */

#pragma once

class OutputDevice {
public:
	virtual ~OutputDevice() {}

	virtual double getOutput() const = 0;
};

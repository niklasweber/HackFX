/*
 * Fader.h
 *
 *  Created on: 03 Nov 2019
 *      Author: Niklas Weber
 */

#ifndef Fader_h
#define Fader_h

#include <Arduino.h>
//#include <SimpleKalmanFilter.h>

class Fader
{ 
private:
	static const int adcPin = A0;

	uint8_t id;
	int value = 0;
	int last_value = 0;
//	SimpleKalmanFilter simpleKalmanFilter;
  
public:
//	Fader(uint8_t ID) :id(ID), simpleKalmanFilter(2, 2, 0.5) {}
	Fader(uint8_t ID) :id(ID) {}
	uint8_t getId();
	void read();
	int getValue();
	int getLastValue();
	uint8_t changed();
};

#endif

/*
 * Fader.cpp
 *
 *  Created on: 03 Nov 2019
 *      Author: Niklas Weber
 */

#include "Fader.h"

void Fader::read()
{
//	int readCount = 4;
//	int avg = 0;
//
//	for(int i=0; i<readCount; i++)
//	{
//		avg += map(analogRead(adcPin), 0, 1023, 0, 127);
//	}
//	avg = avg / readCount;
//
	last_value = value;
//	value = avg;

	value = analogRead(adcPin);
//  value = simpleKalmanFilter.updateEstimate(val) / 1024.0 * 128.0;
//  value = simpleKalmanFilter.updateEstimate(val / 1024.0 * 128.0);
//	value = val / 1024.0 * 128.0;
}

uint8_t Fader::changed()
{
  if(value != last_value)
    return 1;
  else
    return 0;
}

uint8_t Fader::getId()
{
  return id;
}

int Fader::getValue()
{
  return value;
}

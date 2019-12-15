/*
 * FaderMux.cpp
 *
 *  Created on: 10 Oct 2019
 *      Author: Niklas Weber
 * 
 * Multiplexers on board: ST HCF4052BE 
 */

#include "Arduino.h"
#include "FaderMux.h"

/**
 * FaderMux constructor. Sets faderId corresponding to array index.
 */
FaderMux::FaderMux()
{
	ptrFaderValChanged = nullptr;
	for(unsigned int i=0; i<=counterMax; i++)
	{
		fader[i] = new Fader(i);
	}
}

/**
 *	FaderMux de-constructor. Deletes all fader objects.
 */
FaderMux::~FaderMux()
{
	for(unsigned int i=0; i<=counterMax; i++)
	{
		delete fader[i];
	}
}

/**
 * Initializes the fader multiplexer. Sets pin directions, resets the counter and reads all initial values.
 */
void FaderMux::init()
{
	pinMode(clockPin, OUTPUT);
	pinMode(resetPin, OUTPUT);
	digitalWrite(clockPin, HIGH);

	// Hack to initially read first value. Pretend we are at the last position in order to go to the first.
	counter = counterMax;

	//Read all faders once to get an initial value.
	for(unsigned int i=0; i<=counterMax; i++)
	{
		readNext();
	}
}

/**
 * Resets the fader multiplexer counter back to zero.
 */
void FaderMux::reset()
{
	digitalWrite(resetPin, HIGH);
	digitalWrite(resetPin, LOW);
	digitalWrite(clockPin, HIGH);
	counter = 0;
}

/**
 * Clocks counter to select the next fader. Sets clock pin low and high. Clock is active low.
 */
int FaderMux::clock()
{
	digitalWrite(clockPin, LOW);
	digitalWrite(clockPin, HIGH);
	return ++counter;
}

/**
 * Maps the current multiplexer counter to the corresponding fader number.
 * A counter is used to select the address of the multiplexer. This way only one pin is needed
 * which is clocked to select the next multiplexer channel. The board layout does not correspond
 * to the way the faders are connected to the multiplexer. For example if the top left fader was fader 1,
 * it does not mean it can be selected by multiplexer address 1. Instead multiplexer address 1 might be fader 10.
 * The faderMap array is used to map the multiplexer counter / address to the corresponding board layout fader number.
 */
int FaderMux::mapMuxCounterToFaderNum()
{
	if(counter > counterMax || counter > (sizeof faderMap / sizeof faderMap[0]) )
		return -1;
	else
		return faderMap[counter];
}

/**
 * Reads the current fader value and saves it to the mapped fader.
 * Calls callback function in case the value changed.
 */
Fader* FaderMux::readValue()
{
	int faderNum = mapMuxCounterToFaderNum();

	if(faderNum < 0 || faderNum > (long int)counterMax)
		return nullptr;

	fader[faderNum]->read();

	/* Call callback when fader value changed passing fader object. */
	if(fader[faderNum]->changed()){
		(*ptrFaderValChanged)(fader[faderNum]);
	}

	return fader[faderNum];
}

/**
 * Reads the next fader value. Clocks/counts up the multiplexer counter and reads the fader analog value.
 */
Fader* FaderMux::readNext()
{
	if(counter+1 > counterMax)
		reset();
	else
		clock();

	return readValue();
}

/**
 * Returns the fader with Id faderId.
 */
Fader* FaderMux::get(unsigned int faderId)
{
	if(faderId > counterMax)
		return nullptr;
	else
		return fader[faderId];
}

/**
 *	Fader value changed callback. Called when a fader value changes.
 *	A pointer of the corresponding fader is included. The identity can be checked using faderId.
 *	Needs to be registered during setup.
 */
void FaderMux::registerFaderChangedCallBack(void (*ptrFValCh)(Fader*))
{
	ptrFaderValChanged = ptrFValCh;
}

/* Create object directly in class file, to conveniently use it just like e.g. Arduino Serial Library */
FaderMux faderMux;

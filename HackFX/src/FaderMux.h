/*
 * FaderMux.h
 *
 *  Created on: 10 Oct 2019
 *      Author: Niklas Weber
 */

#ifndef FADERMUX_H_
#define FADERMUX_H_

#include "Fader.h"

class FaderMux
{
private:
	static const int resetPin = A2;
	static const int clockPin = A3;
	static const unsigned int counterMax = 63;

	/* The index represents the current number of the FaderMux counter.
	 * The corresponding value represents the fader that is selected.
	 * Value is 0-indexed. E.g. Physical fader 1 is 0. 2 is 1...
	 * -1 means, no fader is connected. */
	const int faderMap[64] =   {30,24,38,32,46,40,54,48,
								29,27,37,35,45,43,53,51,
								28,25,36,33,44,41,52,49,
								31,26,39,34,47,42,-1,50,
								6, 0, 14,8, 22,16,-1,-1,
								5, 3, 13,11,21,19,-1,-1,
								4, 1, 12,9, 20,17,-1,-1,
								7, 2, 15,10,23,18,-1,-1};

	/* The current number output by the binary counter IC. */
	unsigned int counter = 0;

	/* All fader values */
	Fader *fader[counterMax+1];

	int clock();
	int mapMuxCounterToFaderNum();
	Fader* readValue();

	/* Callback when a fader value changed */
	void (*ptrFaderValChanged)(Fader*);
public:
	FaderMux();
	~FaderMux();
	void init();
	void reset();
	Fader* readNext();
	Fader* get(unsigned int faderId);
	void registerFaderChangedCallBack(void (*ptrFValCh)(Fader*));
};

extern FaderMux faderMux;

#endif /* FADERMUX_H_ */

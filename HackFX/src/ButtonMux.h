/*
 * ButtonMux.h
 *
 *  Created on: 16 Nov 2019
 *      Author: Niklas Weber
 * 
 *  Buttons and speed encoders (Multiplexers: F MM74HC165N)
 * 
 */

#ifndef BUTTONMUX_H_
#define BUTTONMUX_H_

class ButtonMux
{
private:
    static const int dataPin = 0;   //(Licon pin 52) (MISO PIN) Pin Serial Ouput QH
    static const int clockPin = 0;  //(Licon pin 51) (SCK PIN) Pin Shift Register Clock
    static const int loadPin = 0;   //(Licon pin 50) Pin SHIFT/LOAD

    // Button *rotaryEncoder; //Speed controller
    // Button *outer_knob; //Speed controller
    // Button *buttons[BUTTON_COUNT];

    // void readButtons();
    // void checkButtonValues();
    // void (*ptrButtonPressed)(Button*);
    // void (*ptrButtonReleased)(Button*);

    // TODO: readNext();
public:
    // TODO: constructor, deconstructor
    // TODO: init
    // TODO: reset
    // TODO: readNext();
    // TODO: get();
    // TODO: void registerButtonPressedCallBack(void (*ptrBtnPrsd)(Button*));
    // TODO: void registerButtonReleasedCallBack(void (*ptrBtnRlsd)(Button*));
};

extern ButtonMux buttonMux;

#endif /* BUTTONMUX_H_ */

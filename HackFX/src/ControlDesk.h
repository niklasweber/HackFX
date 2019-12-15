#ifndef ControlDesk_h
#define ControlDesk_h

#include <Arduino.h>
#include "board_positions.h"
#include "Button.h"

/*
 * Board: JBE088 v1.1
 */

/*
 * LEDs (Multiplexers: F MM74HC595N)
 */
//#define LED_MUX_SCK 52  //(Licon pin 46) (SCK PIN) Pin Shift Register Clock Input
//#define LED_MUX_DATA 51 //(Licon pin 49) (MOSI PIN) Pin Serial Data in
  #define LED_MUX_RCK 53  //(Licon pin 47) (SS Pin) Pin Storage Regiser Clock Input
  #define LED_MUX_OE 49   //(Licon pin 48) Pin Output Enable

/*
 * Buttons and speed encoders (Multiplexers: F MM74HC165N)
 */
//#define BUTTON_MUX_DATA 50    //(Licon pin 52) (MISO PIN) Pin Serial Ouput QH
//#define BUTTON_MUX_CLK 52     //(Licon pin 51) (SCK PIN) Pin Shift Register Clock
  #define BUTTON_MUX_LOAD 48    //(Licon pin 50) Pin SHIFT/LOAD
  
//#define BUTTON_MUX_INPUT_B 47 //(Licon pin 19) Pin Parallel Input B???

#define DESKLAMP_TRANSISTOR 46  //(Licon pin 3) Pin has to support PWM
#define POWER_LED_TRANSISTOR 44 //(Licon pin 2) <-------- careful! short circuit when power button pressed???

#define BUTTON_COUNT 71

class CControlDesk
{
  //Read analog val X times and get average
  const int analogNoiseReduction = 10;
  
  uint8_t leds[32]; //32 bits for 32 LEDs.
  Button *rotaryEncoder; //Speed controller
  Button *outer_knob; //Speed controller
  Button *buttons[BUTTON_COUNT];

  void switchPotRow(uint8_t row);
  void switchMuxChannel(byte ch);
  void writeLEDs();
  void readButtons();
  void readPots();
  void checkPotValues();
  void checkButtonValues();
  void (*ptrButtonPressed)(Button*);
  void (*ptrButtonReleased)(Button*);
  
  public:
  CControlDesk();
  void registerButtonPressedCallBack(void (*ptrBtnPrsd)(Button*));
  void registerButtonReleasedCallBack(void (*ptrBtnRlsd)(Button*));
  void update();
  void setDeskLamp(uint8_t br);
  void setLed(uint8_t led, uint8_t br);
  uint8_t getLed(uint8_t led);
};

extern CControlDesk ControlDesk;

#endif

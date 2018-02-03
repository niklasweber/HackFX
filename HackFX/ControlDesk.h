#ifndef ControlDesk_h
#define ControlDesk_h

#include <Arduino.h>
#include "board_positions.h"
#include "Pot.h"
#include "Button.h"

/*
 * Board: JBE088 v1.1
 */

/*
 * Potentiometers (Multiplexers: ST HCF4052BE) 
 */

#if defined(__AVR_ATmega2560__)

#define COMMON_X_1 A0 //(Licon pin 53) channel X output of chip 1 or 4 (depending on INH_L & INH_U)
#define COMMON_X_2 A1 //(Licon pin 54) channel X output of chip 2 or 5 (depending on INH_L & INH_U)
#define COMMON_X_3 A2 //(Licon pin 55) channel X output of chip 3 or 6 (depending on INH_L & INH_U)
#define COMMON_X_4 A3 //(Licon pin 56) channel X output of chip 7 (depending on INH_L & INH_U)

#define COMMON_Y_1 A4 //(Licon pin 13) channel Y output of chip 1 or 4 (depending on INH_L & INH_U)
#define COMMON_Y_2 A5 //(Licon pin 12) channel Y output of chip 2 or 5 (depending on INH_L & INH_U)
#define COMMON_Y_3 A6 //(Licon pin 11) channel Y output of chip 3 or 6 (depending on INH_L & INH_U)
#define COMMON_Y_4 A7 //(Licon pin 10) channel Y output of chip 7 (depending on INH_L & INH_U)

#define MUX_A A8      //(Licon pin 9) Channel select A
#define MUX_B A9      //(Licon pin 57) Channel select B

#define INH_U A10     //(Licon pin 58) inhibit pin for upper row (active low)
#define INH_L A11     //(Licon pin 8) inhibit pin for lower row (active low)

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

/*
 * Display
 */

#define D_BACKLIGHT_LED 4

#define D_D0      //(Licon pin )
#define D_D1      //(Licon pin )
#define D_D2      //(Licon pin )
#define D_D3      //(Licon pin )
#define D_D4      //(Licon pin )
#define D_D5      //(Licon pin )
#define D_D6      //(Licon pin )
#define D_D7      //(Licon pin )

#define D_READ    //(Licon pin ) (active low) Data Bus = output
#define D_WRITE   //(Licon pin ) (active low) Data Bus = input
#define D_A0      //(Licon pin ) (Also called RS) HIGH = Display Data, LOW = Control Data
#define D_RESET   //(Licon pin ) (active low) Reset all registers
#define D_CS1     //(Licon pin ) Chip Select (active low)

#endif


#define POT_COUNT 55
#define BUTTON_COUNT 71

class CControlDesk
{
  //Read analog val X times and get average
  const int analogNoiseReduction = 10;
  
  uint8_t leds[32]; //32 bits for 32 LEDs.
  Button *rotaryEncoder; //Speed controller
  Button *outer_knob; //Speed controller
  Button *buttons[BUTTON_COUNT];
  Pot *pots[POT_COUNT];

  void switchPotRow(uint8_t row);
  void switchMuxChannel(byte ch);
  void writeLEDs();
  void readButtons();
  void readPots();
  void checkPotValues();
  void checkButtonValues();
  void (*ptrButtonPressed)(Button*);
  void (*ptrButtonReleased)(Button*);
  void (*ptrPotValChanged)(Pot*);
  
  public:
  CControlDesk();
  void registerButtonPressedCallBack(void (*ptrBtnPrsd)(Button*));
  void registerButtonReleasedCallBack(void (*ptrBtnRlsd)(Button*));
  void registerPotChangedCallBack(void (*ptrPValCh)(Pot*));
  void update();
  void setDeskLamp(uint8_t br);
  void setLed(uint8_t led, uint8_t br);
  uint8_t getLed(uint8_t led);
};

extern CControlDesk ControlDesk;

#endif

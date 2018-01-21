#ifndef ControlDesk_h
#define ControlDesk_h

#include <Arduino.h>
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





#if defined(__AVR_ATmega328P__) //Just for debugging. Actually not enough pins / Analog inputs

#define COMMON_X_1 A0 //(Licon pin 53) channel X output of chip 1 or 4 (depending on INH_L & INH_U)
#define COMMON_X_2 A1 //(Licon pin 54) channel X output of chip 2 or 5 (depending on INH_L & INH_U)
#define COMMON_X_3 A2 //(Licon pin 55) channel X output of chip 3 or 6 (depending on INH_L & INH_U)
#define COMMON_X_4 A3 //(Licon pin 56) channel X output of chip 7 (depending on INH_L & INH_U)

#define COMMON_Y_1 A4 //(Licon pin 13) channel Y output of chip 1 or 4 (depending on INH_L & INH_U)
#define COMMON_Y_2 A5 //(Licon pin 12) channel Y output of chip 2 or 5 (depending on INH_L & INH_U)
#define COMMON_Y_3 A5 //(Licon pin 11) channel Y output of chip 3 or 6 (depending on INH_L & INH_U)
#define COMMON_Y_4 A5 //(Licon pin 10) channel Y output of chip 7 (depending on INH_L & INH_U)

#define MUX_A 2       //(Licon pin 9) Channel select A
#define MUX_B 3       //(Licon pin 57) Channel select B

#define INH_U 4      //(Licon pin 58) inhibit pin for upper row (active low)
#define INH_L 7      //(Licon pin 8) inhibit pin for lower row (active low)

/*
 * LEDs (Multiplexers: F MM74HC595N)
 */
//#define LED_MUX_SCK 13  //(Licon pin 46) (SCK PIN) Pin Shift Register Clock Input
//#define LED_MUX_DATA 11 //(Licon pin 49) (MOSI PIN) Pin Serial Data in
  #define LED_MUX_RCK 10  //(Licon pin 47) (SS Pin) Pin Storage Regiser Clock Input
  #define LED_MUX_OE 9    //(Licon pin 48) Pin Output Enable

/*
 * Buttons and speed encoders (Multiplexers: F MM74HC165N)
 */
//#define BUTTON_MUX_DATA 12    //(Licon pin 52) (MISO PIN) Pin Serial Ouput QH
//#define BUTTON_MUX_CLK 13     //(Licon pin 51) (SCK PIN) Pin Shift Register Clock
  #define BUTTON_MUX_LOAD 8     //(Licon pin 50) Pin SHIFT/LOAD
  
//#define BUTTON_MUX_INPUT_B   //(Licon pin 19) Pin Parallel Input B???

#define DESKLAMP_TRANSISTOR 6  //(Licon pin 3) Pin has to support PWM
#define POWER_LED_TRANSISTOR 5 //(Licon pin 2) <-------- careful! short circuit when power button pressed???


#endif






#define LED_AC1 0
#define LED_AC2 1
#define LED_AC3 2
#define LED_AC4 7
#define LED_BC1 8
#define LED_BC2 9
#define LED_BC3 10
#define LED_BC4 15
#define LED_CC1 3
#define LED_CC2 4
#define LED_CC3 5
#define LED_CC4 6
#define LED_DC1 11
#define LED_DC2 12
#define LED_DC3 13
#define LED_DC4 14
#define LED_GO 20
#define LED_TIME_R 21
#define LED_TIME_G 22
#define LED_SYNC 16
#define LED_DIR_R 17
#define LED_DIR_G 18
#define LED_SOUND 19
#define LED_LEARN 23
#define LED_MODE_A_R 24
#define LED_MODE_A_G 25
#define LED_MODE_B_R 26
#define LED_MODE_B_G 31
#define LED_BLACKOUT 27
#define LED_DISPLAY_1 30
#define LED_DISPLAY_2 29
#define LED_SWAP 28,
#define LED_ONOFF

//61,62,63,67,68,69,70(inverted),
//(speed controller inner)X,X,
//(speed controller outer)X,X,X,X,X,X,
//56,57,58,59,54,53,52,60,48,49,50,51,66,65,65,55,17,18,19,20,16,23,22,21,
//40,41,42,43,47,46,45,44,9,10,11,12,8,15,14,13,32,33,34,35,39,38,37,36,5,
//6,7,4,3,2,1,0,24,25,26,27,31,30,29,28
#define BUTTON_A1
#define BUTTON_A2
#define BUTTON_A3
#define BUTTON_A4
#define BUTTON_A5
#define BUTTON_A6
#define BUTTON_A7
#define BUTTON_A8
#define BUTTON_AC1
#define BUTTON_AC2
#define BUTTON_AC3
#define BUTTON_AC4
#define BUTTON_B1
#define BUTTON_B2
#define BUTTON_B3
#define BUTTON_B4
#define BUTTON_B5
#define BUTTON_B6
#define BUTTON_B7
#define BUTTON_B8
#define BUTTON_BC1
#define BUTTON_BC2
#define BUTTON_BC3
#define BUTTON_BC4
#define BUTTON_C1
#define BUTTON_C2
#define BUTTON_C3
#define BUTTON_C4
#define BUTTON_C5
#define BUTTON_C6
#define BUTTON_C7
#define BUTTON_C8
#define BUTTON_CC1
#define BUTTON_CC2
#define BUTTON_CC3
#define BUTTON_CC4
#define BUTTON_D1
#define BUTTON_D2
#define BUTTON_D3
#define BUTTON_D4
#define BUTTON_D5
#define BUTTON_D6
#define BUTTON_D7
#define BUTTON_D8
#define BUTTON_DC1
#define BUTTON_DC2
#define BUTTON_DC3
#define BUTTON_DC4
#define BUTTON_GO_M
#define BUTTON_GO_P
#define BUTTON_GO
#define BUTTON_SYNC
#define BUTTON_DIR
#define BUTTON_SOUND
#define BUTTON_RESTART
#define BUTTON_SELECT
#define BUTTON_LEARN
#define BUTTON_SEC_A
#define BUTTON_SEC_B
#define BUTTON_MAIN
#define BUTTON_MODE_A
#define BUTTON_MODE_B
#define BUTTON_BLACKOUT
#define BUTTON_DISPLAY_1
#define BUTTON_DISPLAY_2
#define BUTTON_DISPLAY_3
#define BUTTON_DISPLAY_4
#define BUTTON_ESC
#define BUTTON_SWAP
#define BUTTON_ONOFF

#define SPEEDCONTROL_OUTER
#define SPEEDCONTROL_INNER

#define POT_A1 25
#define POT_A2 41
#define POT_A3 49
#define POT_A4 33
#define POT_A5 40
#define POT_A6 32
#define POT_A7 24
#define POT_A8 48
#define POT_AC1 27
#define POT_AC2 43
#define POT_AC3 51
#define POT_AC4 35
#define POT_B1 42
#define POT_B2 34
#define POT_B3 26
#define POT_B4 50
#define POT_B5 29
#define POT_B6 45
#define POT_B7 53
#define POT_B8 37
#define POT_BC1 44
#define POT_BC2 36
#define POT_BC3 28
#define POT_BC4 52
#define POT_C1 1
#define POT_C2 13
#define POT_C3 19
#define POT_C4 7
#define POT_C5 12
#define POT_C6 6
#define POT_C7 0
#define POT_C8 18
#define POT_CC1 3
#define POT_CC2 15
#define POT_CC3 21
#define POT_CC4 9
#define POT_D1 14
#define POT_D2 8
#define POT_D3 2
#define POT_D4 20
#define POT_D5 5
#define POT_D6 17
#define POT_D7 23
#define POT_D8 11
#define POT_DC1 16
#define POT_DC2 10
#define POT_DC3 4
#define POT_DC4 22
#define POT_TIME 31
#define POT_SEC_A 47
#define POT_SEC_B 55
#define POT_MAIN 39
#define POT_AUX1 46
#define POT_AUX2 38
#define POT_AUX3 30
#define POT_NOT_USED 54

#define POT_COUNT 56
#define BUTTON_COUNT 71

class CControlDesk
{
  //Read analog val X times and get average
  const int analogNoiseReduction = 10;
  
  uint32_t leds; //32 bits for 32 LEDs.
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
  
  public:
  CControlDesk();
  void update();
  void setDeskLamp(uint8_t br);
  void setLed(uint8_t led, uint8_t br);
  //uint8_t getButton(uint8_t button);
  //uint16_t getPot(uint8_t pot);
  
  //void registerButtonPressedCallBack();
  //void registerButtonReleasedCallBack();
  //void registerFaderChangedCallBack();
  //void registerKnobChangedCallBack();
};

extern CControlDesk ControlDesk;

#endif

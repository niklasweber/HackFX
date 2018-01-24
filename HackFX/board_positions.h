#ifndef board_positions_h
#define board_positions_h

/*
 * LEDs
 * 
 * Shift register order
 * +------------------------------------------------------------
 * | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
 * +------------------------------------------------------------
 * |     |     |     |     |     |     |     |     |     |     |
 * +------------------------------------------------------------
 */
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

/*
 * Buttons
 * 
 * Shift register order
 * +------------------------------------------------------------
 * | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
 * +------------------------------------------------------------
 * |     |     |     |     |     |     |     |     |     |     |
 * +------------------------------------------------------------
 */
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

/*
 * Pots
 * 
 * Shift register order
 * +-----------------------------------------------------------+
 * | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
 * +------------------------------------------------------------
 * | C7  | C1  | D3  | CC1 | DC3 | D5  | C6  | C4  | D2  | CC4 |
 * +-----------------------------------------------------------+
 * 
 * +-----------------------------------------------------------+
 * | 11  | 12  | 13  | 14  | 15  | 16  | 17  | 18  | 19  | 20  |
 * +------------------------------------------------------------
 * | DC2 | D8  | C5  | C2  | D1  | CC2 | DC1 | D6  | C8  | C3  |
 * +-----------------------------------------------------------+
 * 
 * +-----------------------------------------------------------+
 * | 21  | 22  | 23  | 24  | 25  | 26  | 27  | 28  | 29  | 30  |
 * +------------------------------------------------------------
 * | D4  | CC3 | DC4 | D7  | A7  | A1  | B3  | AC1 | BC3 | B5  |
 * +-----------------------------------------------------------+
 * 
 * +-----------------------------------------------------------+
 * | 31  | 32  | 33  | 34  | 35  | 36  | 37  | 38  | 39  | 40  |
 * +------------------------------------------------------------
 * |AUX3 |TIME | A6  | A4  | B2  | AC4 | BC2 | B8  |AUX2 |MAIN |
 * +-----------------------------------------------------------+
 * 
 * +-----------------------------------------------------------+
 * | 41  | 42  | 43  | 44  | 45  | 46  | 47  | 48  | 49  | 50  |
 * +------------------------------------------------------------
 * | A5  | A2  | B1  | AC2 | BC1 | B6  |AUX1 |SECA | A8  | A3  |
 * +-----------------------------------------------------------+
 * 
 * +-----------------------------------+
 * | 51  | 52  | 53  | 54  | 55  | 56  |
 * +-----------------------------------
 * | B4  | AC3 | BC4 | B7  | n.c.| SECB|
 * +-----------------------------------+
 */
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

#endif

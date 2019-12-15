#include "ControlDesk.h"
#include <SPI.h>

CControlDesk ControlDesk;

CControlDesk::CControlDesk() {

  pinMode(BUTTON_MUX_LOAD, OUTPUT);
  //pinMode(BUTTON_MUX_INPUT_B, OUTPUT);

  pinMode(DESKLAMP_TRANSISTOR, OUTPUT);
  analogWrite(DESKLAMP_TRANSISTOR, 0);
  pinMode(POWER_LED_TRANSISTOR, OUTPUT);
  digitalWrite(POWER_LED_TRANSISTOR, HIGH);
  
  digitalWrite(BUTTON_MUX_LOAD, HIGH);
  digitalWrite(LED_MUX_OE, LOW);
  digitalWrite(LED_MUX_RCK, LOW);

  for(int i=0; i<BUTTON_COUNT; i++){
    buttons[i] = new Button(i);
  }

  rotaryEncoder = new Button(BUTTON_COUNT);
  outer_knob = new Button(BUTTON_COUNT+1);

  SPI.begin();

  readButtons();
  readButtons();
}

void CControlDesk::registerButtonPressedCallBack(void (*ptrBtnPrsd)(Button*)){
  ptrButtonPressed = ptrBtnPrsd;
}

void CControlDesk::registerButtonReleasedCallBack(void (*ptrBtnRlsd)(Button*)){
  ptrButtonReleased = ptrBtnRlsd;
}

void CControlDesk::setLed(uint8_t led, uint8_t br){
  if(led >= 0 && led <= 31){
    leds[led] = br;
  }
}

uint8_t CControlDesk::getLed(uint8_t led){
  if(led >= 0 && led <= 31){
    return leds[led];
  }
}

void CControlDesk::readButtons(){

  //BUTTON_MUX_CLK = SCK
  //BUTTON_MUX_DATA = MISO
  
  //Feed MM74HC165 shift register with button states by pulsing SHIFT/LOAD
  digitalWrite(BUTTON_MUX_LOAD, LOW);
  digitalWrite(BUTTON_MUX_LOAD, HIGH);

  //uint8_t testData[] = {0b00000001, 0b10000000, 0,0,0,0,0,0,0,0};
  uint8_t btnCounter = 0;
  //Transfer 10 bytes. 79 Buttons need 10x8 bits, 32 LEDs need 4x8 bits.
  for(int i=0; i<10; i++){
    uint8_t c = SPI.transfer(0);
    //uint8_t c = testData[i];

    //Serial.print("[");
    //Serial.print(c, BIN);
    //Serial.print("]");

    
    switch(i){
      case 0:
        //MSB ignored (not used on board?)
        buttons[btnCounter++]->setState( ((c & (1<<6))>>6) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<5))>>5) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<4))>>4) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<3))>>3) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<2))>>2) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<1))>>1) ^ 1 );
        buttons[btnCounter++]->setState( c & 1 ); //Power button bit inversed
      break;
      
      case 1:
        //rotaryEncoder->setState;
        //rotaryEncoder->setState;
        //outer_knob->setState; //rotaryEncoder->setState;
        //outer_knob->setState //rotaryEncoder->setState;
        //outer_knob->setState
        //outer_knob->setState
        //outer_knob->setState
        //outer_knob->setState
        //outer_knob->setState
      break;
      
      default:
        buttons[btnCounter++]->setState( ((c & (1<<7))>>7) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<6))>>6) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<5))>>5) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<4))>>4) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<3))>>3) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<2))>>2) ^ 1 );
        buttons[btnCounter++]->setState( ((c & (1<<1))>>1) ^ 1 );
        buttons[btnCounter++]->setState( (c & 1) ^ 1 );
      break;
    }//switch
    
  }//for
  //Serial.println("");
}

void CControlDesk::writeLEDs(){

  //LED_MUX_SCK = SCK
  //LED_MUX_DATA = MOSI
  
  //LED bits could be transfered simultaneously, but for convenience here it is transmitted separately

  for(int i=3; i>=0; i--){
    uint8_t ch = 0;
    for(int j=7; j>=0; j--){
      if(leds[(i*8)+j])
        ch &= ~(1 << j); //Set bit to 0
      else
        ch |= (1 << j);  //Set bit to 1
    }
    SPI.transfer(ch);
  }
  //To make changes visible on MM74HC595, Storage Regiser clock needs to be clocked.
  digitalWrite(LED_MUX_RCK, HIGH);
  digitalWrite(LED_MUX_RCK, LOW);
}

void CControlDesk::setDeskLamp(uint8_t br){
  analogWrite(DESKLAMP_TRANSISTOR, br);
}

void CControlDesk::checkButtonValues(){
  for(int i=0; i<BUTTON_COUNT; i++){
    if(buttons[i]->changed()){
      if(buttons[i]->getState())
        (*ptrButtonPressed)(buttons[i]);
      else
        (*ptrButtonReleased)(buttons[i]);
    }
  }
}

void CControlDesk::update(){
  writeLEDs();
  readButtons();
  checkButtonValues();
}

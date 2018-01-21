#include "ControlDesk.h"
#include <SPI.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();
CControlDesk ControlDesk;

CControlDesk::CControlDesk() {
  pinMode(INH_U, OUTPUT);
  pinMode(INH_L, OUTPUT);
  
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);

  pinMode(LED_MUX_RCK, OUTPUT);
  pinMode(LED_MUX_OE, OUTPUT);

  pinMode(BUTTON_MUX_LOAD, OUTPUT);
  //pinMode(BUTTON_MUX_INPUT_B, OUTPUT);

  pinMode(DESKLAMP_TRANSISTOR, OUTPUT);
  analogWrite(DESKLAMP_TRANSISTOR, 0);
  pinMode(POWER_LED_TRANSISTOR, OUTPUT);
  digitalWrite(POWER_LED_TRANSISTOR, HIGH);
  
  digitalWrite(BUTTON_MUX_LOAD, HIGH);
  digitalWrite(LED_MUX_OE, LOW);
  digitalWrite(LED_MUX_RCK, LOW);


  for(int i=0; i<POT_COUNT; i++){
    pots[i] = new Pot(i); //Word game haha
  }

  for(int i=0; i<BUTTON_COUNT; i++){
    buttons[i] = new Button(i);
  }

  rotaryEncoder = new Button(BUTTON_COUNT);
  outer_knob = new Button(BUTTON_COUNT+1);

  SPI.begin();
  MIDI.begin(MIDI_CHANNEL_OMNI);

  readButtons();
  readButtons();
  readPots();
  readPots();
}

void CControlDesk::setLed(uint8_t led, uint8_t br){
  if(br)
    leds &= ~(1 << led); //Set bit nr. led to 0
  else
    leds |= (1 << led);  //Set bit nr. led to 1
}

void CControlDesk::switchPotRow(uint8_t row){
  if (row == 0){
    //activate upper chip row (INH is active low)
    digitalWrite(INH_U, LOW);
    digitalWrite(INH_L, HIGH);
  } else if(row == 1) {
    //activate lower chip row (INH is active low), deactivate upper chip row
    digitalWrite(INH_U, HIGH);
    digitalWrite(INH_L, LOW);
  }
}

void CControlDesk::switchMuxChannel(byte ch){
  switch (ch) {
    case 0:
      //set multiplexer channel 0x,0y
      digitalWrite(MUX_A, LOW);
      digitalWrite(MUX_B, LOW);
      break;
    case 1:
      //set multiplexer channel 1x,1y
      digitalWrite(MUX_A, HIGH);
      digitalWrite(MUX_B, LOW);
      break;
    case 2:
      //set multiplexer channel 2x,2y
      digitalWrite(MUX_A, LOW);
      digitalWrite(MUX_B, HIGH);
      break;
    case 3:
      //set multiplexer channel 3x,3y
      digitalWrite(MUX_A, HIGH);
      digitalWrite(MUX_B, HIGH);
      break;
  }
}

//Read pots via ST HCF4052BE multiplexers
void CControlDesk::readPots() {
  
  int potCounter = 0;
  for(int row=0; row<2; row++){
    
    switchPotRow(row);
    
    for(int ch=0; ch<4; ch++){
      
      switchMuxChannel(ch);
      
      pots[potCounter++]->setValue(analogRead(COMMON_X_1));
      pots[potCounter++]->setValue(analogRead(COMMON_Y_1));
      pots[potCounter++]->setValue(analogRead(COMMON_X_2));
      pots[potCounter++]->setValue(analogRead(COMMON_Y_2));
      pots[potCounter++]->setValue(analogRead(COMMON_X_3));
      pots[potCounter++]->setValue(analogRead(COMMON_Y_3));
      if(row == 1){
        pots[potCounter++]->setValue(analogRead(COMMON_X_4));
        pots[potCounter++]->setValue(analogRead(COMMON_Y_4));
      }
      
    }//channel
  }//row
  
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
        buttons[btnCounter++]->setState( (c & (1<<6))>>6 );
        buttons[btnCounter++]->setState( (c & (1<<5))>>5 );
        buttons[btnCounter++]->setState( (c & (1<<4))>>4 );
        buttons[btnCounter++]->setState( (c & (1<<3))>>3 );
        buttons[btnCounter++]->setState( (c & (1<<2))>>2 );
        buttons[btnCounter++]->setState( (c & (1<<1))>>1 );
        buttons[btnCounter++]->setState( (c & 1) ^ 1 ); //Power button bit inversed
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
        buttons[btnCounter++]->setState( (c & (1<<7))>>7 );
        buttons[btnCounter++]->setState( (c & (1<<6))>>6 );
        buttons[btnCounter++]->setState( (c & (1<<5))>>5 );
        buttons[btnCounter++]->setState( (c & (1<<4))>>4 );
        buttons[btnCounter++]->setState( (c & (1<<3))>>3 );
        buttons[btnCounter++]->setState( (c & (1<<2))>>2 );
        buttons[btnCounter++]->setState( (c & (1<<1))>>1 );
        buttons[btnCounter++]->setState( c & 1 );
      break;
    }//switch
    
  }//for
  //Serial.println("");
}

void CControlDesk::writeLEDs(){

  //LED_MUX_SCK = SCK
  //LED_MUX_DATA = MOSI
  
  //LED bits could be transfered simultaneously, but for convenience here it is transmitted separately
  SPI.transfer(leds >> 24);
  SPI.transfer(leds >> 16);
  SPI.transfer(leds >> 8);
  SPI.transfer(leds);

  //To make changes visible on MM74HC595, Storage Regiser clock needs to be clocked.
  digitalWrite(LED_MUX_RCK, HIGH);
  digitalWrite(LED_MUX_RCK, LOW);
}

void CControlDesk::setDeskLamp(uint8_t br){
  analogWrite(DESKLAMP_TRANSISTOR, br);
}

void CControlDesk::checkPotValues(){
  for(int i=0; i<POT_COUNT; i++){
    if(pots[i]->changed()){
      //MIDI.sendControlChange(pots[i]->getId(),pots[i]->getValue(),1);
      //TODO: call callback function(s)
      
      Serial.print("Pot ");
      Serial.print(pots[i]->getId());
      Serial.print(" changed to ");
      Serial.println(pots[i]->getValue());
    }
  }
}

void CControlDesk::checkButtonValues(){
  for(int i=0; i<BUTTON_COUNT; i++){
    if(buttons[i]->changed()){
      if(buttons[i]->getState()){
        //MIDI.sendNoteOn(1, buttons[i]->getId(), 1);
        //TODO: call callback function(s)
      }
      else {
        //MIDI.sendNoteOff(1, buttons[i]->getId(), 1);
        //TODO: call callback function(s)
      }
      Serial.print("Button ");
      Serial.print(buttons[i]->getId());
      Serial.print(" changed to ");
      Serial.println(buttons[i]->getState());
    }
  }
}

//void CControlDesk::checkEncoderValues(){
  
//}

void CControlDesk::update(){
  //writeLEDs();
  readButtons();
  checkButtonValues();
  //checkEncoderValues();
  //readPots();
  //checkPotValues();
}

#include <Arduino.h>
#include "ControlDesk.h"
#include "MIDI.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial3,  MIDI);

void onButtonPressed(Button *button){
  switch (button->getId()){
    case 43: ControlDesk.getLed(LED_CC1) ? ControlDesk.setLed(LED_CC1, LOW) : ControlDesk.setLed(LED_CC1, HIGH); break;
    case 39: ControlDesk.getLed(LED_CC2) ? ControlDesk.setLed(LED_CC2, LOW) : ControlDesk.setLed(LED_CC2, HIGH); break;
    case 40: ControlDesk.getLed(LED_CC3) ? ControlDesk.setLed(LED_CC3, LOW) : ControlDesk.setLed(LED_CC3, HIGH); break;
    case 41: ControlDesk.getLed(LED_CC4) ? ControlDesk.setLed(LED_CC4, LOW) : ControlDesk.setLed(LED_CC4, HIGH); break;
    case 26: ControlDesk.getLed(LED_DC1) ? ControlDesk.setLed(LED_DC1, LOW) : ControlDesk.setLed(LED_DC1, HIGH); break;
    case 30: ControlDesk.getLed(LED_DC2) ? ControlDesk.setLed(LED_DC2, LOW) : ControlDesk.setLed(LED_DC2, HIGH); break;
    case 29: ControlDesk.getLed(LED_DC3) ? ControlDesk.setLed(LED_DC3, LOW) : ControlDesk.setLed(LED_DC3, HIGH); break;
    case 28: ControlDesk.getLed(LED_DC4) ? ControlDesk.setLed(LED_DC4, LOW) : ControlDesk.setLed(LED_DC4, HIGH); break;
    case 47: ControlDesk.getLed(LED_AC1) ? ControlDesk.setLed(LED_AC1, LOW) : ControlDesk.setLed(LED_AC1, HIGH); break;
    case 48: ControlDesk.getLed(LED_AC2) ? ControlDesk.setLed(LED_AC2, LOW) : ControlDesk.setLed(LED_AC2, HIGH); break;
    case 49: ControlDesk.getLed(LED_AC3) ? ControlDesk.setLed(LED_AC3, LOW) : ControlDesk.setLed(LED_AC3, HIGH); break;
    case 50: ControlDesk.getLed(LED_AC4) ? ControlDesk.setLed(LED_AC4, LOW) : ControlDesk.setLed(LED_AC4, HIGH); break;
    case 38: ControlDesk.getLed(LED_BC1) ? ControlDesk.setLed(LED_BC1, LOW) : ControlDesk.setLed(LED_BC1, HIGH); break;
    case 37: ControlDesk.getLed(LED_BC2) ? ControlDesk.setLed(LED_BC2, LOW) : ControlDesk.setLed(LED_BC2, HIGH); break;
    case 36: ControlDesk.getLed(LED_BC3) ? ControlDesk.setLed(LED_BC3, LOW) : ControlDesk.setLed(LED_BC3, HIGH); break;
    case 35: ControlDesk.getLed(LED_BC4) ? ControlDesk.setLed(LED_BC4, LOW) : ControlDesk.setLed(LED_BC4, HIGH); break;
  }
  MIDI.sendNoteOn(button->getId(), 1, 5);
}

void onButtonReleased(Button *button){
  MIDI.sendNoteOff(button->getId(), 1, 5);
}

void onPotValChanged(Pot *pot){
  MIDI.sendControlChange(pot->getId(),pot->getValue(),5);
}

void setup() {

  ControlDesk.registerButtonPressedCallBack(onButtonPressed);
  ControlDesk.registerButtonReleasedCallBack(onButtonReleased);
  ControlDesk.registerPotChangedCallBack(onPotValChanged);
  
  ControlDesk.setDeskLamp(255);
  
  Serial.begin(115200);
  Serial.println("Start");

  MIDI.begin(MIDI_CHANNEL_OMNI);

  //by default all LEDs are HIGH
  for(int i=0; i<32; i++){
    ControlDesk.setLed(i, LOW);
  }
}

/* ########################################################## */

void loop() {

  ControlDesk.update();

  //TODO: Handle when power button is pressed
  //TODO: eventually make PWM for LEDs possible (not enough memory?)
}

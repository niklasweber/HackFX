#include "ControlDesk.h"
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial3,  MIDI);

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

  ControlDesk.setLed(LED_CC1, HIGH);
  ControlDesk.setLed(LED_CC2, HIGH);
  ControlDesk.setLed(LED_CC3, HIGH);
  ControlDesk.setLed(LED_CC4, HIGH);

  ControlDesk.update();

  //TODO: Handle when power button is pressed
  //TODO: eventually make PWM for LEDs possible (not enough memory?)
}

void onButtonPressed(Button *button){
  MIDI.sendNoteOn(button->getId(), 1, 5);
}

void onButtonReleased(Button *button){
  MIDI.sendNoteOff(button->getId(), 1, 5);
}

void onPotValChanged(Pot *pot){
  MIDI.sendControlChange(pot->getId(),pot->getValue(),5);
}


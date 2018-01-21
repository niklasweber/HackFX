#include "ControlDesk.h"
//#include <MIDI.h>

//MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  
  ControlDesk.setDeskLamp(255);
  
  Serial.begin(115200);
  Serial.println("Start");

  //MIDI.begin(MIDI_CHANNEL_OMNI);

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

void onButtonPressed(Button button){
  //MIDI.sendNoteOn(i, i*2, 1); 
}

void onButtonReleased(Button button){
  //MIDI.sendNoteOff(i, i*2, 1); 
}

void onEncoderValChanged(Button encoder){
  
}

void onPotValChanged(Pot pot){
  
}


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

  //TODO: debounce Buttons
  //TODO: Handle when power button is pressed
  //TODO: eventually make PWM for LEDs possible (not enough memory?)
}

void onButtonPressed(Button *button){
  Serial.print("Button ");
  Serial.print(button->getId());
  Serial.println(" pressed.");
  MIDI.sendNoteOn(1, button->getId(), 1);
}

void onButtonReleased(Button *button){
  Serial.print("Button ");
  Serial.print(button->getId());
  Serial.println(" released.");
  MIDI.sendNoteOff(1, button->getId(), 1);
}

void onPotValChanged(Pot *pot){
  if(pot->getId() == 0){
    Serial.print("Pot ");
    Serial.print(pot->getId());
    Serial.print(" changed to ");
    Serial.println(pot->getValue()); 
  }
  MIDI.sendControlChange(pot->getId(),pot->getValue(),1);
}


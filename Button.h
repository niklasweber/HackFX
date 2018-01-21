#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{ 
  private:
  uint8_t id;
  uint8_t state;
  uint8_t last_state;
  
  public:
  Button(uint8_t ID) :id(ID) {}
  uint8_t getId();
  void setState(uint8_t st);
  uint8_t getState();
  uint8_t changed();
};

#endif

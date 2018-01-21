#ifndef Pot_h
#define Pot_h

#include <Arduino.h>

class Pot
{ 
  private:
  uint8_t id;
  int value = 50;
  int last_value = 0;
  
  public:
  Pot(uint8_t ID) :id(ID) {}
  uint8_t getId();
  void setValue(int val);
  int getValue();
  int getLastValue();
  uint8_t changed();
};

#endif

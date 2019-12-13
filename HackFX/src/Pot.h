#ifndef Pot_h
#define Pot_h

#include <Arduino.h>
#include <SimpleKalmanFilter.h>

class Pot
{ 
  private:
  uint8_t id;
  int value = 0;
  int last_value = 0;
  SimpleKalmanFilter simpleKalmanFilter;
  
  public:
  Pot(uint8_t ID) :id(ID), simpleKalmanFilter(2, 2, 0.05) {}
  uint8_t getId();
  void setValue(int val);
  int getValue();
  int getLastValue();
  uint8_t changed();
};

#endif

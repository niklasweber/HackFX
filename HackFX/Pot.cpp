#include "Pot.h"

uint8_t Pot::getId(){
  return id;
}

void Pot::setValue(int val) {
  last_value = value;
  value = simpleKalmanFilter.updateEstimate(val) / 1024.0 * 128.0;
}

int Pot::getValue() {
  return value;
}

int Pot::getLastValue(){
  return last_value;
}

uint8_t Pot::changed(){
  
  if(value != last_value)
    return 1;
  else
    return 0;
}

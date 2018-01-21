#include "Pot.h"

uint8_t Pot::getId(){
  return id;
}

void Pot::setValue(int val) {
  last_value = value;
  value = val;
}

int Pot::getValue() {
  //map(analogRead(COMMON_X_1), 0, 1023, 0, 127)
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

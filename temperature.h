/*
 * Vector United -- Guide -- Temperature Control
 */

#ifndef guide_temperature_h
#define guide_temperature_h

#include "OneWire.h"

class GuideTemperature
{
public:
  GuideTemperature(unsigned int pin);
  
  // Member Variables
  OneWire* ds;
  
  // Member Functions
  float getTemp();
};

#endif

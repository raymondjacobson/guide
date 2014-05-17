/*
 * Vector United -- Guide -- Water Level Control
 */

#ifndef guide_waterlevel_cpp
#define guide_water_level_cpp

#include "waterlevel.h"
#include "arduino.h"

GuideWaterlevel::GuideWaterlevel(unsigned int pow, unsigned int r0, unsigned int r1, unsigned int r2){
  powerPin = pow;
  recPin0 = r0;
  recPin1 = r1;
  recPin2 = r2;
}

void GuideWaterlevel::checkSubmerge(){
  digitalWrite(powerPin, HIGH);
  delay(2);
  int readVal = analogRead(recPin0);
  if (readVal < 1020)
    r0read = true;
  else
    r0read = false;
  readVal = analogRead(recPin1);
  if (readVal < 1020)
    r1read = true;
  else
    r1read = false;
  readVal = analogRead(recPin2);
  if (readVal < 1020)
    r2read = true;
  else
    r2read = false;
  delay(2);
  digitalWrite(powerPin, LOW);
}

#endif

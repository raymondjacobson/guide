/*
 * Vector United -- Guide -- Speaker Control
 */

#ifndef guide_speaker_cpp
#define guide_speaker_cpp

#include "speaker.h"
#include "arduino.h"

GuideSpeaker::GuideSpeaker(unsigned int pin){
  speakerPin = pin;
}

void GuideSpeaker::beep(unsigned int frequency, unsigned int quantity, unsigned int delayMS){
  for (int i=0; i<quantity; ++i){
    tone(speakerPin, frequency);
    delay(delayMS);
    noTone(speakerPin);
    delay(delayMS);
  }
}

#endif

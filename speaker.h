/*
 * Vector United -- Guide -- Speaker Control
 */

#ifndef guide_speaker_h
#define guide_speaker_h

class GuideSpeaker
{
public:
  GuideSpeaker(unsigned int pin);
  
  // Member Variables
  unsigned int speakerPin;
  
  // Member Functions
  void beep(unsigned int frequency, unsigned int quantity, unsigned int delayMS);
};

#endif

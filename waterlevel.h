/*
 * Vector United -- Guide -- Water Level Control
 */

#ifndef guide_waterlevel_h
#define guide_waterlevel_h

class GuideWaterlevel
{
public:
  GuideWaterlevel(unsigned int pow, unsigned int r0, unsigned int r1, unsigned int r2);
  
  // Member Variables
  unsigned int powerPin;
  unsigned int recPin0;
  unsigned int recPin1;
  unsigned int recPin2;
  
  bool r0read;
  bool r1read;
  bool r2read;
  
  // Member Functions
  void checkSubmerge();
};

#endif

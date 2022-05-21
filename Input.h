#ifndef Input_h
#define Input_h

#include "Arduino.h"
#include "PPMReader.h"

//Define the PPM Channels
#define THROTTLE 1
#define STEERING 2

struct InputPackage {
  int throttleValue;
  int steeringValue;

  int throttleValuePercent;
  int steeringValuePercent;
};

class Input {
  public:
    //The constructor and public methodes:
    Input(uint8_t throttlePin, uint8_t steeringPin);

    InputPackage update();
    
  private:
    PPMReader throttlePPM;
    PPMReader steeringPPM;
    
    int maxValue = 2000;
    int minValue = 1000;
    
    int throttleValue;
    int steeringValue;

    int throttleValuePercent;
    int steeringValuePercent;
};



#endif

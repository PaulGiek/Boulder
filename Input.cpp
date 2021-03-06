#include "Input.h"

//Assign the trottlePPM to the given pin (1 for one data channel)    
//Assign the steeringPPM to the given pin (1 for one data channel) 
Input::Input(uint8_t throttlePin, uint8_t steeringPin) : throttlePPM(PPMReader(throttlePin,1)), steeringPPM(PPMReader(steeringPin, 1)) {
 
}

InputPackage Input::update() {
    //Get the Measurements over PPM
    throttleValue = throttlePPM.latestValidChannelValue(1, 0);
    steeringValue = steeringPPM.latestValidChannelValue(1, 0);

    InputPackage inputs = {
        throttleValue,
        steeringValue,
    };

    return inputs;
}

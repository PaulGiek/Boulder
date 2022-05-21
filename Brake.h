#ifndef Brake_h
#define Brake_h

#include "Arduino.h"
#include "Servo.h"

class Brake {
  public:
    Brake(uint8_t actuatorPin, uint8_t potentiometerPinNew);
    void setTargetPercent(int newTarget);
    void update();
    
  private:
    //The servo object for the actuator
    Servo linearActuator;

    //Values for the controller
    float Kp = 5.0;
    float Ki = 0.0;
    float Kd = 0.0;

    float integralError;

    float oldTime;
    float oldError;

    
      
    //The target value in percent (extended by targetPercent)
    int targetPercent = 0;

    //Potentiometer bounds
    int potentiometerMin = 0;
    int potentiometerMax = 1023;
    
    //Potentiometer Pin
    int potentiometerPin;
};

#endif

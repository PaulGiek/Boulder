#ifndef Steering_h
#define Steering_h

#include "Arduino.h"
#include "Servo.h"

class Stearing {
  public:
    Steering(uint8_t actuatorPin, uint8_t potentiometerPinNew);
    void setTargetPercent(int newTarget);
    void update();
    
  private:
    //The servo object for the actuator
    Servo motor;

    //Values for the controller
    float Kp = 5.0;
    float Ki = 0.0;
    float Kd = 0.0;

    float integralError;

    float oldTime;
    float oldError;

    
      
    //The target value in percent (0 is hard left 1 is hard right)
    int targetPercent = 0;

    //Potentiometer bounds (max is full right)
    int potentiometerMin = 0;
    int potentiometerMax = 1023;
    
    //Potentiometer Pin
    int potentiometerPin;
};

#endif

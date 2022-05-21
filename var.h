#include "Input.h"
#include "Servo.h"
#include "Brake.h"
#include "Steering.h"

//Inputs
//Throttle Pin, Steering Pin
Input inputs(7 , 8);
InputPackage inputValues;


//Outputs
//Servo
int throttleServoPin = 6;
Servo throttleServo;

//This marks the position the servo doesn't engange the throttle in
int servoMinPos = 0;
//This marks the position the servo fully enganges the throttle in
int servoMaxPos = 180;

//Brake
//Actuator Pin, Potentiometer Pin
Brake brake(3, A1);

//Steering 
Steering steering(5 , A0);


//Emergency Disable
int emergencyPin = 9;

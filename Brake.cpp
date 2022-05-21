#include "Brake.h"

Brake::Brake(uint8_t actuatorPin, uint8_t potentiometerPinNew) {
  linearActuator.attach(actuatorPin);
    
  //Set the potentiometerPin and declare it as an output
  potentiometerPin = potentiometerPinNew; 
  pinMode(potentiometerPin, INPUT);
}

void Brake::setTargetPercent(int newTarget) {
  targetPercent = newTarget;
}

void Brake::update() {
  int pos = analogRead(potentiometerPin);
  int posPercent = pos / potentiometerMax;

  float u;
  unsigned long now = millis();
  unsigned long dt = now - oldTime;
  
  //Calculate the error 
  float error = posPercent - targetPercent;
  integralError += error * dt;    

  u = error * Kp + integralError * Ki + ((error - oldError) / dt) * Kd;
 
  //1500 is no movement. By running the Motor at a speed of u we correct for position offsets
  linearActuator.writeMicroseconds(1500 + u);

  oldTime = now;
  oldError = error;
}

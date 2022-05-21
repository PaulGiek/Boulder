#include "Steering.h"

Steering::Steering(uint8_t actuatorPin, uint8_t potentiometerPinNew) {
  motor.attach(actuatorPin);
    
  //Set the potentiometerPin and declare it as an output
  potentiometerPin = potentiometerPinNew; 
  pinMode(potentiometerPin, INPUT);
}

void Steering::setTargetPercent(int newTarget) {
  targetPercent = newTarget;
  Serial.println("Steering is trying to archieve: " + targetPercent);
}

void Steering::update() {
  //Full left is 0
  int pos = analogRead(potentiometerPin);
  int posPercent = pos / potentiometerMax;
  Serial.println("Steering Potentiometer Pos (%) is: " + posPercent);

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

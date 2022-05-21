#include "var.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  
  throttleServo.attach(throttleServoPin);
  throttleServo.write(servoMinPos);
}

void loop() {
  inputValues = inputs.update();

  
  if (inputValues.throttleValue > 1500) {
    //By subtracting 1500 from the measurement we get by how much we should throttle in a range from 0 - 500 by deviding this by 500 we get it in a 0 - 1 range 
    //which we can multply with the servo max pos
    float servoPosNew = ((inputValues.throttleValue - 1500)/500) * servoMaxPos;
    throttleServo.write(servoPosNew);
  }

  if (inputValues.throttleValue < 1500)  {
    //By subtracting the measurement from 1500 we get by how much we should brake in a range from 0 - 500 by deviding this by 500 we get it in a 0 - 1 range 
    //Which is the range the brake function needs to know so we just pass it that value
    float brakeExtendPercent = ((1500 - inputValues.throttleValue)/500);
    brake.setTargetPercent(brakeExtendPercent);
  }


  brake.update();
}

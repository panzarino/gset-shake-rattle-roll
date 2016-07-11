#include "Arduino.h"

class PIDController {
  
  public:
  
  float target;          // setpoint
  float kp, ki, kd;      // gain constants
  unsigned long prevtime;
  float lastInput, sigma, output, max_, min_;
  
  // empty initializer
  PIDController() {};
  
  // initializer with no function
  PIDController(float minOut, float maxOut, float setpoint = 0,
                float kP = 0.0, float kI = 0.0, float kD = 0.0) {
    max_ = maxOut;
    min_ = minOut;
    setTarget(setpoint, kP, kI, kD);
  }
  
  // update values and calculate
  float calculate(float current) {
    
    // time check
    unsigned long now = millis();
    double dt = (double) (now - lastTime);
    
    // p, i, d updates
    double error = target - current;
    sigma += (error * dt);
    double slope = (lastInput - current) / dt;
    
    // total and bound pid output
    output = kp * error + ki * sigma + kd * slope;
    output = output > max_ ? max_ : output;
    output = output < min_ ? min_ : output;
    
    // update variables and return
    lastTime = now;
    lastInput = current;
    return output;
  }
  
  // set new target with new pid constants, if given; otherwise keep same
  void setTarget(float setpoint, float kP = -999, float kI = -999, float kD = -999) {
    target = setpoint;
    if (kP != -999) kp = kP;
    if (kI != -999) ki = kI;
    if (kD != -999) kd = kD;
    lastTime = millis();
    lastInput = 0;
  }
  
  // set new constants
  void setConstants(float kP, float kI, float kD) {
    kp = kP;
    ki = kI;
    kd = kD;
  }
};

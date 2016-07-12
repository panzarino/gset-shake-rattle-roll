#include "Arduino.h"

/**
 * creds to Emily Liu for teaching me to write PID derps
 */

class PIDController {
  
  public:
  
  float sp;                                      // setpoint
  float kp, ki, kd;                              // gain constants
  unsigned long prevtime;                        // previous time stamp
  float prevval, integral, output, max_, min_;   // previous input, integral, output, max/min output values
  
  /** 
   * initializer PIDController
   * min and max are min and max motor output respectively
   * setpoint is the target sensor combined value we want
   * kP, kI, and kD are the gain constants we want and we will need to tune them
   */
  PIDController(float min, float max, float setpoint, float kP, float kI, float kD) {
    max_ = max;         // set max output 
    min_ = min;         // set min output
    setsp(setpoint);            // set set point
    setconstants(kP, kI, kD);   // sets gain constants
  }
  
  /** 
   * update values and calculate
   * curval is the curval sensor reading
   */
  float calculate(float curval) {
    // get curval time
    unsigned long curtime = millis();
    double dt = (double) (curtime - prevtime);      // dt
    // calculate error from set point
    double error = sp - curval;
    integral += (error * dt);                // update intgral by Riemann sum
    double de = (prevval - curval) / dt;  // de, difference in error over time
    /* P only control*/
    // output  = kp * error
    /* PI control */
    // output = kp * error + ki * integral
    /* PD control */
    // output = kp * error + kd * de
    /* PID control */
    output = kp * error + ki * integral + kd * de;
    // check if within bounds
    if (output > max_) {
      return max_;
    }
    else if (output < min_) {
      return min_;
    }
    else {
      return output;
    }
    // update variables and return
    prevtime = curtime;
    prevval = curval;
    return output;
  }
  
  /**
   * set new sp with new pid constant
   */
  void setsp(float setpoint) {
    sp = setpoint;
    prevtime = millis();
    prevval = 0;
  }
  
  /** 
   * set new constants
   */
  void setconstants(float kP, float kI, float kD) {
    kp = kP;
    ki = kI;
    kd = kD;
  }
};

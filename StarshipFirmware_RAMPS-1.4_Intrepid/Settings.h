
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <Arduino.h>
#include "Stepper.h"

class Settings // contains machine and build settings
{
  public:
    Settings(): 
        units("mm"),
        step_angle(1.8) {}
    
    StepperMotor polar_stepper = StepperMotor(1,1,1, true);
    StepperMotor radial_stepper = StepperMotor(1,1,1, false);
    StepperMotor z_stepper = StepperMotor(1,1,1, false);
    StepperMotor extruder_stepper = StepperMotor(1,1,1, false);
    String units;
    float step_angle;
};

extern Settings settings;

#endif

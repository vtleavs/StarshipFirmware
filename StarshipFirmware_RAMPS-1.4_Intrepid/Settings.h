
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

class Settings // contains machine and build settings
{
  public:
    Settings(): 
        units("mm"),
        step_angle(1.8){}
    String units;
    float step_angle;
};

Settings settings;

#endif

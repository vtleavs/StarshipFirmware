
struct Settings // contains machine and build settings
{
    Settings(): 
        units("mm")
        step_angle(1.8){}
    String units;
    float step_angle;
};

Settings settings;

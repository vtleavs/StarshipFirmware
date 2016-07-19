
struct MetaData  // contains information about the program
{
  public:
    MetaData(): version_num(0.01), hardware_class("Intrepid"), control_scheme("RAMPS 1.4"){}
  
    float version_num;// = 0.01;
    String hardware_class;// = "Intrepid";
    String control_scheme;// = "RAMPS 1.4";
    //char version_name[];// = "StarShip 3D RAMPS 1.4 Firmware version 0.01";
};

MetaData metadata;

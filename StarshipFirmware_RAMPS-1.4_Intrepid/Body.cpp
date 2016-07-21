
#ifndef _BODY_CPP_
#define _BODY_CPP_

#include <Arduino.h>

#include "MetaData.h"
#include "Settings.h"

void body()
{
    Serial.println("Starship 3D");
    Serial.print("Class: ");
    Serial.println(metadata.hardware_class);
    Serial.print(metadata.control_scheme);
    Serial.print(" Firmware version ");
    Serial.println(metadata.version_num);
  
    Serial.println();


}

#endif

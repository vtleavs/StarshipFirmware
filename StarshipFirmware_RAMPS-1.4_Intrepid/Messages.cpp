
#ifndef _MESSAGES_CPP_
#define _MESSAGES_CPP_

#include <Arduino.h>

#include "MetaData.h"
#include "Settings.h"

void header()
{
    delay(100);
    Serial.println("Starship 3D");
    Serial.print("Class: ");
    Serial.println(metadata.hardware_class);
    Serial.print(metadata.control_scheme);
    Serial.print(" Firmware version ");
    Serial.println(metadata.version_num);
    Serial.println();
}

#endif

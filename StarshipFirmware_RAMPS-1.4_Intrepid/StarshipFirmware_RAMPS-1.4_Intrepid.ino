
#include "MetaData.h"
#include "Settings.h"

bool start = true;

void setup() 
{
    // runs once
    Serial.begin(9600);
    
}

void loop() 
{
    if(start)
    {
        start = false;
        body(); // if on start, run the main body of the program
    }

    if(Serial.read() == 'r') // check to see if the restart command has been given
    {
        Serial.println("restarting...");
        start = true;
    }
}

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


#ifndef _MESSAGES_CPP_
#define _MESSAGES_CPP_

#include <Arduino.h>

#include "MetaData.h"
#include "Settings.h"

void header()
{
    delay(100); // Smooth out serial stream
    Serial.println("Starship 3D");
    Serial.print("Class: ");
    Serial.println(metadata.hardware_class);
    Serial.print(metadata.control_scheme);
    Serial.print(" Firmware version ");
    Serial.println(metadata.version_num);
    Serial.println();
}

void list_g_commands()
{
    delay(100);
    Serial.println("G: List all supported G-Codes");
    Serial.println("G0: Rapid Linear Move");
    Serial.println("G1: Linear Move");
    Serial.println("G4: Dwell");
    Serial.println("G5: Polar Move");
    Serial.println("G10: Retract Filament");
    Serial.println("G11: Unretract Filament");
    Serial.println("G20: Set Units to in");
    Serial.println("G21: Set Units to mm");
    Serial.println("G27: Move to Origin (polar)");
    Serial.println("G28: Move to Origin (linear)");
    Serial.println("G90: Set absolute positioning");
    Serial.println("G91: Set relative positioning");
    Serial.println("G92: Set current position");
    Serial.println();
}

void list_m_commands()
{
    delay(100);
    Serial.println("M: List all supported M-Codes");
    Serial.println("M0: Unconditional Stop");
    Serial.println("M1: Conditional Stop");
    Serial.println("M5: Restart Firmware");
    Serial.println("M0: Unconditional Stop");
    Serial.println("M0: Unconditional Stop");
    Serial.println("M0: Unconditional Stop");
    Serial.println("M0: Unconditional Stop");
    
    void M0(); // Unconditional Stop
void M1(); // Conditional Stop

void M5(); // Restart firmware

void M17(char letters[], float numbers[]); // Disable all stepper motors (polar) ****
void M18(char letters[], float numbers[]);// Disable all stepper motors (linear)

void M20(); // List SD card
void M23(String file); // Select SD file
void M24(); // Start/Resume SD print
void M25(); // Pause SD print
void M26(char letters[], float numbers[]); // Set SD position in bits
void M27(); // Report SD print status
void M29(); // Stop SD logging

/*
    M28-M30, SD write: not yet implemented
*/

void M32(String file); // Start SD print on file
void M36(String file); // Return file info

void M82(); // Set extruder to absolute mode
void M83(); // Set extruder to relative mode

void M92(char letters[], float numbers[]); // Set steps per unit
void M98(String file); // Run macro
void M98(char letters[], float numbers[]); // Run inline macro
void M99(); // Return from inline macro

void M104(char letters[], float numbers[]); // Set extruder temp
void M105(); // Return extruder temp
void M106(char letters[], float numbers[]); // Fan on
void M107(char letters[], float numbers[]); // Fan off
void M109(char letters[], float numbers[]); // Set extruder temp and wait

void M112(); // Emergency Stop

void M113(char letters[], float numbers[]); // Get current position (polar) ****
void M114(char letters[], float numbers[]); // Get current position (linear)

void M115(); // Get firmware version and Specs

void M116(); // Wait for temperature

void M118(char letters[], float numbers[]); // Display Message on LCD

void M119(); // Get endstop status

void M120(); // Stack Push
void M121(); // Stack Pop

void M122(); // Send diagnostic info

void M140(char letters[], float numbers[]); // Set bed temperature
void M144(); // Set bed to standby temp
void M190(char letters[], float numbers[]); // Wait for bed to reach temp

void M200(char letters[], float numbers[]); // Set max acceleration units/second^2 (polar)
void M201(char letters[], float numbers[]); // Set max acceleration units/second^2 (linear)

void M202(char letters[], float numbers[]); // Set max velocity mm/min (polar)
void M203(char letters[], float numbers[]); // Set max velocity mm/min (linear)

void M207(char letters[], float numbers[]); // set axis max (polar)
void M208(char letters[], float numbers[]); // set axis max (linear)

void M220(char letters[], float numbers[]); // Set speed factor percentage
void M221(char letters[], float numbers[]); // Set extruder speed factor percentage

void M226(); // G-Code initiated pause

void M300(char letters[], float numbers[]); // Play beep sound

void M301(char letters[], float numbers[]); // Set Extruder PID
void M302(char letters[], float numbers[]); // Allow cold extrudes
void M304(char letters[], float numbers[]); // Set Bed PID

void M349(char letters[], float numbers[]); // Set microstepping mode (polar)
void M350(char letters[], float numbers[]); // Set microstepping mode (linear)

void M360(); // Report firmware config

void M400(); // Wait for buffer to empty

void M404(char letters[], float numbers[]); // Filament width and Nozzle diameter
void M407(); // Display filament diameter

void M502(); // Revert to factory settings
void M503(); // Return print settings

void M556(char letters[], float numbers[]); // Set axis compensation

void M562(); // Reset temp fault

void M577(char letters[], float numbers[]); // Wait for endstop to be triggered

void M579(char letters[], float numbers[]); // Set scale factor on axes

void M928(String file); // Start SD logging
}

#endif

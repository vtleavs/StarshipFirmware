
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
    Serial.println("M17: Disable All Steppers (polar)");
    Serial.println("M18: Disable All Steppers (linear)");
    Serial.println("M20: List SD card");
    Serial.println("M23: Select SD file");
    Serial.println("M24: Start/Resume SD print");
    Serial.println("M25: Pause SD print");
    Serial.println("M26: Set SD position in bits");
    Serial.println("M27: Report SD print status");
    Serial.println("M29: Stop SD logging");
    Serial.println("M32: Start SD print on file");
    Serial.println("M36: Return file info");
    Serial.println("M82: Set extruder to absolute mode");
    Serial.println("M83: Set extruder to relative mode");
    Serial.println("M92: Set steps per unit");
    Serial.println("M98 filename: Run macro");
    Serial.println("M98 Pnnn: Run inline macro on line Pnnn");
    Serial.println("M99: Return from inline macro");
    Serial.println("M104: Set extruder temp");
    Serial.println("M105: Return extruder temp");
    Serial.println("M106: Fan on");
    Serial.println("M107: Fan off");
    Serial.println("M109: Set extruder temp and wait");
    Serial.println("M112: Emergency Stop");
    Serial.println("M113: Get current position (polar)");
    Serial.println("M114: Get current position (linear)");
    Serial.println("M115: Get firmware version and Specs");
    Serial.println("M116: Wait for temperature");
    Serial.println("M118: Display Message on LCD");
    Serial.println("M119: Get Endstop Status");
    Serial.println("M120: Stack Push");
    Serial.println("M121: Stack Pop");
    Serial.println("M122: Send diagnostic info");
    Serial.println("M140: Set bed temperature");
    Serial.println("M144: Set bed to standby temp");
    Serial.println("M190: Wait for bed to reach temp");
    Serial.println("M200: Set max acceleration units/second^2 (polar)");
    Serial.println("M201: Set max acceleration units/second^2 (linear)");
    Serial.println("M202: Set max velocity mm/min (polar)");
    Serial.println("M203: Set max velocity mm/min (linear)");
    Serial.println("M207: Set axis max (polar)");
    Serial.println("M208: Set axis max (linear)");
    Serial.println("M220: Set speed factor percentage");
    Serial.println("M221: Set extruder speed factor percentage");
    Serial.println("M226: G-Code initiated pause");
    Serial.println("M300: Play beep sound");
    Serial.println("M301: Set Extruder PID");
    Serial.println("M302: Allow cold extrudes");
    Serial.println("M304: Set Bed PID");
    Serial.println("M349: Set microstepping mode (polar)");
    Serial.println("M350: Set microstepping mode (linear)");
    Serial.println("M360: Report firmware config");
    Serial.println("M400: Wait for buffer to empty");
    Serial.println("M404: Set Filament Width and Nozzle diameter");
    Serial.println("M407: Display filament diameter");
    Serial.println("M502: Revert to factory settings");
    Serial.println("M503: Return print settings");
    Serial.println("M556: Set axis compensation");
    Serial.println("M562: Reset temp fault");
    Serial.println("M577: Wait for endstop to be triggered");
    Serial.println("M579: Set scale factor on axes");
    Serial.println("M928: Start SD logging");
    Serial.println();
}

#endif

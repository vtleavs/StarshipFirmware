
#ifndef _COMMANDS_H_
#define _COMMANDS_H_

void parse_command(String command);
char find_letter(const char (&letters)[13], char c);

// COMMAND ACTIVE - set to true if command is currently active
extern bool G0_active;
extern bool G1_active;
extern bool G4_active;
extern bool G5_active;
extern bool G10_active;
extern bool G11_active;
extern bool G27_active;
extern bool G28_active;

//.
//.
//.

// G COMMANDS

void G0(const char (&letters)[13], const float (&numbers)[13]); // Rapid Linear Move
void G1(const char (&letters)[13], const float (&numbers)[13]); // Linear Move

void G4(const char (&letters)[13], const float (&numbers)[13]); // Dwell

void G5(const char (&letters)[13], const float (&numbers)[13]); // Polar Move ****

void G10(const char (&letters)[13], const float (&numbers)[13]); // Retract
void Gll(const char (&letters)[13], const float (&numbers)[13]); // Unretract

void G20(); // Set units to in
void G21(); // Set units to mm

void G27(const char (&letters)[13], const float (&numbers)[13]); // Move to origin (polar) ****
void G28(const char (&letters)[13], const float (&numbers)[13]); // Move to origin (linear)

void G90(); // Set absolute positioning
void G91(); // Set relative positioning

void G92(const char (&letters)[13], const float (&numbers)[13]); // Set current position

// M COMMANDS

void M0(); // Unconditional Stop
void M1(); // Conditional Stop

void M5(); // Restart firmware

void M17(const char (&letters)[13], const float (&numbers)[13]); // Disable all stepper motors (polar) ****
void M18(const char (&letters)[13], const float (&numbers)[13]);// Disable all stepper motors (linear)

void M20(); // List SD card
void M23(String file); // Select SD file
void M24(); // Start/Resume SD print
void M25(); // Pause SD print
void M26(const char (&letters)[13], const float (&numbers)[13]); // Set SD position in bits
void M27(); // Report SD print status
void M29(); // Stop SD logging

/*
    M28-M30, SD write: not yet implemented
*/

void M32(String file); // Start SD print on file
void M36(String file); // Return file info

void M82(); // Set extruder to absolute mode
void M83(); // Set extruder to relative mode

void M92(const char (&letters)[13], const float (&numbers)[13]); // Set steps per unit
void M98(String file); // Run macro
void M98(char letters[], float numbers[]); // Run inline macro
void M99(); // Return from inline macro

void M104(const char (&letters)[13], const float (&numbers)[13]); // Set extruder temp
void M105(); // Return extruder temp
void M106(const char (&letters)[13], const float (&numbers)[13]); // Fan on
void M107(const char (&letters)[13], const float (&numbers)[13]); // Fan off
void M109(const char (&letters)[13], const float (&numbers)[13]); // Set extruder temp and wait

void M112(); // Emergency Stop

void M113(); // Get current position (polar) ****
void M114(); // Get current position (linear)

void M115(); // Get firmware version and Specs

void M116(); // Wait for temperature

void M118(const char (&letters)[13], const float (&numbers)[13]); // Display Message on LCD

void M119(); // Get endstop status

void M120(); // Stack Push
void M121(); // Stack Pop

void M122(); // Send diagnostic info

void M140(const char (&letters)[13], const float (&numbers)[13]); // Set bed temperature
void M144(); // Set bed to standby temp
void M190(const char (&letters)[13], const float (&numbers)[13]); // Wait for bed to reach temp

void M200(const char (&letters)[13], const float (&numbers)[13]); // Set max acceleration units/second^2 (polar)
void M201(const char (&letters)[13], const float (&numbers)[13]); // Set max acceleration units/second^2 (linear)

void M202(const char (&letters)[13], const float (&numbers)[13]); // Set max velocity mm/min (polar)
void M203(const char (&letters)[13], const float (&numbers)[13]); // Set max velocity mm/min (linear)

void M207(const char (&letters)[13], const float (&numbers)[13]); // set axis max (polar)
void M208(const char (&letters)[13], const float (&numbers)[13]); // set axis max (linear)

void M220(const char (&letters)[13], const float (&numbers)[13]); // Set speed factor percentage
void M221(const char (&letters)[13], const float (&numbers)[13]); // Set extruder speed factor percentage

void M226(); // G-Code initiated pause

void M300(const char (&letters)[13], const float (&numbers)[13]); // Play beep sound

void M301(const char (&letters)[13], const float (&numbers)[13]); // Set Extruder PID
void M302(const char (&letters)[13], const float (&numbers)[13]); // Allow cold extrudes
void M304(const char (&letters)[13], const float (&numbers)[13]); // Set Bed PID

void M349(const char (&letters)[13], const float (&numbers)[13]); // Set microstepping mode (polar)
void M350(const char (&letters)[13], const float (&numbers)[13]); // Set microstepping mode (linear)

void M360(); // Report firmware config

void M400(); // Wait for buffer to empty

void M404(const char (&letters)[13], const float (&numbers)[13]); // Filament width and Nozzle diameter
void M407(); // Display filament diameter

void M502(); // Revert to factory settings
void M503(); // Return print settings

void M556(const char (&letters)[13], const float (&numbers)[13]); // Set axis compensation

void M562(); // Reset temp fault

void M577(const char (&letters)[13], const float (&numbers)[13]); // Wait for endstop to be triggered

void M579(const char (&letters)[13], const float (&numbers)[13]); // Set scale factor on axes

void M928(String file); // Start SD logging

void G(); // List all G-Codes
void M(); // List all M-Codes

#endif













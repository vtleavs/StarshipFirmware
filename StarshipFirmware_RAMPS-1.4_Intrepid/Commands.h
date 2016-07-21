
void parse_command(String command);

// G COMMANDS

void G0(float x, float y, float z, float e, float f, float s){ G1(x, y, z, e, f, s); } // Rapid Linear Move
void G1(float x, float y, float z, float e, float f) { G5(x, y, z, e, f); } // Linear Move

void G4(int m); // Dwell
void G5(float p, float r, float z, float e, float f); // Polar Move ****

void G10(float s); // Retract
void Gll(float s); // Unretract

void G20(); // Set units to in
void G21(); // Set units to in

void G27(bool p, bool r, bool z); // Move to origin (polar) ****
void G28(bool x, bool y, bool z) { G27(x, y, z); } // Move to origin (linear)

void G90(); // Set absolute positioning
void G91(); // Set relative positioning

void G92(float x, float y, float z, float e); // Set current position

// M COMMANDS

void M0(); // Unconditional Stop
void M1(); // Conditional Stop

void M17(bool p, bool r, bool z. bool e); // Disable all stepper motors (polar) ****
void M18(bool x, bool y, bool z, bool e) { M17(x, y, z, e); } // Disable all stepper motors (linear)

void M20(); // List SD card
void M23(String file); // Select SD file
void M24(); // Start/Resume SD print
void M25(); // Pause SD print
void M26(int s); // Set SD position in bits
void M27(); // Report SD print status

/*
    M28-M30, SD write: not implemented
*/

void M32(String file); // Start SD print on file
void M36(String file); // Return file info

void M82(); // Set extruder to absolute mode
void M83(); // Set extruder to relative mode

void M92(float x, float y, float z, float e); // Set steps per unit
void M98(String file); // Run macro
void M98(int p); // Run inline macro
void M99(); // Return from inline macro

void M104(short s); // Set extruder temp
void M105(); // Return extruder temp
void M106(char p, char s, bool i); // Fan on
void M107(char p); // Fan off
void M109(short s); // Set extruder temp and wait

void M112(); // Emergency Stop

void M113(bool p, bool r, bool z, bool e); // Get current position (polar) ****
void M114(bool x, bool y, bool z, bool e) { M113(x, y, z, e); } // Get current position (linear)

void M115(); // Get firmware version and Specs

void M116(); // Wait for temperature

void M118(String message); // Display Message on LCD

void M119(); // Get endstop status

void M120(); // Stack Push
void M121(); // Stack Pop

void M122(); // Send diagnostic info

void M140(short s); // Set bed temperature
void M144(); // Set bed to standby temp
void M190(short s); // Wait for bed to reach temp

void M200(short p, short r, short z, short e); // Set max acceleration units/second^2 (polar)
void M201(short x, short y, short z, short e) { M200(x, y, z, e); } // Set max acceleration units/second^2 (linear)

void M202(short p, short r, short z, short e); // Set max velocity mm/min (polar)
void M203(short x, short y, short z, short e) { M200(x, y, z, e); } // Set max velocity mm/min (linear)

void M207(float p, float r, float z, float e); // set axis max (polar)
void M208(float x, float y, float z, float e) { M207(x, y, z, e); } // set axis max (linear)

void M220(); //




void parse_command(String command);

void G0(float x, float y, float z, float e, float f, float s){ G1(x, y, z, e, f, s); } // Rapid Linear Move
void G1(float x, float y, float z, float e, float f, float s); // Linear Move

void G4(int m); // Dwell
void G5(float p, float r, float z, float e, float f); // Polar Move

void G10(float s); // Retract
void Gll(float s); // Unretract


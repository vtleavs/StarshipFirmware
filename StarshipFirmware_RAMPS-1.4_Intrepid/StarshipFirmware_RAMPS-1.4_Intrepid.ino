#include "Pins.h"
#include "Messages.h"
#include "Commands.h"

bool start = true;

void setup() 
{
    // runs once
    Serial.begin(9600);

    pinMode(FAN_PIN , OUTPUT);
    pinMode(HEATER_0_PIN , OUTPUT);
    pinMode(HEATER_1_PIN , OUTPUT);
    pinMode(LED_PIN  , OUTPUT);
    
    pinMode(P_STEP_PIN  , OUTPUT);
    pinMode(P_DIR_PIN    , OUTPUT);
    pinMode(P_ENABLE_PIN    , OUTPUT);
    
    pinMode(R_STEP_PIN  , OUTPUT);
    pinMode(R_DIR_PIN    , OUTPUT);
    pinMode(R_ENABLE_PIN    , OUTPUT);
    
    pinMode(Z_STEP_PIN  , OUTPUT);
    pinMode(Z_DIR_PIN    , OUTPUT);
    pinMode(Z_ENABLE_PIN    , OUTPUT);
    
    pinMode(E_STEP_PIN  , OUTPUT);
    pinMode(E_DIR_PIN    , OUTPUT);
    pinMode(E_ENABLE_PIN    , OUTPUT);
    
    pinMode(Q_STEP_PIN  , OUTPUT);
    pinMode(Q_DIR_PIN    , OUTPUT);
    pinMode(Q_ENABLE_PIN    , OUTPUT);
    
}

void loop() 
{
    if(start)
    {
        start = false;
        header(); // if on start, run the main body of the program
    }
    
    String command = Serial.readString();
    if(command != "")
    {
      //Serial.println(command);
      parse_command(command);
    }

    
}



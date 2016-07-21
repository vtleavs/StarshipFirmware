#define P_STEP_PIN         54
#define P_DIR_PIN          55
#define P_ENABLE_PIN       38
#define P_MIN_PIN           3
#define P_MAP_PIN           2

#define R_STEP_PIN         60
#define R_DIR_PIN          61
#define R_ENABLE_PIN       56
#define R_MIN_PIN          14
#define R_MAP_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAP_PIN          19

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING

#include "Body.h"

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
        body(); // if on start, run the main body of the program
    }

        digitalWrite(38, LOW);
    digitalWrite(54, HIGH);
    delay(10);
    digitalWrite(54, LOW);

    if(Serial.read() == 'r') // check to see if the restart command has been given
    {
        Serial.println("restarting...");
        start = true;
    }
}



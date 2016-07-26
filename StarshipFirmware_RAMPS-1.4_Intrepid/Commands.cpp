
#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_

#include <Arduino.h>
#include "Commands.h"

bool G0_active = false;
bool G1_active = false;
bool G4_active = false;
bool G5_active = false;
bool G10_active = false;
bool G11_active = false;
bool G27_active = false;
bool G28_active = false;

void parse_command(String command)
{ 
  Serial.println("\nparsing command...");
  // Parse first letter
  char command_letter = command[0];

  char letters[13];
  float numbers[13];
  char count = -1;
  char current = command[0];
  char cstart = 0;
  char cstop = -1;
  while(current != '\n')
  {
       cstop++;
       cstart = cstop;
       current = command[cstop];
       count++;

       letters[count] = current;
       cstop++;
       cstart++;
       current = command[cstop];
       while(current != '\n' && current != ' ')
       {
          cstop++;
          current = command[cstop];
       }
       numbers[count] = (float)command.substring(cstart, cstop).toInt();
  }

  for(char i = 0; i <= count; ++i)
  {
    Serial.print(letters[i]);
    Serial.print(":");
    Serial.print(numbers[i]);
    Serial.print(", ");
  }
  Serial.println();
  
  if(letters[0] == 'G')
  {
    switch((int)numbers[0])
    {
      case 0 : G0(letters, numbers);
               break;
      case 1 : G1(letters, numbers);
               break;
      case 20 : G20();
                break;
      case 21 : G21();
                break;
      default : Serial.println("Command Unsupported");
                break;
    }
  }
  else if(letters[0] == 'M')
  {
    switch((int)numbers[0])
    {
      case 5 : M5();
                break;
      default : Serial.println("Command Unsupported");
                break;
    }
  }
}

void G0(char letters[], float numbers[])
{ 
  Serial.println("rapid linear move, calling G1");
  G1(letters, numbers); 
}

void G1(char letters[], float numbers[]) 
{ 
  Serial.println("linear move, calling G5");
  G5(letters, numbers); 
}

void G5(char letters[], float numbers[])
{
  Serial.println("polar move");
}

void G28(char letters[], float numbers[]) 
{ 
  G27(letters, numbers); 
}

void M5()
{
  Serial.println("Restarting firmware...\n");
  delay(200);
  asm volatile ("  jmp 0");
}

void M18(char letters[], float numbers[])
{ 
  M17(letters, numbers); 
}

void G20()
{
  Serial.println("setting units to inches...");
}

void G21()
{
  Serial.println("setting units to millimeters...");
}

void M114(char letters[], float numbers[]) 
{ 
  M113(letters, numbers); 
}

void M201(char letters[], float numbers[]) 
{ 
  M200(letters, numbers); 
} 

void M203(char letters[], float numbers[]) 
{ 
  M200(letters, numbers); 
} 

void M208(char letters[], float numbers[]) 
{ 
  M207(letters, numbers); 
}

#endif

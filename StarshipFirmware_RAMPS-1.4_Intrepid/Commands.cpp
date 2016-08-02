
#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_

#include <Arduino.h>
#include "Commands.h"
#include "Messages.h"
#include "Settings.h"

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

// G COMMANDS

void G()
{
  list_g_commands();
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

void G4(char letters[], float numbers[])
{
  
}

void G5(char letters[], float numbers[])
{
  Serial.println("polar move");
}

void G10(char letters[], float numbers[])
{
  
}

void Gll(char letters[], float numbers[])
{
  
}

void G20()
{
  Serial.println("setting units to inches...");
  settings.units = "in";
}

void G21()
{
  Serial.println("setting units to millimeters...");
  settings.units = "mm";
}

void G27(char letters[], float numbers[])
{
  
}

void G28(char letters[], float numbers[]) 
{ 
  G27(letters, numbers); 
}

void G90()
{
  
}

void G91()
{
  
}

void G92(char letters[], float numbers[])
{
  
}

// M COMMANDS

void M()
{
  list_m_commands();
}

void M0()
{
  
}

void M1()
{
  
}

void M5()
{
  Serial.println("Restarting firmware...\n");
  delay(200);
  asm volatile ("  jmp 0");
}

void M17(char letters[], float numbers[])
{
  
}

void M18(char letters[], float numbers[])
{ 
  M17(letters, numbers); 
}

void M20()
{
  
}

void M23(String file)
{
  
}

void M24()
{
  
}

void M25()
{
  
}

void M26(char letters[], float numbers[])
{
  
}

void M27()
{
  
}

void M29()
{
  
}

void M32(String file)
{
  
}

void M36(String file)
{
  
}

void M82()
{
  
}

void M83()
{
  
}

void M92(char letters[], float numbers[])
{
  
}

void M98(String file)
{
  
}

void M98(char letters[], float numbers[])
{
  
}

void M99()
{
  
}

void M104(char letters[], float numbers[])
{
  
}

void M105()
{
  
}

void M106(char letters[], float numbers[])
{
  
}

void M107(char letters[], float numbers[])
{
  
}

void M109(char letters[], float numbers[])
{
  
}

void M112()
{
  
}

void M113(char letters[], float numbers[])
{
  
}

void M114(char letters[], float numbers[]) 
{ 
  M113(letters, numbers); 
}

void M115()
{
  
}

void M116()
{
  
}


void M118(char letters[], float numbers[])
{
  
}

void M119()
{
  
}

void M120()
{
  
}

void M121()
{
  
}

void M122()
{
  
}

void M140(char letters[], float numbers[])
{
  
}

void M144()
{
  
}

void M190(char letters[], float numbers[])
{
  
}

void M200(char letters[], float numbers[])
{
  
}

void M201(char letters[], float numbers[]) 
{ 
  M200(letters, numbers); 
} 

void M202(char letters[], float numbers[])
{
  
}

void M203(char letters[], float numbers[]) 
{ 
  M200(letters, numbers); 
} 


void M207(char letters[], float numbers[])
{
  
}

void M208(char letters[], float numbers[]) 
{ 
  M207(letters, numbers); 
}
void M220(char letters[], float numbers[])
{
  
}

void M221(char letters[], float numbers[])
{
  
}

void M226()
{
  
}

void M300(char letters[], float numbers[])
{
  
}

void M301(char letters[], float numbers[])
{
  
}

void M302(char letters[], float numbers[])
{
  
}

void M304(char letters[], float numbers[])
{
  
}

void M349(char letters[], float numbers[])
{
  
}

void M350(char letters[], float numbers[])
{
  
}

void M360()
{
  
}

void M400()
{
  
}

void M404(char letters[], float numbers[])
{
  
}

void M407()
{
  
}

void M502()
{
  
}

void M503()
{
  
}

void M556(char letters[], float numbers[])
{
  
}

void M562()
{
  
}

void M577(char letters[], float numbers[])
{
  
}

void M579(char letters[], float numbers[])
{
  
}

void M928(String file)
{
  
}

#endif

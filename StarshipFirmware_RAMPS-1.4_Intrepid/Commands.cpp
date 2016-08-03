
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
    if(letters[1] != 0)
    {
      Serial.print(numbers[i]);
      Serial.print(", ");
    }
  }
  Serial.println();

  if(letters[0] == 'G')
  {
    switch((int)numbers[0])
    {
      case 0 : if(letters[1] == 0)
                  G();
                  break;
               G0(letters, numbers);
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
      case 0 : if(letters[1] == 0)
                  M();
                  break;
      case 5 : M5();
                break;
      case 113 : M113();
                 break;
      default : Serial.println("Command Unsupported");
                break;
    }
  }
}

char find_letter(const char (&letters)[13], char c)
{
  for(char i = 0; i < 13; ++i)
  {
    if(letters[i] == c)
       return i;
  }
  return 99;
}

// G COMMANDS

void G()
{
  list_g_commands();
}

void G0(const char (&letters)[13], const float (&numbers)[13])
{ 
  Serial.println("rapid linear move, calling G1");
  //G1(letters, numbers); 
}

void G1(const char (&letters)[13], const float (&numbers)[13]) 
{ 
  Serial.println("linear move, calling G5");
  G5(letters, numbers); 
}

void G4(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void G5(const char (&letters)[13], const float (&numbers)[13])
{
  Serial.println("polar move - unimplemented");
}

void G10(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void Gll(const char (&letters)[13], const float (&numbers)[13])
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

void G27(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void G28(const char (&letters)[13], const float (&numbers)[13]) 
{ 
  G27(letters, numbers); 
}

void G90()
{
  Serial.println("setting axes to absolute mode...");
  settings.polar_stepper.set_absolute(true);
  settings.radial_stepper.set_absolute(true);
  settings.z_stepper.set_absolute(true);
}

void G91()
{
  Serial.println("setting axes to relative mode...");
  settings.polar_stepper.set_absolute(false);
  settings.radial_stepper.set_absolute(false);
  settings.z_stepper.set_absolute(false);
}

void G92(const char (&letters)[13], const float (&numbers)[13])
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

void M17(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M18(const char (&letters)[13], const float (&numbers)[13])
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

void M26(const char (&letters)[13], const float (&numbers)[13])
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

void M92(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M98(String file)
{
  
}

void M98(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M99()
{
  
}

void M104(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M105()
{
  
}

void M106(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M107(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M109(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M112()
{
  
}

void M113()
{
  Serial.print("Polar Position: ");
  Serial.print(settings.polar_stepper.get_stepnum() * settings.step_angle);
  Serial.println("deg");

  Serial.print("Radial Position: ");
  Serial.print(settings.radial_stepper.get_pos());
  Serial.println(settings.units);

  Serial.print("Z Position: ");
  Serial.print(settings.z_stepper.get_pos());
  Serial.println(settings.units);
}

void M114() 
{ 
}

void M115()
{
  
}

void M116()
{
  
}


void M118(const char (&letters)[13], const float (&numbers)[13])
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

void M140(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M144()
{
  
}

void M190(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M200(const char (&letters)[13], const float (&numbers)[13])
{
    char p = find_letter(letters, 'P');
    if(p != 99)
    {
      Serial.print("Polar Position: ");
      Serial.print(numbers[p]);
      Serial.println(settings.units);
    }
}

void M201(const char (&letters)[13], const float (&numbers)[13]) 
{ 
  M200(letters, numbers); 
} 

void M202(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M203(const char (&letters)[13], const float (&numbers)[13]) 
{ 
  M200(letters, numbers); 
} 


void M207(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M208(const char (&letters)[13], const float (&numbers)[13]) 
{ 
  M207(letters, numbers); 
}
void M220(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M221(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M226()
{
  
}

void M300(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M301(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M302(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M304(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M349(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M350(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M360()
{
  
}

void M400()
{
  
}

void M404(const char (&letters)[13], const float (&numbers)[13])
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

void M556(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M562()
{
  
}

void M577(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M579(const char (&letters)[13], const float (&numbers)[13])
{
  
}

void M928(String file)
{
  
}

#endif

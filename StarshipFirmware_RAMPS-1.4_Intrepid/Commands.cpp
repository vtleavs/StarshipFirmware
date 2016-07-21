#include "Commands.h"

void parse_command(String command)
{ 
  // Parse first letter
  char command_letter;
  // Parse trailing number
  short command_number
  
  if(command_letter == 'G')
  {
    switch(command_number)
    {
      case 1 : break;
      case 20 : G20();
                break;
      case 21 : G21();
                break;
      default : break;
    }
  }
  else if(command_letter == 'M')
  {
    
  }
}

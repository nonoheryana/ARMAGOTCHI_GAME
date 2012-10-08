#ifndef NAMES_H
#define NAMES_H

#include <string>

enum 
{
  ent_AlienGotchi,

  ent_RoboGotchi
};

inline std::string GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_AlienGotchi:

    return "AlienGotchi";

  case ent_RoboGotchi:
    
    return "RoboGotchi"; 

  default:

    return "UNKNOWN!";
  }
}

#endif
#ifndef _BULBASAUR
#define _BULBASAUR

#include <string>
#include "Pokemon.h"

class Bulbasaur : public Pokemon
{
  protected:
  unsigned short int id;
  string name;
  unsigned short int type;
  unsigned short int Hp;
  unsigned short int atk;
  unsigned short int sAtk;
  unsigned short int def;
  unsigned short int sDef;
  unsigned short int speed;
  unsigned short int lvl;

  ///@brief class constructor
  Bulbasaur ()

  ///@brief class destructor
  ~Bulbasaur ()

}
#endif

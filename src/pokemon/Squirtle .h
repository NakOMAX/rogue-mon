#ifndef _SQUIRTLE
#define _SQUIRTLE

#include <string>
#include "Pokemon.h"

class Squirtle  : public Pokemon
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
Squirtle ()

///@brief class destructor
~Squirtle()



}
#endif

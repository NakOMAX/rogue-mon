#ifndef _BULBASAUR_H
#define _BULBASAUR_H

#include <string>
#include "Pokemon.h"
#include "Attack.h"


// Faut-il associer les attaques à chaque Pokemon ?
class Bulbasaur : public Pokemon
{
 public :

  ///@brief class constructor
  Bulbasaur ();

  ///@brief class destructor
  ~Bulbasaur ();

};
#endif

#ifndef _SQUIRTLE_H
#define _SQUIRTLE_H

#include <string>
#include "Pokemon.h"
#include "Attack.h"


// Faut-il associer les attaques à chaque Pokemon ?
/**@class Squirtle
  @brief a water-type pokemon*/
class Squirtle  : public Pokemon
{
    public :

    ///@brief class constructor
    Squirtle ();

    ///@brief class destructor
    ~Squirtle();
};
#endif

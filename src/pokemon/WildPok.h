#ifndef _WILDPOK
#define _WILDPOK

#include <string>
#include "Pokemon.h"
#include "Attack.h"
using namespace std;

// Faut-il associer les attaques à chaque Pokemon ?

class WildPok : public Pokemon
{
public :

    ///@brief class constructor
    WildPok ();

    ///@brief class destructor
    ~WildPok ();

    ///@brief check if the WildPokemon is dead
    bool wildIsDead();

};
#endif

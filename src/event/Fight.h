#ifndef _Fight
#define _Fight

#include "Player.h"
#include "Pokemon.h"
#include "WildPok.h"
#include "Attack.h"
#include "Item.h"

#include <string>

class Fight
{
    private :
        Player* me;
        WildPok* opposant;

        ///@brief  produces the effects of the attack
        void effectsatt(const Attack &att);
        ///@brief player attack
        void raid(Pokemon* pok);
        ///@brief action of the item
        void acitem(Pokemon* Pok);
    public :

    ///@brief class constructor
    Fight (const Player& newme, const WildPok & newopposant);
    ///@brief class destructor
    ~Fight ();
    ///@brief first part of the round
    //void playerplay ();

    ///@brief choising a pokemon in your inventory
    Pokemon* choicePok(Pokemon* old);
    ///@brief menu of the actions during the fight
    void action ();



};

#endif

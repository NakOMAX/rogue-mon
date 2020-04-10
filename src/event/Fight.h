#ifndef _Fight
#define _Fight

#include "Player.h"
#include "WildPok.h"
#include "Attack.h"


class Fight 
{
    private : 
        Player* me;
        WildPok* opposant;

        ///@brief  produces the effects of the attack
        void effects(const Attack &att);

    public :

    ///@brief class constructor
    Fight (const Player& newme, const WildPok & newopposant);
    ///@brief class destructor
    ~Fight ();
    ///@brief first part of the round
    //void playerplay ();

    ///@ choising a pokemon in your inventory
    pokemon choice();
    ///@brief player attack
    void raid();
    

};

#endif
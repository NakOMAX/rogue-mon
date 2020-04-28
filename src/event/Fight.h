///@file Fight header file 
#ifndef _FIGHT_H
#define _FIGHT_H

#include "Player.h"
#include "Pokemon.h"
#include "WildPok.h"
#include "Attack.h"
#include "Item.h"
#include "Event.h"
#include "Component.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <memory>


class Fight : public Event

{


/*----------------------------*/
    public :

    ///@brief class constructor
    Fight (Player& newme, WildPok & newopposant);
    ///@brief class destructor
    ~Fight ();



    private :
        Player* me;
        WildPok* opposant;
        

        ///@brief  produces the effects of the attack played by the player
        ///@param att {is the attack we want to play} Pok {is the pokemon who attacks}
        void effectsattPlayer (Attack* att, Pokemon* Pok);     
        ///@brief player attack
        ///@param Pok {is the Pokemon in play}
        void raid(Pokemon* Pok);
        ///@brief action of the item
        ///@param Pok {is the Pokemon in play}
        ///precondition : The player must have at least an Item 
        void acitem(Pokemon* Pok);
        ///@brief choising a pokemon in your inventory
        ///@param Pok {is the Pokemon you want to remplace}
        /// Precondition : The playermust have more than one pokemonin his array
        Pokemon* choicePok(Pokemon* old);
    /*///@brief menu of the actions during the fight 
        void action (); */
        ///@brief Opposant turn
        ///@param defender {is the pokemon from Player in game}
        void actionOpposant (Pokemon* defender);
        ///@brief produces the effects of the attack played by the opposant
        ///@param defender {is the pokemon from Player in game} att {is the attack we want to play}
        void effectsattopposant (Attack* att, Pokemon* defender);

        


        ///@brief see event init
        short int init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer);
        ///@brief see event run
        short int run(SDL_Renderer * renderer, Pokemon * Pok);
        /** @brief dialogue box for cinematic*/
        std::shared_ptr<DialogueBox> box;
       
};

#endif

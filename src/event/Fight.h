///@file Fight header file 
#ifndef _Fight
#define _Fight

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
    private :
        Player* me;
        WildPok* opposant;
        

        ///@brief  produces the effects of the attack
        void effectsatt (Attack* att, Pokemon* Pok);
/*---------without sdl---------------*/        
        ///@brief player attack
        void raid(Pokemon* pok);
        ///@brief action of the item
        ///precondition : The player must have at least an Item 
        void acitem(Pokemon* Pok);


/*----------------------------*/
    public :

    ///@brief class constructor
    Fight (Player& newme, WildPok & newopposant);
    ///@brief class destructor
    ~Fight ();
 /*----------Without SDL (maybe not for long anymore)--------------------*/
    ///@brief choising a pokemon in your inventory
    /// Precondition : The playermust have more than one pokemonin his array
    Pokemon* choicePok(Pokemon* old);
    ///@brief menu of the actions during the fight 
    void action ();


/*---------With SDL--------------------------*/
    ///@brief see event init
    short int init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer);
    ///@brief see event run
    short int run(SDL_Renderer * renderer, Pokemon * Pok);
    /** @brief dialogue box for cinematic*/
    std::shared_ptr<DialogueBox> box;





};

#endif

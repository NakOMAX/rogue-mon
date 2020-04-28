#include "Player.h"
#include "Pokemon.h"
#include "WildPok.h"
#include "Attack.h"
#include "Item.h"
#include "Fight.h"
#include "Component.h"
#include "InheritedEvents.h"
#include "Event.h"
//#include "../player/Player.h"
#include <iostream> //testing/debug only
#include <string>
#include <cstring>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "sdlTools.h"







Fight :: Fight (Player& newme, WildPok & newopposant)
{
    me = &newme;
    opposant = &newopposant;
    
}

Fight :: ~Fight () {}

Pokemon* Fight :: choicePok (Pokemon* old)
{
    SDL_Event event;

    (*box) << "Quel Pokemon voulez-vous utliser ? " ;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case 1: if (old!= me->getPokemon(0)) return me->getPokemon(0);

                case 2 :if ((1<me->getNbPokemon()) && (old!= me->getPokemon(1))) return me->getPokemon(1);

                case 3 :if ((2<me->getNbPokemon()) && (old!= me->getPokemon(2))) return me->getPokemon(2);
                case 4 :if ((3<me->getNbPokemon()) && (old!= me->getPokemon(3))) return me->getPokemon(3);
                case 5 :if ((4<me->getNbPokemon()) && (old!= me->getPokemon(4))) return me->getPokemon(4);
                case 6 :if ((5<me->getNbPokemon()) && (old!= me->getPokemon(5))) return me->getPokemon(5);
            }
        default : return choicePok (old); //ce return est très laid et consommateur de mémoire et temps, autre idée ?
        //Faut-il faire d'autre cas ?
    }

}

void Fight :: raid  (Pokemon* Pok)
{
    SDL_Event event;
       // (*box)= std :: make_shared<DialogueBox>();

    (*box) << strcat("Quelle attaque voulez-vous effectuer ?  1 est ", Pok->getMyAttacks(0)->getName().c_str()); // étendre avec un pour quand on aura plus d'attques
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case 1 :  effectsattPlayer(Pok->getMyAttacks(0), Pok);break;

                case 2 :  effectsattPlayer(Pok->getMyAttacks(1), Pok);break;

            }
        default : return raid(Pok); //ce return est très laid et consommateur de mémoire et temps, autre idée ?
        //Faut-il faire d'autre cas ?

    }



}

void Fight :: effectsattPlayer (Attack* att, Pokemon* Pok)
{
    opposant->setHp( opposant->getHp()- (att->getImpact()*(Pok->getAtk())-opposant->getDef()));
    Pok->defIncrease( att->getGainDefense() );
    Pok->atkIncrease( att->getGainAtk() );
}

void Fight :: acitem (Pokemon* Pok) // à completer
{
    if (me->getNbItem() == 0) return;
    SDL_Event event;

    (*box) << "Quel objet vous-vous utiliser ? " ;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case 1:   (me->getItem(0))->actionitem(Pok);break;

                case 2 :if (1<me->getNbItem())   me->actionitem(me->getItem(1),Pok);break;

                case 3 :if (2<me->getNbItem())   me->actionitem(me->getItem(2),Pok); break;

                case 4 :if (3<me->getNbItem())   me->actionitem(me->getItem(3),Pok); break;

                case 5 :if (4<me->getNbItem())   me->actionitem(me->getItem(4),Pok); break;

                case 6 :if (5<me->getNbItem())   me->actionitem(me->getItem(5), Pok); break;
            }
        default :  acitem(Pok);
        //Faut-il faire d'autre cas ?
    }


}

void Fight :: actionOpposant (Pokemon* defender)
{
    short int att;
    att = rand()%2 - 1;
    (*box) << strcat(strcat(opposant->getName().c_str(),"Effectue "), opposant->getMyAttacks(att)->getName().c_str());
    effectsattopposant (opposant->getMyAttacks(att), defender);
}

void Fight :: effectsattopposant (Attack* att, Pokemon* defender)
{
    defender->setHp( defender->getHp()- (att->getImpact()*(opposant->getAtk())-defender->getDef()));
    opposant->defIncrease( att->getGainDefense() );
    opposant->atkIncrease( att->getGainAtk() );
}

/*
void Fight :: action ()
{
    Pokemon* Pok= new Pokemon;
    char act;
    Pok=me->getPokemon(0);
    if(!me->playerIsDead() && !opposant->wildIsDead())//fonction à écrire
    {
        if (me->pokIsDead())
            {act = 's';}
        else
        {
            do {
                cout<< "Quelle action voulez-vous effectuer ? x: attaquer; c: item; s: changer de pokemon" <<endl;
                cin>>act;
            }while (act != 'x' || act != 'c' || act != 's');
        }
        switch (act)
            {
                case 'x': raid(Pok); break;

                case 'c': acitem(Pok); break;

                case 's': choicePok(Pok); break;

               default : break;

            }

    }
    else
    {
        if (me->playerIsDead()){ cout<<"Vous avez perdu";}// bizarre pour l'appel
        else { cout<<"Vous avez gagné ! Bravo !!!";}
    }

     delete Pok;

}*/

short int Fight::init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer)
{
    //std :: cout<<"Fight correct initialisation"<<endl; //debug

    box= std :: make_shared<DialogueBox>();

    Pokemon* Pok= new Pokemon;
    Pok=me->getPokemon(0);


    // init components
    box->_init(dimX, dimY, renderer);
    for (short unsigned int i = 0; i < components.size(); i++) {
        if (!(components[i]->_init(dimX, dimY, renderer))) return 1;
    }

    /*//init background
    back_text = loadImage(background_source);
    background = SDL_CreateTextureFromSurface(renderer, back_text);


    //init file ifstream
    myfile.open(txt_source);
    */
    return run(renderer, Pok);
}

short int Fight::run(SDL_Renderer * renderer, Pokemon* Pok) {
  bool hasFinished = false;
  SDL_Event evt;
  std :: cout<<"Launched cinematic loop"<< std :: endl; //debug

  do{
    //render bg
    if (SDL_RenderCopy(renderer, background, NULL, NULL) < 0)
    {
        printf("Box: No renderer error. Forcing exit...\n" );
        return ERRCODE_NO_RENDER;
    }

    // update every component
    if (box->_update(renderer) > 0)
    {
        // error during rendering, exit
        break;
    }

    for (unsigned int i = 0; i < components.size(); i++)
    {
        if ((!components[i]->_update(renderer))>0)
            return 1;
    }

    if(opposant->wildIsDead())
    {
        (*box)<<"Vous avez gagné le combat";
        hasFinished = true;
    }


    if(me->pokIsDead())
    {
        (*box)<<"Votre Pokémon n'a plus de point de vie";
        if (me->playerIsDead())
        {
            (*box)<<"Vous avez perdu";
            hasFinished = true;
        }
        else choicePok(Pok);
    }



    //render
    SDL_RenderPresent(renderer);
    // event treatement
    while ( SDL_PollEvent(&evt) )
    {
        switch(evt.type)
        {
            case SDL_QUIT:
                hasFinished= true;
                break;
            case SDL_KEYDOWN:
                switch (evt.key.keysym.sym)
                {
                    case SDLK_x : raid(Pok); break;

                    case SDLK_c : acitem(Pok); break;

                    case SDLK_s : choicePok(Pok); break;
                }
            default: break;
        }
        
    }
    //Je pense que l'opposant doit jouer ici mais ca va poser probleme dans la boucle
    } while (!hasFinished);
    //end of event
    delete Pok;
    return 0;
}

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
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "sdlTools.h"







Fight :: Fight (Player * newme, WildPok * newopposant)
{
    me = newme;
    opposant = newopposant;

}

Fight :: ~Fight () {}

Pokemon* Fight :: choicePok (Pokemon* old)
{
    SDL_Event event;
      *box << "Quel Pokemon voulez-vous utliser ? " ;
      SDL_WaitEvent(&event);
      if (event.type == SDL_KEYDOWN)
      {
        // Number is within range?
        if (event.key.keysym.sym > 0 && event.key.keysym.sym <= me->getNbPokemon())
        {
          // Number is the pokemon that was already fighting?
          if (old == me->getPokemon(event.key.keysym.sym-1))
          {
            *box << "Ce pokemon est déjà sur le champ";
            SDL_WaitEvent(&event);
          } else {
            // Selected pokemon is ok and can be returned
            return me->getPokemon(event.key.keysym.sym-1);
          }
        } else {
          *box << "Numèro de pokemon invalide";
          SDL_WaitEvent(&event);
        }
      }
    return old;
}

void Fight :: raid  (Pokemon* Pok)
{
  SDL_Event event;
     // (*box)= std :: make_shared<DialogueBox>();
  bool ok = false;
  do {
    std::string text = "Quelle attaque voulez-vous effectuer ?  1 est " + Pok->getMyAttacks(0)->getName();
    *box << text.c_str(); // étendre avec un pour quand on aura plus d'attques

    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN)
    {
      // Number is within range?
      /* pensez à implementer une fonction pour récuperer le nombre d'attaques*/
      if (event.key.keysym.sym > 0 && event.key.keysym.sym <= 1)
      {
        effectsattPlayer(Pok->getMyAttacks(event.key.keysym.sym), Pok);
      } else {
        *box << "Numèro d'attaque invalide";
        SDL_WaitEvent(&event);
      }
    }
  } while (!ok);
}

void Fight :: effectsattPlayer (Attack* att, Pokemon* Pok)
{
    opposant->setHp( opposant->getHp()- (att->getImpact()*(Pok->getAtk())-opposant->getDef()));
    Pok->defIncrease( att->getGainDefense() );
    Pok->atkIncrease( att->getGainAtk() );
}

void Fight :: acitem(Pokemon* Pok) // à completer
{
  // C'est mieux d'éviter d'appeller cette fonction s'il n'y a plus d'items
  //if (me->getNbItem() == 0) return;
  // (*box)= std :: make_shared<DialogueBox>();

  SDL_Event event;
  bool ok = false;
  do {
    *box << "Quel objet vous-vous utiliser ? " ;

    SDL_WaitEvent(&event);
    if(event.type == SDL_KEYDOWN)
    {
      // Number is within range?
      if (event.key.keysym.sym > 0 && event.key.keysym.sym <= me->getNbItem())
      {
        me->getItem(event.key.keysym.sym)->actionItem(Pok);
      } else {
        *box << "Numèro d'attaque invalide";
        SDL_WaitEvent(&event);
      }
    }
  } while (!ok);
}

void Fight :: actionOpposant (Pokemon* defender)
{
    /*pensez à implementer une fonction pour recuperer le nombre d'attaques d'un pokemon */
    short int att = rand()%1;
    std::string text = opposant->getName() + " enemi effectue " + opposant->getMyAttacks(att)->getName();
    *box << text.c_str();
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

short int Fight::init(SDL_Renderer * renderer, unsigned short int dimX, unsigned short int dimY)
{
    //std :: cout<<"Fight correct initialisation"<<endl; //debug

    box= new DialogueBox;
    components.push_back(&(*box));

    active = new Pokemon;
    active = me->getPokemon(0);

    /*//init background
    back_text = loadImage(background_source);
    background = SDL_CreateTextureFromSurface(renderer, back_text);


    //init file ifstream
    myfile.open(txt_source);
    */
    return 0;
}

short int Fight::run(SDL_Renderer * renderer, SDL_Event evt) {
  std :: cout<<"Launched cinematic loop"<< std :: endl; //debug

  //render bg EVENT HAS NO BACKGROUND
  // if (SDL_RenderCopy(renderer, background, NULL, NULL) < 0)
  // {
  //     printf("Box: No renderer error. Forcing exit...\n" );
  //     return ERRCODE_NO_RENDER;
  // }

  if(opposant->wildIsDead())
  {
      (*box)<<"Vous avez gagné le combat";
      return -1;
  }


  if(active->pokIsDead())
  {
      (*box)<<"Votre Pokémon n'a plus de point de vie";


      if (me->playerIsDead())
      {
          (*box)<<"Vous avez perdu";
          return -1;
      }
      else active = choicePok(active);
  }



  //render
  SDL_RenderPresent(renderer);
  // event treatement
  while ( SDL_PollEvent(&evt) )
  {
      switch(evt.type)
      {
          case SDL_QUIT:
              return -1;
              break;
          case SDL_KEYDOWN:
              switch (evt.key.keysym.sym)
              {
              case SDLK_x :
                raid(active);
                // Enemy's turn
                break;

              case SDLK_c :
                acitem(active);
                // Enemy's turn
                break;

              case SDLK_s :
                choicePok(active);
                // Enemy's turn
                break;
              }
          default: break;
      }
    }
    return 0;
}

short int Fight::exit(){
  delete box;
  box = NULL;
  me = NULL;
  delete opposant;
  opposant = NULL;
  return 0;
}

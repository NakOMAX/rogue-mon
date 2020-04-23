#include "InheritedEvents.h"
#include "Event.h"
//#include "../player/Player.h"
#include <iostream> //testing/debug only
#include <string>
#include <fstream>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "sdlTools.h"
#include "Component.h"

// ---------------- Test

short int Test::init(/*Player p*/) {
  ennemy[0].hp = 10;
  ennemy[1].hp = 13;
  ennemy[0].hp_max = 10;
  ennemy[1].hp_max = 13;
  ennemy[0].atk = 1;
  ennemy[1].atk = 1;
  ennemy[0].def = 4;
  ennemy[1].def = 2;
  return run(/*p*/);
}

short int Test::run(/*Player p*/) {
  bool hasFinished = false;
  while (!hasFinished) {
    for (int i = 0; i < 2; i++) {
      std::cout<<"Ennemy number "<<i<<" dealt "<<ennemy[i].atk<<" damage"<<std::endl;
    }
    std::cout<<" Wait I forgot to implement logic"<<std::endl;
    hasFinished = !hasFinished;
  }
  return 0;
}

// ------------ cinematic

Cinematic::Cinematic(std::string text_adress, std::string image_adress) {
  txt_source = text_adress;
  background_source = image_adress;
}

short int Cinematic::init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer) {
  std::cout<<"Cinematic correct initialisation"<<std::endl; //debug

  box = std::make_shared<DialogueBox>();

  // init components
  box->_init(dimX, dimY, renderer);
  for (short unsigned int i = 0; i < components.size(); i++) {
    if (!(components[i]->_init(dimX, dimY, renderer))) return 1;
  }

  //init background
  back_text = loadImage(background_source);
  background = SDL_CreateTextureFromSurface(renderer, back_text);

  //init file ifstream
  myfile.open(txt_source);

  return run(renderer);
}

short int Cinematic::run(SDL_Renderer * renderer) {
  bool hasFinished = false;
  SDL_Event evt;
  std::cout<<"Launched cinematic loop"<<std::endl; //debug
  read(box);
  do {
    //render bg
    if (SDL_RenderCopy(renderer, background, NULL, NULL) < 0) {
      printf("Box: No renderer error. Forcing exit...\n" );
      return ERRCODE_NO_RENDER;
    }

    // read(box);
    //*box<<"Hello";
    // update every component
    if (box->_update(renderer) > 0)
    {
      // error during rendering, exit
      break;
    }

    for (unsigned int i = 0; i < components.size(); i++) {
      if ((!components[i]->_update(renderer))>0)
        return 1;
    }

    //render
    SDL_RenderPresent(renderer);
    // event treatement
    while ( SDL_PollEvent(&evt) ) {
      switch (evt.type) {
        case SDL_QUIT: hasFinished = !hasFinished; break; // devra être mis dans le controlleur
        case SDL_KEYUP : if (read(box)>0) hasFinished = !hasFinished; break; //component 0 is dialoguebox
        default: break;
      }
    }
  } while (!hasFinished);
  //end of event
  myfile.close();
  return 0;
}

short int Cinematic::read(std::shared_ptr<DialogueBox> db) {
  if (!myfile.is_open()) {
    myfile.open(txt_source);
  } else {
    if(!myfile.eof()) {
      std::string buf;
      getline(myfile, buf);
      std::cout<<buf<<std::endl; //debug
      db->clean();
      (*db)<<buf.c_str();
    } else {
      return 1;
    }
  }
  return 0;
}

//----------------------------------------------------------------------------//
//-------------------------------->HEALING<-----------------------------------//
//____________________________________________________________________________//

/*short int Healing::init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer, const Player & player)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 20);
  for (unsigned short int i = 0; i < 100; i++)
  {
    SDL_RenderDrawRect(renderer, NULL);
    SDL_Delay(5);
  }
  unsigned short int n = player.getNumberOfPokemons();//changer le nom de la fonction 
  Pokemon * current;
  for (unsigned short int i = 0; i<n; i++)
  {
    current = player.getPokemon(i);
    current->setHP(current->getMaxHp());
  }
  return 0;
}*/

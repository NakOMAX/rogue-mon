#include "InheritedEvents.h"
#include "Event.h"
//#include "../player/Player.h"
#include <iostream> //testing/debug only
#include <string>
#include <fstream>
#include <memory>
#include <iostream> //debug
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

short int Cinematic::init(SDL_Renderer * renderer, unsigned short int dimX, unsigned short int dimY) {
  std::cout<<"Cinematic correct initialisation"<<std::endl; //debug

  // box = std::make_shared<DialogueBox>();
  box = new DialogueBox;
  std::cout<<"DB made"<<std::endl; //boxtest
  components.push_back(&(*box)); //boxtest

  //init background
  back_text = loadImage(background_source);
  background = SDL_CreateTextureFromSurface(renderer, back_text);

  //init file ifstream
  myfile.open(txt_source);

  return 0;
}

short int Cinematic::run(SDL_Renderer * renderer, SDL_Event evt) {
  //render bg
  if (SDL_RenderCopy(renderer, background, NULL, NULL) < 0) {
    printf("Box: No renderer error. Forcing exit...\n" );
    return ERRCODE_NO_RENDER;
  }

  if(box->isEmpty()) read(box);

  // event treatement
  while(SDL_PollEvent(&evt)) {
    switch (evt.type) {
        case SDL_QUIT: return -1; // devra être mis dans le controlleur
        case SDL_KEYUP : if (read(box)>0) return -1;
        default: break;
    }
  }
  return 0;
}

short int Cinematic::exit() {
  std::cout<<"exit event"<<std::endl; //debug
  //end of event
  myfile.close();
  return 0;
}

short int Cinematic::read(DialogueBox* db) {
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
      return 99;
    }
  }
  return 0;
}

//----------------------------------------------------------------------------//
//-------------------------------->HEALING<-----------------------------------//
//____________________________________________________________________________//

// short int Healing::init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer, const Player & player)
// {
//   SDL_SetRenderDrawColor(renderer, 255, 255, 255, 20);
//   for (unsigned short int i = 0; i < 100; i++)
//   {
//     SDL_RenderDrawRect(renderer, NULL);
//     SDL_Delay(5);
//   }
//   unsigned short int n = player.getNumberOfPokemons();
//   Pokemon * current;
//   for (unsigned short int i = 0; i<n; i++)
//   {
//     current = player.getPokemon(i);
//     current->setHP(current->getMaxHp());
//   }
//   return 0;
// }

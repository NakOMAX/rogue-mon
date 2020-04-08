#include "InheritedEvents.h"
#include "Event.h"
// #include "../player/Player.h"
#include <iostream> //testing/debug only
#include <string>
#include <fstream>
#include <memory>
#include <iostream> //debug
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Component.h"

// BLOC POUR TEST, INCLU AVEC MAP.cpp
SDL_Surface * loadImage(const std::string & filename)
{
  SDL_Surface * surface;
  surface = IMG_Load(filename.c_str());
  if (surface==NULL)
  {
    std::string modFilename;
    modFilename = "../" + filename;
    surface = IMG_Load(modFilename.c_str());
    if (surface==NULL)
    {
      modFilename = "../" + modFilename;
      surface = IMG_Load(modFilename.c_str());
      if (surface==NULL)
      {
        printf("Error: %s\n", SDL_GetError());
      }
    }
  }
  return surface;
}
// FIN BLOC TEST

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

  // init components
  box->_init(dimX, dimY, renderer);
  for (short unsigned int i = 0; i < components.size(); i++) {
    if (!(components[i]->_init(dimX, dimY, renderer))) return 1;
  }

  //init background
  SDL_Surface * surf = loadImage(background_source);
  background = SDL_CreateTextureFromSurface(renderer, surf);

  //init file ifstream
  myfile.open(txt_source);

  return run(renderer);
}

short int Cinematic::run(SDL_Renderer * renderer) {
  bool hasFinished = false;
  SDL_Event evt;
  std::cout<<"Launched cinematic loop"<<std::endl; //debug
  do {
    read(box);
    // update every component
    if ((box->_update(renderer))>0) std::cout<<"update box failed"<<std::endl;
    for (unsigned int i = 0; i < components.size(); i++) {
      if ((!components[i]->_update(renderer))>0) return 1;
    }
    //render
    std::cout<<"render"<<std::endl;
    SDL_RenderPresent(renderer);
    // get every event back
    while ( SDL_PollEvent(&evt) ) {
      switch (evt.type) {
        case SDL_QUIT: hasFinished = false; break;
        case SDL_KEYUP : read(box); //component 0 is dialoguebox
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

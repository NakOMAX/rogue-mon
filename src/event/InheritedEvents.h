/**@file inherited events header file*/

#ifndef POKE_EVI_H
#define POKE_EVI_H

#include "Event.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string.h>
#include <fstream>
#include <memory>

/*------------------ TESTING BLOCK STRUCTURE ---------------------------------*/
struct data {
  int hp;
  int hp_max;
  int atk;
  int def;
};


/** @class Test class, first event
    @brief testing purposes only
    yo*/
class Test : public Event {
public :
  /** @brief see Event init() */
  short int init();

  /** @brief see Event run() */
  short int run();

private :
  data ennemy[2];
};
/*----------------------------------------------------------------------------*/

class Cinematic : public Event {
public :
  /** class constructor */
  Cinematic(std::string text_adress, std::string image_adress);
  /** @brief see Event init() */
  short int init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * & render);
  /** @brief see Event run()*/
  short int run(SDL_Renderer * & render);
private :
  /** @brief text reader */
  short int read(DialogueBox * dBox);
  /** @brief cinematic text file adress */
  std::string txt_source;
  /** @brief background adress */
  std::string background_source;
  /** @brief text flux */
  std::ifstream myfile;
};

#endif

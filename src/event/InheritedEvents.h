/**@file inherited events header file*/

#ifndef POKE_EVI_H
#define POKE_EVI_H

#include "Event.h"
#include "Component.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
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
  virtual short int init();

  /** @brief see Event run() */
  virtual short int run();

private :
  data ennemy[2];
};
/*----------------------------------------------------------------------------*/

class Cinematic : public Event {
public :
  /** class constructor */
  Cinematic(std::string text_adress, std::string image_adress, std::string sprite_adress = "");
  /** @brief see Event run()*/
  short int run(SDL_Renderer * render, SDL_Event evt);
  /** @brief see Event init() */
  short int init(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY);
  /**@brief see Event exit()*/
  short int exit();
private :
  /** @brief text reader */
  short int read(DialogueBox* db);
  /** @brief cinematic text file adress */
  std::string txt_source;
  /** @brief background adress */
  std::string background_source;
  SDL_Texture * background;
  SDL_Surface * back_text;
  /** @brief text flux */
  std::ifstream myfile;
  /** @brief dialogue box for cinematic*/
  DialogueBox * box;
  /** @brief sprite*/
  std::string spr_source;
  Sprite * spr;
};
/*----------------------------------------------------------------------------*/

/*class Healing : public Event {
public:
  Healing();
  ~Healing();
  short int init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer, const Player & player);
};
*/
#endif

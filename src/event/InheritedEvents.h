/**@file inherited events header file*/

#ifndef POKE_EVI_H
#define POKE_EVI_H

#include "Event.h"
#include "Player.h"
#include "Component.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <fstream>
#include <memory>


/*----------------------------------------------------------------------------*/

/**@class Cinematic
  @brief event that displays a cinematic
  aka a portrait sprite with a background and a text read from a text file*/
class Cinematic : public Event {
public :
  /** @brief class constructor
      @param text_adress adress of text file
      @param image_adress adress of background
      @param adress of sprite to display as portrait*/
  Cinematic(std::string text_adress, std::string image_adress, std::string sprite_adress = "");
  /** @brief see Event run()*/
  short int run(SDL_Renderer * render, SDL_Event evt);
  /** @brief see Event init() */
  short int init(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY);
  /**@brief see Event exit()*/
  short int exit();
private :
  /** @brief text reader
      @param db points to dialoguebox to send line to*/
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

/**@class Healing
  @brief a healing event
  heals the player's party to full*/
class Healing : public Event {
public:
  Healing();
  ~Healing();
  short int init(unsigned short int dimX, unsigned short int dimY, SDL_Renderer * renderer, Player & player);
};
#endif

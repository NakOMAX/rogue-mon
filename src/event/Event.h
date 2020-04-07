/** @file header file for the Event class*/

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "Component.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <memory>

#ifndef POKE_EVE_H
#define POKE_EVE_H

/** @class Event class
    @brief events launched in gameplay
    An event launched by interacting with a node. Overrides gameplay.*/
class Event{
public:
  /** @brief Event constructor
      used so inherited classes can have a default*/
  Event();

  /** @brief event constructor
      never used due to being impractical with inheritace
      @param layer used in scaling*/
  Event(int layer);

  /** @brief event destructor*/
  ~Event();

  /** @brief init method
      called when launching event, launches run(), performs setup. Returns 0 if everything went correctly, else errorcode*/
  short int init(SDL_Renderer * render);

  /** @brief get method for scaling*/
  short int getScaling();

  /** @brief mainloop for the event
  overrides the normal mainloop until returned. Returns 0 if exited properly, errorcode else.*/
  short int run(SDL_Renderer * render);

protected:
  /** @brief scaling value of event
      used in order to choose difficulty and rewards*/
  int scaling;

  /** @brief background of event*/
  SDL_Texture * background;

  /**@brief array of components to draw*/
  std::vector<std::shared_ptr<Component>> components;
};
#endif

/** @file header file for the Event class*/

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "Component.h"
#include <stdlib.h>
#include <string>
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

  /** @brief event destructor*/
  ~Event();

  /** @brief mainloop for the event
  overrides the normal mainloop until returned. Returns 0 if while continues, -1 if mainloop exited, errorcode else. Called every frame.*/
  virtual short int run(SDL_Renderer * render, SDL_Event event) = 0;

  /** @brief init method
  called when launching event, launches run(), performs setup. Returns 0 if everything went correctly, else errorcode*/
  virtual short int init(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY) = 0;

  /** @brief exit method
    called once when event closes*/
  virtual short int exit() = 0;


  /** @brief meta version of init()
      called when launching event */
  short int launch(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY);

  /** @brief get method for scaling*/
  short int getScaling();

  /** @brief actual mainloop
  Calls run every frame after updating every components. Also get keyboard events.*/
  short int mainloop(SDL_Renderer * render);

protected:
  /** @brief scaling value of event
      used in order to choose difficulty and rewards*/
  int scaling;

  /**@brief array of components to draw*/
  std::vector<Component*> components;
};
#endif

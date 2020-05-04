#include "Event.h"
#include "Component.h"
#include "SDL.h"
#include "SDL_ttf.h"

/**@class Template
  @brief never instantiated or compiled, just an example to learn how events work*/
class Template : public Event {
public :
  /** @brief called every frame*/
  short int run(SDL_Renderer * render, SDL_Event evt);
  /** @brief called once at event launch
  Since you cannon change the parameters, do any additionnal setup in constructor
  You may consider stocking adresses and info on constructor then initialise fully
  on init call.*/
  short int init(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY);
  /**@brief called at event exit*/
  short int exit();
protected :
  // add any component by using a pointer then initialise in init() :
  DialogueBox * box;
  // you can add more elements or methods of course
};

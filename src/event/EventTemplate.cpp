#include "InheritedEvents.h"
#include "Event.h
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "sdlTools.h"
#include "Component.h"


short int run(SDL_Renderer * render, SDL_Event evt){
  /*This method is called every frame. You must render everything that is not
  in the components vector. Used mainly for logic.
  You must use SDL_PollEvent(&evt) manually to deal with events.*/
}

short int init(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY){
  /*This method is called at event launch exactly once. You do not have to init
  any component, but you must push them in the components array. Example below
  with a simple dialogueBox component.*/
  box = new DialogueBox;
  components.push_back(&(*box));
}

short int exit(){
  /*This method is called exactly once at event exit. Used to compress event
  size, since we cannot use any destructor until our event tree is deleted.*/
}

/** @file cpp file for the Event class
*/

#include "Event.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream> //debug

Event::Event() {
  scaling = 1;
}

Event::Event(int layer) {
  switch (layer) {
    default : scaling = 1;
  }
}

Event::~Event() {
}

short int Event::init(SDL_Renderer * render) {
  std::cout<<std::endl<<"Event initialised"<<std::endl; //debug
  return run(render);
}

short int Event::getScaling() {
  return scaling;
}

//#N Pointeur
short int Event::run(SDL_Renderer * render) {
  bool hasFinished = false;
  while (!hasFinished) {
    for (long long unsigned int i = 0; i < components.size(); i++) {
      if(components[i]->_update(render)) return 1;
    }
    hasFinished = !hasFinished;
  }
  std::cout<<"event normal exit"<<std::endl; //debug
  return 0;
}

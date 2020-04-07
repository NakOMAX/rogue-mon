/** @file cpp file for the Event class
*/

#include "Event.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <memory>

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
      components[i]->_update(render);
    }
    hasFinished = !hasFinished;
  }
  return 0;
}

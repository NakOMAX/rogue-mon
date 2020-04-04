/** @file cpp file for the Event class
*/

#include "Event.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <string.h>

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

short int Event::init() {
  return run();
}

short int Event::getScaling() {
  return scaling;
}

short int Event::run(SDL_Renderer render) {
  bool hasFinished = false;
  while (!hasFinished)
    for (int i = 0; i < components.size(); i++) {
      components[i]._update(render);
    }
    hasFinished = !hasFinished;
  }
  return 0;
}

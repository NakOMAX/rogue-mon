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

Event::~Event() {
}

short int Event::launch(SDL_Renderer * render, unsigned short int dimX, unsigned short int dimY) {
  std::cout<<"launch"<<std::endl;//debug
  init(render, dimX, dimY);
  std::cout<<"init check"<<std::endl;//debug
  for (size_t i = 0; i < components.size(); i++) {
    components[i]->_init(dimX, dimY, render);
  }
  std::cout<<"component init check"<<std::endl;
  return mainloop(render);
}

short int Event::mainloop(SDL_Renderer * render) {
  SDL_Event evt;
  short int res = 0;
  do {
    res = run(render, evt);
    for (size_t i = 0; i < components.size(); i++) {
      components[i]->_update(render);
    }
    SDL_RenderPresent(render);
  } while (res == 0);

  if (res > 0) {
    std::cout<<"bad exit : "<<res<<std::endl;
    return res;
  }

  return exit();
}

short int Event::getScaling() {
  return scaling;
}

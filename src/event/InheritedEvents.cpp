#include "InheritedEvents.h"
#include "Event.h"
// #include "../player/Player.h"
#include <iostream> //testing/debug only
#include "SDL_ttf.h"

short int Test::init(/*Player p*/) {
  ennemy[0].hp = 10;
  ennemy[1].hp = 13;
  ennemy[0].hp_max = 10;
  ennemy[1].hp_max = 13;
  ennemy[0].atk = 1;
  ennemy[1].atk = 1;
  ennemy[0].def = 4;
  ennemy[1].def = 2;
  return run(/*p*/);
}

short int Test::run(/*Player p*/) {
  bool hasFinished = false;
  while (!hasFinished) {
    for (int i = 0; i < 2; i++) {
      std::cout<<"Ennemy number "<<i<<" dealt "<<ennemy[i].atk<<" damage"<<std::endl;
    }
    std::cout<<" Wait I forgot to implement logic"<<std::endl;
    hasFinished = !hasFinished;
  }
  return 0;
}

/**@file inherited events header file*/

#ifndef POKE_EVI_H
#define POKE_EVI_H

#include "Event.h"

/*------------------ TESTING BLOCK STRUCTURE ---------------------------------*/
struct data {
  int hp;
  int hp_max;
  int atk;
  int def;
};


/** @class Test class, first event
    @brief testing purposes only
    yo*/
class Test : public Event {
public :
  /** @brief see Event init() */
  short int init();

  /** @brief see Event run() */
  short int run();

private :
  data ennemy[2];
};
/*----------------------------------------------------------------------------*/

#endif

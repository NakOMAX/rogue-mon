#ifndef _FIRST_H
#define _FIRST_H

#include <string>
#include "Attack.h"
/**@class First
  @brief the fisrt attack created.
  Its goal is a quick debug and a test of fonction in the fight*/
class First : public Attack{

    public :
    First();
    std :: string getName();
};

#endif

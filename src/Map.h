#ifndef POKE_MAP
#define POKE_MAP

#include "Event.h"

class Map{
public:
  /** @brief Class constructor */
  /** The class constructor randomly generates a map*/
  Map();
  /** @brief Class destructor */
  ~Map();
protected:
  /** @brief Array where the events are stocked */
  Event ** eventTree;
  /** @brief Array that stores the upper step of the n-th event */
  unsigned short int * father;
};
